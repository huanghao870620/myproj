aux_source_directory(. source_files)
add_executable(tetris WIN32 ${source_files} tetris.rc )
target_link_libraries(tetris ${libname})