cmake_minimum_required(VERSION 3.16)

# 如果没有在配置时指定 CMAKE_BUILD_TYPE，则默认设为 Release，方便用户在未传参时得到发布构建。
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build." FORCE)
endif()

# 项目名称
project(QtWidgetsApp VERSION 0.1 LANGUAGES CXX)

# 指定 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 启用自动处理 UI / MOC / 资源
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 指定 UI 文件搜索路径
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/forms)

# 确保生成 compile_commands.json 供 clangd 使用
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 添加推荐的警告级别和 Qt 特定警告抑制
add_compile_options(-Wall -Wextra -Wno-unused-parameter -Wno-non-virtual-dtor -Wno-unused-variable -Wno-unused-private-field)

# 本地 Qt SDK CMake 路径（Windows 和 Linux）
if(WIN32)
    set(CMAKE_PREFIX_PATH "D:/Qt/Qt6.5.3/6.5.3/mingw_64/lib/cmake;D:/Qt/Qt5.14.2/5.14.2/mingw73_64/lib/cmake")
else()
    set(CMAKE_PREFIX_PATH "/home/wind/Qt/6.5.3/6.5.3/gcc_64/lib/cmake")
endif()

# 查找 Qt6 和 Qt5
find_package(Qt6 COMPONENTS Core Gui Widgets QUIET)
if(NOT Qt6_FOUND)
    find_package(Qt5 5.15 COMPONENTS Core Gui Widgets REQUIRED)
endif()

# 源文件、头文件、UI 文件
set(SOURCES
    src/main.cpp
    src/widget.cpp
)
set(HEADERS
    include/widget.h
)
set(UI_FILES
    forms/widget.ui
)

# 添加QRC资源文件
qt_add_resources(SOURCES res/resources.qrc)

# 添加可执行文件（Qt6/Qt5 兼容）
if(Qt6_FOUND)
    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${SOURCES}
        ${HEADERS}
        ${UI_FILES}
    )
    target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
    qt_finalize_executable(${PROJECT_NAME})
else()
    qt5_wrap_ui(UI_HEADERS ${UI_FILES})
    add_executable(${PROJECT_NAME}
        ${SOURCES}
        ${HEADERS}
        ${UI_HEADERS}
    )
    target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)
endif()

# Windows 可执行文件属性
if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
endif()

# 安装规则
include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# 自定义目标：清理中间文件（保留 build 目录）
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E remove -f ${CMAKE_BINARY_DIR}/*.exe ${CMAKE_BINARY_DIR}/*.o ${CMAKE_BINARY_DIR}/moc_* ${CMAKE_BINARY_DIR}/ui_* ${CMAKE_BINARY_DIR}/CMakeCache.txt ${CMAKE_BINARY_DIR}/*.ninja ${CMAKE_BINARY_DIR}/compile_commands.json
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/CMakeFiles
    COMMENT "Cleaning build artifacts (executables, objects, moc, ui, cache)"
)

# 自定义目标：强制重新配置
add_custom_target(reconfigure
    COMMAND ${CMAKE_COMMAND} -E remove -f ${CMAKE_BINARY_DIR}/CMakeCache.txt
    COMMAND ${CMAKE_COMMAND} ${CMAKE_SOURCE_DIR}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Reconfiguring CMake project"
    DEPENDS ${SOURCES} ${HEADERS} ${UI_FILES}
)