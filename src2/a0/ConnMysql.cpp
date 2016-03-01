#include <Windows.h>
#include <stdio.h>
#include <mysql.h>

#include "ReadIniFile.h"
#include "ConnMysql.h"



ConnMysql::ConnMysql()
{
	this->rif = new ReadIniFile;

	this->dbuser = this->rif->get_dbuser();
	this->dbpasswd = this->rif->get_dbpass();
	this->dbip = this->rif->get_dbip();
	this->dbname = this->rif->get_dbname();
	this->tablename = "rr_report";

	fflush(stdin);
	con = mysql_init((MYSQL*)0);
	mysql_real_connect(con, 
		 this->dbip.c_str(),
		 this->dbuser.c_str(), 
		 this->dbpasswd.c_str(), 
		 this->dbname.c_str(), 
		 3306,
		 NULL, 
		 0);
	mysql_select_db(con, this->dbname.c_str());
	con->reconnect = 1;
	query = "set names \'GBK\'";
    mysql_real_query(con, query, strlen(query));
}

ConnMysql::~ConnMysql()
{
	delete this->rif;
}

void ConnMysql::init() {
}

void ConnMysql::insert(){
	//	mysql_error(con);
	//	sprintf(tmp, "insert into %s values(%s,%d,%d)", tablename, "null", 2, 1); 
	//	rt = mysql_real_query(con, tmp, strlen(tmp));
}

//sprintf(tmp, "select * from %s", tablename);
MYSQL_RES * ConnMysql::select(const char * sql){
	MYSQL_ROW row;
	MYSQL_FIELD *field = nullptr;
    mysql_real_query(con, sql, strlen(sql));
	res = mysql_store_result(con);
	return res;
}

int ConnMysql::Delete(const char * sql){
	return mysql_query(this->con, sql);
}

	//std::cout << "1 : " << row[1] << std::endl;
	//mysql_free_result(res);
	//mysql_close(con);
