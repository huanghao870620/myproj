///////////////////////////////////////////////////////////
//  good_file_service.h
//  Implementation of the Class good_file_service
//  Created on:      27-Ê®Ò»ÔÂ-2016 18:06:24
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_29993B0C_5AB6_49d6_9E60_6AF332447A15__INCLUDED_)
#define EA_29993B0C_5AB6_49d6_9E60_6AF332447A15__INCLUDED_

#include<memory>
#include<iostream>
#include<odb\database.hxx>
#include<odb\transaction.hxx>
#include<odb\mysql\database.hxx>
#include"../util/db_util.h"
#include"../entity/goods.h"
#include"../entity/file.h"
#include"../dao/file_dao.h"
#include"../dao/good_file_dao.h"
#include"../odb/good_file-odb.hxx"
#include"../odb/goods-odb.hxx"


class good_file_service
{

public:
	good_file_service();
	virtual ~good_file_service();
private:std::auto_ptr<odb::database> db;
private:good_file_dao*gfd;
public:static good_file_service* get_good_file_service(){
	static good_file_service gfs;
	return &gfs;
}
private:file_dao*fd;
public:void add_good_file(good_file&gf);
public:void findFileByGoodId(long goodId, long type_id_, std::list<file*> *fs);
};
#endif // !defined(EA_29993B0C_5AB6_49d6_9E60_6AF332447A15__INCLUDED_)
