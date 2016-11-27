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
#include"good_file-odb.hxx"
#include"goods-odb.hxx"

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

};
#endif // !defined(EA_959D68BD_06AA_466f_B7A8_557E08D212AF__INCLUDED_)
