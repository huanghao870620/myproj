///////////////////////////////////////////////////////////
//  good_service.cpp
//  Implementation of the Class good_service
//  Created on:      27-Ê®Ò»ÔÂ-2016 17:05:26
//  Original author: admin
///////////////////////////////////////////////////////////

#include "good_service.h"


good_service::good_service(){
	this->db = db_util::get_db_util()->get_db();
	this->gd= good_dao::get_good_dao();
}



good_service::~good_service(){

}

void good_service::update_good(goods&good){
	odb::core::transaction tx(db->begin());
	this->gd->update(good, this->db);
	tx.commit();
}


void good_service::query_list(std::list<goods*>* goods_list){
	this->gd->query_list(goods_list, this->db);
}

void good_service::findById(goods*good, long id){
	this->gd->findById(good, id, this->db);
}