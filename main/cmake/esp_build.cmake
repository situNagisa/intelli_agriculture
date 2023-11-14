function(import_intelli_agriculture ia_dir include_var source_var)
	set(options)
	set(single_value)
	set(multi_value)
	cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}" ${ARGN})

	set(build_as_component TRUE)
	include(${ia_dir}/CMakeLists.txt)

	set(${__include_var} ${ia_include_dir} PARENT_SCOPE)
	set(${__source_var} ${ia_source_dir} PARENT_SCOPE)
	#unset(ia_include_dir CACHE)
	#unset(ia_source_dir CACHE)
endfunction()