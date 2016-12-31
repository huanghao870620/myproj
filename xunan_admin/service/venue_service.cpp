///////////////////////////////////////////////////////////
//  venue_service.cpp
//  Implementation of the Class venue_service
//  Created on:      30-Ê®Ò»ÔÂ-2016 19:49:37
//  Original author: admin
///////////////////////////////////////////////////////////
#include"upload_service.h"
#include "venue_service.h"


venue_service::venue_service(){
	this->db = db_util::get_db_util()->get_db();
	this->vd = venue_dao::get_venue_dao();
}



venue_service::~venue_service(){

}

/**/
void venue_service::add_venue(std::string&name,std::string&adv_pic_path, upload_service*us){
	venue v;
	file f;
	v.set_name(name);
	us->upload_file(f, adv_pic_path.c_str(), 18);
	v.set_adv_pic(f.get_id());
	this->vd->add_venue(v,this->db);
}