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

set(mylist)

set(result 0)
list(LENGTH libname libname_length)
math(EXPR libname_length "${libname_length}-1")
foreach(_var RANGE 0 ${libname_length})
endforeach()

list(GET libname 0 temp)
set(a 1)
math(EXPR b "${a}+10")

function(test0 arg)
  return(1)
endfunction()

set(bb 2)
test0("a")

add_subdirectory(library/src)
add_subdirectory(monitor)
add_subdirectory(chat_server)
add_subdirectory(test/src)
add_subdirectory(example0)
add_subdirectory(example1)
add_subdirectory(example2)
add_subdirectory(example3)
add_subdirectory(example4)
add_subdirectory(example5)
add_subdirectory(example6)
add_subdirectory(example7)
add_subdirectory(example8)
add_subdirectory(example9)
add_subdirectory(example10)
add_subdirectory(example11)
add_subdirectory(example12)
#add_subdirectory(xunan_admin)
add_subdirectory(example14)
add_subdirectory(example15)
add_subdirectory(example16)
add_subdirectory(example17)
add_subdirectory(example18)
add_subdirectory(example19)
add_subdirectory(example20)
add_subdirectory(example21)
add_subdirectory(example22)
add_subdirectory(example23)
add_subdirectory(example24)
add_subdirectory(example25)
add_subdirectory(example26)
add_subdirectory(example27)
add_subdirectory(example28)
add_subdirectory(example29)
add_subdirectory(example30)
add_subdirectory(example31)
add_subdirectory(example32)
add_subdirectory(example33)
add_subdirectory(example34)
add_subdirectory(tetris)