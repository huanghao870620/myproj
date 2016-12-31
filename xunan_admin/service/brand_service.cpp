///////////////////////////////////////////////////////////
//  brand_service.cpp
//  Implementation of the Class brand_service
//  Created on:      28-Ê®Ò»ÔÂ-2016 16:42:50
//  Original author: admin
///////////////////////////////////////////////////////////

#include "brand_service.h"


brand_service::brand_service(){
	this->db = db_util::get_db_util()->get_db();
	this->d = brand_dao::get_brand_dao();
}

brand_service::~brand_service(){

}

void brand_service::add_brand(brand&b){
	odb::core::transaction*t = new odb::core::transaction(db->begin());
	this->d->add_brand(b,this->db);
	t->commit();
}

std::list<brand>  brand_service::get_brands(){
	std::list<brand> brand_list;
	tran *tx = NULL;
	try{
		if (!t::has_current()){
			tx = new tran(this->db->begin());
		}
		else
		{
			tx = &(t::current());
		}
		brand_list = this->d->query(this->db);
	}
	catch (odb::exception&e){
		std::cout << e.what() << std::endl;
		t::current().rollback();
	}
	return brand_list;
}
