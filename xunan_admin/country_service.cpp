///////////////////////////////////////////////////////////
//  country_service.cpp
//  Implementation of the Class country_service
//  Created on:      28-十一月-2016 19:54:45
//  Original author: admin
///////////////////////////////////////////////////////////
#include"charset_util.h"
#include "country_service.h"


country_service::country_service(){
	this->db = db_util::get_db_util()->get_db();
	this->cd = country_dao::get_country_dao();
}



country_service::~country_service(){

}

/*添加国家*/
void country_service::add_country(country&c){
	try{
	odb::core::transaction tx(this->db->begin());
	c.set_name(charset_util::GBKToUTF8(c.get_name()));
	this->cd->add_country(c, this->db);
	tx.commit();
	}
	catch (odb::exception&e){
		std::cout << e.what() << std::endl;
	}
}

/**/
void country_service::query(std::list<country*>&c_list){
	try{
	odb::core::transaction t(this->db->begin());
	this->cd->query(c_list, this->db);
	}
	catch (odb::exception&e){
		std::cout << e.what() << std::endl;
	}
}