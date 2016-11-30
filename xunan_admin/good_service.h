///////////////////////////////////////////////////////////
//  good_service.h
//  Implementation of the Class good_service
//  Created on:      27-Ê®Ò»ÔÂ-2016 17:05:26
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_959D68BD_06AA_466f_B7A8_557E08D212AF__INCLUDED_)
#define EA_959D68BD_06AA_466f_B7A8_557E08D212AF__INCLUDED_

#include<memory>
#include<iostream>
#include<odb\database.hxx>
#include<odb\transaction.hxx>
#include<odb\mysql\database.hxx>
#include"db_util.h"
#include"goods.h"
#include"good_dao.h"
#include"file.h"
#include"good_file-odb.hxx"
#include"goods-odb.hxx"

class upload_service;
class good_service
{

public:
	good_service();
	virtual ~good_service();
private:std::auto_ptr<odb::database> db;
public:static good_service* get_good_service(){
	static good_service gs;
	return &gs;
}

private:good_dao*gd;

public: void query_list(std::list<goods*>* goods_list);
public:void findById(goods*good, long id);
public:void update_good(goods&good);
public:void  add_good(std::string&name, 
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
	std::string&advPath,
	upload_service*us,
	goods&good);

};
#endif // !defined(EA_959D68BD_06AA_466f_B7A8_557E08D212AF__INCLUDED_)
