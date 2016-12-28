///////////////////////////////////////////////////////////
//  good_service.h
//  Implementation of the Class good_service
//  Created on:      27-十一月-2016 17:05:26
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_959D68BD_06AA_466f_B7A8_557E08D212AF__INCLUDED_)
#define EA_959D68BD_06AA_466f_B7A8_557E08D212AF__INCLUDED_

#include<memory>
#include<iostream>
#include<odb\database.hxx>
#include<odb\transaction.hxx>
#include<odb\mysql\database.hxx>
#include"../util/db_util.h"
#include"../entity/goods.h"
#include"../dao/good_dao.h"
#include"../entity/file.h"
#include"../odb/good_file-odb.hxx"
#include"../odb/goods-odb.hxx"
#include"base_service.h"
#include"file_service.h"
#include"../util/file_type_enum.h"
#include"../dto/file_dto.h"

//enum photo_type;
class upload_service;
typedef odb::core::transaction tran;
typedef odb::transaction t;
class good_service : public base_service<goods,good_dao>
{

public:
	good_service();
	virtual ~good_service();
	static good_service* get_good_service(){
		static good_service gs;
		return &gs;
	}

	void query_list(std::list<goods*>* goods_list);
	void update_good(goods&good);

	void  add_good(
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
			std::string&thumbPath,
			std::string&advPath,
			upload_service*us,
			std::string&is_recom,
			file_service&fs,
			std::string& big1Path, // 大图1
			std::string& cut1_path_str // 切图1
			
	);

	void  edit_good(
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
		);

};
#endif // !defined(EA_959D68BD_06AA_466f_B7A8_557E08D212AF__INCLUDED_)
