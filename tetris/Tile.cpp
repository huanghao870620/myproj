///////////////////////////////////////////////////////////
//  Tile.cpp
//  Implementation of the Class Tile
//  Created on:      26-¾ÅÔÂ-2016 15:05:46
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "Tile.h"


Tile::Tile(int x1, int x2, int y1, int y2){
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;

	this->brickCrect.left = this->x1;
	this->brickCrect.right = this->x2;
	this->brickCrect.top = this->y1;
	this->brickCrect.bottom = this->y2;
}



Tile::~Tile(){

}

void Tile::createTile(){
	pen->m_hObject = NULL;
	pen->CreatePen(PS_SOLID, 1, this->ref);
	pDC->SelectObject(pen);
	pDC->Rectangle(brickCrect);
	brush->m_hObject = NULL;
	brush->CreateSolidBrush(this->ref);
	pDC->FillRect(brickCrect, brush);
	
	pen->m_hObject = NULL;
	pen->CreatePen(PS_SOLID, 1, this->ref);
	pDC->SelectObject(pen);
	pDC->Rectangle(innerBrickCrect);
	brush->m_hObject = NULL;
	brush->CreateSolidBrush(RGB(118, 92, 77));
	pDC->FillRect(innerBrickCrect, brush);
}