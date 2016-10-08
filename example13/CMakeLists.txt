aux_source_directory(. source_files)
add_executable(example13 WIN32 ${source_files} example13.rc)
target_link_libraries(example13 ${libname})