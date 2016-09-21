aux_source_directory(. source_files)
add_executable(example11 ${source_files})
add_library(example11lib ${source_files})
add_definitions(
  #_USE_32BIT_TIME_T
)