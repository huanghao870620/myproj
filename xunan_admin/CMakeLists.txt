cmake_minimum_required(VERSION 3.7)

project(xunan_admin)
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
	"${boost_home}/lib"
	"${boost_home}/stage/lib"
	"${boost_home}/lib/vc12_x64/lib"
	"${vld_home}/lib"
	"${libodb}/lib"
	"${libodb_mysql}/lib"
)

link_directories(
	${link_lib}
)


#set(
#	xunan_admin_lib
#	"${libodb}/lib"
#	"${libodb_mysql}/lib"
#)

#link_directories(
#	${xunan_admin_lib}
#)

#aux_source_directory(library dir_src2)
#aux_source_directory(src_mfc monitor)

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

#CMAKE FAQ 
set(CMAKE_CXX_FLAGS_DEBUG "/D_DEBUG /MDd /ZI /Ob0 /Od /RTC1") 
ADD_DEFINITIONS(-D_AFXDLL)
SET(CMAKE_MFC_FLAG 2)

#set(CMAKE_CXX_FLAGS_RELEASE "/MT")
#set(CMAKE_CXX_FLAGS_DEBUG "/MTd /Zi /Ob0 /Od /RTC1")


include_directories(
D:\\soft\\libodb-2.4.0
D:\\soft\\libodb-mysql-2.4.0
)



add_subdirectory(dlg)
add_subdirectory(dao)
add_subdirectory(service)
add_subdirectory(entity)
add_subdirectory(util)
add_subdirectory(ctrl)

set(
 libname
 libmysql
 ws2_32 
 dlg
 ctrl
 dao
 entity
 service
 util
# nafxcwd
# libcmtd
)


aux_source_directory(. source_files)


set(
 res
 icon1.ico
 icon2.ico
 icon3.ico
)

add_executable(
xunan_admin 
WIN32 
${source_files} 
xunan_admin.rc 
${res}
)

#add_library(xunan_adminlib ${source_files})

set(
 odb
 odb-d
 odb-mysql-d 
)


target_link_libraries(xunan_admin 
 ${libname}
 ${odb}
)
