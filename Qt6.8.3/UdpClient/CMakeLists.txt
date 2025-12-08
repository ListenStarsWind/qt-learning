# ----------------------------------------------------------------------------------
# I. CMake 基础配置与环境检查
# ----------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.22)
project(QtWidgetsApp LANGUAGES CXX)

# 设置 C++ 标准和编译模式
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 默认构建类型设置为 Debug
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build: Debug or Release." FORCE)
endif()

# 检查编译器是否为 Clang
if (NOT CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    message(FATAL_ERROR "本项目基于 LLVM 环境，请确保使用 Clang 编译器。")
endif()

# ----------------------------------------------------------------------------------
# II. 路径定义与 Qt 自动化设置
# ----------------------------------------------------------------------------------
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_SKIP_AUTOMOC_RUN_IN_CMAKE TRUE)

# 源码/头文件/UI/资源目录
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(FORMS_DIR "${CMAKE_SOURCE_DIR}/forms")
set(RES_DIR "${CMAKE_SOURCE_DIR}/res")

# ----------------------------------------------------------------------------------
# III. Qt 模块化开关控制
# ----------------------------------------------------------------------------------
message(STATUS "--------------------------------------------------------")
message(STATUS "Qt 模块开关配置:")

option(USE_QT_CORE      "启用 Qt6::Core 模块"        ON)
option(USE_QT_GUI       "启用 Qt6::Gui 模块"         ON)
option(USE_QT_WIDGETS   "启用 Qt6::Widgets 模块"     ON)
option(USE_QT_NETWORK   "启用 Qt6::Network 模块"     ON)
option(USE_QT_SQL       "启用 Qt6::Sql 模块"         OFF)

set(QT_COMPONENTS_TO_FIND "")
set(QT_LIBRARIES_TO_LINK  "")

macro(add_qt_component name opt)
    if(${opt})
        list(APPEND QT_COMPONENTS_TO_FIND ${name})
        list(APPEND QT_LIBRARIES_TO_LINK Qt6::${name})
    endif()
    message(STATUS "  - ${name}: ${${opt}}")
endmacro()

add_qt_component(Core      USE_QT_CORE)
add_qt_component(Gui       USE_QT_GUI)
add_qt_component(Widgets   USE_QT_WIDGETS)
add_qt_component(Network   USE_QT_NETWORK)
add_qt_component(Sql       USE_QT_SQL)

message(STATUS "--------------------------------------------------------")

# ----------------------------------------------------------------------------------
# IV. 查找 Qt 组件
# ----------------------------------------------------------------------------------
if(QT_COMPONENTS_TO_FIND)
    find_package(Qt6 COMPONENTS ${QT_COMPONENTS_TO_FIND} REQUIRED)
else()
    message(FATAL_ERROR "未启用任何 Qt 组件，请检查配置。")
endif()

qt_standard_project_setup()

# ----------------------------------------------------------------------------------
# V. 源文件和资源处理
# ----------------------------------------------------------------------------------
# 收集 CPP/H 源文件
file(GLOB APP_SOURCES
    "${SOURCE_DIR}/*.cpp"
    "${INCLUDE_DIR}/*.h"
)

# 收集 UI 文件（绝对路径）
file(GLOB UI_FORMS "${FORMS_DIR}/*.ui")

# 注册 Qt 资源文件
qt_add_resources(RESOURCES_QRC_OUTPUT ${RES_DIR}/resources.qrc)
list(APPEND APP_SOURCES ${RESOURCES_QRC_OUTPUT})

# ----------------------------------------------------------------------------------
# VI. 创建目标和链接设置
# ----------------------------------------------------------------------------------
set(TARGET_NAME QtWidgetsApp)

qt_add_executable(${TARGET_NAME} 
    ${APP_SOURCES}
    ${UI_FORMS}  # UI 文件列表，必须是绝对路径
)

# 明确 AUTOUIC 搜索路径
set_property(TARGET ${TARGET_NAME} PROPERTY AUTOUIC_SEARCH_PATHS ${FORMS_DIR})

# 包含头文件目录
target_include_directories(${TARGET_NAME} PRIVATE
    ${INCLUDE_DIR}
)

# 链接 Qt 模块
target_link_libraries(${TARGET_NAME} PRIVATE 
    ${QT_LIBRARIES_TO_LINK}
)

# ----------------------------------------------------------------------------------
# VII. 链接器和编译选项（Windows + Clang/UCRT）
# ----------------------------------------------------------------------------------
if(WIN32)
    if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
        set_target_properties(${TARGET_NAME} PROPERTIES WIN32_EXECUTABLE FALSE)
        target_link_options(${TARGET_NAME} PRIVATE
            $<$<PLATFORM_ID:Windows>:-Wl,--subsystem,console>
        )
        message(STATUS "Debug 模式: 已启用 CONSOLE 子系统链接 (-Wl,--subsystem,console)")
    else()
        set_target_properties(${TARGET_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
        message(STATUS "Release 模式: 已启用 WIN32 子系统链接")
    endif()
endif()

# -------------------- 编译警告选项 --------------------
add_compile_options(
    -Wall -Wextra
    -Wno-unused-parameter
    -Wno-non-virtual-dtor
    -Wno-unused-variable
    -Wno-unused-private-field
)

# ----------------------------------------------------------------------------------
# VIII. 自定义构建目标 (清理)
# ----------------------------------------------------------------------------------
function(add_clean_targets target_name)
    if(CMAKE_GENERATOR STREQUAL "Ninja")
        add_custom_target(clean-${target_name}
            COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean
            COMMENT "Cleaning all intermediate files for ${target_name}..."
        )
    endif()
endfunction()

add_clean_targets(${TARGET_NAME})

# ----------------------------------------------------------------------------------
# IX. 编译信息总结
# ----------------------------------------------------------------------------------
message(STATUS "==========================================")
message(STATUS "🎯 QtWidgetsApp CMake Configuration Summary")
message(STATUS "编译器 ID: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "C++ 标准: C++${CMAKE_CXX_STANDARD}")
message(STATUS "构建类型: ${CMAKE_BUILD_TYPE}")
message(STATUS "Target: ${TARGET_NAME}")
message(STATUS "UI 文件目录: ${FORMS_DIR}")
message(STATUS "==========================================")
