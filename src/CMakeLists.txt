# CMakeList.txt: goods_0 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#

# 将源代码添加到此项目的可执行文件。

file(GLOB_RECURSE __include ${PROJECT_SOURCE_DIR}/include/*.h)
aux_source_directory(. __src)

add_executable (main ${__src} ${__include})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET main PROPERTY CXX_STANDARD 20)
endif()

set(nagisa_include $ENV{NAGISA_DIR}/include CACHE PATH "")
set(extern_include $ENV{NAGISA_ROOT}/include CACHE PATH "")

target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(main PUBLIC ${nagisa_include} ${extern_include})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	target_compile_definitions(main PRIVATE _DEBUG)
endif()


# TODO: 如有需要，请添加测试并安装目标。
