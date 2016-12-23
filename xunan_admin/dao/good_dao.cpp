///////////////////////////////////////////////////////////
//  good_dao.cpp
//  Implementation of the Class good_dao
//  Created on:      23-十一月-2016 20:53:55
//  Original author: admin
///////////////////////////////////////////////////////////

#include "good_dao.h"


good_dao::good_dao(){
	this->db = db_util::get_db_util()->get_db();
}



good_dao::~good_dao(){

}

void good_dao::query_list(std::list<goods*>* goods_list, std::auto_ptr<odb::database> &db){
	odb::core::transaction tx(db->begin());
	odb::result<goods> r(db->query<goods>(odb::query<goods>::id>1));
	for (odb::result<goods>::iterator i(r.begin()); i != r.end(); ++i){
		goods *g = new goods;
		g->set_id(i->get_id());
		g->set_name(i->get_name());
		g->set_info(i->get_info());
		goods_list->push_back(g);
	}
	
}

/*通过id获取商品*/
void good_dao::findById(goods*good, long id, std::auto_ptr<odb::database> &db){
	odb::core::transaction tx(db->begin());
	odb::result<goods> r(db->query<goods>(odb::query<goods>::id == id));
	odb::result<goods>::iterator i(r.begin());
	good->set_id(i->get_id());
	good->set_name(i->get_name());
	good->set_info(i->get_info());
	good->set_capacity(i->get_capacity());
	good->set_lowest_price(i->get_lowest_price());
	good->set_highestPrice(i->get_highest_price());
	good->set_purchasing_position(i->get_purchasing_position());
	good->set_classid(i->get_classid());
}

/*修改商品信息*/
void good_dao::update(goods&good, std::auto_ptr<odb::database> &db){
	db->update(good);
}

/*添加商品*/
void good_dao::add(goods&good, std::auto_ptr<odb::database>&db){
	db->persist(good);
}