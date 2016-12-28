///////////////////////////////////////////////////////////
//  good_file_service.cpp
//  Implementation of the Class good_file_service
//  Created on:      27-十一月-2016 18:06:24
//  Original author: admin
///////////////////////////////////////////////////////////

#include"upload_service.h"
#include "good_file_service.h"

good_file_service::good_file_service(){
	this->db = db_util::get_db_util()->get_db();
	this->d = good_file_dao::get_good_file_dao();
	this->fd = file_dao::get_file_dao();
}



good_file_service::~good_file_service(){

}


void good_file_service::add_good_file(good_file&gf){
	odb::core::transaction *tx = new odb::core::transaction(db->begin());
	this->d->add_good_file(gf, this->db);
	tx->commit();
}

/*添加商品图片*/
void good_file_service::add_good_file(
	std::string& local_path,
	long type_id,
	long goodId,
	 upload_service*us
	){

	good_file gf;
	file f;
	
	us->upload_file(f, local_path.c_str(), type_id);
	gf.set_file_id(f.get_id());
	gf.set_good_id(goodId);
	this->d->add(gf,this->db);
	t::current().commit();
}


/*修改商品图片*/
void good_file_service::update_good_file(
	std::string& local_path,
	long type_id,
	long goodId,
	long file_id,
	upload_service*us
	){
	
	good_file gf;
	file f;
	f.set_id(file_id);
	us->upload_file(f, local_path.c_str(), type_id);
	t::current().commit();
	/*gf.set_file_id(f.get_id());
	gf.set_good_id(goodId);
	this->d->add(gf, this->db);*/
}

/**/
void good_file_service::findFileByGoodId(long goodId, long type_id_, std::list<file> *fs){
	tran *tx = NULL;
	try{
		if (!t::has_current()){
			tx = new tran(db->begin());
		}
		odb::result<good_file> r(db->query<good_file>(odb::query<good_file>::good_id == goodId) );
	for (odb::result<good_file>::iterator i(r.begin()); i != r.end(); ++i){
		long file_id = i->get_file_id();
		 file&f=fd->findById(file_id, db);
		 std::cout << "" << std::endl;
		long type_id = f.get_type_id();
		if (type_id == type_id_){
			fs->push_back(f);
		}
	}
	}
	catch (odb::exception&e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << "" << std::endl;
}

/**/
file good_file_service::getThumbFile4GoodId(long goodId){
	 tran *tx = NULL;
	try{
		if (!t::has_current()){
			tx = new tran(db->begin()); 
		}

		odb::result<good_file> r(db->query<good_file>(odb::query<good_file>::good_id == goodId));
		for (odb::result<good_file>::iterator i(r.begin()); i != r.end(); ++i){
			long file_id = i->get_file_id();
			file&f = fd->findById(file_id, db);
			long type_id = f.get_type_id();
			if (type_id == 12){
				//tx->commit();
				return f;
			}
		}
	}
	catch (odb::exception&e){
		std::cerr << e.what() << std::endl;
		tx->rollback();
	}
}

/*查询商品大图*/
std::list<file*>*  queryBigPic4Goods(long goodId, long type_id){
	return NULL;
}

/*删除商品图片*/
void good_file_service::deleteGoodFile(long file_id){
	good_file gf= this->d->findGfByImgId(file_id, this->db);
	this->d->erase(gf,this->db);

	file&f= this->fd->findById(file_id,this->db);
	this->fd->erase(f,this->db);
	t::current().commit();
}