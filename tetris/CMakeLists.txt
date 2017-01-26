cmake_minimum_required(VERSION 3.7)
aux_source_directory(. source_files)


set(CMAKE_CXX_FLAGS_RELEASE "/MT")
set(CMAKE_CXX_FLAGS_DEBUG "/MTd /Zi /Ob0 /Od /RTC1")

add_executable(tetris WIN32 ${source_files} tetris.rc )
target_link_libraries(tetris ${libname})