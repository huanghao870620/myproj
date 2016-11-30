///////////////////////////////////////////////////////////
//  country_service.cpp
//  Implementation of the Class country_service
//  Created on:      28-十一月-2016 19:54:45
//  Original author: admin
///////////////////////////////////////////////////////////

#include "country_service.h"


country_service::country_service(){
	this->db = db_util::get_db_util()->get_db();
	this->cd = country_dao::get_country_dao();
}



country_service::~country_service(){

}

/*添加国家*/
void country_service::add_country(country&c){
	odb::core::transaction tx(this->db->begin());
	this->cd->add_country(c, this->db);
	tx.commit();
}