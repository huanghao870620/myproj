///////////////////////////////////////////////////////////
//  file.h
//  Implementation of the Class file
//  Created on:      17-十一月-2016 19:05:19
//  Original author: burgess
///////////////////////////////////////////////////////////

#if !defined(EA_4A00C58B_123F_4022_AB37_366A04430FB5__INCLUDED_)
#define EA_4A00C58B_123F_4022_AB37_366A04430FB5__INCLUDED_

#include<memory>
#include<iostream>
#include<odb\database.hxx>
#include<odb\transaction.hxx>
#include<odb\mysql\database.hxx>
#include<odb\core.hxx>


/**
 * 文件
 */
#pragma db object
class file
{

public:
	file();

public:file(std::string &name, 
	std::string& path,
	std::string&uri_path,
	long type_id) : 
	name_(name), 
	path_(path), 
	uri_path_(uri_path),
	type_id_(type_id){

}
	virtual ~file();
private:friend class odb::access;
#pragma db id auto
private:unsigned long id_;
public:void set_id(unsigned long id){
	this->id_ = id;
}
public:unsigned long get_id(){
	return this->id_;
}
private:std::string name_;
public:void set_name(std::string name){
	this->name_ = name;
}
public:std::string&get_name(){
	return this->name_;
}
private:std::string path_;
public:void set_path(std::string&path){
	this->path_ = path;
}
public:std::string&get_path(){
	return this->path_;
}
private:std::string uri_path_;
public:void set_uri_path(std::string&uri_path){
	this->uri_path_ = uri_path;
}
public:std::string&get_uri_path(){
	return this->uri_path_;
}
private:unsigned long type_id_;
public:void set_type_id(unsigned long type_id){
	this->type_id_ = type_id;
}
public:unsigned long get_type_id(){
	return this->type_id_;
}

};
#endif // !defined(EA_4A00C58B_123F_4022_AB37_366A04430FB5__INCLUDED_)
