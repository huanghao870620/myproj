///////////////////////////////////////////////////////////
//  brand_service.h
//  Implementation of the Class brand_service
//  Created on:      28-十一月-2016 16:42:50
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_4D7ABAE8_A099_454e_AC35_EC386B3C430A__INCLUDED_)
#define EA_4D7ABAE8_A099_454e_AC35_EC386B3C430A__INCLUDED_
#include<memory>
#include<iostream>
#include<odb\database.hxx>
#include<odb\transaction.hxx>
#include<odb\mysql\database.hxx>
#include"../odb/brand-odb.hxx"
#include"../util/db_util.h"
#include"../entity/brand.h"
#include"../dao/brand_dao.h"

class brand_service
{

public:
	brand_service();
	virtual ~brand_service();
private:std::auto_ptr<odb::database> db;
private:brand_dao*bd;
public:static brand_service* get_brand_service(){
	static brand_service bs;
	return &bs;
}
public:void add_brand(brand&b);

public:void get_brands(std::list<brand*> &brand_list);/*获取所有品牌*/

};
#endif // !defined(EA_4D7ABAE8_A099_454e_AC35_EC386B3C430A__INCLUDED_)
