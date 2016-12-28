///////////////////////////////////////////////////////////
//  file_dao.cpp
//  Implementation of the Class file_dao
//  Created on:      17-Ê®Ò»ÔÂ-2016 19:36:58
//  Original author: admin
///////////////////////////////////////////////////////////

#include "file_dao.h"


file_dao::file_dao(){
}



file_dao::~file_dao(){

}

void file_dao::add_file(file&f, std::auto_ptr<odb::database> &db){
	db->persist(f);
}

void file_dao::update_file(file&f, std::auto_ptr<odb::database> &db){
	 db->update(f);
}

