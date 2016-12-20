///////////////////////////////////////////////////////////
//  upload_type_service.h
//  Implementation of the Class upload_type_service
//  Created on:      05-Ê®¶þÔÂ-2016 14:41:18
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_834BF6D1_2FA6_43cf_A409_571CF29E296D__INCLUDED_)
#define EA_834BF6D1_2FA6_43cf_A409_571CF29E296D__INCLUDED_
#include<list>
#include<memory>
#include<iostream>
#include"../entity/upload_type.h"
#include"../dao/upload_type_dao.h"
#include"../util/db_util.h"
class upload_type_service
{

public:
	upload_type_service();
	virtual ~upload_type_service();
public:static upload_type_service*get_upload_type_service(){
	static upload_type_service uts;
	return&uts;
}
private:std::auto_ptr<odb::database> db;
private:upload_type_dao*utd;
public:void query(std::list<upload_type*>&ut_list);
};
#endif // !defined(EA_834BF6D1_2FA6_43cf_A409_571CF29E296D__INCLUDED_)
