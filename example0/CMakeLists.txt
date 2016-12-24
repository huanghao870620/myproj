cmake_minimum_required(VERSION 3.5)

cmake_minimum_required(VERSION 3.4)
project(proj0)

aux_source_directory("library/src"  bbcd)

file(STRINGS path_company.txt variables)
list(GET variables 0 boost_home)
list(GET variables 1 mysql_sdk_home)
list(GET variables 2 vld_home)
list(GET variables 3 libodb)
list(GET variables 4 libodb_mysql)

include_directories(
 "${boost_home}"
 "${mysql_sdk_home}/include"
 "${vld_home}/include"
)

set(
	link_lib
	"${mysql_sdk_home}/lib"
#	"library/src/Debug"
#	"monitor/src/Debug"
	"${boost_home}/lib"
	"${boost_home}/stage/lib"
	"${boost_home}/lib/vc12_x64/lib"
	"${vld_home}/lib"
)

link_directories(
	${link_lib}
)

aux_source_directory(library dir_src2)
aux_source_directory(src_mfc monitor)

include_directories(
#./library/src
#./chat_server
#./monitor/src
)


set(
 libname
 libmysql
# my_library
# chat_serverlib
 ws2_32
 nafxcwd
 libcmtd
)


aux_source_directory(. source_files)
set(CMAKE_CXX_FLAGS_RELEASE "/MT")
set(CMAKE_CXX_FLAGS_DEBUG "/MTd /Zi /Ob0 /Od /RTC1")
set(CMAKE_MFC_FLAG 1)
add_executable(example0 WIN32 ${source_files} example0.rc)
target_link_libraries(example0 ${libname})