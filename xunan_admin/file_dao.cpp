///////////////////////////////////////////////////////////
//  file_dao.cpp
//  Implementation of the Class file_dao
//  Created on:      17-Ê®Ò»ÔÂ-2016 19:36:58
//  Original author: admin
///////////////////////////////////////////////////////////

#include "file_dao.h"


file_dao::file_dao(){
	this->db = db_util::get_db_util()->get_db();
}



file_dao::~file_dao(){

}

void file_dao::add_file(file&f){
	odb::core::transaction *t = nullptr;
	t = new odb::core::transaction(this->db->begin());
	this->db->persist(f);
	t->commit();
}

void file_dao::update_file(file&f){
	 odb::core::transaction *t = new odb::core::transaction(this->db->begin());
	 this->db->update(f);
	 t->commit();
}