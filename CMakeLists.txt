cmake_minimum_required(VERSION 3.4)
project(proj0)
include_directories(
 "D:\\soft\\boost_1_60_0"
 "C:\\Users\\hp\\Downloads\\mysql-5.6.24-win32.1432006610\\mysql-5.6.24-win32\\include"
 "C:\\Program Files (x86)\\Visual Leak Detector\\include"
)

link_directories(
	"library\\src\\Debug"
	"C:\\Users\\hp\\Downloads\\mysql-5.6.24-win32.1432006610\\mysql-5.6.24-win32\\lib"
	"D:\\soft\\boost_1_60_0\\bin.v2\\libs\\locale\\build\\msvc-12.0\\debug\\link-static\\threading-multi"
	"C:\\Program Files (x86)\\Visual Leak Detector\\lib\\Win32"
)

aux_source_directory(library dir_src2)
aux_source_directory(src_mfc monitor)
add_subdirectory(library/src)
add_subdirectory(monitor)

include_directories(./library/src)
set(CMAKE_CXX_FLAGS_RELEASE "/MT")
set(CMAKE_CXX_FLAGS_DEBUG "/MTd")
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
add_executable(test_proj ${dir_src2})
target_link_libraries(test_proj ${DSFDS})
target_link_libraries(test_proj ${b0})

