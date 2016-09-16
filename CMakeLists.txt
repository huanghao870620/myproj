cmake_minimum_required(VERSION 3.4)
project(proj0)

aux_source_directory("library/src"  bbcd)

file(STRINGS path_company.txt variables)
#file(STRINGS path_home.txt variables)
#list(GET bb0 [0 2] c0)
list(GET variables 0 boost_home)
list(GET variables 1 mysql_sdk_home)
list(GET variables 2 vld_home)



include_directories(
 "${boost_home}"
 "${mysql_sdk_home}/include"
 "${vld_home}/include"
)

#file(READ 1.txt aa0 2 1 2)
#file(STRINGS 1.txt bb0)
#list(GET bb0 [0 2] c0)
#http://www.cnblogs.com/coderfenghc/archive/2012/07/08/2581734.html

set(
	link_lib
	"${mysql_sdk_home}/lib"
	"library/src/Debug"
	"monitor/src/Debug"
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
./library/src
./chat_server
./monitor/src
)
set(CMAKE_CXX_FLAGS_RELEASE "/MT")
set(CMAKE_CXX_FLAGS_DEBUG "/MTd /Zi /Ob0 /Od /RTC1")
set(
 libname
 libmysql
 #mfcde2lib
 my_library
 chat_serverlib
 ws2_32
 libboost_locale-vc120-mt-sgd-1_60 
 libboost_unit_test_framework-vc120-mt-s-1_60
 nafxcwd
 libcmtd
)



set(mylist)
#find_library(
# lib 
# NAMES ${libname}
# HINTS ${link_lib}
#)
#foreach(_var ${libname})
#  find_library(
#   lib
#   NAMES ${_var}
#   HINTS ${link_lib}
#  )
#  list(APPEND mylist ${lib})
#endforeach()

set(result 0)
list(LENGTH libname libname_length)
math(EXPR libname_length "${libname_length}-1")
foreach(_var RANGE 0 ${libname_length})
  #message(${_var})
endforeach()

list(GET libname 0 temp)
set(a 1)
math(EXPR b "${a}+10")

#set(
#mylist
#a
#b
#c
#d
#)


function(test0 arg)
  return(1)
endfunction()

set(bb 2)
 test0("a")



#foreach(_var ${mylist})
# message("当前变量是: " ${_var})
#endforeach()

#set(result 0)	
#foreach(_var RANGE 0 100)
#    message(${_var})
#	math(EXPR result "${result}+${_var}")
#endforeach()
#message("from 0 plus to 100 is:${result}")

#list(LENGTH mylist ab)
#message(==${ab}==)

#list(APPEND mylist e)
#message(==${mylist}==)

# find_library(b0
#  NAMES my_library
#  PATHS ${fdsg32s}
# )
 
#message("${dir_src2}")
#add_executable(test_proj ${dir_src2})
#target_link_libraries(test_proj ${dddd})
#target_link_libraries(test_proj ${b0})


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