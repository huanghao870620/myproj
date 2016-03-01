#ifndef READINIFILE_H
#define READINIFILE_H


class ReadIniFile
{



    public:
        ReadIniFile(); 

        ~ReadIniFile(); 

		void read();

		char * get_dbuser();
		char * get_dbpass();
		char * get_dbip();
		char * get_dbname();
		char * get_server_ip();

private:
	char path[100];
	 char dbuser[100];
	 char dbpass[100];
	 char dbip[100];
	 char dbname[100];
	 char server_ip[100];
};  //end class ReadIniFile



#endif
