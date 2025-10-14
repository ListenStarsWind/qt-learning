cmake_minimum_required(VERSION 3.16)

# 项目名称
project(QtWidgetsApp VERSION 0.1 LANGUAGES CXX)

# 启用自动处理 UI / MOC / 资源
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# 指定 UI 文件搜索路径
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/forms)

# 指定 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 本地 Qt SDK CMake 路径
set(CMAKE_PREFIX_PATH "D:/Qt/Qt6.5.3/6.5.3/mingw_64/lib/cmake;D:/Qt/Qt5.14.2/5.14.2/mingw73_64/lib/cmake")

# 查找 Qt6 和 Qt5
find_package(Qt6 COMPONENTS Core Gui Widgets OPTIONAL_COMPONENTS)
find_package(Qt5 COMPONENTS Core Gui Widgets OPTIONAL_COMPONENTS)

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

# 添加可执行文件（Qt6/Qt5 兼容）
if(Qt6_FOUND)
    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${SOURCES}
        ${HEADERS}
        ${UI_FILES}   # 自动处理 UI
    )
    target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
    qt_finalize_executable(${PROJECT_NAME})
elseif(Qt5_FOUND)
    qt5_wrap_ui(UI_HEADERS ${UI_FILES})
    add_executable(${PROJECT_NAME}
        ${SOURCES}
        ${HEADERS}
        ${UI_HEADERS}
    )
    target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)
else()
    message(FATAL_ERROR "Neither Qt6 nor Qt5 found!")
endif()

# Windows 可执行文件属性
set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)

# 安装规则
include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
