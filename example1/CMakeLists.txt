aux_source_directory(. source_files)
set(CMAKE_CXX_FLAGS_DEBUG "/MTd /Zi /Ob0 /Od /RTC1")
add_executable(example1 WIN32 ${source_files} example1.rc)