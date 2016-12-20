///////////////////////////////////////////////////////////
//  good_file_service.cpp
//  Implementation of the Class good_file_service
//  Created on:      27-Ê®Ò»ÔÂ-2016 18:06:24
//  Original author: admin
///////////////////////////////////////////////////////////

#include "good_file_service.h"


good_file_service::good_file_service(){
	this->db = db_util::get_db_util()->get_db();
	this->gfd = good_file_dao::get_good_file_dao();
	this->fd = file_dao::get_file_dao();
}



good_file_service::~good_file_service(){

}


void good_file_service::add_good_file(good_file&gf){
	odb::core::transaction *tx = new odb::core::transaction(db->begin());
	this->gfd->add_good_file(gf, this->db);
	tx->commit();
}

void good_file_service::findFileByGoodId(long goodId, long type_id_, std::list<file*> *fs){
	try{
		odb::core::transaction *tx = new odb::core::transaction(db->begin());
	odb::result<good_file> r(db->query<good_file>(odb::query<good_file>::good_id == goodId));
	for (odb::result<good_file>::iterator i(r.begin()); i != r.end(); ++i){
		long file_id = i->get_file_id();
		 file *f=fd->findById(file_id, db);
		long type_id = f->get_type_id();
		if (type_id == type_id_){
			fs->push_back(f);
		}
	}
	}
	catch (odb::exception&e){
		std::cerr << e.what() << std::endl;
	}
}