///////////////////////////////////////////////////////////
//  upload_service.cpp
//  Implementation of the Class upload_service
//  Created on:      28-ʮһ��-2016 17:42:12
//  Original author: admin
///////////////////////////////////////////////////////////

#include "upload_service.h"


upload_service::upload_service(){
	this->fd = file_dao::get_file_dao();
	this->db = db_util::get_db_util()->get_db();
}



upload_service::~upload_service(){

}

/*�ϴ��ļ�*/
void upload_service::upload_file(file&f, LPCSTR localFilePath,long file_type){
	typedef odb::core::transaction tran;
	typedef odb::transaction t;
	tran *tx = NULL;
	std::string fileTypeIdStr;
	std::string b1Path = "";
	f.set_path(b1Path);
	f.set_type_id(file_type);
	std::string base;
	f.set_uri_path(base);

	unsigned long file_id;
	if (f.get_id() > 0){
		//�޸�
		fd->update(f, this->db);
		//file f000= this->db->persist(f);
	}
	else{
		//���
		file_id = fd->add(f, this->db);
	f = fd->findById(file_id,this->db);
	}

	UploadFile uf;
	fileTypeIdStr = Util::ltos(file_type);
	std::string id_str = Util::ltos(f.get_id());
	uf.upload(localFilePath, base, fileTypeIdStr.c_str(), id_str.c_str());

	f.set_uri_path(base);
	fd->update(f, this->db);
}

