///////////////////////////////////////////////////////////
//  Combination.cpp
//  Implementation of the Class Combination
//  Created on:      26-¾ÅÔÂ-2016 15:40:26
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "Combination.h"


Combination::Combination(CDC*pDC){
	this->pDC = pDC;
}



Combination::~Combination(){

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

void Combination::t(){
	Singleton *inst = Singleton::getSingleton();
	std::list<Coordinates*>::iterator iter2 = inst->getCoors()->begin();
	Coordinates *coor0 = *iter2;
	int x = coor0->getX();
	int y = coor0->getY();

	rect2 = new CRect;
	rect2->left = x;
	rect2->top = y;

	
	rect2->right = x + MyView::sideLength;
	rect2->bottom = y + MyView::sideLength;
	pDC->FillRect(rect2, brush);


	c0 = new CRect;
	c0->left = rect2->left + MyView::sideLength + MyView::gap;
	c0->top = rect2->top;
	c0->bottom = rect2->bottom;
	c0->right = rect2->right + MyView::sideLength + MyView::gap;
	pDC->FillRect(c0, brush);

	c1 = new CRect;
	c1->left = c0->left + MyView::sideLength + MyView::gap;
	c1->top = rect2->top;
	c1->bottom = rect2->bottom;
	c1->right = c0->right + MyView::sideLength + MyView::gap;
	pDC->FillRect(c1, brush);

	c2 = new CRect;
	c2->left = c1->left + MyView::sideLength + MyView::gap;
	c2->top = rect2->top;
	c2->right = c1->right + MyView::sideLength + MyView::gap;
	c2->bottom = rect2->bottom;
	pDC->FillRect(c2, brush);
}