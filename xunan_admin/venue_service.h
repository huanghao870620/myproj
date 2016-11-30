///////////////////////////////////////////////////////////
//  venue_service.h
//  Implementation of the Class venue_service
//  Created on:      30-Ê®Ò»ÔÂ-2016 19:49:37
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_BE32F681_210A_41dc_9711_C96AC691D060__INCLUDED_)
#define EA_BE32F681_210A_41dc_9711_C96AC691D060__INCLUDED_
#include<memory>
#include"venue-odb.hxx"
#include"db_util.h"
#include"venue_dao.h"

class upload_service;
class venue_service
{

public:
	venue_service();
	virtual ~venue_service();
private:std::auto_ptr<odb::database> db;
public:void add_venue(std::string&name, std::string&adv_pic_path, upload_service*us);
public:static venue_service*get_venue_service(){
	static venue_service vs;
	return &vs;
}

private:venue_dao*vd;
};
#endif // !defined(EA_BE32F681_210A_41dc_9711_C96AC691D060__INCLUDED_)
