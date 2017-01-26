///////////////////////////////////////////////////////////
//  Combination.cpp
//  Implementation of the Class Combination
//  Created on:      26-¾ÅÔÂ-2016 15:40:26
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "Combination.h"
#include"Queue.h"


Combination::Combination(){
}

Combination::~Combination(){
	
}

Combination::Combination(int pat){
	this->init(pat);
}


void Combination::init(int pat){
	Coordinates *coor = this->getFirstCoor();
	int x = coor->getX();
	int y = coor->getY();
	this->c0 = new Tile;
	this->c1 = new Tile;
	this->c2 = new Tile;
	this->c3 = new Tile;
	this->tileList.push_back(this->c0);
	this->tileList.push_back(this->c1);
	this->tileList.push_back(this->c2);
	this->tileList.push_back(this->c3);

	switch (pat)
	{
	case 0: // ----
		this->c0->setX1(x);
		this->c0->setY1(y);
		this->c0->setX2(x + Constants::sideLength);
		this->c0->setY2(y + Constants::sideLength);

		this->c1->setX1(this->c0->getX1() + Constants::sideLength + Constants::gap);
		this->c1->setY1(this->c0->getY1());
		this->c1->setX2(this->c0->getX2() + Constants::sideLength + Constants::gap);
		this->c1->setY2(this->c0->getY2());

		this->c2->setX1(c1->getX1() + Constants::sideLength + Constants::gap);
		this->c2->setY1(this->c1->getY1());
		this->c2->setX2(this->c1->getX2() + Constants::sideLength + Constants::gap);
		this->c2->setY2(this->c1->getY2());

		this->c3->setX1(this->c2->getX1() + Constants::sideLength + Constants::gap);
		this->c3->setY1(this->c2->getY1());
		this->c3->setX2(this->c2->getX2() + Constants::sideLength + Constants::gap);
		this->c3->setY2(this->c2->getY2());
		break;
	case 1: // | | | |
		this->c0->setX1(x);
		this->c0->setY1(y);
		this->c0->setX2(x + Constants::sideLength);
		this->c0->setY2(y + Constants::sideLength);

		this->c1->setX1(x);
		this->c1->setY1(this->c0->getY1() + Constants::sideLength + Constants::gap);
		this->c1->setX2(x + Constants::sideLength);
		this->c1->setY2(this->c0->getY2() + Constants::sideLength + Constants::gap);

		this->c2->setX1(x);
		this->c2->setY1(this->c1->getY1() + Constants::sideLength + Constants::gap);
		this->c2->setX2(x + Constants::sideLength);
		this->c2->setY2(this->c1->getY2() + Constants::sideLength + Constants::gap);

		this->c3->setX1(x);
		this->c3->setY1(this->c2->getY1() + Constants::sideLength + Constants::gap);
		this->c3->setX2(x + Constants::sideLength);
		this->c3->setY2(this->c2->getY2() + Constants::sideLength + Constants::gap);
		break;
	case 2: // |_ _ _
		this->c0->setX1(x);
		this->c0->setY1(y);
		this->c0->setX2(x + Constants::sideLength);
		this->c0->setY2(y + Constants::sideLength);

		this->c1->setX1(x);
		this->c1->setY1(this->c0->getY1() + Constants::sideLength + Constants::gap);
		this->c1->setX2(x + Constants::sideLength);
		this->c1->setY2(this->c0->getY2() + Constants::sideLength + Constants::gap);

		this->c2->setX1(this->c1->getX1() + Constants::sideLength + Constants::gap);
		this->c2->setY1(this->c1->getY1());
		this->c2->setX2(this->c1->getX2() + Constants::sideLength + Constants::gap);
		this->c2->setY2(this->c1->getY2());

		this->c3->setX1(this->c2->getX1() + Constants::sideLength + Constants::gap);
		this->c3->setY1(this->c2->getY1());
		this->c3->setX2(this->c2->getX2() + Constants::sideLength + Constants::gap);
		this->c3->setY2(this->c2->getY2());
		break;
	case 3:// Ìï
		this->c0->setX1(x);
		this->c0->setY1(y);
		this->c0->setX2(x + Constants::sideLength);
		this->c0->setY2(y + Constants::sideLength);

		this->c1->setX1(this->c0->getX1() + Constants::sideLength + Constants::gap);
		this->c1->setY1(this->c0->getY1());
		this->c1->setX2(this->c0->getX2() + Constants::sideLength + Constants::gap);
		this->c1->setY2(this->c0->getY2());

		this->c2->setX1(this->c0->getX1());
		this->c2->setY1(this->c0->getY1() + Constants::sideLength + Constants::gap);
		this->c2->setX2(this->c0->getX2());
		this->c2->setY2(this->c0->getY2() + Constants::sideLength + Constants::gap);

		this->c3->setX1(this->c1->getX1());
		this->c3->setY1(this->c1->getY1() + Constants::sideLength + Constants::gap);
		this->c3->setX2(this->c1->getX2());
		this->c3->setY2(this->c1->getY2() + Constants::sideLength + Constants::gap);
		break;
	case 4:// _|_
		this->c0->setX1(x + Constants::sideLength + Constants::gap);
		this->c0->setY1(y);
		this->c0->setX2(this->c0->getX1() + Constants::sideLength);
		this->c0->setY2(this->c0->getY1() + Constants::sideLength);

		this->c1->setX1(x);
		this->c1->setY1(this->c0->getY1() + Constants::sideLength + Constants::gap);
		this->c1->setX2(this->c1->getX1() + Constants::sideLength);
		this->c1->setY2(this->c1->getY1() + Constants::sideLength);

		this->c2->setX1(this->c1->getX1() + Constants::sideLength + Constants::gap);
		this->c2->setY1(this->c1->getY1());
		this->c2->setX2(this->c2->getX1() + Constants::sideLength);
		this->c2->setY2(this->c2->getY1() + Constants::sideLength);

		this->c3->setX1(this->c2->getX1() + Constants::sideLength + Constants::gap);
		this->c3->setY1(this->c2->getY1());
		this->c3->setX2(this->c3->getX1() + Constants::sideLength);
		this->c3->setY2(this->c2->getY2());
		break;
	case 5: // _ _ _|
		this->c0->setX1(x);
		this->c0->setY1(y + Constants::sideLength + Constants::gap);
		this->c0->setX2(x + Constants::sideLength);
		this->c0->setY2(this->c0->getY1() + Constants::sideLength);

		this->c1->setX1(this->c0->getX1() + Constants::sideLength + Constants::gap);
		this->c1->setY1(this->c0->getY1());
		this->c1->setX2(this->c1->getX1() + Constants::sideLength);
		this->c1->setY2(this->c0->getY2());

		this->c2->setX1(this->c1->getX1() + Constants::sideLength + Constants::gap);
		this->c2->setY1(this->c1->getY1());
		this->c2->setX2(this->c2->getX1() + Constants::sideLength);
		this->c2->setY2(this->c1->getY2());

		this->c3->setX1(this->c2->getX1());
		this->c3->setY1(this->c2->getY1() - Constants::sideLength - Constants::gap);
		this->c3->setX2(this->c2->getX2());
		this->c3->setY2(this->c3->getY1() + Constants::sideLength);
		break;
	case 6: // _ _- -
		this->c0->setX1(x);
		this->c0->setY1(y + Constants::sideLength + Constants::gap);
		this->c0->setX2(this->c0->getX1() + Constants::sideLength);
		this->c0->setY2(this->c0->getY1() + Constants::sideLength);

		this->c1->setX1(this->c0->getX1() + Constants::sideLength + Constants::gap);
		this->c1->setY1(this->c0->getY1());
		this->c1->setX2(this->c1->getX1() + Constants::sideLength);
		this->c1->setY2(this->c0->getY2());

		this->c2->setX1(this->c1->getX1());
		this->c2->setY1(this->c1->getY1() - Constants::sideLength - Constants::gap);
		this->c2->setX2(this->c1->getX2());
		this->c2->setY2(this->c2->getY1() + Constants::sideLength);

		this->c3->setX1(this->c2->getX1() + Constants::sideLength + Constants::gap);
		this->c3->setY1(this->c2->getY1());
		this->c3->setX2(this->c3->getX1() + Constants::sideLength);
		this->c3->setY2(this->c3->getY1() + Constants::sideLength);
		break;
	default:
		std::cout << "" << std::endl;
		break;
	}
	this->scre = new Screen;
	this->last = this->scre->getBottomCoor();
}

/**/
void Combination::DrawCom(CDC*pDC,CBrush*brush){
	std::list<Tile*>::iterator itor =  this->tileList.begin();
	while (itor != this->tileList.end()){
		Tile *tile = *itor;
		pDC->FillRect(CRect(tile->getX1(), tile->getY1(), tile->getX2(), tile->getY2()), brush);
		itor++;
	}
	if (!this->isStop){
		this->landing();
	}
	else
	{
		//Queue::getInstance()->remove();
	}
	
}

bool Combination::getIsStop(){
	return this->isStop;
}


void Combination::landing(){
	std::list<Tile*>::iterator iter = this->tileList.begin();
	while (iter != this->tileList.end())
	{
		Tile *tile = *iter;
		tile->setY1(tile->getY1() + Constants::sideLength + Constants::gap);
		tile->setY2(tile->getY2() + Constants::sideLength + Constants::gap);
		if (tile->getY1() == this->last->getY()){
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

Coordinates Combination::getBottomCoor(){
	Singleton *inst= Singleton::getSingleton();
	std::list<Coordinates*>::iterator iter = inst->getCoors()->begin();
	int maxHeight = -1;
	Coordinates cd;
	for (; iter != inst->getCoors()->end(); iter++){
		Coordinates *coor = *iter;
		if (coor->getY() > -1){
			maxHeight = coor->getY();
			cd = *coor;
		}
	}
	return cd;
}




