set(intelli_agriculture_main_dir "../../main")
set(nagisa_dir $ENV{NAGISA_DIR}include)
set(extern_dir $ENV{NAGISA_ROOT}include)

idf_component_register(
    SRCS "main.cpp"
    INCLUDE_DIRS ${intelli_agriculture_main_dir}/include ${nagisa_dir} ${extern_dir}
)

set_property(TARGET ${COMPONENT_LIB} PROPERTY CXX_STANDARD 20)
target_compile_definitions(${COMPONENT_LIB} PRIVATE _DEBUG)