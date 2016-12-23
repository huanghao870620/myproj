///////////////////////////////////////////////////////////
//  db_util.cpp
//  Implementation of the Class db_util
//  Created on:      17-Ê®Ò»ÔÂ-2016 19:26:05
//  Original author: admin
//////////////////////////////////////////////////////////k/

#include "db_util.h"
#include"Config.h"

db_util::db_util(){
	Config*config= Config::getConfig();
	char *b=config->get_db_user();
	std::cout << "" << std::endl;
	odb::mysql::database*database = new odb::mysql::database(
		config->get_db_user(),
		config->get_db_pass(),
		"test", 
		config->get_db_ip(),
		3306, 
		"", 
		"utf8");

	this->db = new  std::auto_ptr<odb::database> (database);
}



db_util::~db_util(){
	std::cout << "" << std::endl;
}