///////////////////////////////////////////////////////////
//  good_file_dao.cpp
//  Implementation of the Class good_file_dao
//  Created on:      22-Ê®Ò»ÔÂ-2016 20:43:00
//  Original author: admin
///////////////////////////////////////////////////////////

#include "good_file_dao.h"


good_file_dao::good_file_dao(){
}



good_file_dao::~good_file_dao(){

}

/*add good_file*/
void good_file_dao::add_good_file(good_file&gf, std::auto_ptr<odb::database> &db){
	db->persist(gf);
}

/**/
good_file good_file_dao::findGfByImgId(long img_id, std::auto_ptr<odb::database> &db){
	typedef odb::core::transaction tran;
	typedef odb::transaction t;
	tran *tx = NULL;
	if (!t::has_current()){
		tx = new tran(db->begin());
	}
	else
	{
		tx = &(t::current());
	}
	odb::result<good_file> r(db->query<good_file>(odb::query<good_file>::file_id==img_id));
	odb::result<good_file>::iterator i(r.begin());
	return *i;
}
