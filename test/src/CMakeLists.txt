aux_source_directory(. source_files)
add_executable(test_proj ${source_files})
target_link_libraries(test_proj mfcde2lib )
target_link_libraries(test_proj ${libname} )
