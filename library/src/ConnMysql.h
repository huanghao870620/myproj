#ifndef CONNMYSQL_H
#define CONNMYSQL_H
#include <iostream>

#include <winsock.h>
#include <mysql.h>
class ConnMysql;
static ConnMysql * conn;
class ConnMysql
{

	private:
        ConnMysql(); 

	private:
		MYSQL *con;
		MYSQL_RES *res;
		MYSQL_ROW row;
		std::string tmp;
		std::string dbname;
		std::string tablename;
		char *query = nullptr;
		

	public:
		static ConnMysql* getInstance();

        ~ConnMysql(); 
		void init();
		void insert();
		MYSQL_RES * select( const char * sql);
		int Delete(const char * sql);

};  



#endif
