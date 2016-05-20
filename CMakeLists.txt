cmake_minimum_required(VERSION 3.4)
project(proj0)

aux_source_directory("library/src"  bbcd)


file(STRINGS path_company.txt variables)
#list(GET bb0 [0 2] c0)
list(GET variables 0 boost_home)
list(GET variables 1 mysql_sdk_home)
list(GET variables 2 vld_home)

include_directories(
 ${boost_home}
 "${mysql_sdk_home}/include"
 "${vld_home}/include"
)

#file(READ 1.txt aa0 2 1 2)
#file(STRINGS 1.txt bb0)
#list(GET bb0 [0 2] c0)
#http://www.cnblogs.com/coderfenghc/archive/2012/07/08/2581734.html

#set(
#fdsg32s
#"library\\src\\Debug"
#	"C:\\Users\\hp\\Downloads\\mysql-5.6.24-win32.1432006610\\mysql-5.6.24-win32\\lib"
#	"D:\\soft\\boost_1_60_0\\bin.v2\\libs\\locale\\build\\msvc-12.0\\debug\\link-static\\threading-multi"
#	"C:\\Program Files (x86)\\Visual Leak Detector\\lib\\Win32"
#)

set(
fdsg32s
"library\\src\\Debug"
"C:\\Program Files\\MySQL\\Connector C 6.0.2\\lib\\debug"
	"D:\\soft\\boost_1_60_0\\bin.v2\\libs\\locale\\build\\msvc-12.0\\debug\\link-static\\threading-multi"
	"C:\\Program Files (x86)\\Visual Leak Detector\\lib\\Win32"
)


link_directories(
	${fdsg32s}
)

aux_source_directory(library dir_src2)
aux_source_directory(src_mfc monitor)
add_subdirectory(library/src)
add_subdirectory(monitor)

include_directories(./library/src)
set(CMAKE_CXX_FLAGS_RELEASE "/MT")
set(CMAKE_CXX_FLAGS_DEBUG "/MTd /Zi /Ob0 /Od /RTC1")
set(
 libname
 libmysql 
)


#add_library(library ${dir_src2})
#find_library(DSFDS 
# NAMES ${libname}
# HINTS ${fdsg32s}
# )
 
# find_library(b0
#  NAMES my_library
#  PATHS ${fdsg32s}
# )
 
#message("${dir_src2}")
#add_executable(test_proj ${dir_src2})
#target_link_libraries(test_proj ${DSFDS})
#target_link_libraries(test_proj ${b0})

