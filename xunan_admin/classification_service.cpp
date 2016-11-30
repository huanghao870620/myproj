///////////////////////////////////////////////////////////
//  classification_service.cpp
//  Implementation of the Class classification_service
//  Created on:      27-Ê®Ò»ÔÂ-2016 19:06:11
//  Original author: admin
///////////////////////////////////////////////////////////

#include "classification_service.h"


classification_service::classification_service(){
	this->db = db_util::get_db_util()->get_db();
	this->cd = classification_dao::get_classification_dao();
}



classification_service::~classification_service(){

}

void classification_service::add_classifi(classification&classifi){
	odb::core::transaction*t = new odb::core::transaction(db->begin());
	this->cd->add_classifi(classifi, this->db);
	t->commit();
}

void classification_service::getParentClass(classification*classifi, long classid){
	//odb::core::transaction t(db->begin());
	this->cd->getParentClass(classifi, classid, this->db);
}


/**/
void classification_service::query_class_bypid(std::list<classification*>*child_class, DWORD_PTR pid){
	try{
	odb::core::transaction t(db->begin());
	odb::result<classification> r(db->query<classification>(odb::query<classification>::pid == pid));
	for (odb::result<classification>::iterator i(r.begin()); i != r.end(); ++i){
		classification *cla = new classification;
		cla->set_id(i->get_id());
		cla->set_name(i->get_name());
		cla->set_pid(i->get_pid());
		child_class->push_back(cla);
	}
	//t.commit();
	}
	catch (odb::exception&e){
		std::cout << e.what() << std::endl;
	}
}