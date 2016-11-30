///////////////////////////////////////////////////////////
//  brand_dao.cpp
//  Implementation of the Class brand_dao
//  Created on:      28-Ê®Ò»ÔÂ-2016 16:42:48
//  Original author: admin
///////////////////////////////////////////////////////////

#include "brand_dao.h"


brand_dao::brand_dao(){

}



brand_dao::~brand_dao(){

}


void brand_dao::add_brand(brand&b, std::auto_ptr<odb::database> &db){
	db->persist(b);
}