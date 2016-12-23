///////////////////////////////////////////////////////////
//  good_service.cpp
//  Implementation of the Class good_service
//  Created on:      27-十一月-2016 17:05:26
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
	good.set_classid(selClass);//分类
	good.set_info(info_str);//描述
	good.set_capacity(capl);//容量
	good.set_date_of_production(dop);//生产日期
	good.set_lowest_price(lp);//最低价
	good.set_highestPrice(hp);//最高价
	good.set_price(real_price);//实际价格
	good.set_purchasing_position(purchPostion);//采购位置
	good.set_addTime(addTime);//时间戳

	good.set_left_photo(2);//左侧视图
	good.set_expressSingle(2);
	good.set_goodsAccordingToPositive(2);
	good.set_goodsInvoice(2);
	good.set_right_photo(2);//右侧视图
	good.set_adv_pic(adv_file.get_id());//广告图

	int reco = -1;/*推荐*/
	if ("是" == is_recom){
		reco = 1;
	}
	else if ("" == is_recom){
		reco = 0;
	}
	//good.set_is_recommended(reco);

	if (goodId > 0){ /*修改商品*/
		good.set_id(goodId);
		this->gd->update(good, this->db);
	}
	else{ /*添加商品*/
		this->gd->add(good,this->db);
	}
	tx.commit();
	}
	catch (odb::exception&e){
		std::cout << e.what() << std::endl;
	}


	
}