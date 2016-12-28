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
	this->d= good_dao::get_good_dao();
}



good_service::~good_service(){

}

void good_service::update_good(goods&good){
	odb::core::transaction tx(db->begin());
	this->d->update(good, this->db);
	tx.commit();
}


void good_service::query_list(std::list<goods*>* goods_list){
	this->d->query_list(goods_list, this->db);
}


/*添加商品*/
void  good_service::add_good(
		std::string&name, 
		int selClass,
		std::string&info_str,
		long capl,
		std::string&dop,
		float lp,
		float hp,
		float real_price,
		std::string&purchPostion,
		std::string&addTime,
		std::string&thumbPath,/*缩略图路径*/
		std::string&advPath,
		upload_service*us,
		std::string&is_recom,
		file_service&fs,
		std::string& big1Path, // 大图1
		std::string& cut1_path // 切图1
	){

	

	goods good;
	tran *tx = NULL;
	tx = &(t::current());
	try{
		if (!t::has_current()){
		  tx = new tran(this->db->begin());
		}
		else{
			tx = &(t::current());
		}

	file adv_file;
	//us->upload_file_no_tran(adv_file, advPath.c_str(), 17);
	us->upload_file(adv_file, advPath.c_str(), 17);

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
	this->d->add(good,this->db);


	

	/*添加商品缩略图*/
	fs.add_good_file(thumbPath, good.get_id(), COMMODITY_THUMBNAIL);


	/*添加商品大图1*/
	//fs.add_good_file(big1Path, good.get_id(), GOOD_BIG_PHOTO);

	///*添加切图1*/
	//fs.add_good_file(cut1_path, good.get_id(), GOOD_CUT_PHOTO);
	/*if (t::)
	tx->commit();*/
	}
	catch (odb::exception&e){
		std::cout << e.what() << std::endl;
		tx->rollback();
	}
	
}



/*编辑商品*/
void  good_service::edit_good(std::string&name,
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
	file_service&fs,
	long big1_id,
	std::list<file_dto*> &big_list,
	long adv_pic_id
	){

	typedef odb::core::transaction tran;
	typedef odb::transaction t;
	goods good;
	tran *tx = NULL;
	try{
		if (!t::has_current()){
		 tx = new tran(this->db->begin());
		}
		else
		{
			tx = &(t::current());
		}

		file adv_file;
		//us->upload_file_no_tran(adv_file, advPath.c_str(), GOOD_ADV_PHOTO); //商品广告图
		if (adv_pic_id > 0){
			// 修改
			adv_file.set_id(adv_pic_id);
			us->upload_file(adv_file, advPath.c_str(), GOOD_ADV_PHOTO);
		}
		else{
			//添加
		us->upload_file(adv_file, advPath.c_str(), GOOD_ADV_PHOTO);
		}
		

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


		/*修改缩略图*/
		fs.update_and_upload_file(thumbFileId, thumbPath, COMMODITY_THUMBNAIL);

		good.set_id(goodId);
		this->d->update(good, this->db);
		t::current().commit();
	}
	catch (odb::exception&e){
		std::cout << e.what() << std::endl;
		t::current().rollback();
	}



}