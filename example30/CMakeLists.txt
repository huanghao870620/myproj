aux_source_directory(. source)
add_executable(example30 WIN32 ${source})
target_link_libraries(example30 ${libname})