cmake_minimum_required(VERSION 3.5)
aux_source_directory(. source_files)
set(CMAKE_CXX_FLAGS_RELEASE "/MT")
set(CMAKE_CXX_FLAGS_DEBUG "/MTd /Zi /Ob0 /Od /RTC1")
set(CMAKE_MFC_FLAG 1)

#target_link_libraries(my_library ${b0})
add_library(my_library ${source_files})
#target_link_libraries(my_library ${abc})
