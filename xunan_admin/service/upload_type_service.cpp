///////////////////////////////////////////////////////////
//  upload_type_service.cpp
//  Implementation of the Class upload_type_service
//  Created on:      05-Ê®¶þÔÂ-2016 14:41:18
//  Original author: admin
///////////////////////////////////////////////////////////

#include "upload_type_service.h"


upload_type_service::upload_type_service(){
	this->db = db_util::get_db_util()->get_db();
	this->utd = upload_type_dao::get_upload_type_dao();
}



upload_type_service::~upload_type_service(){

}

void upload_type_service::query(std::list<upload_type*>&ut_list){
	this->utd->query(ut_list, this->db);
}