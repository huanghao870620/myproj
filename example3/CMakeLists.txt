aux_source_directory(. source_files)
add_executable(example3 WIN32 ${source_files} example3.rc Clock.htm)


add_custom_command(OUTPUT Clock.htm
  POST_BUILD 
  COMMAND copy Clock.htm Debug
  COMMENT "sdfsdfsd"
 )