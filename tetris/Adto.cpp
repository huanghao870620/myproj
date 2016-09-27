///////////////////////////////////////////////////////////
//  Adto.cpp
//  Implementation of the Class Adto
//  Created on:      27-¾ÅÔÂ-2016 14:47:45
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "Adto.h"


Adto::Adto(){

}



Adto::~Adto(){

}

void Adto::addX(int x){
	this->xList.push_back(x);
}

void Adto::addY(int y){
	this->yList.push_back(y);
}

std::list<int>* Adto::getXList(){
	return &this->xList;
}

std::list<int>* Adto::getYList(){
	return &this->yList;
}