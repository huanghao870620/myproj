///////////////////////////////////////////////////////////
//  Combination.cpp
//  Implementation of the Class Combination
//  Created on:      26-¾ÅÔÂ-2016 15:40:26
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "Combination.h"


Combination::Combination(CDC*pDC,CBrush *brush){
	this->pDC = pDC;
	this->brush = brush;
	this->init();
}

Combination::Combination(){
	this->init();
}

Combination::~Combination(){
	
}

void Combination::init(){
	Singleton *inst = Singleton::getSingleton();
	std::list<Coordinates*>::iterator iter2 = inst->getCoors()->begin();
	Coordinates *coor0 = *iter2;
	int x = coor0->getX();
	int y = coor0->getY();

	rect2 = new Tile();
	rect2->setX1(x);
	rect2->setY1(y);
	rect2->setX2(x + Constants::sideLength);
	rect2->setY2(y + Constants::sideLength);
	 
	c0 = new Tile();
	c0->setX1(rect2->getX1() + Constants::sideLength + Constants::gap);
	c0->setY1(rect2->getY1());
	c0->setX2(rect2->getX2() + Constants::sideLength + Constants::gap);
	c0->setY2(rect2->getY2());

	c1 = new Tile();
	c1->setX1(c0->getX1() + Constants::sideLength + Constants::gap);
	c1->setY1(rect2->getY1());
	c1->setX2(c0->getX2() + Constants::sideLength + Constants::gap);
	c1->setY2(rect2->getY2());

	c2 = new Tile();
	c2->setX1(c1->getX1() + Constants::sideLength + Constants::gap);
	c2->setY1(rect2->getY1());
	c2->setX2(c1->getX2() + Constants::sideLength + Constants::gap);
	c2->setY2(rect2->getY2());

	this->tileList.push_back(rect2);
	this->tileList.push_back(c0);
	this->tileList.push_back(c1);
	this->tileList.push_back(c2);

	this->scre = new Screen;
	this->last = this->scre->getBottomCoor();
}

Combination* Combination::getOne(){
	Tile *t0 = new Tile(0, 0, 0, 0);
	Tile *t1 = new Tile(0, 0, 0, 0);
	Tile *t2 = new Tile(0, 0, 0, 0);
	Tile *t3 = new Tile(0, 0, 0, 0);
	this->tiles.push_back(t0);
	this->tiles.push_back(t1);
	this->tiles.push_back(t2);
	this->tiles.push_back(t3);
	return this;
}

void Combination::DrawCom(){
	pDC->FillRect(CRect(rect2->getX1(), rect2->getY1(), rect2->getX2(), rect2->getY2()), brush);
	pDC->FillRect(CRect(c0->getX1(),c0->getY1(),c0->getX2(),c0->getY2()), brush);
	pDC->FillRect(CRect(c1->getX1(),c1->getY1(),c1->getX2(),c1->getY2()), brush);
	pDC->FillRect(CRect(c2->getX1(),c2->getY1(),c2->getX2(),c2->getY2()), brush);
	if (!this->isStop){
		this->landing();
	}
}


void Combination::landing(){
	std::list<Tile*>::iterator iter = this->tileList.begin();
	while (iter != this->tileList.end())
	{
		Tile *rect = *iter;
		rect->setY1(rect->getY1() + Constants::sideLength + Constants::gap);
		rect->setY2(rect->getY2() + Constants::sideLength + Constants::gap);
		std::cout << " bottom : " << rect->getY2() << std::endl;
		if (rect->getY1() == this->last->getY()){
			this->isStop = true;
		}
		iter++;
	}
}

void Combination::setCDC(CDC*pDC){
	this->pDC = pDC;
}

void Combination::setBrush(CBrush*brush){
	this->brush = brush;
}