///////////////////////////////////////////////////////////
//  good_service.cpp
//  Implementation of the Class good_service
//  Created on:      27-ʮһ��-2016 17:05:26
//  Original author: admin
///////////////////////////////////////////////////////////

#include "good_service.h"


good_service::good_service(){
	this->db = db_util::get_db_util()->get_db();
	this->gd= good_dao::get_good_dao();
}



good_service::~good_service(){

}

void good_service::update_good(goods&good){
	odb::core::transaction tx(db->begin());
	this->gd->update(good, this->db);
	tx.commit();
}


void good_service::query_list(std::list<goods*>* goods_list){
	this->gd->query_list(goods_list, this->db);
}

void good_service::findById(goods*good, long id){
	this->gd->findById(good, id, this->db);
}


void  good_service::add_good(std::string&name, 
	int selClass,
	std::string&info_str,
	long capl,
	std::string&dop,
	long lp,
	long hp,
	std::string&purchPostion,
	std::string&addTime,
	long goodId,
	long thumbFileId,
	std::string&thumbPath,
	goods&good){
	
	good.set_name(name);
	good.set_classid(selClass);
	good.set_info(info_str);//����
	good.set_capacity(capl);//����
	good.set_date_of_production(dop);//��������
	good.set_lowest_price(lp);//��ͼ�
	good.set_highestPrice(hp);//��߼�
	good.set_purchasing_position(purchPostion);//�ɹ�λ��
	good.set_addTime(addTime);//ʱ���

	good.set_left_photo(2);//�����ͼ
	good.set_expressSingle(2);
	good.set_goodsAccordingToPositive(2);
	good.set_goodsInvoice(2);
	good.set_right_photo(2);//�Ҳ���ͼ

	if (goodId > 0){ /*�޸���Ʒ*/
		good.set_id(goodId);
		this->gd->update(good, this->db);
	}
	else{ /*�����Ʒ*/
		this->gd->add(good,this->db);
	}



	
}