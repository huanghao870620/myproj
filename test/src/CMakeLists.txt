aux_source_directory(. source_files)
set(
 var2
 xunan_adminlib
 libmysql 
 ws2_32
)

include_directories(
  ../../xunan_admin
)

set(CMAKE_CXX_FLAGS_RELEASE "/MT")
set(CMAKE_CXX_FLAGS_DEBUG "/MDd /Zi /Ob0 /Od /RTC1")
ADD_DEFINITIONS(-D_AFXDLL)

add_executable(test_proj   ${source_files})
message(${libname})
target_link_libraries(test_proj   ${var2})
