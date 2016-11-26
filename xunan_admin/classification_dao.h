///////////////////////////////////////////////////////////
//  classification_dao.h
//  Implementation of the Class classification_dao
//  Created on:      18-ʮһ��-2016 11:04:54
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_FA146DB4_0BBA_414e_A8D2_49E24CC24013__INCLUDED_)
#define EA_FA146DB4_0BBA_414e_A8D2_49E24CC24013__INCLUDED_

#include<memory>
#include<iostream>
#include<odb\database.hxx>
#include<odb\transaction.hxx>
#include<odb\mysql\database.hxx>
#include"classification-odb.hxx"
#include"db_util.h"
#include"classification.h"

class classification_dao
{


private:classification_dao();
public:	virtual ~classification_dao();
private:std::auto_ptr<odb::database> db;
public:static classification_dao* get_classification_dao(){
	static classification_dao dao;
	return &dao;
}
public:void add_classifi(classification&classifi);
public:void getParentClass(classification*classifi,long classid);
};
#endif // !defined(EA_FA146DB4_0BBA_414e_A8D2_49E24CC24013__INCLUDED_)