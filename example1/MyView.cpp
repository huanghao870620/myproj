///////////////////////////////////////////////////////////
//  MyView.cpp
//  Implementation of the Class MyView
//  Created on:      09-����-2016 14:04:31
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

void MyView::OnDraw(CDC *pDC){
	RECT * rect = new RECT;
	rect->top = 0;
	rect->left = 0;
	rect->bottom = 100;
	rect->right = 100;
	pDC->DrawText("dddddd", rect, DT_MODIFYSTRING);
}