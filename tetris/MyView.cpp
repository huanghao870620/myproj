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
	CRect rightBrickRect(leftBrickRect.left + 300, leftBrickRect.top, leftBrickRect.right + 300, leftBrickRect.bottom);
	LeftBrick *rb = new LeftBrick(pDC, &rightBrickRect,&brush,&pen);
	rb->drawBrick();
	delete rb;


	/*CRect brickCrect(100, 100, 120, 120);
	pDC->Rectangle(brickCrect);
	CRect innerBrickCrect(107, 107, 113, 113);
	pDC->Rectangle(innerBrickCrect);
	brush.m_hObject = NULL;
	brush.CreateSolidBrush(RGB(0, 0, 0));
	pDC->FillRect(innerBrickCrect,&brush);*/

	pen.m_hObject = NULL;
	pen.CreatePen(PS_DOT, 1, RGB(0, 0, 0));
	pDC->SelectObject(pen);
	pDC->MoveTo(leftBrickRect.right + gap, leftBrickRect.top);
	pDC->LineTo(rightBrickRect.left - gap, leftBrickRect.top);
	pDC->LineTo(rightBrickRect.left - gap, leftBrickRect.bottom);
	pDC->LineTo(leftBrickRect.right + gap, leftBrickRect.bottom);
	pDC->LineTo(leftBrickRect.right + gap, leftBrickRect.top);


	for (int i = leftBrickRect.top+sideLength; i < rightBrickRect.bottom; i+=sideLength)
	{
		pDC->MoveTo(leftBrickRect.right + gap, i);
		pDC->LineTo(rightBrickRect.left - gap, i);

		i = i + gap;
		pDC->MoveTo(leftBrickRect.right + gap, i );
		pDC->LineTo(rightBrickRect.left - gap, i );
	}


	int count = 0;
	for (int i = leftBrickRect.right +gap+ sideLength; i < rightBrickRect.left; i+=sideLength,count++)
	{
		pDC->MoveTo(i, leftBrickRect.top);
		pDC->LineTo(i, leftBrickRect.bottom);

		i = i + gap;
		pDC->MoveTo(i, leftBrickRect.top);
		pDC->LineTo(i, leftBrickRect.bottom);
		/*if (count == 10){
			std::cout << "i = " << i << std::endl;
		}*/
		/*std::cout << "i = " << i << std::endl;
		std::cout << " i + gap : " << i + gap << std::endl;*/
	}

	pDC->MoveTo(leftBrickRect.right + gap, leftBrickRect.top + gap);
	pDC->LineTo(rightBrickRect.left - gap, leftBrickRect.top + gap);

	pDC->MoveTo(leftBrickRect.right + gap + gap, leftBrickRect.top);
	pDC->LineTo(leftBrickRect.right + gap + gap, leftBrickRect.bottom);
}