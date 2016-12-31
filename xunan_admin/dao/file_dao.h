///////////////////////////////////////////////////////////
//  file_dao.h
//  Implementation of the Class file_dao
//  Created on:      17-Ê®Ò»ÔÂ-2016 19:36:58
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_8CF62838_CD30_47ce_8653_68FC11C745C5__INCLUDED_)
#define EA_8CF62838_CD30_47ce_8653_68FC11C745C5__INCLUDED_
#include<memory>
#include<odb\database.hxx>
#include<odb\transaction.hxx>
#include<odb\mysql\database.hxx>
#include"../util/db_util.h"
#include"../entity/file.h"
#include"../odb/file-odb.hxx"
#include"base_dao.h"
class file_dao : public base_dao<file>
{

private:	
		file_dao();
public:
		virtual ~file_dao();
		static file_dao* get_file_dao(){
			static file_dao f_dao;
			return &f_dao;
		}
};
#endif
