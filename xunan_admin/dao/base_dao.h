///////////////////////////////////////////////////////////
//  base_dao.h
//  Implementation of the Class base_dao
//  Created on:      24-Ê®¶þÔÂ-2016 14:33:51
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_0533E1BE_F9D0_4f49_9399_D9CF2D4F7959__INCLUDED_)
#define EA_0533E1BE_F9D0_4f49_9399_D9CF2D4F7959__INCLUDED_
#include<memory>
#include<odb\database.hxx>
#include<odb\transaction.hxx>
#include<odb\mysql\database.hxx>
#include<odb\core.hxx>
template<class T>
class base_dao
{

public:
	T findById(long id, std::auto_ptr<odb::database> &db){
		typedef odb::result<T> result;
		result r(db->query<T>(odb::query<T>::id == id));
		result::iterator i(r.begin());
		return *i;
	}

	void edit(T e, std::auto_ptr<odb::database>&db){
		db->update(e);
	}

	void add(T e, std::auto_ptr<odb::database>&db){
		db->persist(e);
	}

	void update(T e, std::auto_ptr<odb::database>&db){
		db->update(e);
	}

	void erase(T e, std::auto_ptr<odb::database>&db){
		db->erase(e);
	}
};
#endif // !defined(EA_0533E1BE_F9D0_4f49_9399_D9CF2D4F7959__INCLUDED_)
