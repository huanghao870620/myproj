aux_source_directory(. source_files)
add_executable(example12 ${source_files})
target_link_libraries(example12 example11lib)