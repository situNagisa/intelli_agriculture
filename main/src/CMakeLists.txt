﻿
option(build_as_component "for esp idf build" FALSE)

set(main_src)
file(GLOB_RECURSE main_src ${main_src} ${PROJECT_SOURCE_DIR}/include/*.h)

set(nagisa_include $ENV{NGS_ROOT}/include CACHE PATH "")

set(ia_include_dir ${nagisa_include} ${PROJECT_SOURCE_DIR}/include)
set(ia_source ${main_src})

if(NOT build_as_component)
    set(ia_target main)
    add_executable (${ia_target} ${ia_source} "main.cpp")
else()
    set(ia_target ia_lib)
    add_library (${ia_target} ${ia_source})
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET ${ia_target} PROPERTY CXX_STANDARD 20)
endif()

target_include_directories(${ia_target} PUBLIC ${ia_include_dir})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	target_compile_definitions(${ia_target} PRIVATE _DEBUG)
endif()