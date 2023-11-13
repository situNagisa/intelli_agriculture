
set(main_src "")
file(GLOB_RECURSE main_src ${main_src} ${PROJECT_SOURCE_DIR}/include/*.h)
file(GLOB main_src ${main_src} *.cpp *.c *.h *.hpp)

set(target_system "windows" CACHE STRING "Choose an system: windows, esp32(freeRTOS)")
set_property(CACHE target_system PROPERTY STRINGS "windows" "esp32")
message(STATUS "target system: ${target_system}")

if(target_system STREQUAL "windows")
    add_subdirectory(windows)
elseif(target_system STREQUAL "esp32")
    add_subdirectory(esp32)
else()
    message(FATAL_ERROR "Invalid target system selected: ${target_system}")
endif()

add_executable (main ${main_src})

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