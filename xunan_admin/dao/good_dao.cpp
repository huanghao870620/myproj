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

std::list<goods>  good_dao::query_list(std::auto_ptr<odb::database> &db){
	std::list<goods> goods_list;
	odb::result<goods> r(db->query<goods>(odb::query<goods>::id>1));
	for (odb::result<goods>::iterator i(r.begin()); i != r.end(); ++i){
		goods_list.push_back(*i);
	}
	return goods_list;
}



/*修改商品信息*/
void good_dao::update(goods&good, std::auto_ptr<odb::database> &db){
	db->update(good);
}

/*添加商品*/
void good_dao::add(goods&good, std::auto_ptr<odb::database>&db){
	db->persist(good);
}