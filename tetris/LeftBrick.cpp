///////////////////////////////////////////////////////////
//  LeftBrick.cpp
//  Implementation of the Class LeftBrick
//  Created on:      23-¾ÅÔÂ-2016 15:27:26
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "LeftBrick.h"


LeftBrick::LeftBrick(){

}

LeftBrick::LeftBrick(CDC *pDC,CRect leftBrickRect){
	this->pDC = pDC;
	this->leftBrickRect = leftBrickRect;
}

LeftBrick::~LeftBrick(){

}


void LeftBrick::drawBrick(){
	for (size_t i = 18; i < 520; i += 8)
	{
		pDC->MoveTo(leftBrickRect.left + 2, i);
		pDC->LineTo(leftBrickRect.left + 26, i);
	}

	for (size_t i = leftBrickRect.top, j = 0; i < leftBrickRect.bottom; i += 8, j++)
	{
		if (j % 2 == 0){
			pDC->MoveTo(leftBrickRect.left + 6, i);
			pDC->LineTo(leftBrickRect.left + 6, i + 8);

			pDC->MoveTo(leftBrickRect.left + 20, i);
			pDC->LineTo(leftBrickRect.left + 20, i + 8);
		}
		else
		{
			pDC->MoveTo(leftBrickRect.left + 12, i);
			pDC->LineTo(leftBrickRect.left + 12, i + 5);

			pDC->MoveTo(leftBrickRect.left + 28, i);
			pDC->LineTo(leftBrickRect.left + 28, i + 5);
		}
	}
}