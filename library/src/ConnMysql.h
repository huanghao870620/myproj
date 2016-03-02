#ifndef CONNMYSQL_H
#define CONNMYSQL_H
#include <iostream>

#include <winsock.h>
#include <mysql.h>

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
		std::string tmp;
		std::string dbuser;
		std::string dbpasswd;
		std::string dbip;
		std::string dbname;
		std::string tablename;

		char *query = nullptr;

};  



#endif
