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


/*�����Ʒ*/
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
		std::string&thumbPath,/*����ͼ·��*/
		std::string&advPath,
		upload_service*us,
		std::string&is_recom,
		file_service&fs,
		std::string& big1Path, // ��ͼ1
		std::string& cut1_path // ��ͼ1
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
	this->d->add(good,this->db);


	

	/*�����Ʒ����ͼ*/
	fs.add_good_file(thumbPath, good.get_id(), COMMODITY_THUMBNAIL);


	/*�����Ʒ��ͼ1*/
	//fs.add_good_file(big1Path, good.get_id(), GOOD_BIG_PHOTO);

	///*�����ͼ1*/
	//fs.add_good_file(cut1_path, good.get_id(), GOOD_CUT_PHOTO);
	/*if (t::)
	tx->commit();*/
	}
	catch (odb::exception&e){
		std::cout << e.what() << std::endl;
		tx->rollback();
	}
	
}



/*�༭��Ʒ*/
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
		//us->upload_file_no_tran(adv_file, advPath.c_str(), GOOD_ADV_PHOTO); //��Ʒ���ͼ
		if (adv_pic_id > 0){
			// �޸�
			adv_file.set_id(adv_pic_id);
			us->upload_file(adv_file, advPath.c_str(), GOOD_ADV_PHOTO);
		}
		else{
			//���
		us->upload_file(adv_file, advPath.c_str(), GOOD_ADV_PHOTO);
		}
		

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


		/*�޸�����ͼ*/
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