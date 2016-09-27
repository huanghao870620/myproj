///////////////////////////////////////////////////////////
//  Singleton.cpp
//  Implementation of the Class Singleton
//  Created on:      26-¾ÅÔÂ-2016 16:29:40
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "Singleton.h"


Singleton::Singleton(){

}



Singleton::~Singleton(){

}

std::list<Coordinates*>* Singleton::getCoors(){
	return this->coors;
}

void Singleton::setCoors(std::list<Coordinates*> *coors){
	this->coors = coors;
}

//
//Singleton* Singleton::getSingleton(){
//		if (nullptr == instance){
//			instance = new Singleton;
//		}
//		return instance;
//}