///////////////////////////////////////////////////////////
//  classification.h
//  Implementation of the Class classification
//  Created on:      16-十一月-2016 15:48:49
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_B987B51F_CCC9_4df5_B17D_7C2704A024FD__INCLUDED_)
#define EA_B987B51F_CCC9_4df5_B17D_7C2704A024FD__INCLUDED_

#include<memory>
#include<iostream>
#include<odb\database.hxx>
#include<odb\transaction.hxx>
//#include<odb\mysql\database.hxx>
#include<odb\core.hxx>

/**
 * 分类
 */

#pragma db object
class classification
{

public:
	classification();
	virtual ~classification();
private:friend class odb::access;
#pragma db id auto
private:unsigned long id_;
private:std::string name_;
private:long pid_;
private:unsigned long img_id_;
public:void set_id(long id){
	this->id_ = id;
}
public:unsigned long get_id(){
	return this->id_;
}
public:void set_name(std::string&name){
	this->name_ = name;
}
public:std::string&get_name(){
	return this->name_;
}
public:void set_pid(long pid){
	this->pid_ = pid;
}
public:long get_pid(){
	return this->pid_;
}
public:void set_img_id(unsigned long img_id){
	this->img_id_ = img_id;
}
public:unsigned long get_img_id(){
	return this->img_id_;
}
};
#endif // !defined(EA_B987B51F_CCC9_4df5_B17D_7C2704A024FD__INCLUDED_)
