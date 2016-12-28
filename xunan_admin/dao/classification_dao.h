///////////////////////////////////////////////////////////
//  classification_dao.h
//  Implementation of the Class classification_dao
//  Created on:      18-Ê®Ò»ÔÂ-2016 11:04:54
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_FA146DB4_0BBA_414e_A8D2_49E24CC24013__INCLUDED_)
#define EA_FA146DB4_0BBA_414e_A8D2_49E24CC24013__INCLUDED_

#include<memory>
#include<iostream>
#include<odb\database.hxx>
#include<odb\transaction.hxx>
#include<odb\mysql\database.hxx>
#include"../odb/classification-odb.hxx"
#include"../util/db_util.h"
#include"../entity/classification.h"
#include"base_dao.h"

class classification_dao : public base_dao<classification>
{


private:classification_dao();
public:	virtual ~classification_dao();

public:static classification_dao* get_classification_dao(){
	static classification_dao dao;
	return &dao;
}
public:void add_classifi(classification&classifi, std::auto_ptr<odb::database> &db);
public:void getParentClass(classification*classifi, long classid, std::auto_ptr<odb::database> &db);
public:void query_class_bypid(std::list<classification*>*child_class, long pid, std::auto_ptr<odb::database> &db);
};
#endif // !defined(EA_FA146DB4_0BBA_414e_A8D2_49E24CC24013__INCLUDED_)
