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
	CRect rect(10, 10, 100, 100);
	this->m_wndPushButton.Create("pushbutton", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, rect, this, IDC_BUTTON);
	this->m_wndPushButton.ShowWindow(SW_SHOW);

	CRect rect0(110, 10, 210, 100);
	this->m_wndDefPushButton.Create("defpushbutton", WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, rect0, this, IDC_DEFPUSHBUTTON);

	CRect rect2(220, 10, 320, 100);
	this->m_wndRadio.Create("checkbox", WS_CHILD | WS_VISIBLE|BS_CHECKBOX, rect2, this, IDC_RADIO);

	CRect rect1(330, 10, 430, 100);
	this->m_wndAutoCheckBox.Create("autoCheckBox", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, rect1, this, IDC_AUTOCHECKBOX);

	CRect rect3(440, 10, 540, 100);
	this->m_wnd3State.Create("3state", WS_CHILD | WS_VISIBLE | BS_3STATE, rect3, this, IDC_3STATE);

	CRect rect4(550, 10, 650, 100);
	this->m_wndAuto3State.Create("auto3state",WS_CHILD|WS_VISIBLE|BS_AUTO3STATE,rect4,this,IDC_AUTO3STATE);

	CRect rect5(660, 10, 760, 100);
	this->m_wndRadioButton.Create("radiobutton", WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON, rect5, this, IDC_RADIOBUTTON);

	CRect rect6(770, 10, 870, 100);
	this->m_wndAutoRadioButton.Create("autoradiobutton", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, rect6, this, IDC_AUTORADIOBUTTON);

	CRect rect7(880, 10, 980, 100);
	this->m_wndGroupBox.Create("groupbox", WS_CHILD | WS_VISIBLE | BS_GROUPBOX, rect7, this, IDC_GROUPBOX);

	CRect rect8(10, 110, 510, 410);
	this->m_wndListCtrl.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_EDITLABELS, rect8, this, IDC_LISTCTRL);
	return TRUE;
}

void MyView::OnButton(){
	std::cout << "333" << std::endl;
}