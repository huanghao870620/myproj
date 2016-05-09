#cmake_minimum_required(VERSION 3.4)

#aux_source_directory(. source_files)

include_directories(
 "C:\\Program Files (x86)\\Microsoft Visual Studio 12.0\\VC\\atlmfc\\include"
 "D:\\soft\\boost_1_60_0"
)

add_subdirectory(src)

#add_library(mfcd ${source_files})