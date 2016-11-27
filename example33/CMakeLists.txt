cmake_minimum_required(VERSION 3.6)
include_directories(
 "C:\\Program Files (x86)\\Java\\jdk1.8.0_101\\include"
  "C:\\Program Files (x86)\\Java\\jdk1.8.0_101\\include\\win32"
 )
aux_source_directory(. source_file)
add_library(goodluck SHARED ${source_file})

