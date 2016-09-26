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

}



MyView::~MyView(){

}

void MyView::OnDraw(CDC*pDC){
	/*CRect rect;
	GetClientRect(&rect);
	pDC->FillSolidRect(rect, RGB(255, 255, 255));*/
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


	/*CPen pen;
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
	pDC->LineTo(leftBrickRect.right + gap + gap, leftBrickRect.bottom);*/

	//Singleton *d = Singleton::getSingleton();

	/*for (int y = leftBrickRect.top + gap + sideLength; y < rightBrickRect.bottom; y += sideLength)
	{
		for (int x = leftBrickRect.right + gap + gap + sideLength; x < rightBrickRect.left; x += sideLength){

		}
	}*/


	/*this->dto = new Dto;
	std::list<Coordinates*> *xList = new std::list<Coordinates*>;
	this->dto->setXList(xList);

	this->arrayDto = new ArrayDto;
	int *xArray = new int[10];
	int *yArray = new int[10];


	int count = 0;
	for (int y = leftBrickRect.top + gap + sideLength; y < rightBrickRect.bottom; y += sideLength,count++)
	{
		Coordinates * coor = new Coordinates;
		
		yArray[count] = y;
		pDC->MoveTo(leftBrickRect.right + gap, y);
		pDC->LineTo(rightBrickRect.left - gap, y);
		y = y + gap;
		pDC->MoveTo(leftBrickRect.right + gap, y);
		pDC->LineTo(rightBrickRect.left - gap, y);
	}

	count = 0;
	for (int x = leftBrickRect.right + gap + gap + sideLength; x < rightBrickRect.left; x += sideLength, count++)
	{
		xArray[count] = x;
		pDC->MoveTo(x, leftBrickRect.top);
		pDC->LineTo(x, leftBrickRect.bottom);
		x = x + gap;
		pDC->MoveTo(x, leftBrickRect.top);
		pDC->LineTo(x, leftBrickRect.bottom);
	}


	int yCount = 0;
	for (int y = leftBrickRect.top+gap+sideLength; y < rightBrickRect.bottom; y+=sideLength,yCount++)
	{
		pDC->MoveTo(leftBrickRect.right + gap, y);
		pDC->LineTo(rightBrickRect.left - gap, y);
		y = y + gap;
		pDC->MoveTo(leftBrickRect.right + gap, y );
		pDC->LineTo(rightBrickRect.left - gap, y );
	}


	 count = 0;
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
	tile->createTile();


	CRect scoreRect(rightBrickRect.right + gap * 2, rightBrickRect.top, rightBrickRect.right + 140, rightBrickRect.bottom);
	pDC->Rectangle(scoreRect);*/
}