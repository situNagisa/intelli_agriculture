set(intelli_agriculture_main_dir "../../main")
set(nagisa_dir $ENV{NAGISA_DIR}include)
set(extern_dir $ENV{NAGISA_ROOT}include)

idf_component_register(
    SRCS "main.cpp"
    INCLUDE_DIRS ${intelli_agriculture_main_dir}/include ${nagisa_dir} ${extern_dir}
)

