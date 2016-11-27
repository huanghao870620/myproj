///////////////////////////////////////////////////////////
//  classification_service.h
//  Implementation of the Class classification_service
//  Created on:      27-Ê®Ò»ÔÂ-2016 19:06:11
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_BE459C55_A3DA_4d19_B83E_A5AAA5F874D9__INCLUDED_)
#define EA_BE459C55_A3DA_4d19_B83E_A5AAA5F874D9__INCLUDED_
#include<memory>
#include<iostream>
#include<odb\database.hxx>
#include<odb\transaction.hxx>
#include<odb\mysql\database.hxx>
#include"classification-odb.hxx"
#include"db_util.h"
#include"classification.h"
#include"classification_dao.h"

class classification_service
{

public:
	classification_service();
	virtual ~classification_service();
	private:std::auto_ptr<odb::database> db;
private:classification_dao*cd;
public:void add_classifi(classification&classifi);
public:void getParentClass(classification*classifi, long classid);

public:static classification_service*get_classification_service(){
	static classification_service cs;
	return &cs;
}
};
#endif // !defined(EA_BE459C55_A3DA_4d19_B83E_A5AAA5F874D9__INCLUDED_)
