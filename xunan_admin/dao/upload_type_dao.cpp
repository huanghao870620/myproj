///////////////////////////////////////////////////////////
//  upload_type_dao.cpp
//  Implementation of the Class upload_type_dao
//  Created on:      05-Ê®¶þÔÂ-2016 14:41:17
//  Original author: admin
///////////////////////////////////////////////////////////

#include "upload_type_dao.h"


upload_type_dao::upload_type_dao(){

}



upload_type_dao::~upload_type_dao(){

}

void upload_type_dao::query(std::list<upload_type*>&ut_list, std::auto_ptr<odb::database>&db){
	odb::result<upload_type> r(db->query<upload_type>());
	for (odb::result<upload_type>::iterator i(r.begin()); i != r.end(); ++i){
		upload_type*ut = new upload_type;
		ut->set_id(i->get_id());
		ut->set_name(i->get_name());
		ut_list.push_back(ut);
	}

}