///////////////////////////////////////////////////////////
//  classification_dao.cpp
//  Implementation of the Class classification_dao
//  Created on:      18-十一月-2016 11:04:54
//  Original author: admin
///////////////////////////////////////////////////////////

#include "classification_dao.h"


classification_dao::classification_dao(){
}



classification_dao::~classification_dao(){

}

/*添加分类*/
void classification_dao::add_classifi(classification&classifi, std::auto_ptr<odb::database> &db){
	std::cout << "" << std::endl;
	odb::core::transaction*t = new odb::core::transaction(db->begin());
	db->persist(classifi);
	t->commit();
}

/**/
void classification_dao::getParentClass(classification*classifi, long classid, std::auto_ptr<odb::database> &db){
	odb::core::transaction t(db->begin());
	odb::result<classification> r(db->query<classification>(odb::query<classification>::id==classid));
	odb::result<classification>::iterator i(r.begin());
	classifi->set_pid(i->get_pid());
	classifi->set_id(classid);
}