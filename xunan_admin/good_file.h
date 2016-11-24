///////////////////////////////////////////////////////////
//  good_file.h
//  Implementation of the Class good_file
//  Created on:      22-Ê®Ò»ÔÂ-2016 20:25:23
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_8F329A60_5AAC_467e_A5FF_36521252034E__INCLUDED_)
#define EA_8F329A60_5AAC_467e_A5FF_36521252034E__INCLUDED_


#include<memory>
#include<iostream>
#include<odb\database.hxx>
#include<odb\transaction.hxx>
//#include<odb\mysql\database.hxx>
#include<odb\core.hxx>


#pragma db object
class good_file
{

public:
	good_file();
public:good_file(long good_id, long file_id) :
	good_id_(good_id), file_id_(file_id){
};
	virtual ~good_file();

private:friend class odb::access;
#pragma db id auto
private:unsigned long id_;
public:void set_id(long id){
	this->id_ = id;
}
public:long get_id(){
	return this->id_;
}
private:unsigned long good_id_;
public:void set_good_id(long good_id){
	this->good_id_ = good_id;
}
public:long get_good_id(){
	return this->good_id_;
}
		
private:unsigned long file_id_;
public:void set_file_id(long file_id){
	this->file_id_ = file_id;
}
public:long get_file_id(){
	return this->file_id_;
}

};
#endif // !defined(EA_8F329A60_5AAC_467e_A5FF_36521252034E__INCLUDED_)
