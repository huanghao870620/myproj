///////////////////////////////////////////////////////////
//  good_file_service.cpp
//  Implementation of the Class good_file_service
//  Created on:      27-Ê®Ò»ÔÂ-2016 18:06:24
//  Original author: admin
///////////////////////////////////////////////////////////

#include "good_file_service.h"


good_file_service::good_file_service(){
	this->db = db_util::get_db_util()->get_db();
	this->gfd = good_file_dao::get_good_file_dao();
}



good_file_service::~good_file_service(){

}


void good_file_service::add_good_file(good_file&gf){
	this->gfd->add_good_file(gf, this->db);
}

void good_file_service::findFileByGoodId(long goodId, long type_id_, std::list<file*> *fs){
	this->gfd->findFileByGoodId(goodId, type_id_, fs, this->db);
}