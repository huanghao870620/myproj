///////////////////////////////////////////////////////////
//  db_util.h
//  Implementation of the Class db_util
//  Created on:      17-ʮһ��-2016 19:26:05
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_22F90774_10D6_44ee_B259_2846B0A686DB__INCLUDED_)
#define EA_22F90774_10D6_44ee_B259_2846B0A686DB__INCLUDED_

#include<memory>
#include<odb\database.hxx>
#include<odb\transaction.hxx>
#include<odb\mysql\database.hxx>

#include<iostream>
class db_util
{


private:db_util();
	virtual ~db_util();
	 std::auto_ptr<odb::database> *db =nullptr;
//public:static std::auto_ptr<odb::database>* get_db(){
//	static std::auto_ptr<odb::database> db(
//		new odb::mysql::database("root", "xa", "test", "192.168.1.102", 3306, "", "utf8")
//		);
//	return &db;
//}
public: std::auto_ptr<odb::database> get_db(){
	return *db;
}
public:static db_util* get_db_util(){
	static db_util *util=nullptr;
	util = new db_util;
	return util;
}
};
#endif // !defined(EA_22F90774_10D6_44ee_B259_2846B0A686DB__INCLUDED_)