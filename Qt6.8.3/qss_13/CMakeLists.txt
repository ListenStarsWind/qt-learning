# 本项目的核心原则：
# - 构建期：完全交给 CMake + MinGW-w64，不依赖 IDE 行为
# - 运行期：所有动态库依赖在构建完成后会全部拷贝到build下

cmake_minimum_required(VERSION 3.22)
project(QtMainWindowApp LANGUAGES CXX)
set(TARGET_NAME QtMainWindowApp)

# ---------------------------------------------------------------------
# 工具链引导脚本
#
# 这里只负责“引导环境”，而不是强行指定编译器：
# - 真正决定编译器的是 CC / CXX / PATH
# - CMake 在 project() 阶段就已经锁定编译器
# - 这个脚本的职责是：
#     1) 提供统一的工具链根路径
#     2) 暴露 Boost / Qt / MinGW 等路径变量给后续模块使用
# ---------------------------------------------------------------------
include("E:/test/toolchains/env/toolchain-paths.cmake")

# ---------------------------------------------------------------------
# C++ 基础配置
# ---------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 开启 clangd 语言服务
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 默认使用 debug 模式
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Debug or Release" FORCE)
endif()

# ---------------------------------------------------------------------
# 编译器约束：仅允许 GNU 工具链（MinGW-w64）
#
# 注意：
#   这里不是“选择”编译器，而是“校验”当前环境是否正确
#
# 编译器的选择早在 project() 之前就已经完成：
#   - 如果这里报错，说明环境变量或 PATH 配置本身就不符合预期
#   - 因为 boost 和 qt 都是用 GUN 本地编译的因此遇到此错误直接终止项目
# ---------------------------------------------------------------------

if(NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(FATAL_ERROR
        "本项目必须使用 GNU 编译器 (gcc/g++)，当前为: "
        "${CMAKE_CXX_COMPILER_ID}"
    )
endif()

# 额外兜底：禁止任何 MSVC ABI（包括 clang-cl）
if(MSVC)
    message(FATAL_ERROR
        "检测到 MSVC ABI(包括 clang-cl)，与 Qt-MinGW ABI 不兼容。"
    )
endif()

message(STATUS "使用编译器: ${CMAKE_CXX_COMPILER}")
message(STATUS "编译器类型: ${CMAKE_CXX_COMPILER_ID} (GNU)")

# ---------------------------------------------------------------------
# Qt 组件开关
# ---------------------------------------------------------------------
option(USE_QT_CORE      "启用 Qt6::Core"      ON)
option(USE_QT_GUI       "启用 Qt6::Gui"       ON)
option(USE_QT_WIDGETS   "启用 Qt6::Widgets"   ON)
option(USE_QT_NETWORK   "启用 Qt6::Network"   OFF)
option(USE_QT_SQL       "启用 Qt6::Sql"       OFF)
option(USE_QT_OPENGL    "启用 Qt6::OpenGL"    OFF)
option(USE_QT_PRINTSUPPORT "启用 Qt6::PrintSupport" OFF)

# ---------------------------------------------------------------------
# Boost 组件开关
# ---------------------------------------------------------------------
option(USE_BOOST_FILESYSTEM      "启用 Boost.Filesystem"      OFF)
option(USE_BOOST_THREAD          "启用 Boost.Thread"          OFF)
option(USE_BOOST_LOG             "启用 Boost.Log"             OFF)
option(USE_BOOST_LOG_SETUP       "启用 Boost.Log.Setup"       OFF)
option(USE_BOOST_PROGRAM_OPTIONS "启用 Boost.ProgramOptions"  OFF)
option(USE_BOOST_JSON            "启用 Boost.Json"            OFF)
option(USE_BOOST_REGEX           "启用 Boost.Regex"           OFF)
option(USE_BOOST_IOSTREAMS       "启用 Boost.Iostreams"       OFF)
option(USE_BOOST_SERIALIZATION   "启用 Boost.Serialization"   OFF)
option(USE_BOOST_ATOMIC          "启用 Boost.Atomic"          OFF)

# ---------------------------------------------------------------------
# 加载自定义模块, 依据功能开关内容查找对应的组件
# ---------------------------------------------------------------------
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(Qt/QtModules)
include(Boost/BoostModules)

setup_qt_modules()
setup_boost_modules()

# ---------------------------------------------------------------------
# 源文件
# ---------------------------------------------------------------------
set(SOURCE_DIR  "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(FORMS_DIR   "${CMAKE_SOURCE_DIR}/forms")
set(RES_DIR     "${CMAKE_SOURCE_DIR}/res")

set(APP_SOURCES
    "${CMAKE_SOURCE_DIR}/src/main.cpp"
    "${CMAKE_SOURCE_DIR}/src/mainwindow.cpp"
    "${CMAKE_SOURCE_DIR}/include/mainwindow.h"
)

# ---------------------------------------------------------------------
# AUTOGEN（使用 CMake 原生 AUTOmoc / AUTOuic / AUTOrcc）
#
# 这里刻意不使用 qt_add_executable / qt_add_resources 等 Qt 封装命令：
# - Qt 官方 CMake 宏在不同版本间存在行为差异
# - 对 MinGW + 非官方工具链组合不够稳定
#
# 使用 CMake 原生 AUTOGEN：
#   - 行为可预期
#   - 依赖关系清晰
#   - 出问题时更容易定位
# ---------------------------------------------------------------------
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(${TARGET_NAME}
    ${APP_SOURCES}
    "${RES_DIR}/resources.qrc"
)

set_target_properties(${TARGET_NAME} PROPERTIES
    LINKER_LANGUAGE CXX
)

# 扩展 froms 搜索路径
set_property(TARGET ${TARGET_NAME}
    PROPERTY AUTOUIC_SEARCH_PATHS "${FORMS_DIR}"
)

# 项目头文件, boost 头文件, Qt 依靠 cmake.config自动引入
target_include_directories(${TARGET_NAME} PRIVATE
    "${INCLUDE_DIR}"
    "${BOOST_INCLUDEDIR}"
)

target_compile_options(${TARGET_NAME} PRIVATE
    -Wall -Wextra -Wpedantic
    -Wno-unused-parameter
    -Wno-unused-variable
)

# ---------------------------------------------------------------------
# 强制使用 libstdc++ (以兼容qt, boost)
# ---------------------------------------------------------------------
if(WIN32 AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(${TARGET_NAME} PRIVATE
        -stdlib=libstdc++
    )
    target_link_options(${TARGET_NAME} PRIVATE
        -stdlib=libstdc++
    )
endif()

# ---------------------------------------------------------------------
# Windows 子系统 / 入口点策略说明
# ---------------------------------------------------------------------
if(WIN32)
    set_target_properties(${TARGET_NAME} PROPERTIES
        WIN32_EXECUTABLE $<$<CONFIG:Release>:TRUE>
    )

    target_link_options(${TARGET_NAME} PRIVATE
        $<$<CONFIG:Debug>:-Wl,--subsystem,console>
        $<$<CONFIG:Release>:-Wl,--subsystem,windows>
    )
endif()

# ---------------------------------------------------------------------
# 链接之前功能开关打开的模块
# ---------------------------------------------------------------------
target_link_libraries(${TARGET_NAME}
    PRIVATE
        ${QT_LIBRARIES}
        ${BOOST_LIBRARIES_TO_LINK}
        $<$<AND:$<PLATFORM_ID:Windows>,$<CONFIG:Release>>:Qt6::EntryPoint>
)

# ==========================================================
# 运行期依赖部署策略（Windows / MinGW）
# ==========================================================

function(deploy_runtime_deps target)
  if(NOT WIN32)
    return()
  endif()

  add_custom_command(TARGET ${target} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "== Deploy runtime deps (non-Qt) for: ${target} =="
    VERBATIM
  )

  foreach(boost_target IN LISTS BOOST_LIBRARIES_TO_LINK)
    get_target_property(_boost_type ${boost_target} TYPE)
    if(_boost_type STREQUAL "SHARED_LIBRARY")
      get_target_property(_boost_dll ${boost_target} IMPORTED_LOCATION)
      if(_boost_dll AND EXISTS "${_boost_dll}")
        add_custom_command(TARGET ${target} POST_BUILD
          COMMAND ${CMAKE_COMMAND} -E copy_if_different
                  "${_boost_dll}"
                  "$<TARGET_FILE_DIR:${target}>"
          VERBATIM
        )
      endif()
    endif()
  endforeach()
endfunction()

if(WIN32)
  find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${QT_ROOT}/bin" REQUIRED)

  add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
    COMMAND "${WINDEPLOYQT_EXECUTABLE}"
            --no-translations
            --no-system-d3d-compiler
            "$<TARGET_FILE:${TARGET_NAME}>"
    VERBATIM
  )

  deploy_runtime_deps(${TARGET_NAME})
endif()

# ---------------------------------------------------------------------
# 构建结果与运行期依赖摘要
# ---------------------------------------------------------------------
message(STATUS "============================================================")
message(STATUS "                ${TARGET_NAME} 构建与部署摘要")
message(STATUS "------------------------------------------------------------")
message(STATUS "[Build]")
message(STATUS "目标名称:        ${TARGET_NAME}")
message(STATUS "构建类型:        ${CMAKE_BUILD_TYPE}")
message(STATUS "生成器:          ${CMAKE_GENERATOR}")
message(STATUS "C++ 标准:        C++${CMAKE_CXX_STANDARD}")
message(STATUS "------------------------------------------------------------")
message(STATUS "[Compiler]")
message(STATUS "编译器路径:      ${CMAKE_CXX_COMPILER}")
message(STATUS "编译器 ID:       ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "------------------------------------------------------------")
message(STATUS "[Qt]")
message(STATUS "Qt 根目录:       ${QT_ROOT}")
message(STATUS "启用模块:        ${QT_COMPONENTS}")
message(STATUS "链接目标:        ${QT_LIBRARIES}")
message(STATUS "运行期部署:      windeployqt (按实际依赖动态解析)")
message(STATUS "------------------------------------------------------------")
if(BOOST_COMPONENTS_TO_FIND)
    message(STATUS "[Boost]")
    message(STATUS "Boost 根目录:    ${BOOST_ROOT}")
    message(STATUS "启用组件:        ${BOOST_COMPONENTS_TO_FIND}")
    message(STATUS "链接 targets:    ${BOOST_LIBRARIES_TO_LINK}")
else()
    message(STATUS "[Boost]")
    message(STATUS "状态:            未启用任何 Boost 组件")
endif()
message(STATUS "============================================================")
