///////////////////////////////////////////////////////////
//  good_dao.cpp
//  Implementation of the Class good_dao
//  Created on:      23-ʮһ��-2016 20:53:55
//  Original author: admin
///////////////////////////////////////////////////////////

#include "good_dao.h"


good_dao::good_dao(){
	this->db = db_util::get_db_util()->get_db();
}



good_dao::~good_dao(){

}

void good_dao::query_list(std::list<goods*>* goods_list, std::auto_ptr<odb::database> &db){
	typedef odb::core::transaction tran;
	typedef odb::transaction t;
	tran *tx = NULL;
	if (!t::has_current()){
	 	tx = new tran(db->begin());
	}
	odb::result<goods> r(db->query<goods>(odb::query<goods>::id>1));
	for (odb::result<goods>::iterator i(r.begin()); i != r.end(); ++i){
		goods *g = new goods;
		g->set_id(i->get_id());
		g->set_name(i->get_name());
		g->set_info(i->get_info());
		goods_list->push_back(g);
	}
	
}



/*�޸���Ʒ��Ϣ*/
void good_dao::update(goods&good, std::auto_ptr<odb::database> &db){
	db->update(good);
}

/*�����Ʒ*/
void good_dao::add(goods&good, std::auto_ptr<odb::database>&db){
	db->persist(good);
}