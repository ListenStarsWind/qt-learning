# cmake/Qt/QtModules.cmake

set(QT_COMPONENTS)
set(QT_LIBRARIES)

macro(_qt_add_component name opt)
    if(${opt})
        list(APPEND QT_COMPONENTS ${name})
        list(APPEND QT_LIBRARIES Qt6::${name})
        message(STATUS "[Qt] 启用模块: ${name}")
    else()
        message(STATUS "[Qt] 关闭模块: ${name}")
    endif()
endmacro()

function(setup_qt_modules)
    if(DEFINED _QT_MODULES_ALREADY_SETUP)
        message(FATAL_ERROR "setup_qt_modules() 只能调用一次。")
    endif()
    set(_QT_MODULES_ALREADY_SETUP TRUE CACHE INTERNAL "Qt modules setup done")

    _qt_add_component(Core         USE_QT_CORE)
    _qt_add_component(Gui          USE_QT_GUI)
    _qt_add_component(Widgets      USE_QT_WIDGETS)
    _qt_add_component(Network      USE_QT_NETWORK)
    _qt_add_component(Sql          USE_QT_SQL)
    _qt_add_component(OpenGL       USE_QT_OPENGL)
    _qt_add_component(PrintSupport USE_QT_PRINTSUPPORT)
    _qt_add_component(Multimedia USE_QT_MULTIMEDIA)

    if(NOT QT_COMPONENTS)
        message(FATAL_ERROR "未启用任何 Qt 模块，请至少开启 USE_QT_CORE=ON。")
    endif()

    # 只允许 find_package，不允许 qt_* 方法
    find_package(Qt6 REQUIRED COMPONENTS ${QT_COMPONENTS})

    set(QT_COMPONENTS ${QT_COMPONENTS} PARENT_SCOPE)
    set(QT_LIBRARIES  ${QT_LIBRARIES}  PARENT_SCOPE)
endfunction()
