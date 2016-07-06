cmake_minimum_required(VERSION 3.5)
aux_source_directory(. source_files)
#aux_source_directory("D:/cppwork/myproj/library/src" slib)

#add_definitions(-D_AFXDLL)
set(CMAKE_CXX_FLAGS_RELEASE "/MT")
set(CMAKE_CXX_FLAGS_DEBUG "/MTd /Zi /Ob0 /Od /RTC1")
set(CMAKE_MFC_FLAG 1)
add_executable(monitor WIN32 ${source_files}  mfcde2.rc test.ini)
add_library(mfcde2lib ${source_files})
target_link_libraries(mfcde2lib ${source_files})

find_library(cc0 
  NAMES libmysql
  PATHS ${link_lib}
 )
target_link_libraries(monitor ${libname})

