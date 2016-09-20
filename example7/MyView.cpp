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
	ON_BN_CLICKED(IDC_CHECKBOX0,MyView::OnCheckBox0)
	ON_BN_CLICKED(IDC_CHECKBOX1,MyView::OnCheckBox1)
	ON_BN_CLICKED(IDC_CHECKBOX2,MyView::OnCheckBox2)
	ON_BN_CLICKED(IDC_CHECKBOX3,MyView::OnCheckBox3)
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
	this->m_wndListCtrl.InsertColumn(0, "ID", LVCFMT_LEFT, 40);
	this->m_wndListCtrl.InsertColumn(1, "Name", LVCFMT_LEFT, 50);
	int nRow = this->m_wndListCtrl.InsertItem(0, "11");
	this->m_wndListCtrl.SetItemText(nRow, 1, "jacky");

	CRect rect9(620, 110, 670, 120);
	this->m_wndCheckBox0.Create("a", WS_CHILD | WS_VISIBLE | BS_CHECKBOX, rect9, this, IDC_CHECKBOX0);

	CRect rect10(680, 110, 730, 120);
	this->m_wndCheckBox1.Create("b", WS_CHILD | WS_VISIBLE | BS_CHECKBOX, rect10, this, IDC_CHECKBOX1);

	CRect rect11(740, 110, 790, 120);
	this->m_wndCheckBox2.Create("c", WS_CHILD | WS_VISIBLE | BS_CHECKBOX, rect11, this, IDC_CHECKBOX2);

	CRect rect12(800, 110, 850, 120);
	this->m_wndCheckBox3.Create("d", WS_CHILD | WS_VISIBLE | BS_CHECKBOX, rect12, this, IDC_CHECKBOX3);
	
	CRect rect13(520, 110, 570, 130);
	this->m_wndStatic.Create("¸´Ñ¡¿ò:", WS_CHILD | WS_VISIBLE | SS_CENTER, rect13, this);
	return TRUE;
}

void MyView::OnButton(){
	std::cout << "333" << std::endl;
}

void MyView::OnCheckBox0(){
	this->m_wndCheckBox0.SetCheck(this->m_wndCheckBox0.GetCheck() == BST_CHECKED ? BST_UNCHECKED : BST_CHECKED);
}

void MyView::OnCheckBox1(){
	this->m_wndCheckBox1.SetCheck(this->m_wndCheckBox1.GetCheck() == BST_CHECKED ? BST_UNCHECKED : BST_CHECKED);
}

void MyView::OnCheckBox2(){
	this->m_wndCheckBox2.SetCheck(this->m_wndCheckBox2.GetCheck() == BST_CHECKED ? BST_UNCHECKED : BST_CHECKED);
}

void MyView::OnCheckBox3(){
	this->m_wndCheckBox3.SetCheck(this->m_wndCheckBox3.GetCheck() == BST_CHECKED ? BST_UNCHECKED : BST_CHECKED);
}