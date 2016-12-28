///////////////////////////////////////////////////////////
//  good_file_dao.h
//  Implementation of the Class good_file_dao
//  Created on:      22-Ê®Ò»ÔÂ-2016 20:43:00
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_33C8784F_4A1E_4073_8EA1_3621CFE523DA__INCLUDED_)
#define EA_33C8784F_4A1E_4073_8EA1_3621CFE523DA__INCLUDED_


#include<memory>
#include<iostream>
#include<odb\database.hxx>
#include<odb\transaction.hxx>
#include<odb\mysql\database.hxx>
#include"../odb/good_file-odb.hxx"
#include"../util/db_util.h"
#include"../entity/good_file.h"
#include"file_dao.h"
#include"base_dao.h"

class good_file_dao : public base_dao<good_file>
{

private:
	good_file_dao();
public:
	virtual ~good_file_dao();
	static good_file_dao* get_good_file_dao(){
		static good_file_dao dao;
		return &dao;
	}
	void add_good_file(good_file&gf, std::auto_ptr<odb::database> &db);
	void findFileByGoodId(long goodId, long type_id_, std::list<file*> *fs, std::auto_ptr<odb::database> &db);
	good_file findGfByImgId(long img_id, std::auto_ptr<odb::database> &db);
};
#endif // !defined(EA_33C8784F_4A1E_4073_8EA1_3621CFE523DA__INCLUDED_)
