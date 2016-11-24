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
#include"db_util.h"
#include"goods.h"
#include"good_file-odb.hxx"
#include"goods-odb.hxx"

class good_dao
{

public:
	good_dao();
	virtual ~good_dao();

private:std::auto_ptr<odb::database> db;
public:static good_dao* get_good_dao(){
	static good_dao dao;
	return &dao;
}

public: void query_list(std::list<goods*>* goods_list);

};
#endif // !defined(EA_8269055E_2BD2_4918_BC9F_3229ACE9CDFB__INCLUDED_)
