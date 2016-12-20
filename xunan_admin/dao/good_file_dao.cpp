///////////////////////////////////////////////////////////
//  good_file_dao.cpp
//  Implementation of the Class good_file_dao
//  Created on:      22-Ê®Ò»ÔÂ-2016 20:43:00
//  Original author: admin
///////////////////////////////////////////////////////////

#include "good_file_dao.h"


good_file_dao::good_file_dao(){
	//this->db = db_util::get_db_util()->get_db();
}



good_file_dao::~good_file_dao(){

}

/*add good_file*/
void good_file_dao::add_good_file(good_file&gf, std::auto_ptr<odb::database> &db){
	db->persist(gf);
}

