///////////////////////////////////////////////////////////
//  upload_type.h
//  Implementation of the Class upload_type
//  Created on:      05-Ê®¶þÔÂ-2016 14:41:15
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_70D53E7B_D47B_436e_8669_CF999C941760__INCLUDED_)
#define EA_70D53E7B_D47B_436e_8669_CF999C941760__INCLUDED_
#include<memory>
#include<odb\database.hxx>
#include<odb\transaction.hxx>
#include<odb\core.hxx>
//#include<odb\mysql\database.hxx>
//#include"uplo"
#include<iostream>

#pragma db object
class upload_type
{

public:
	upload_type();
	virtual ~upload_type();
private:friend class odb::access;
#pragma db id auto
private:unsigned long id_;
public:void set_id(long id){
	this->id_ = id;
}
public:long get_id(){
	return this->id_;
}
private:std::string name_;
public:void set_name(std::string&name){
	this->name_ = name;	
}
public:std::string&get_name(){
	return this->name_;
}

};
#endif // !defined(EA_70D53E7B_D47B_436e_8669_CF999C941760__INCLUDED_)
