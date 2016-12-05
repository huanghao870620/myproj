///////////////////////////////////////////////////////////
//  brand_service.cpp
//  Implementation of the Class brand_service
//  Created on:      28-Ê®Ò»ÔÂ-2016 16:42:50
//  Original author: admin
///////////////////////////////////////////////////////////

#include "brand_service.h"


brand_service::brand_service(){
	this->db = db_util::get_db_util()->get_db();
	this->bd = brand_dao::get_brand_dao();
}

brand_service::~brand_service(){

}

void brand_service::add_brand(brand&b){
	odb::core::transaction*t = new odb::core::transaction(db->begin());
	this->bd->add_brand(b,this->db);
	t->commit();
}

void brand_service::get_brands(std::list<brand*> &brand_list){
	odb::core::transaction tx(this->db->begin());
	this->bd->query(brand_list, this->db);
}
