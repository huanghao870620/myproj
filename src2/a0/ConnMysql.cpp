#include <Windows.h>
#include <stdio.h>
#include <mysql.h>
#include <iostream>
#include "ReadIniFile.h"
#include "ConnMysql.h"



ConnMysql::ConnMysql()
{
	this->rif = new ReadIniFile;

	strcpy_s(this->dbuser,  this->rif->get_dbuser());
	strcpy_s(this->dbpasswd, this->rif->get_dbpass());
	strcpy_s(this->dbip,  this->rif->get_dbip());
	strcpy_s(this->dbname,  this->rif->get_dbname());
	strcpy_s(this->tablename, "rr_report");

	fflush(stdin);
	con = mysql_init((MYSQL*)0);
	mysql_real_connect(con, dbip, dbuser, dbpasswd, dbname, 3306, NULL, 0);
	mysql_select_db(con, dbname);
	con->reconnect = 1;
	query = "set names \'GBK\'";
	rt = mysql_real_query(con, query, strlen(query));
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
	rt = mysql_real_query(con, sql, strlen(sql));
	res = mysql_store_result(con);
	return res;
}

int ConnMysql::Delete(const char * sql){
	return mysql_query(this->con, sql);
}

	//std::cout << "1 : " << row[1] << std::endl;
	//mysql_free_result(res);
	//mysql_close(con);
