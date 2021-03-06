///////////////////////////////////////////////////////////
//  classification_service.cpp
//  Implementation of the Class classification_service
//  Created on:      27-ʮһ��-2016 19:06:11
//  Original author: admin
///////////////////////////////////////////////////////////

#include "classification_service.h"


classification_service::classification_service(){
	this->db = db_util::get_db_util()->get_db();
	this->d = classification_dao::get_classification_dao();
	this->fd = file_dao::get_file_dao();
}



classification_service::~classification_service(){

}

void classification_service::add_classifi(classification&classifi){
	this->d->add_classifi(classifi, this->db);
}

void classification_service::getParentClass(classification*classifi, long classid){
	this->d->getParentClass(classifi, classid, this->db);
}


/**/
void classification_service::query_class_bypid(std::list<classification*>*child_class, long pid){
	this->d->query_class_bypid(child_class, pid, this->db);
	std::list<classification*>::iterator iter= child_class->begin();
	for (; iter != child_class->end(); iter++){
		classification *c = *iter;
		long img_id= c->get_img_id();
		file&f=this->fd->findById(img_id,this->db);
	}
}


/**/
void classification_service::query_classification(std::list<classification*>*class_list){
	typedef odb::core::transaction tran;
	typedef odb::transaction t;
	tran *tx = NULL;
	typedef  odb::query<classification> que;
	odb::result<classification> s = db->query<classification>(que::pid == -1);

		odb::result<classification> r(s);
		for (odb::result<classification>::iterator i(r.begin()); i != r.end(); ++i){
			classification *cla = new classification;
			cla->set_id(i->get_id());
			cla->set_name(i->get_name());
			cla->set_pid(i->get_pid());
			class_list->push_back(cla);
		}
}