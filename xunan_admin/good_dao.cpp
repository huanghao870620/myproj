///////////////////////////////////////////////////////////
//  good_dao.cpp
//  Implementation of the Class good_dao
//  Created on:      23-Ê®Ò»ÔÂ-2016 20:53:55
//  Original author: admin
///////////////////////////////////////////////////////////

#include "good_dao.h"


good_dao::good_dao(){
	this->db = db_util::get_db_util()->get_db();
}



good_dao::~good_dao(){

}

void good_dao::query_list(std::list<goods*>* goods_list){
	odb::core::transaction tx(this->db->begin());
	odb::result<goods> r(this->db->query<goods>(odb::query<goods>::id>1));
	for (odb::result<goods>::iterator i(r.begin()); i != r.end(); ++i){
		goods *g = new goods;
		g->set_name(i->get_name());
		g->set_info(i->get_info());
		goods_list->push_back(g);
	}
}