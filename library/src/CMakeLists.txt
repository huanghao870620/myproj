message("bbbbbbbbbbbbbbbbbbbbbbbbbb")

#set(
# source_files
# Crawler.cpp
# ConnMysql.cpp
#)

aux_source_directory(. source_files)

#include_directories(
#"D:\\soft\\boost_1_60_0"
# .
# C:\\Users\\hp\\Downloads\\mysql-5.6.24-win32.1432006610\\mysql-5.6.24-win32\\include
#)

#aux_source_directory(src2 dir_src2)
#add_executable(abc ${source_files})
#add_definitions(-D_AFXDLL)
set(CMAKE_CXX_FLAGS_RELEASE "/MT")
set(CMAKE_CXX_FLAGS_DEBUG "/MTd /Zi /Ob0 /Od /RTC1")
set(CMAKE_MFC_FLAG 1)
add_library(my_library ${source_files})
#target_link_libraries(abc fsdfd)