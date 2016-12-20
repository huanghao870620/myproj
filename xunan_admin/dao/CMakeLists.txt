 aux_source_directory(. dao_src)

set(
	xunan_admin_lib
	"${libodb}/lib"
	"${libodb_mysql}/lib"
)

link_directories(
	${xunan_admin_lib}
)

set(
 odb-lib
 odb-d
 odb-mysql-d
)


add_library(dao ${dao_src})
target_link_libraries(
dao 
 ${odb-lib}
)