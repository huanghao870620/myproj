///////////////////////////////////////////////////////////
//  MyView.cpp
//  Implementation of the Class MyView
//  Created on:      17-¾ÅÔÂ-2016 19:24:56
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "MyView.h"

IMPLEMENT_DYNCREATE(MyView,CView)
BEGIN_MESSAGE_MAP(MyView,CView)
	ON_WM_CREATE()
END_MESSAGE_MAP()
MyView::MyView(){

}



MyView::~MyView(){

}

BOOL MyView::OnCreate(LPCREATESTRUCT lpCreateStruct){
	CRect rect(0, 0, 100, 100);
	this->m_wndListBox.CreateEx(WS_EX_CLIENTEDGE, "LISTBOX", NULL, WS_CHILD | WS_VISIBLE | LBS_STANDARD, rect, this, IDC_LISTBOX);
	return TRUE;
}

void MyView::OnDraw(CDC*pDC){

}