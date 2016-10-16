///////////////////////////////////////////////////////////
//  A.cpp
//  Implementation of the Class A
//  Created on:      16-十月-2016 20:17:47
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "A.h"


A::A(){
	this->a = 10;
	std::cout << "构造函数" << std::endl;
}



A::~A(){
	std::cout << "析构函数" << std::endl;
}

int A::getA(){
	return this->a;
}