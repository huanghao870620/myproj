///////////////////////////////////////////////////////////
//  upload_type_dao.h
//  Implementation of the Class upload_type_dao
//  Created on:      05-Ê®¶þÔÂ-2016 14:41:17
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_384B436A_7231_4b80_A692_1A271DF916BA__INCLUDED_)
#define EA_384B436A_7231_4b80_A692_1A271DF916BA__INCLUDED_

#include<memory>
#include"upload_type.h"
#include"upload_type-odb.hxx"

class upload_type_dao
{

public:
	upload_type_dao();
	virtual ~upload_type_dao();
public:static upload_type_dao*get_upload_type_dao(){
	static upload_type_dao utd;
	return &utd;
}
public:void query(std::list<upload_type*>&ut_list, std::auto_ptr<odb::database>&db);
};
#endif // !defined(EA_384B436A_7231_4b80_A692_1A271DF916BA__INCLUDED_)
