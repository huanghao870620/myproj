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

	rect2 = new CRect;
	rect2->left = x;
	rect2->top = y;
	
	rect2->right = x + Constants::sideLength;
	rect2->bottom = y + Constants::sideLength;


	c0 = new CRect;
	c0->left = rect2->left + Constants::sideLength + Constants::gap;
	c0->top = rect2->top;
	c0->bottom = rect2->bottom;
	c0->right = rect2->right + Constants::sideLength + Constants::gap;

	c1 = new CRect;
	c1->left = c0->left + Constants::sideLength + Constants::gap;
	c1->top = rect2->top;
	c1->bottom = rect2->bottom;
	c1->right = c0->right + Constants::sideLength + Constants::gap;

	c2 = new CRect;
	c2->left = c1->left + Constants::sideLength + Constants::gap;
	c2->top = rect2->top;
	c2->right = c1->right + Constants::sideLength + Constants::gap;
	c2->bottom = rect2->bottom;

	this->rectList.push_back(rect2);
	this->rectList.push_back(c0);
	this->rectList.push_back(c1);
	this->rectList.push_back(c2);
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
	pDC->FillRect(rect2, brush);
	pDC->FillRect(c0, brush);
	pDC->FillRect(c1, brush);
	pDC->FillRect(c2, brush);
	this->landing();
}


void Combination::landing(){
	std::list<CRect*>::iterator iter = this->rectList.begin();
	while (iter != this->rectList.end())
	{
		CRect *rect = *iter;
		rect->top = rect->top + Constants::sideLength + Constants::gap;
		rect->bottom = rect->bottom + Constants::sideLength + Constants::gap;
		iter++;
	}
}

void Combination::setCDC(CDC*pDC){
	this->pDC = pDC;
}

void Combination::setBrush(CBrush*brush){
	this->brush = brush;
}