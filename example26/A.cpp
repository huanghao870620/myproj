///////////////////////////////////////////////////////////
//  A.cpp
//  Implementation of the Class A
//  Created on:      15-Ê®ÔÂ-2016 23:11:58
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "A.h"


A::A(){

}



A::~A(){

}

void A::add(B*b){
	this->que.push(b);
}

std::queue<B*>* A::getQue(){
	return &this->que;
}

void A::remove(){
	this->que.pop();
}