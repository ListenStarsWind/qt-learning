# 本项目的核心原则：
# - 构建期：完全交给 CMake + MinGW-w64，不依赖 IDE 行为
# - 运行期：所有动态库依赖在构建完成后会全部拷贝到build下

cmake_minimum_required(VERSION 3.22)
project(QtWidgetsApp LANGUAGES CXX)
set(TARGET_NAME QtWidgetsApp)
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
set(STYLE_DIR "${CMAKE_SOURCE_DIR}/style")

set(APP_SOURCES
    "${CMAKE_SOURCE_DIR}/src/main.cpp"
    "${CMAKE_SOURCE_DIR}/src/widget.cpp"
    "${CMAKE_SOURCE_DIR}/include/widget.h"
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
# 设计原则：
#   - Debug  模式：console 子系统
#       - 入口：main
#       - 允许 stdout / stderr / qDebug 输出
#       - 终端应当被阻塞，直到窗口关闭
#
#   - Release 模式：windows 子系统
#       - 入口：WinMain（由 Qt6::EntryPoint 提供）
#       - 不依赖控制台存在
#       - 双击 / 终端行为一致
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
#
# 这一步不是“方便”，而是必须：
#
# - cmake 确实会在可执行文件上打上依赖库路径, 但前提是 linux 的可执行文件格式
# - Windows 的 cmake 不会把依赖库路径写到 exe 上, 只会在工作路径, 系统环境变量中寻找
#
# 本项目的明确分工：
#   1) Qt 相关：
#        - 完全交给 windeployqt
#        - 包括 Qt DLL / plugins / platforms 等
#
#   2) 非 Qt 相关（Boost / libstdc++ / libgcc 等）：
#        - 只拷贝“实际被链接使用”的 DLL
#        - 来源必须可追溯（IMPORTED target）
#
# 目标只有一个：
#   build 目录自带依赖库, 从而解决动态库依赖问题
# ==========================================================

# 统一的运行期依赖部署函数
#
# 设计前提：
#   - setup_boost_modules() 已经准确区分：
#       * Boost::xxx 是动态库还是静态库
#       * 动态库已设置 IMPORTED_LOCATION
#
#   1) 枚举实际参与链接的 Boost targets
#   2) 只处理 SHARED_LIBRARY
#   3) 精确拷贝其 DLL 到 exe 同目录
function(deploy_runtime_deps target)
  if(NOT WIN32)
    return()
  endif()

  add_custom_command(TARGET ${target} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "== Deploy runtime deps (non-Qt) for: ${target} =="
    VERBATIM
  )

  # --------------------------------------------------
  # 从 Boost IMPORTED targets 中拷贝 DLL
  # --------------------------------------------------
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
  # 1) Qt 官方部署（插件 / Qt DLL）
  find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${QT_ROOT}/bin" REQUIRED)

  add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
    COMMAND "${WINDEPLOYQT_EXECUTABLE}"
            --no-translations
            --no-system-d3d-compiler
            "$<TARGET_FILE:${TARGET_NAME}>"
    VERBATIM
  )

  # 2) 统一运行期依赖部署（Boost / libstdc++ / libgcc / 其它 DLL）
  deploy_runtime_deps(${TARGET_NAME})
endif()

# ---------------------------------------------------------------------
# 运行期样式文件部署（QSS）
#
# 设计原则：
#   - QSS 作为运行期配置，不进入 qrc
#   - 与 exe 保持稳定相对路径
# ---------------------------------------------------------------------
if(WIN32)
  add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${STYLE_DIR}"
            "$<TARGET_FILE_DIR:${TARGET_NAME}>/style"
    VERBATIM
  )
endif()

# ---------------------------------------------------------------------
# 构建结果与运行期依赖摘要
#
# 设计目标：
#   - 不依赖模块脚本中的 message 输出
#   - 所有关键信息在此处一次性汇总
#   - 方便日志留存、问题回溯、环境复现
# ---------------------------------------------------------------------
message(STATUS "============================================================")
message(STATUS "                QtWidgetsApp 构建与部署摘要")
message(STATUS "------------------------------------------------------------")

# --------------------------------------------------
# 基本构建信息
# --------------------------------------------------
message(STATUS "[Build]")
message(STATUS "目标名称:        ${TARGET_NAME}")
message(STATUS "构建类型:        ${CMAKE_BUILD_TYPE}")
message(STATUS "生成器:          ${CMAKE_GENERATOR}")
message(STATUS "C++ 标准:        C++${CMAKE_CXX_STANDARD}")

# --------------------------------------------------
# 编译器信息（这是 ABI 的根）
# --------------------------------------------------
message(STATUS "------------------------------------------------------------")
message(STATUS "[Compiler]")
message(STATUS "编译器路径:      ${CMAKE_CXX_COMPILER}")
message(STATUS "编译器 ID:       ${CMAKE_CXX_COMPILER_ID}")

# --------------------------------------------------
# Qt 配置与运行期依赖（来自 windeployqt 的解析结果）
# --------------------------------------------------
message(STATUS "------------------------------------------------------------")
message(STATUS "[Qt]")
message(STATUS "Qt 根目录:       ${QT_ROOT}")
message(STATUS "启用模块:        ${QT_COMPONENTS}")
message(STATUS "链接目标:        ${QT_LIBRARIES}")
message(STATUS "运行期部署:      windeployqt (按实际依赖动态解析)")

# --------------------------------------------------
# Boost（仅在启用组件时输出）
# --------------------------------------------------
if(BOOST_COMPONENTS_TO_FIND)
    message(STATUS "------------------------------------------------------------")
    message(STATUS "[Boost]")
    message(STATUS "Boost 根目录:    ${BOOST_ROOT}")
    message(STATUS "启用组件:        ${BOOST_COMPONENTS_TO_FIND}")
    message(STATUS "链接 targets:    ${BOOST_LIBRARIES_TO_LINK}")
else()
    message(STATUS "------------------------------------------------------------")
    message(STATUS "[Boost]")
    message(STATUS "状态:            未启用任何 Boost 组件")
endif()

# --------------------------------------------------
# 非 Qt 运行期库（由 deploy_runtime_deps 精确拷贝）
# --------------------------------------------------
message(STATUS "------------------------------------------------------------")
message(STATUS "[Runtime Libraries]")
message(STATUS "libstdc++:        libstdc++-6.dll")
message(STATUS "libgcc:           libgcc_s_seh-1.dll")
message(STATUS "pthread:          libwinpthread-1.dll")

# --------------------------------------------------
# 运行期策略说明（结论性描述）
# --------------------------------------------------
message(STATUS "------------------------------------------------------------")
message(STATUS "[Runtime Strategy]")
message(STATUS "Qt 运行期:       windeployqt 自动解析并部署")
message(STATUS "非 Qt 运行期:    基于 IMPORTED target / 依赖扫描精确拷贝")
message(STATUS "运行目录:        exe 目录即完整运行环境")
message(STATUS "PATH 依赖:       不依赖外部 PATH, 可直接双击运行")

message(STATUS "============================================================")
