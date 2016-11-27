///////////////////////////////////////////////////////////
//  file_service.h
//  Implementation of the Class file_service
//  Created on:      27-Ê®Ò»ÔÂ-2016 17:30:07
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_FFC473C9_FFCF_4478_B7B8_3CE0DA4B2214__INCLUDED_)
#define EA_FFC473C9_FFCF_4478_B7B8_3CE0DA4B2214__INCLUDED_

#include<memory>
#include<odb\database.hxx>
#include<odb\transaction.hxx>
#include<odb\mysql\database.hxx>
#include"db_util.h"
#include"file.h"
#include"file-odb.hxx"
#include"file_dao.h"
class file_service
{

public:
	file_service();
	virtual ~file_service();

private:std::auto_ptr<odb::database> db;

public:static file_service* get_file_service(){
	static file_service fs;
	return &fs;
}

private: file_dao *fd;

public:void findById(long id,file*f);
public:void add_file(file&f);
public:void update_file(file&f);
};
#endif // !defined(EA_FFC473C9_FFCF_4478_B7B8_3CE0DA4B2214__INCLUDED_)
