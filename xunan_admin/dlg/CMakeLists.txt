aux_source_directory(. dlg_src)

#CMAKE FAQ 
#set(CMAKE_CXX_FLAGS_DEBUG "/D_DEBUG /MDd /ZI /Ob0 /Od /RTC1") 
#ADD_DEFINITIONS(-D_AFXDLL)
#SET(CMAKE_MFC_FLAG 2)

#set(CMAKE_CXX_FLAGS_RELEASE "/MT")
#set(CMAKE_CXX_FLAGS_DEBUG "/MTd /Zi /Ob0 /Od /RTC1")

#set(
#	xunan_admin_lib
#	"${libodb}/lib"
#	"${libodb_mysql}/lib"
#)

#link_directories(
#	${xunan_admin_lib}
#)

set(
 odb-lib
 odb-d
 odb-mysql-d
)

add_library(dlg ${dlg_src})
#target_link_libraries(dlg 
# ${odb-lib}
#)
