///////////////////////////////////////////////////////////
//  country_dao.h
//  Implementation of the Class country_dao
//  Created on:      28-ʮһ��-2016 19:54:44
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_5ED24531_09DB_42da_A55E_F3481F1DA5C0__INCLUDED_)
#define EA_5ED24531_09DB_42da_A55E_F3481F1DA5C0__INCLUDED_
#include"../entity/country.h"
#include"../odb/country-odb.hxx"
#include"base_dao.h"
class country_dao : public base_dao<country>
{

public:
	country_dao();
	virtual ~country_dao();
public:
	static country_dao* get_country_dao(){
		static country_dao cd;
		return&cd;
	}

public:
	void add_country(country&c, std::auto_ptr<odb::database> &db);
	void query(std::list<country*>&country_list, std::auto_ptr<odb::database>&db);

};
#endif // !defined(EA_5ED24531_09DB_42da_A55E_F3481F1DA5C0__INCLUDED_)
