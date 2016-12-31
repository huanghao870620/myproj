///////////////////////////////////////////////////////////
//  brand_dao.cpp
//  Implementation of the Class brand_dao
//  Created on:      28-十一月-2016 16:42:48
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

/*获取所有品牌*/
std::list<brand> brand_dao::query(std::auto_ptr<odb::database>&db){
	std::list<brand> brand_list;
	odb::result<brand> r(db->query<brand>());
	for (odb::result<brand>::iterator i(r.begin()); i != r.end(); ++i){
		brand_list.push_back(*i);
	}
	return brand_list;
}