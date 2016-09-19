///////////////////////////////////////////////////////////
//  MyView.cpp
//  Implementation of the Class MyView
//  Created on:      16-¾ÅÔÂ-2016 15:39:01
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "MyView.h"

IMPLEMENT_DYNCREATE(MyView,CView)
BEGIN_MESSAGE_MAP(MyView,CView)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON, MyView::OnButton)
END_MESSAGE_MAP()
MyView::MyView(){
	
}



MyView::~MyView(){

}

void MyView::OnDraw(CDC*pDC){

}

BOOL MyView::OnCreate(LPCREATESTRUCT lpCreateStruct){
	CRect rect(0, 0, 100, 100);
	this->m_wndPushButton.Create("ddd", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, rect, this, IDC_BUTTON);
	this->m_wndPushButton.ShowWindow(SW_SHOW);

	CRect rect2(101, 101, 200, 200);
	this->m_wndRadio.Create("radio", WS_CHILD | WS_VISIBLE|BS_CHECKBOX, rect2, this, IDC_RADIO);
	return TRUE;
}

void MyView::OnButton(){
	std::cout << "333" << std::endl;
}