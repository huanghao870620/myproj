/////////////////////////////////////////////////////////////
////  file_service.cpp
////  Implementation of the Class file_service
////  Created on:      27-十一月-2016 17:30:07
////  Original author: admin
/////////////////////////////////////////////////////////////
//
#include"UploadFile.h"
#include"Util.h"
#include "file_service.h"
//
//
file_service::file_service(){
	this->db = db_util::get_db_util()->get_db();
	this->fd = file_dao::get_file_dao();
	this->gfd = good_file_dao::get_good_file_dao();
}



file_service::~file_service(){

}

file* file_service::findById(long id){
	return this->fd->findById(id,  this->db);
}

void file_service::add_file(file&f){
	try{
		odb::core::transaction tx(this->db->begin());
		this->fd->add_file(f, this->db);
		tx.commit();
	}
	catch (odb::exception&e){
		std::cout << e.what() << std::endl;
	}
}

void file_service::update_file(file&f){
	odb::core::transaction tx(this->db->begin());
	this->fd->update_file(f,this->db);
	tx.commit();
}

/*修改和上传文件*/
void file_service::update_and_upload_file(long file_id,
	std::string&localPath, 
	long fileTypeId){
	std::string base;
	std::string id_str;
	std::string fileTypeIdStr;
	UploadFile uf;
	try{
	odb::core::transaction tx(this->db->begin());
	file*f= this->fd->findById(file_id, this->db);
	id_str = Util::ltos(f->get_id());
	fileTypeIdStr = Util::ltos(fileTypeId);
	uf.upload(localPath.c_str(), base, fileTypeIdStr.c_str(), id_str.c_str());
	f->set_uri_path(base);
	this->fd->update_file(*f, this->db);
	tx.commit();
	}
	catch (odb::exception&e){
		std::cout << e.what() << std::endl;
	}
}


void file_service::add_good_file(std::string&localPath,long good_id,long file_type){
	std::string path = "";
	std::string uri_path = "";
	file f;
	good_file gf;
	UploadFile uf;
	std::string base;
	try{
		odb::core::transaction tx(this->db->begin());
	f.set_name("");
	f.set_path(path);
	f.set_type_id(file_type);
	f.set_uri_path(uri_path);
	this->fd->add_file(f, this->db);

	std::string id_str = Util::ltos(f.get_id());
	std::string fileTypeIdStr = Util::ltos(file_type);
	uf.upload(localPath.c_str(), base, fileTypeIdStr.c_str(), id_str.c_str());
	f.set_uri_path(base);
	this->fd->update_file(f, this->db);
	
	gf.set_file_id(f.get_id());
	gf.set_good_id(good_id);
	this->gfd->add_good_file(gf, this->db);
	tx.commit();
	}
	catch (odb::exception&e){
		std::cout << e.what() << std::endl;
	}
}