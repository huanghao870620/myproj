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
			typedef odb::core::transaction tran;
			typedef odb::transaction t;
			
			tran *tx = NULL;
			try{
				if (!t::has_current()){
				tx=new tran(this->db->begin());
				}
				else
				{
					tx = &(t::current());
				}
				E &e=this->d->findById(id, this->db);
				//tx->commit();
				return e;
			}
			catch (odb::exception&e){
				std::cerr << e.what() << std::endl;
				tx->rollback();
			}
		}

protected:
		D* d;
		std::auto_ptr<odb::database> db;
};
#endif // !defined(EA_C1202C9A_C7AA_4828_BF1F_44BB41B048D0__INCLUDED_)
