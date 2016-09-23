///////////////////////////////////////////////////////////
//  LeftBrick.cpp
//  Implementation of the Class LeftBrick
//  Created on:      23-¾ÅÔÂ-2016 15:27:26
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "LeftBrick.h"


LeftBrick::LeftBrick(){

}

LeftBrick::LeftBrick(CDC *pDC,CRect &leftBrickRect,CBrush &brush, CPen &pen){
	this->pDC = pDC;
	this->leftBrickRect = leftBrickRect;
	this->brush = brush;
	this->pen = pen;
	this->drawBack();
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

/*»­±³¾°*/
void LeftBrick::drawBack(){
	pDC->Rectangle(leftBrickRect);
	brush.CreateSolidBrush(RGB(195, 182, 173));
	pDC->FillRect(leftBrickRect, &brush);

	pen.DeleteObject();
	pen.CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
	pDC->SelectObject(pen);
}