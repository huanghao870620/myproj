///////////////////////////////////////////////////////////
//  MyView.cpp
//  Implementation of the Class MyView
//  Created on:      23-����-2016 9:04:28
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "MyView.h"

IMPLEMENT_DYNCREATE(MyView,CView)
BEGIN_MESSAGE_MAP(MyView,CView)
END_MESSAGE_MAP()
MyView::MyView(){

}



MyView::~MyView(){

}

void MyView::OnDraw(CDC*pDC){
	CRect rect;
	GetClientRect(&rect);
	pDC->FillSolidRect(rect, RGB(255, 255, 255));
	//201 178 162
	/*CBitmap bitmap;
	bitmap.LoadBitmapA(IDB_BG);
	BITMAP bmp;
	bitmap.GetBitmap(&bmp);
	CDC dcCompatible;
	dcCompatible.CreateCompatibleDC(pDC);
	dcCompatible.SelectObject(bitmap);

	CRect rect;
	GetClientRect(&rect);
	pDC->StretchBlt(0, 0, rect.Width(), rect.Height(), &dcCompatible, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY);*/


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

	pDC->MoveTo(leftBrickRect.right + gap, leftBrickRect.top);
	pDC->LineTo(rightBrickRect.left - gap, leftBrickRect.top);
	pDC->LineTo(rightBrickRect.left - gap, leftBrickRect.bottom);
	pDC->LineTo(leftBrickRect.right + gap, leftBrickRect.bottom);
	pDC->LineTo(leftBrickRect.right + gap, leftBrickRect.top);


	pDC->MoveTo(leftBrickRect.right + gap, leftBrickRect.top + gap);
	pDC->LineTo(rightBrickRect.left - gap, leftBrickRect.top + gap);

	pDC->MoveTo(leftBrickRect.right + gap + gap, leftBrickRect.top);
	pDC->LineTo(leftBrickRect.right + gap + gap, leftBrickRect.bottom);

	Singleton *inst = Singleton::getSingleton();

	this->dto = new Dto;
	std::list<Coordinates*> *xList = new std::list<Coordinates*>;
	this->dto->setXList(xList);

	this->arrayDto = new ArrayDto;
	

	this->adto = new Adto;

	for (int y = leftBrickRect.top + gap + sideLength; y < rightBrickRect.bottom; y += sideLength)
	{
		Coordinates * coor = new Coordinates;
		
		this->adto->addY(y - sideLength);
		pDC->MoveTo(leftBrickRect.right + gap, y);
		pDC->LineTo(rightBrickRect.left - gap, y);
		y = y + gap;
		pDC->MoveTo(leftBrickRect.right + gap, y);
		pDC->LineTo(rightBrickRect.left - gap, y);
	}


	
	for (int x = leftBrickRect.right + gap + gap + sideLength; x < rightBrickRect.left; x += sideLength)
	{
		this->adto->addX(x - sideLength);
		pDC->MoveTo(x, leftBrickRect.top);
		pDC->LineTo(x, leftBrickRect.bottom);
		x = x + gap;
		pDC->MoveTo(x, leftBrickRect.top);
		pDC->LineTo(x, leftBrickRect.bottom);
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

	for (int i = 0; i < ylen; i++,yIter++){
		yArray[i] = *yIter;
	}


	for (int i = 0; i < xlen; i++){
		for (int j = 0; j < ylen; j++){
			Coordinates *coor = new Coordinates(xArray[i],yArray[j]);
			inst->addCoor(coor);
		}
	}

	 int len = inst->getCoors()->size();
	 std::cout << "len : " << len << std::endl;

	int yCount = 0;
	for (int y = leftBrickRect.top+gap+sideLength; y < rightBrickRect.bottom; y+=sideLength,yCount++)
	{
		pDC->MoveTo(leftBrickRect.right + gap, y);
		pDC->LineTo(rightBrickRect.left - gap, y);
		y = y + gap;
		pDC->MoveTo(leftBrickRect.right + gap, y );
		pDC->LineTo(rightBrickRect.left - gap, y );
	}


	int count = 0;
	for (int x = leftBrickRect.right +gap + gap + sideLength; x < rightBrickRect.left; x+=sideLength,count++)
	{
		pDC->MoveTo(x, leftBrickRect.top);
		pDC->LineTo(x, leftBrickRect.bottom);
		x = x + gap;
		pDC->MoveTo(x, leftBrickRect.top);
		pDC->LineTo(x, leftBrickRect.bottom);
		if (count == 10){
			pen.m_hObject = NULL;
			pen.CreatePen(PS_DOT, 1, RGB(255, 0, 0));
			pDC->SelectObject(pen);
		}
	}

	Tile *tile = new Tile(0,0,0,0);
	try{
	tile->createTile();
	}
	catch (std::exception e){
		std::cout << "" << std::endl;
	}


	CRect scoreRect(rightBrickRect.right + gap * 2, rightBrickRect.top, rightBrickRect.right + 140, rightBrickRect.bottom);
	pDC->Rectangle(scoreRect);

	std::list<Coordinates*>::iterator iter2 = inst->getCoors()->begin();
	Coordinates *coor0 = *iter2;
	int x = coor0->getX();
	int y = coor0->getY();

	rect2 = new CRect;
	rect2->left = x;
	rect2->top = y;
	rect2->right = x + sideLength;
	rect2->bottom = y + sideLength;
	pDC->FillRect(rect2, &brush);

	while (iter2 != inst->getCoors()->end())
	{
		Coordinates *coor1 = *iter2;
		int x = coor1->getX();
		int y = coor1->getY();
		iter2++;
	}

	c0 = new CRect;
	c0->left = rect2->left + sideLength + gap;
	c0->top = rect2->top;
	c0->bottom = rect2->bottom;
	c0->right = rect2->right + sideLength + gap;
	pDC->FillRect(c0, &brush);

	c1 = new CRect;
	c1->left = c0->left + sideLength + gap;
	c1->top = rect2->top;
	c1->bottom = rect2->bottom;
	c1->right = c0->right + sideLength + gap;
	pDC->FillRect(c1, &brush);

	c2 = new CRect;
	c2->left = c1->left + sideLength + gap;
	c2->top = rect2->top;
	c2->right = c1->right + sideLength + gap;
	c2->bottom = rect2->bottom;
	pDC->FillRect(c2, &brush);

	std::cout << "111111111111" << std::endl;
} 