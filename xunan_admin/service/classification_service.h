///////////////////////////////////////////////////////////
//  classification_service.h
//  Implementation of the Class classification_service
//  Created on:      27-十一月-2016 19:06:11
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_BE459C55_A3DA_4d19_B83E_A5AAA5F874D9__INCLUDED_)
#define EA_BE459C55_A3DA_4d19_B83E_A5AAA5F874D9__INCLUDED_
#include<memory>
#include<iostream>
#include<odb\database.hxx>
#include<odb\transaction.hxx>
#include<odb\mysql\database.hxx>
#include"../odb/classification-odb.hxx"
#include"../util/db_util.h"
#include"../entity/classification.h"
#include"../dao/classification_dao.h"
#include"../dao/file_dao.h"
#include"base_service.h"

class classification_service : public base_service<classification,classification_dao>
{

public:
	classification_service();
	virtual ~classification_service();
private:file_dao*fd;
public:void add_classifi(classification&classifi);
public:void getParentClass(classification*classifi, long classid);
public:void query_class_bypid(std::list<classification*>*child_class, long pid);
public:void query_classification(std::list<classification*>*class_list);/*获取一级分类*/
public:static classification_service*get_classification_service(){
	static classification_service cs;
	return &cs;
}
};
#endif // !defined(EA_BE459C55_A3DA_4d19_B83E_A5AAA5F874D9__INCLUDED_)
