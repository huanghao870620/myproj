aux_source_directory(. source_file)
add_executable(example18 WIN32 ${source_file})
target_link_libraries(example18 ${libname})