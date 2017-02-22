cmake_minimum_required(VERSION 3.7)
aux_source_directory(. source_files)



file(STRINGS path_company.txt variables)
list(GET variables 0 boost_home)
list(GET variables 1 mysql_sdk_home)
list(GET variables 2 vld_home)
list(GET variables 3 libodb)
list(GET variables 4 libodb_mysql)
list(GET variables 5 cximage_home)
list(GET variables 6 wpdpack_home)

include_directories(
 #"${boost_home}"
 #"${mysql_sdk_home}/include"
 #"${vld_home}/include"
 #"${cximage_home}"
 "${wpdpack_home}/Include"
)

set(
	link_lib
#	"${mysql_sdk_home}/lib"
#	"${boost_home}/lib"
#	"${boost_home}/stage/lib"
#	"${boost_home}/lib/vc12_x64/lib"
#	"${vld_home}/lib"
#	"${libodb}/lib"
#	"${libodb_mysql}/lib"
	"${wpdpack_home}/Lib"
)

link_directories(
	${link_lib}
)


set(
 libname
wpcap
)


set(CMAKE_CXX_FLAGS_RELEASE "/MT")
set(CMAKE_CXX_FLAGS_DEBUG "/MTd /Zi /Ob0 /Od /RTC1")

add_executable(tetris WIN32 ${source_files} tetris.rc )
target_link_libraries(tetris ${libname})