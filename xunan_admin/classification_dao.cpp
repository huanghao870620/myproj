///////////////////////////////////////////////////////////
//  classification_dao.cpp
//  Implementation of the Class classification_dao
//  Created on:      18-ʮһ��-2016 11:04:54
//  Original author: admin
///////////////////////////////////////////////////////////

#include "classification_dao.h"


classification_dao::classification_dao(){
	this->db = db_util::get_db_util()->get_db();
}



classification_dao::~classification_dao(){

}

/*��ӷ���*/
void classification_dao::add_classifi(classification&classifi){
	std::cout << "" << std::endl;
	odb::core::transaction*t = new odb::core::transaction(this->db->begin());
	this->db->persist(classifi);
	t->commit();
}