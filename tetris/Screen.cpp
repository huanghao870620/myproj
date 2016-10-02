///////////////////////////////////////////////////////////
//  Screen.cpp
//  Implementation of the Class Screen
//  Created on:      01-Ê®ÔÂ-2016 10:26:01
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "Screen.h"


Screen::Screen(){
	this->sing = Singleton::getSingleton();
}

Screen::~Screen(){

}

Coordinates* Screen::getBottomCoor(){
	std::list<Coordinates*> *coors = this->sing->getCoors();
	std::list<Coordinates*>::iterator itor = coors->begin();
	int len = coors->size();
	int count = 0;
	Coordinates * ret = nullptr;
	std::list<Coordinates*>::iterator end_iter = coors->end();
	while (++itor != end_iter)
	{
		count++;
		Coordinates *coor = *itor;
		if (count == 22){
			ret = coor;
		}
	}
	return ret;
}