///////////////////////////////////////////////////////////
//  brand_dao.h
//  Implementation of the Class brand_dao
//  Created on:      28-Ê®Ò»ÔÂ-2016 16:42:48
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_D6E7D6BF_5EF3_4c40_B449_7649CDE8268B__INCLUDED_)
#define EA_D6E7D6BF_5EF3_4c40_B449_7649CDE8268B__INCLUDED_

#include<memory>
#include<iostream>
#include<odb\database.hxx>
#include<odb\transaction.hxx>
#include"../odb/brand-odb.hxx"
#include"../entity/brand.h"
class brand_dao
{

public:
	brand_dao();
	virtual ~brand_dao();
public:void add_brand(brand&b, std::auto_ptr<odb::database> &db);
public:static brand_dao* get_brand_dao(){
	static brand_dao bd;
	return &bd;
}

public:void query(std::list<brand*> &brand_list, std::auto_ptr<odb::database>&db);

};
#endif // !defined(EA_D6E7D6BF_5EF3_4c40_B449_7649CDE8268B__INCLUDED_)
