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