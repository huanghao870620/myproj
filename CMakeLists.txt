cmake_minimum_required(VERSION 3.4)

project(proj0)

aux_source_directory(src dir_srcs)

add_executable(a0 ${dir_srcs})

aux_source_directory(src1 dir_src1)

add_executable(a1 ${dir_src1})


include_directories(
 "D:\\soft\\boost_1_60_0"
 "C:\\Users\\hp\\Downloads\\mysql-5.6.24-win32.1432006610\\mysql-5.6.24-win32\\include"
 "C:\\Program Files (x86)\\Visual Leak Detector\\include"
# "C:\\test"
# "C:\\Program Files (x86)\\Microsoft Visual Studio 12.0\\VC\\atlmfc\\include"
)

link_directories(
	"src2\\a0\\Debug"
	"C:\\Users\\hp\\Downloads\\mysql-5.6.24-win32.1432006610\\mysql-5.6.24-win32\\lib"
	"D:\\soft\\boost_1_60_0\\bin.v2\\libs\\locale\\build\\msvc-12.0\\debug\\link-static\\threading-multi"
	"C:\\Program Files (x86)\\Visual Leak Detector\\lib\\Win32"
)

aux_source_directory(src2 dir_src2)


set(
 src_mfc
)

aux_source_directory(src_mfc src_mfc)
add_subdirectory(src2/a0)
add_subdirectory(src_mfc)


#aux_source_directory(/src2/a0 b0)
include_directories(./src2/a0)
add_executable(a2 ${dir_src2})

add_executable(mfc_exa ${src_mfc})

#target_link_libraries(a2 )

add_subdirectory(test test_bin)

