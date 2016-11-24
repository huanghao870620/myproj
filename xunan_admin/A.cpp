///////////////////////////////////////////////////////////
//  A.cpp
//  Implementation of the Class A
//  Created on:      08-Ê®ÔÂ-2016 22:07:06
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "A.h"


A::A(){
	this->a = 0;
}



A::~A(){

}

void A::add(){
	this->a++;
}

int A::getA(){
	return this->a;
}