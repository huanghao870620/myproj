///////////////////////////////////////////////////////////
//  file_dao.cpp
//  Implementation of the Class file_dao
//  Created on:      17-Ê®Ò»ÔÂ-2016 19:36:58
//  Original author: admin
///////////////////////////////////////////////////////////

#include "file_dao.h"


file_dao::file_dao(){
	//this->db = db_util::get_db_util()->get_db();
}



file_dao::~file_dao(){

}

void file_dao::add_file(file&f, std::auto_ptr<odb::database> &db){
	db->persist(f);
}

void file_dao::update_file(file&f, std::auto_ptr<odb::database> &db){
	 db->update(f);
}

file* file_dao::findById(long id,  std::auto_ptr<odb::database> &db){
	odb::result<file> r(db->query<file>(odb::query<file>::id == id));
	odb::result<file>::iterator i(r.begin());
	file *f = new file;
	f->set_type_id(i->get_type_id());
	f->set_uri_path(i->get_uri_path());
	f->set_id(i->get_id());
	return f;
}