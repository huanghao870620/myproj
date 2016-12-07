///////////////////////////////////////////////////////////
//  country_dao.cpp
//  Implementation of the Class country_dao
//  Created on:      28-Ê®Ò»ÔÂ-2016 19:54:44
//  Original author: admin
///////////////////////////////////////////////////////////

#include "country_dao.h"


country_dao::country_dao(){

}


country_dao::~country_dao(){

}

void country_dao::add_country(country&c,std::auto_ptr<odb::database> &db){
	db->persist(c);
}

void country_dao::query(std::list<country*>&country_list, std::auto_ptr<odb::database>&db){
	odb::result<country> r(db->query<country>());
	for (odb::result<country>::iterator i(r.begin()); i != r.end(); ++i){
		country *c = new country;
		c->set_country_code(i->get_country_code());
		c->set_id(i->get_id());
		c->set_img_id(i->get_img_id());
		c->set_name(i->get_name());
		country_list.push_back(c);
	}
}