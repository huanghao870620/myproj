///////////////////////////////////////////////////////////
//  good_dao.h
//  Implementation of the Class good_dao
//  Created on:      23-Ê®Ò»ÔÂ-2016 20:53:54
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_8269055E_2BD2_4918_BC9F_3229ACE9CDFB__INCLUDED_)
#define EA_8269055E_2BD2_4918_BC9F_3229ACE9CDFB__INCLUDED_

#include<memory>
#include<iostream>
#include<odb\database.hxx>
#include<odb\transaction.hxx>
#include<odb\mysql\database.hxx>
#include"../util/db_util.h"
#include"../entity/goods.h"
#include"../odb/good_file-odb.hxx"
#include"../odb/goods-odb.hxx"
#include"base_dao.h"

class good_dao : public base_dao<goods>
{

public:
	good_dao();
	virtual ~good_dao();

	static good_dao* get_good_dao(){
		static good_dao dao;
		return &dao;
	}

	std::list<goods> query_list(std::auto_ptr<odb::database> &db);
	void update(goods&good, std::auto_ptr<odb::database> &db);
	void add(goods&good, std::auto_ptr<odb::database>&db);
	typedef odb::core::transaction tran;

private:
	std::auto_ptr<odb::database> db;
};
#endif // !defined(EA_8269055E_2BD2_4918_BC9F_3229ACE9CDFB__INCLUDED_)
