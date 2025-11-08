cmake_minimum_required(VERSION 3.16)

# 如果没有在配置时指定 CMAKE_BUILD_TYPE，则默认设为 Release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build." FORCE)
endif()

project(QtWidgetsApp VERSION 0.1 LANGUAGES CXX)

# ================== 基础设置 ==================
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 启用 Qt 自动处理
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/forms)

# ================== 源码与头文件路径 ==================
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(FORMS_DIR   ${CMAKE_CURRENT_SOURCE_DIR}/forms)

file(GLOB SOURCES CONFIGURE_DEPENDS "${SOURCE_DIR}/*.cpp")
file(GLOB HEADERS CONFIGURE_DEPENDS "${INCLUDE_DIR}/*.h" "${INCLUDE_DIR}/*.hpp")
file(GLOB UI_FILES CONFIGURE_DEPENDS "${FORMS_DIR}/*.ui")

# ================== Qt 路径与查找 ==================
if(WIN32)
    set(CMAKE_PREFIX_PATH 
        "D:/Qt/Qt6.5.3/6.5.3/mingw_64/lib/cmake"
        "D:/Qt/Qt5.14.2/5.14.2/mingw73_64/lib/cmake"
    )
else()
    set(CMAKE_PREFIX_PATH "/home/wind/Qt/6.5.3/6.5.3/gcc_64/lib/cmake")
endif()

find_package(Qt6 COMPONENTS Core Gui Widgets QUIET)
if(NOT Qt6_FOUND)
    find_package(Qt5 5.15 COMPONENTS Core Gui Widgets REQUIRED)
endif()

# ================== 资源文件 ==================
qt_add_resources(SOURCES res/resources.qrc)

# ================== 可执行文件 ==================
if(Qt6_FOUND)
    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${SOURCES}
        ${HEADERS}
        ${UI_FILES}
    )
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
    qt_finalize_executable(${PROJECT_NAME})
else()
    qt5_wrap_ui(UI_HEADERS ${UI_FILES})
    add_executable(${PROJECT_NAME}
        ${SOURCES}
        ${HEADERS}
        ${UI_HEADERS}
    )
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)
endif()

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})

# Windows GUI 程序
if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
endif()

# ================== 编译选项 ==================
add_compile_options(
    -Wall -Wextra
    -Wno-unused-parameter
    -Wno-non-virtual-dtor
    -Wno-unused-variable
    -Wno-unused-private-field
)

# ================== 安装规则 ==================
include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# ================== 自定义目标 ==================
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E remove -f 
        ${CMAKE_BINARY_DIR}/*.exe
        ${CMAKE_BINARY_DIR}/*.o
        ${CMAKE_BINARY_DIR}/moc_*
        ${CMAKE_BINARY_DIR}/ui_*
        ${CMAKE_BINARY_DIR}/qrc_*
        ${CMAKE_BINARY_DIR}/compile_commands.json
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/CMakeFiles
    COMMAND ${CMAKE_COMMAND} -E remove -f ${CMAKE_BINARY_DIR}/CMakeCache.txt
    COMMENT "Cleaning build artifacts (executables, objects, moc, ui, cache)"
)

add_custom_target(reconfigure
    COMMAND ${CMAKE_COMMAND} -E remove -f ${CMAKE_BINARY_DIR}/CMakeCache.txt
    COMMAND ${CMAKE_COMMAND} ${CMAKE_SOURCE_DIR}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Reconfiguring CMake project"
    DEPENDS ${SOURCES} ${HEADERS} ${UI_FILES}
)

# ================== 打印信息 ==================
message(STATUS "============================================ 编译信息 ============================================")
message(STATUS "源码目录: ${SOURCE_DIR}")
message(STATUS "头文件目录: ${INCLUDE_DIR}")
message(STATUS "UI 文件目录: ${FORMS_DIR}")
message(STATUS "编译器: ${CMAKE_CXX_COMPILER}")
message(STATUS "C++ 标准: C++${CMAKE_CXX_STANDARD}")
message(STATUS "构建类型: ${CMAKE_BUILD_TYPE}")
message(STATUS "生成 compile_commands.json: ${CMAKE_EXPORT_COMPILE_COMMANDS}")
message(STATUS "Qt 版本: ${Qt${Qt_VERSION_MAJOR}_VERSION}")
message(STATUS "自动 MOC/UIC/RCC: 已启用")
message(STATUS "资源文件: res/resources.qrc 已添加")
message(STATUS "Windows GUI 模式: 已启用")
message(STATUS "==============================================================================================")
