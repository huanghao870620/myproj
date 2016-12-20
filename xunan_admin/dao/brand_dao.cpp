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
void brand_dao::query(std::list<brand*> &brand_list, std::auto_ptr<odb::database>&db){
	odb::result<brand> r(db->query<brand>());
	for (odb::result<brand>::iterator i(r.begin()); i != r.end(); ++i){
		brand*b = new brand;
		b->set_id(i->get_id());
		b->set_img_id(i->get_img_id());
		b->set_is_recommended(i->get_is_recommended());
		b->set_name(i->get_name());
		b->set_upload_type_id(i->get_upload_type_id());
		brand_list.push_back(b);
	}
}