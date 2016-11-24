///////////////////////////////////////////////////////////
//  customer.h
//  Implementation of the Class customer
//  Created on:      08-Ê®Ò»ÔÂ-2016 10:21:23
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_C6FD291C_145B_4459_B21C_1EBBE580FB99__INCLUDED_)
#define EA_C6FD291C_145B_4459_B21C_1EBBE580FB99__INCLUDED_
#include<string>

#include <memory>   // std::auto_ptr
#include <iostream>
#include <odb/database.hxx>
#include <odb/transaction.hxx>

//#include "database.hxx" // create_database
#include<odb/mysql/database.hxx>

#include<odb\core.hxx>
#pragma db object
class customer
{

public:
	customer();
	virtual ~customer();


private: friend class odb::access;
#pragma db id auto
private: unsigned long id_;

#pragma db get(mobile_) set(mobile_)
private:std::string mobile_;
public: void set_mobile(std::string& mobile){
			this->mobile_ = mobile;
}
public:std::string& get_mobile(){
		   return this->mobile_;
}
//public:const std::string& name() const;
//public:void name(const std::string&);
//public:std::string& get_name();

	  

	   /*const std::string&
		   getName() const
	   {
			   return this->name_;
		   }

	   std::string&
		   setName()
	   {
			   return this->name_;
		   }*/

//private: long id;

//#pragma db get(id) set(id)
//#pragma db id
//private:long id;
//#pragma db object(customer)
}; 
//#pragma db member(customer::name_) id
#endif // !defined(EA_C6FD291C_145B_4459_B21C_1EBBE580FB99__INCLUDED_)
