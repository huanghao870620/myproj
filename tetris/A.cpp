///////////////////////////////////////////////////////////
//  A.cpp
//  Implementation of the Class A
//  Created on:      09-Ê®ÔÂ-2016 18:41:18
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "A.h"


A::A(){

}



A::~A(){

}

void A::init(){
	CRect leftBrickRect(41, 10, 71, 520);
	CRect rightBrickRect(leftBrickRect.left + 256, leftBrickRect.top, leftBrickRect.right + 256, leftBrickRect.bottom);
	Singleton *inst = Singleton::getSingleton();
	this->arrayDto = new ArrayDto;
	this->adto = new Adto;

	for (int y = leftBrickRect.top + Constants::gap + Constants::sideLength; y < rightBrickRect.bottom; y += Constants::sideLength)
	{
		Coordinates * coor = new Coordinates;
		this->adto->addY(y - Constants::sideLength);
		y = y + Constants::gap;
	}

	for (int x = leftBrickRect.right + Constants::gap + Constants::gap + Constants::sideLength; x < rightBrickRect.left; x += Constants::sideLength)
	{
		this->adto->addX(x - Constants::sideLength);
		x = x + Constants::gap;
	}

	int xlen = this->adto->getXList()->size();
	int ylen = this->adto->getYList()->size();
	int *xArray = new int[xlen];
	int *yArray = new int[ylen];

	std::list<int>* xIntList = this->adto->getXList();
	std::list<int>* yList = this->adto->getYList();
	std::list<int>::iterator iter = xIntList->begin();
	std::list<int>::iterator yIter = yList->begin();
	for (int i = 0; i < xlen; i++, iter++){
		xArray[i] = *iter;
	}

	for (int i = 0; i < ylen; i++, yIter++){
		yArray[i] = *yIter;
	}


	for (int i = 0; i < xlen; i++){
		for (int j = 0; j < ylen; j++){
			Coordinates *coor = new Coordinates(xArray[i], yArray[j]);
			inst->addCoor(coor);
		}
	}

	Queue *queue = Queue::getInstance();
	this->com = queue->get();
}