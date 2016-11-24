aux_source_directory(. source_file)
include_directories(
D:\\soft\\libodb-2.4.0
D:\\soft\\libodb-mysql-2.4.0
)

set(
	example34_lib
	"${libodb}/lib"
	"${libodb_mysql}/lib"
)

link_directories(
	${example34_lib}
)


set(
 example34_libname
 odb-d
 odb-mysql-d
)

add_executable(example34 ${source_file})
target_link_libraries(example34 ${example34_libname})