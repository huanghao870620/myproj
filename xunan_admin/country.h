///////////////////////////////////////////////////////////
//  country.h
//  Implementation of the Class country
//  Created on:      28-十一月-2016 19:54:43
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_A8AE8FC2_1C1F_4003_886F_87E8948CDE7D__INCLUDED_)
#define EA_A8AE8FC2_1C1F_4003_886F_87E8948CDE7D__INCLUDED_

#include<memory>
#include<iostream>
#include<odb\database.hxx>
#include<odb\transaction.hxx>
#include<odb\mysql\database.hxx>
#include<odb\core.hxx>

/**
 * 国家
 */
#pragma db object
class country
{

public:
	country();
	virtual ~country();
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
public:void set_name(std::string &name){
	this->name_ = name;
}
public:std::string&get_name(){
	return this->name_;
}

private:long img_id_;
public:void set_img_id(long img_id){
	this->img_id_ = img_id;
}
public:long get_img_id(){
	return this->img_id_;
}

private:std::string country_code_;
public:void set_country_code(std::string&country_code){
	this->country_code_ = country_code;
}
public:std::string& get_country_code(){
	return this->country_code_;
}

};
#endif // !defined(EA_A8AE8FC2_1C1F_4003_886F_87E8948CDE7D__INCLUDED_)
