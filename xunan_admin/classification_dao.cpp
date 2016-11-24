///////////////////////////////////////////////////////////
//  classification_dao.cpp
//  Implementation of the Class classification_dao
//  Created on:      18-十一月-2016 11:04:54
//  Original author: admin
///////////////////////////////////////////////////////////

#include "classification_dao.h"


classification_dao::classification_dao(){
	this->db = db_util::get_db_util()->get_db();
}



classification_dao::~classification_dao(){

}

/*添加分类*/
void classification_dao::add_classifi(classification&classifi){
	std::cout << "" << std::endl;
	odb::core::transaction*t = new odb::core::transaction(this->db->begin());
	this->db->persist(classifi);
	t->commit();
}