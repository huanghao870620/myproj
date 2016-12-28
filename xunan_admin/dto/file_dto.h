///////////////////////////////////////////////////////////
//  file_dto.h
//  Implementation of the Class file_dto
//  Created on:      26-Ê®¶þÔÂ-2016 15:41:14
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_C34E1AEC_AEF7_4d17_9773_E00E57116C74__INCLUDED_)
#define EA_C34E1AEC_AEF7_4d17_9773_E00E57116C74__INCLUDED_

#include<iostream>

class file_dto
{

public:
	file_dto();
	virtual ~file_dto();

	void set_id(long id){
		this->id = id;
	}

	long get_id(){
		return this->id;
	}

	void set_local_path(std::string& local_path){
		this->local_path = local_path;
	}

	std::string& get_local_path(){
		return this->local_path;
	}

private:
	long id;
	std::string local_path;

};
#endif // !defined(EA_C34E1AEC_AEF7_4d17_9773_E00E57116C74__INCLUDED_)
