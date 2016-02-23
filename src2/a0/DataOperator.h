#ifndef DATAOPERATOR_H
#define DATAOPERATOR_H
#include <mysql.h>


class DataOperator
{

    public:
        DataOperator(); 
        ~DataOperator(); 
		void insert(char* tmp); 

private:
		 int newField;
		 MYSQL *con;
		 const char *user;
		 const char *password;
		 const char *ip;
		 const char * db;
};  



#endif
