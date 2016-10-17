aux_source_directory(. source)
add_executable(example31 WIN32 ${source})
target_link_libraries(example31 ${libname})