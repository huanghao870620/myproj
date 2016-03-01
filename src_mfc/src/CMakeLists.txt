#cmake_minimum_required(VERSION 3.4)
message("---mfc---src---")

aux_source_directory(. source_files)

include_directories(
 .
 "C:\\Users\\hp\\Downloads\\mysql-5.6.24-win32.1432006610\\mysql-5.6.24-win32\\include"
 "C:\\Program Files (x86)\\Visual Leak Detector\\include"
 "D:\\gitup\\myproj\\src2\\a0"
)


set(
	fdsg32s
	"D:\\gitup\\myproj\\src2\\a0\\Debug"
#"D:\\gitup\\myproj\\src2\\a0\\Release"
	"C:\\Users\\hp\\Downloads\\mysql-5.6.24-win32.1432006610\\mysql-5.6.24-win32\\lib"
	"C:\\Program Files (x86)\\Microsoft Visual Studio 12.0\\VC\\atlmfc\\lib"
	"C:\\Program Files (x86)\\Visual Leak Detector\\lib\\Win32"
)

set(
 libname
 libmysql 
)
find_library(DSFDS 
 NAMES ${libname}
 HINTS ${fdsg32s}
 )
 find_library(b0
  NAMES my_library
  PATHS ${fdsg32s}
 )

#add_definitions(-D_AFXDLL)
set(CMAKE_CXX_FLAGS_RELEASE "/MT")
set(CMAKE_CXX_FLAGS_DEBUG "/MTd /Zi /Ob0 /Od /RTC1")
set(CMAKE_MFC_FLAG 1)
add_executable(monitor WIN32 ${source_files}  mfcde2.rc)
add_library(mfcde2lib ${source_files})
target_link_libraries(monitor ${DSFDS})
target_link_libraries(monitor ${b0})

