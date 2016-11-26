///////////////////////////////////////////////////////////
//  good_file_dao.cpp
//  Implementation of the Class good_file_dao
//  Created on:      22-十一月-2016 20:43:00
//  Original author: admin
///////////////////////////////////////////////////////////

#include "good_file_dao.h"


good_file_dao::good_file_dao(){
	this->db = db_util::get_db_util()->get_db();
}



good_file_dao::~good_file_dao(){

}

/*add good_file*/
void good_file_dao::add_good_file(good_file&gf){
	odb::core::transaction *tx = new odb::core::transaction(this->db->begin());
	this->db->persist(gf);
	tx->commit();
}

/*获取指定类型的商品图片*/
void good_file_dao::findFileByGoodId(long goodId,long type_id_, std::list<file*> *fs){
	file_dao*fd = file_dao::get_file_dao();
	odb::core::transaction t(this->db->begin());
	odb::result<good_file> r(db->query<good_file>(odb::query<good_file>::good_id == goodId));
	for (odb::result<good_file>::iterator i(r.begin()); i != r.end(); ++i){
		long file_id = i->get_file_id();
		file *f = new file;
		fd->findById(file_id,f,this->db);
		long type_id = f->get_type_id();
		if (type_id == type_id_){
			fs->push_back(f);
		}
	}
}