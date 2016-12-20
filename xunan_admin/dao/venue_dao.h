///////////////////////////////////////////////////////////
//  venue_dao.h
//  Implementation of the Class venue_dao
//  Created on:      30-Ê®Ò»ÔÂ-2016 19:49:35
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_A4355CB0_0A19_4ba7_898A_A5057353845F__INCLUDED_)
#define EA_A4355CB0_0A19_4ba7_898A_A5057353845F__INCLUDED_
#include"../odb/venue-odb.hxx"

class venue_dao
{

public:
	venue_dao();
	virtual ~venue_dao();
public:static venue_dao* get_venue_dao(){
	static venue_dao vd;
	return &vd;
}

public:void add_venue(venue&v, std::auto_ptr<odb::database>&db);

};
#endif // !defined(EA_A4355CB0_0A19_4ba7_898A_A5057353845F__INCLUDED_)
