///////////////////////////////////////////////////////////
//  Singleton.cpp
//  Implementation of the Class Singleton
//  Created on:      10-Ê®ÔÂ-2016 19:44:38
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "Singleton.h"


Singleton::Singleton(){

}



Singleton::~Singleton(){

}

Singleton* Singleton::getInstance(){
	static Singleton instance;
	return &instance;
}

void Singleton::addA(A*a){
	this->aList.push_back(a);
}

std::list<A*>* Singleton::getAList(){
	return &this->aList;
}