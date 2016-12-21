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
	db->persist(classifi);
}

/**/
void classification_dao::getParentClass(classification*classifi, long classid, std::auto_ptr<odb::database> &db){
	odb::result<classification> r(db->query<classification>(odb::query<classification>::id==classid));
	odb::result<classification>::iterator i(r.begin());
	classifi->set_pid(i->get_pid());
	classifi->set_id(classid);
}

void classification_dao::query_class_bypid(std::list<classification*>*child_class, long pid, std::auto_ptr<odb::database> &db){
odb::result<classification> r(db->query<classification>(odb::query<classification>::pid == pid));
for (odb::result<classification>::iterator i(r.begin()); i != r.end(); ++i){
	classification *cla = new classification;
	cla->set_id(i->get_id());
	cla->set_name(i->get_name());
	cla->set_pid(i->get_pid());
	cla->set_img_id(i->get_img_id());
	child_class->push_back(cla);
}
}

