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
	this->cd->add_classifi(classifi, this->db);
}

void classification_service::getParentClass(classification*classifi, long classid){
	this->cd->getParentClass(classifi, classid, this->db);
}