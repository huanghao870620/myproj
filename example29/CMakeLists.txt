aux_source_directory(. source)
add_executable(example29 WIN32 ${source})
target_link_libraries(example29 ${libname})