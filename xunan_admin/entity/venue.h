///////////////////////////////////////////////////////////
//  venue.h
//  Implementation of the Class venue
//  Created on:      30-十一月-2016 19:44:32
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_A8B218BF_99D4_4081_A153_784777FCA827__INCLUDED_)
#define EA_A8B218BF_99D4_4081_A153_784777FCA827__INCLUDED_
#include<memory>
#include<iostream>
#include<odb\database.hxx>
#include<odb\transaction.hxx>
#include<odb\mysql\database.hxx>
#include<odb\core.hxx>
/**
 * 会场
 */
#pragma  db object
class venue
{

public:
	venue();
	virtual ~venue();
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
private:long adv_pic_;
public:void set_adv_pic(long adv_pic){
	this->adv_pic_ = adv_pic;
}
public:long get_adv_pic(){
	return this->adv_pic_;
}
};
#endif // !defined(EA_A8B218BF_99D4_4081_A153_784777FCA827__INCLUDED_)
