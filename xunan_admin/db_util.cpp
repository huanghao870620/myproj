///////////////////////////////////////////////////////////
//  db_util.cpp
//  Implementation of the Class db_util
//  Created on:      17-Ê®Ò»ÔÂ-2016 19:26:05
//  Original author: admin
///////////////////////////////////////////////////////////

#include "db_util.h"


db_util::db_util(){
	std::string config_file_path = "conn.ini";
	std::string username = "";
	//GetPrivateProfileInt("SECTION1", "YPos",0,)

	TCHAR szFilePath[100 + 1] = { 0 };
	GetModuleFileName(NULL, szFilePath, MAX_PATH);
	std::string strFilePath(szFilePath);
	std::size_t last= strFilePath.find_last_of("\\")-2;
	(strchr(szFilePath, '\\'))[last]=0;
	
	std::cout << "" << std::endl;

	odb::mysql::database*database = new odb::mysql::database("root", "xa", "test", "192.168.1.102", 3306, "", "utf8");
	this->db = new  std::auto_ptr<odb::database> (database);
}



db_util::~db_util(){
	std::cout << "" << std::endl;
}