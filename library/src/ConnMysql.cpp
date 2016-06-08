#include <Windows.h>
#include <stdio.h>
#include <mysql.h>
#include "ReadIniFile.h"
#include "ConnMysql.h"


ConnMysql::ConnMysql()
{
	char dbuser[100], dbpass[100], dbip[100], dbname[100];

	ReadIniFile::get_dbuser(dbuser);
	ReadIniFile::get_dbpass(dbpass);
	ReadIniFile::get_dbip(dbip);
	ReadIniFile::get_dbname(dbname);
	this->tablename = "rr_report";

	fflush(stdin);
	con = mysql_init((MYSQL*)0);
	mysql_real_connect(con, 
		 dbip,
		 dbuser, 
		 dbpass, 
		 dbname, 
		 3306,
		 NULL, 
		 0);
	mysql_select_db(con, this->dbname.c_str());
	con->reconnect = 1;
	query = "set names \'GBK\'";
    mysql_real_query(con, query, strlen(query));
}

ConnMysql * ConnMysql::getInstance(){
	if (conn == nullptr){
		conn = new ConnMysql;
	}
	return conn;
}

ConnMysql::~ConnMysql()
{
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
