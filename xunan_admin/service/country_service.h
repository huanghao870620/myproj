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
#include"../odb/country-odb.hxx"
#include"../util/db_util.h"
#include"../entity/country.h"
#include"../entity/file.h"
#include"../dao/country_dao.h"
#include"base_service.h"
#include"upload_service.h"


class country_service : public base_service<country, country_dao>
{
public:
		typedef  odb::core::transaction tran;
		typedef odb::transaction t;
		country_service();
		virtual ~country_service();

		static country_service* get_country_service(){
			static country_service cs;
			return &cs;
		}

		void add_country(country&c);
		void edit_country(long id,
			std::string&name, 
			std::string&country_code,
			std::string&img_path,
			upload_service&us);
		void query(std::list<country*>&c_list);

private:
		//country_dao*cd;
};
#endif // !defined(EA_2F103C4D_B3CB_4d8b_B811_FA5CFEA165C1__INCLUDED_)
