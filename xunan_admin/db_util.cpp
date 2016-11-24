///////////////////////////////////////////////////////////
//  db_util.cpp
//  Implementation of the Class db_util
//  Created on:      17-Ê®Ò»ÔÂ-2016 19:26:05
//  Original author: admin
///////////////////////////////////////////////////////////

#include "db_util.h"


db_util::db_util(){
	this->db = new  std::auto_ptr<odb::database> (
				new odb::mysql::database("root", "xa", "test", "192.168.1.102", 3306, "", "utf8")
				);
}



db_util::~db_util(){
	std::cout << "" << std::endl;
}