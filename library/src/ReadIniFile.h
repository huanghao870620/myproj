#ifndef READINIFILE_H
#define READINIFILE_H
#include <iostream>

class ReadIniFile
{

    public:
        ReadIniFile(); 

        ~ReadIniFile(); 

		static char * get_path();
		static std::string & get_dbuser();
		static std::string & get_dbpass();
		static std::string & get_dbip();
		static std::string & get_dbname();
		static void get_server_ip(char * server_ip);
}; 



#endif
