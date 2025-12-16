# =====================================================================
# Boost 模块管理脚本
#
# 设计说明：
#   1. 不使用 find_package(Boost)
#   2. 每个 Boost 组件都建模为 IMPORTED target
#   3. 动态库模式下：
#        - IMPORTED_IMPLIB   用于链接
#        - IMPORTED_LOCATION 指向运行时 DLL
#
# 这样做的好处：
#   - CMake 能“知道”实际用到了哪些 Boost 模块
#   - 运行期 DLL 可被精确部署
#   - 避免运行时报缺库或 ABI 混乱
#
# 这是为 Windows + MinGW 专门设计的方案。
# =====================================================================

function(setup_boost_modules)
    set(BOOST_COMPONENTS_TO_FIND "")
    set(BOOST_LIBRARIES_TO_LINK "")

    set(BOOST_ROOT "$ENV{BOOST_ROOT}" CACHE PATH "" FORCE)
    set(Boost_INCLUDE_DIR "${BOOST_ROOT}/include")
    set(Boost_LIBRARY_DIR "${BOOST_ROOT}/lib")

    message(STATUS "  [Boost] include dir = ${Boost_INCLUDE_DIR}")
    message(STATUS "  [Boost] library dir = ${Boost_LIBRARY_DIR}")

    # --------------------------------------------------
    # 组件控制（不包含 system）
    # --------------------------------------------------
    macro(boost_add name opt)
        if(${opt})
            list(APPEND BOOST_COMPONENTS_TO_FIND ${name})
            message(STATUS "[Boost] 启用组件: ${name}")
        else()
            message(STATUS "[Boost] 关闭组件: ${name}")
        endif()
    endmacro()

    boost_add(filesystem      USE_BOOST_FILESYSTEM)
    boost_add(thread          USE_BOOST_THREAD)
    boost_add(log             USE_BOOST_LOG)
    boost_add(log_setup       USE_BOOST_LOG_SETUP)
    boost_add(program_options USE_BOOST_PROGRAM_OPTIONS)
    boost_add(json            USE_BOOST_JSON)
    boost_add(regex           USE_BOOST_REGEX)
    boost_add(iostreams       USE_BOOST_IOSTREAMS)
    boost_add(serialization   USE_BOOST_SERIALIZATION)
    boost_add(atomic          USE_BOOST_ATOMIC)

    # --------------------------------------------------
    # 查找库：动态优先，静态兜底
    # --------------------------------------------------
foreach(comp ${BOOST_COMPONENTS_TO_FIND})
    set(dll_implib
        "${Boost_LIBRARY_DIR}/libboost_${comp}-mgw-mt-x64-1_90.dll.a"
    )
    set(dll_runtime
        "${Boost_LIBRARY_DIR}/libboost_${comp}-mgw-mt-x64-1_90.dll"
    )
    set(static_lib
        "${Boost_LIBRARY_DIR}/libboost_${comp}-mgw-mt-x64-1_90.a"
    )

    set(target "Boost::${comp}")

    if(EXISTS "${dll_implib}")
        add_library(${target} SHARED IMPORTED)
        set_target_properties(${target} PROPERTIES
            IMPORTED_IMPLIB   "${dll_implib}"
            IMPORTED_LOCATION "${dll_runtime}"
            INTERFACE_INCLUDE_DIRECTORIES "${Boost_INCLUDE_DIR}"
        )

    elseif(EXISTS "${static_lib}")
        add_library(${target} STATIC IMPORTED)
        set_target_properties(${target} PROPERTIES
            IMPORTED_LOCATION "${static_lib}"
            INTERFACE_INCLUDE_DIRECTORIES "${Boost_INCLUDE_DIR}"
        )

    else()
        message(FATAL_ERROR
            "Boost 组件 ${comp} 未找到（既无 dll.a 也无 a)")
    endif()

    list(APPEND BOOST_LIBRARIES_TO_LINK ${target})
endforeach()

    set(BOOST_COMPONENTS_TO_FIND "${BOOST_COMPONENTS_TO_FIND}" PARENT_SCOPE)
    set(BOOST_LIBRARIES_TO_LINK "${BOOST_LIBRARIES_TO_LINK}" PARENT_SCOPE)
endfunction()
