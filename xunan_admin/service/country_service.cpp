///////////////////////////////////////////////////////////
//  country_service.cpp
//  Implementation of the Class country_service
//  Created on:      28-十一月-2016 19:54:45
//  Original author: admin
///////////////////////////////////////////////////////////
#include"../util/charset_util.h"
#include "country_service.h"
#include"../util/file_type_enum.h"


country_service::country_service(){
	this->db = db_util::get_db_util()->get_db();
	this->d = country_dao::get_country_dao();
}



country_service::~country_service(){

}

/*添加国家*/
void country_service::add_country(country&c){
	try{
	odb::core::transaction tx(this->db->begin());
	c.set_name(charset_util::GBKToUTF8(c.get_name()));
	this->d->add_country(c, this->db);
	tx.commit();
	}
	catch (odb::exception&e){
		std::cout << e.what() << std::endl;
	}
}

/*修改國家信息*/
void country_service::edit_country(long id,
	std::string&name,
	std::string&country_code, 
	std::string&img_path,
	upload_service&us){
	tran *tx = NULL;
	if (!t::has_current()){
		tx = new tran(this->db->begin());
	}

	country c;
	file f;
	
	us.upload_file(f, img_path.c_str(), COUNTRY_PHOTO);

	c.set_id(id);
	c.set_img_id(f.get_id());
	c.set_country_code(country_code);
	c.set_name(name);
	this->d->edit(c,this->db);
}



/**/
void country_service::query(std::list<country*>&c_list){
	try{
	odb::core::transaction t(this->db->begin());
	this->d->query(c_list, this->db);
	}
	catch (odb::exception&e){
		std::cout << e.what() << std::endl;
	}
}