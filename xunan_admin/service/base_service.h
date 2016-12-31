///////////////////////////////////////////////////////////
//  base_service.h
//  Implementation of the Class base_service
//  Created on:      24-Ê®¶þÔÂ-2016 14:24:46
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_C1202C9A_C7AA_4828_BF1F_44BB41B048D0__INCLUDED_)
#define EA_C1202C9A_C7AA_4828_BF1F_44BB41B048D0__INCLUDED_
#include"../dao/base_dao.h"
template<class E, class D >
class base_service
{

public:
		E findById(long id){
				E &e=this->d->findById(id, this->db);
				return e;
		}

		void deleteById(long id){
			this->d->erase(this->d->findById(id, this->db), this->db);
		}

protected:
		D* d;
		std::auto_ptr<odb::database> db;
};
#endif // !defined(EA_C1202C9A_C7AA_4828_BF1F_44BB41B048D0__INCLUDED_)
