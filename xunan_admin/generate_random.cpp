///////////////////////////////////////////////////////////
//  generate_random.cpp
//  Implementation of the Class generate_random
//  Created on:      18-Ê®Ò»ÔÂ-2016 17:25:44
//  Original author: admin
///////////////////////////////////////////////////////////

#include "generate_random.h"


generate_random::generate_random(){

}



generate_random::~generate_random(){

}

std::string generate_random::get_random(){
	srand((unsigned)time(NULL));
	std::string *buf = new std::string;
	for (size_t i = 0; i < 10; i++)
	{
		int ran = rand();
		char *c = new char;
		itoa(ran, c, 10);
		buf->append(c);
	}
	//std::cout << buf.c_str();
	return std::string(*buf);
}