cmake_minimum_required(VERSION 3.5)
aux_source_directory(. source_files)
add_executable(example0 WIN32 ${source_files} example0.rc)