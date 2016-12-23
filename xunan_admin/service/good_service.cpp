///////////////////////////////////////////////////////////
//  good_service.cpp
//  Implementation of the Class good_service
//  Created on:      27-ʮһ��-2016 17:05:26
//  Original author: admin
///////////////////////////////////////////////////////////

#include"upload_service.h"
#include "good_service.h"

//
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
	float lp,
	float hp,
	float real_price,
	std::string&purchPostion,
	std::string&addTime,
	long goodId,
	long thumbFileId,
	std::string&thumbPath,
	std::string&advPath,
	upload_service*us,
	std::string&is_recom,
	goods&good){
	
	try{
	odb::core::transaction tx(this->db->begin());

	file adv_file;
	us->upload_file_no_tran(adv_file, advPath.c_str(), 17);

	good.set_name(name);
	good.set_classid(selClass);//����
	good.set_info(info_str);//����
	good.set_capacity(capl);//����
	good.set_date_of_production(dop);//��������
	good.set_lowest_price(lp);//��ͼ�
	good.set_highestPrice(hp);//��߼�
	good.set_price(real_price);//ʵ�ʼ۸�
	good.set_purchasing_position(purchPostion);//�ɹ�λ��
	good.set_addTime(addTime);//ʱ���

	good.set_left_photo(2);//�����ͼ
	good.set_expressSingle(2);
	good.set_goodsAccordingToPositive(2);
	good.set_goodsInvoice(2);
	good.set_right_photo(2);//�Ҳ���ͼ
	good.set_adv_pic(adv_file.get_id());//���ͼ

	int reco = -1;/*�Ƽ�*/
	if ("��" == is_recom){
		reco = 1;
	}
	else if ("" == is_recom){
		reco = 0;
	}
	//good.set_is_recommended(reco);

	if (goodId > 0){ /*�޸���Ʒ*/
		good.set_id(goodId);
		this->gd->update(good, this->db);
	}
	else{ /*�����Ʒ*/
		this->gd->add(good,this->db);
	}
	tx.commit();
	}
	catch (odb::exception&e){
		std::cout << e.what() << std::endl;
	}


	
}