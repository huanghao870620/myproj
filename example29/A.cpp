///////////////////////////////////////////////////////////
//  A.cpp
//  Implementation of the Class A
//  Created on:      16-ʮ��-2016 20:17:47
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "A.h"


A::A(){
	this->a = 10;
	std::cout << "���캯��" << std::endl;
}



A::~A(){
	std::cout << "��������" << std::endl;
}

int A::getA(){
	return this->a;
}