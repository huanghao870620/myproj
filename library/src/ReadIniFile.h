#ifndef READINIFILE_H
#define READINIFILE_H
#include <iostream>

class ReadIniFile
{

    public:
        ReadIniFile(); 

        ~ReadIniFile(); 

		static char * get_path();
		static void get_dbuser(char * dbuser);
		static void get_dbpass(char * dbpass);
		static void get_dbip(char * dbip);
		static void get_dbname(char * dbname);
		static void get_server_ip(char * server_ip);
}; 



#endif
