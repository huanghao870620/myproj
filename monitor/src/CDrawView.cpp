///////////////////////////////////////////////////////////
//  CDrawView.cpp
//  Implementation of the Class CDrawView
//  Created on:      09-°ËÔÂ-2016 16:09:35
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "CDrawView.h"

//
IMPLEMENT_DYNCREATE(CDrawView, CScrollView)
//
//BEGIN_MESSAGE_MAP(MyView, CView)
//END_MESSAGE_MAP()

CDrawView::CDrawView(){
	std::cout << "" << std::endl;
}



CDrawView::~CDrawView(){

}

void CDrawView::OnDraw(CDC * pDC){
	pDC->DrawText("11111111111111111111111111122222222222222222sddddddddddddddddddsssssssssssssss", CRect(100, 100, 500, 500), DT_CENTER);
}