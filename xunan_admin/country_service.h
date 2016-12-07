///////////////////////////////////////////////////////////
//  country_service.h
//  Implementation of the Class country_service
//  Created on:      28-Ê®Ò»ÔÂ-2016 19:54:45
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_2F103C4D_B3CB_4d8b_B811_FA5CFEA165C1__INCLUDED_)
#define EA_2F103C4D_B3CB_4d8b_B811_FA5CFEA165C1__INCLUDED_
#include<memory>
#include<iostream>
#include<odb\database.hxx>
#include<odb\transaction.hxx>
#include<odb\mysql\database.hxx>
#include"country-odb.hxx"
#include"db_util.h"
#include"country.h"
#include"country_dao.h"


class country_service
{

public:
	country_service();
	virtual ~country_service();
//
private:std::auto_ptr<odb::database> db;
public:static country_service* get_country_service(){
	static country_service cs;
	return &cs;
}

private:country_dao*cd;
public:void add_country(country&c);
public:void query(std::list<country*>&c_list);

};
#endif // !defined(EA_2F103C4D_B3CB_4d8b_B811_FA5CFEA165C1__INCLUDED_)
