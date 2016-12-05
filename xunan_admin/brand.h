///////////////////////////////////////////////////////////
//  brand.h
//  Implementation of the Class brand
//  Created on:      28-十一月-2016 16:39:35
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_CD242B00_54EA_4b71_9F64_E34AFDA4EF5F__INCLUDED_)
#define EA_CD242B00_54EA_4b71_9F64_E34AFDA4EF5F__INCLUDED_
#include<memory>
#include<iostream>
#include<odb\database.hxx>
#include<odb\transaction.hxx>
//#include<odb\mysql\database.hxx>
#include<odb\core.hxx>
/**
 * 品牌
 */
#pragma db object
class brand
{

public:
	brand();
	virtual ~brand();
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
private:long img_id_;
public:void set_img_id(long img_id){
	this->img_id_ = img_id;
}
public:long get_img_id(){
	return this->img_id_;
}
private:int is_recommended_;
public:void set_is_recommended(int is_recommended){
	this->is_recommended_ = is_recommended;
}
public:int get_is_recommended(){
	return this->is_recommended_;
}
	   
private:long upload_type_id;
public:void set_upload_type_id(long upload_type_id){
	this->upload_type_id = upload_type_id;
}
public:long get_upload_type_id(){
	return this->upload_type_id;
}
};
#endif // !defined(EA_CD242B00_54EA_4b71_9F64_E34AFDA4EF5F__INCLUDED_)
