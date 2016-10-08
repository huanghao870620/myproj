///////////////////////////////////////////////////////////
//  MyView.cpp
//  Implementation of the Class MyView
//  Created on:      23-¾ÅÔÂ-2016 9:04:28
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "MyView.h"

IMPLEMENT_DYNCREATE(MyView,CView)
BEGIN_MESSAGE_MAP(MyView,CView)
END_MESSAGE_MAP()
MyView::MyView(){
	CRect leftSideRect(10, 10, 37, 520);
	CBrush brush(RGB(0, 0, 0));
	brush.DeleteObject();
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
	Random *rand = new Random;
	int randInt = rand->getRandomInt();
	this->com = rand->getRandomCom(randInt);
}



MyView::~MyView(){

}

void MyView::OnDraw(CDC*pDC){
	CRect rect;
	GetClientRect(&rect);
	pDC->FillSolidRect(rect, RGB(255, 255, 255));

	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	pDC->SelectObject(pen);
	CRect leftSideRect(10,10,37,520);
	pDC->Rectangle(leftSideRect);
	CBrush brush(RGB(0,0,0)); 
	pDC->FillRect(leftSideRect, &brush);
	brush.DeleteObject();
	CRect leftBrickRect(41, 10, 71, 520);
	
	LeftBrick *lb = new LeftBrick(pDC, &leftBrickRect,&brush,&pen);
	lb->drawBrick();
	delete lb; 
	CRect rightBrickRect(leftBrickRect.left + 256, leftBrickRect.top, leftBrickRect.right + 256, leftBrickRect.bottom);
	LeftBrick *rb = new LeftBrick(pDC, &rightBrickRect,&brush,&pen);
	rb->drawBrick();
	delete rb;

	pen.m_hObject = NULL;
	pen.CreatePen(PS_DOT, 1, RGB(0, 0, 0));
	pDC->SelectObject(pen);

	pDC->MoveTo(leftBrickRect.right + Constants::gap, leftBrickRect.top);
	pDC->LineTo(rightBrickRect.left - Constants::gap, leftBrickRect.top);
	pDC->LineTo(rightBrickRect.left - Constants::gap, leftBrickRect.bottom);
	pDC->LineTo(leftBrickRect.right + Constants::gap, leftBrickRect.bottom);
	pDC->LineTo(leftBrickRect.right + Constants::gap, leftBrickRect.top);

	pDC->MoveTo(leftBrickRect.right + Constants::gap, leftBrickRect.top + Constants::gap);
	pDC->LineTo(rightBrickRect.left - Constants::gap, leftBrickRect.top + Constants::gap);

	pDC->MoveTo(leftBrickRect.right + Constants::gap + Constants::gap, leftBrickRect.top);
	pDC->LineTo(leftBrickRect.right + Constants::gap + Constants::gap, leftBrickRect.bottom);

	Singleton *inst = Singleton::getSingleton();
	this->arrayDto = new ArrayDto;

	for (int y = leftBrickRect.top + Constants::gap + Constants::sideLength; y < rightBrickRect.bottom; y += Constants::sideLength)
	{
		Coordinates * coor = new Coordinates;
		
		pDC->MoveTo(leftBrickRect.right + Constants::gap, y);
		pDC->LineTo(rightBrickRect.left - Constants::gap, y);
		y = y + Constants::gap;
		pDC->MoveTo(leftBrickRect.right + Constants::gap, y);
		pDC->LineTo(rightBrickRect.left - Constants::gap, y);
	}
	
	for (int x = leftBrickRect.right + Constants::gap + Constants::gap + Constants::sideLength; x < rightBrickRect.left; x += Constants::sideLength)
	{
		pDC->MoveTo(x, leftBrickRect.top);
		pDC->LineTo(x, leftBrickRect.bottom);
		x = x + Constants::gap;
		pDC->MoveTo(x, leftBrickRect.top);
		pDC->LineTo(x, leftBrickRect.bottom);
	}

	for (int y = leftBrickRect.top + Constants::gap + Constants::sideLength; y < rightBrickRect.bottom; y += Constants::sideLength)
	{
		pDC->MoveTo(leftBrickRect.right + Constants::gap, y);
		pDC->LineTo(rightBrickRect.left - Constants::gap, y);
		y = y + Constants::gap;
		pDC->MoveTo(leftBrickRect.right + Constants::gap, y);
		pDC->LineTo(rightBrickRect.left - Constants::gap, y);
	}

	int count = 0;
	for (int x = leftBrickRect.right + Constants::gap + Constants::gap + Constants::sideLength; x < rightBrickRect.left; x += Constants::sideLength, count++)
	{
		pDC->MoveTo(x, leftBrickRect.top);
		pDC->LineTo(x, leftBrickRect.bottom);
		x = x + Constants::gap;
		pDC->MoveTo(x, leftBrickRect.top);
		pDC->LineTo(x, leftBrickRect.bottom);
		if (count == 10){
			pen.m_hObject = NULL;
			pen.CreatePen(PS_DOT, 1, RGB(255, 0, 0));
			pDC->SelectObject(pen);
		}
	}

	CRect scoreRect(rightBrickRect.right + Constants::gap * 2, rightBrickRect.top, rightBrickRect.right + 140, rightBrickRect.bottom);
	pDC->Rectangle(scoreRect);
	this->com->DrawCom(pDC,&brush);
} 