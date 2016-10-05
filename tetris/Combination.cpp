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

Combination::Combination(int pat){
	Coordinates *coor = this->getFirstCoor();
	int x = coor->getX();
	int y = coor->getY();
	switch (pat)
	{
	case 0: // ----
		break;
	case 1: // | | | |
		this->c0 = new Tile;
		this->c0->setX1(x);
		this->c0->setY1(y);
		this->c0->setX2(x + Constants::sideLength);
		this->c0->setY2(y + Constants::sideLength);

		this->c1 = new Tile;
		this->c1->setX1(x);
		this->c1->setY1(this->c0->getY1() + Constants::sideLength + Constants::gap);
		this->c1->setX2(x + Constants::sideLength);
		this->c1->setY2(this->c0->getY2() + Constants::sideLength + Constants::gap);

		this->c2 = new Tile;
		this->c2->setX1(x);
		this->c2->setY1(this->c1->getY1() + Constants::sideLength + Constants::gap);
		this->c2->setX2(x + Constants::sideLength);
		this->c2->setY2(this->c1->getY2() + Constants::sideLength + Constants::gap);

		this->c3 = new Tile;
		this->c3->setX1(x);
		this->c3->setY1(this->c2->getY1() + Constants::sideLength + Constants::gap);
		this->c3->setX2(x + Constants::sideLength);
		this->c3->setY2(this->c2->getY2() + Constants::sideLength + Constants::gap);

		this->tileList.push_back(this->c0);
		this->tileList.push_back(this->c1);
		this->tileList.push_back(this->c2);
		this->tileList.push_back(this->c3);
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	default:
		break;
	}
}

void Combination::init(){
	Singleton *inst = Singleton::getSingleton();
	std::list<Coordinates*>::iterator iter2 = inst->getCoors()->begin();
	Coordinates *coor0 = *iter2;
	int x = coor0->getX();
	int y = coor0->getY();

	this->c3 = new Tile();
	this->c3->setX1(x);
	this->c3->setY1(y);
	this->c3->setX2(x + Constants::sideLength);
	this->c3->setY2(y + Constants::sideLength);
	 
	this->c0 = new Tile();
	this->c0->setX1(this->c3->getX1() + Constants::sideLength + Constants::gap);
	this->c0->setY1(this->c3->getY1());
	this->c0->setX2(this->c3->getX2() + Constants::sideLength + Constants::gap);
	this->c0->setY2(this->c3->getY2());

	this->c1 = new Tile();
	this->c1->setX1(c0->getX1() + Constants::sideLength + Constants::gap);
	this->c1->setY1(this->c3->getY1());
	this->c1->setX2(c0->getX2() + Constants::sideLength + Constants::gap);
	this->c1->setY2(this->c3->getY2());

	this->c2 = new Tile();
	this->c2->setX1(this->c1->getX1() + Constants::sideLength + Constants::gap);
	this->c2->setY1(this->c3->getY1());
	this->c2->setX2(this->c1->getX2() + Constants::sideLength + Constants::gap);
	this->c2->setY2(this->c3->getY2());

	this->tileList.push_back(this->c3);
	this->tileList.push_back(this->c0);
	this->tileList.push_back(this->c1);
	this->tileList.push_back(this->c2);

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
	pDC->FillRect(CRect(this->c3->getX1(), this->c3->getY1(), this->c3->getX2(), this->c3->getY2()), brush);
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

Coordinates* Combination::getFirstCoor(){
	Singleton *inst = Singleton::getSingleton();
	std::list<Coordinates*>::iterator iter2 = inst->getCoors()->begin();
	return *iter2;
}

void Combination::setCDC(CDC*pDC){
	this->pDC = pDC;
}

void Combination::setBrush(CBrush*brush){
	this->brush = brush;
}