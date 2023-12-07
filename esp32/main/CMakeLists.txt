set(intelli_agriculture_main_dir "C:/workspace/project/cmake/intelli_agriculture/main")
set(nagisa_dir $ENV{NGS_ROOT}/include)

idf_component_register(
    SRCS "main.cpp"
    INCLUDE_DIRS ${intelli_agriculture_main_dir}/include ${nagisa_dir}
)

set_property(TARGET ${COMPONENT_LIB} PROPERTY CXX_STANDARD 20)
target_compile_definitions(${COMPONENT_LIB} PRIVATE _DEBUG)