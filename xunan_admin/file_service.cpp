///////////////////////////////////////////////////////////
//  file_service.cpp
//  Implementation of the Class file_service
//  Created on:      27-Ê®Ò»ÔÂ-2016 17:30:07
//  Original author: admin
///////////////////////////////////////////////////////////

#include "file_service.h"


file_service::file_service(){
	this->db = db_util::get_db_util()->get_db();
	this->fd = file_dao::get_file_dao();
}



file_service::~file_service(){

}

void file_service::findById(long id,file *f){
	this->fd->findById(id, f, this->db);
}

void file_service::add_file(file&f){
	this->fd->add_file(f, this->db);
}

void file_service::update_file(file&f){
	this->fd->update_file(f,this->db);
}