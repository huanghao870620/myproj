///////////////////////////////////////////////////////////
//  Util.cpp
//  Implementation of the Class Util
//  Created on:      17-Ê®Ò»ÔÂ-2016 15:16:50
//  Original author: admin
///////////////////////////////////////////////////////////

#include "Util.h"


Util::Util(){

}



Util::~Util(){

}

long Util::stol(std::string str){
	long result;
	std::istringstream is(str);
	is >> result;
	return result;
}

float Util::stof(std::string str){
	return atof(str.c_str());
}

std::string Util::ftos(float f){
	char buffer[50];
	_gcvt(f, 7, buffer);
	return std::string(buffer);
}

std::string Util::ltos(long l){
	std::stringstream stream;
	std::string result;
	stream << l;
	stream >> result;
	return result;
}