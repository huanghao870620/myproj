///////////////////////////////////////////////////////////
//  venue_dao.cpp
//  Implementation of the Class venue_dao
//  Created on:      30-Ê®Ò»ÔÂ-2016 19:49:35
//  Original author: admin
///////////////////////////////////////////////////////////

#include "venue_dao.h"


venue_dao::venue_dao(){

}



venue_dao::~venue_dao(){

}

void venue_dao::add_venue(venue&v,std::auto_ptr<odb::database>&db){
	db->persist(v);
}