#ifndef CONNMYSQL_H
#define CONNMYSQL_H


#include <winsock.h>

typedef struct st_mysql_res MYSQL_RES;
typedef struct st_mysql MYSQL;
typedef char **MYSQL_ROW;

class ReadIniFile;
class ConnMysql
{

    public:

        ConnMysql(); 
        ~ConnMysql(); 
		void init();

		void insert();

		MYSQL_RES * select( const char * sql);

		int Delete(const char * sql);

private:
		MYSQL *con;
		MYSQL_RES *res;
		MYSQL_ROW row;
		char tmp[400];
		char dbuser[30];
		char dbpasswd[30];
		char dbip[30];
		char dbname[50];
		char tablename[50];
		char *query = nullptr;

		int x;
		int y;
		int rt;
		unsigned int t;
		int count = 0;


		ReadIniFile * rif = nullptr;
};  //end class ConnMysql



#endif
