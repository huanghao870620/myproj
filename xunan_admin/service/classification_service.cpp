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
	this->fd = file_dao::get_file_dao();
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
void classification_service::query_class_bypid(std::list<classification*>*child_class, long pid){
	try{
	odb::core::transaction t(db->begin());
	this->cd->query_class_bypid(child_class, pid, this->db);
	std::list<classification*>::iterator iter= child_class->begin();
	for (; iter != child_class->end(); iter++){
		classification *c = *iter;
		long img_id= c->get_img_id();
		file*f=this->fd->findById(img_id,this->db);

	}
	}
	catch (odb::exception&e){
		std::cout << e.what() << std::endl;
	}
}