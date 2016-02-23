#include <stdio.h>
#include <Windows.h>
#include "mysql.h"
#include "rr_report.h"
#include "DataOperator.h"

DataOperator::DataOperator() 
{
	this->con = mysql_init((MYSQL *)0);
	this->user = "founder";
	this->password = "123";
	this->ip = "172.18.146.216";
	this->db = "ffinance";

	mysql_real_connect(con, this->ip, this->user, this->password, this->db, 3306, NULL, 0);
	mysql_select_db(this->con, this->db);
	this->con->reconnect = 1;
}

DataOperator::~DataOperator() 
{
}

/*²åÈë*/
void DataOperator::insert(char *sql) 
{
	mysql_real_query(this->con, sql, strlen(sql));
}

