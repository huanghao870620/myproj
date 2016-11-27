aux_source_directory(. source_files)
#aux_source_directory(./util util)
include_directories(
D:\\soft\\libodb-2.4.0
D:\\soft\\libodb-mysql-2.4.0
)

set(
	xunan_admin_lib
	"${libodb}/lib"
	"${libodb_mysql}/lib"
)

link_directories(
	${xunan_admin_lib}
)


set(
 xunan_admin_libname
 odb-d
 odb-mysql-d
)
#CMAKE FAQ 
set(CMAKE_CXX_FLAGS_DEBUG "/D_DEBUG /MDd /ZI /Ob0 /Od /RTC1") 
ADD_DEFINITIONS(-D_AFXDLL)
SET(CMAKE_MFC_FLAG 2)

#set(CMAKE_CXX_FLAGS_RELEASE "/MT")
#set(CMAKE_CXX_FLAGS_DEBUG "/MTd /Zi /Ob0 /Od /RTC1")

set(
 res
 icon1.ico
 icon2.ico
 icon3.ico
)

add_executable(xunan_admin WIN32 ${source_files} ${util} xunan_admin.rc ${res})
add_library(xunan_adminlib ${source_files})
target_link_libraries(xunan_admin 
${xunan_admin_libname}
)
