///////////////////////////////////////////////////////////
//  MyFrame.cpp
//  Implementation of the Class MyFrame
//  Created on:      16-¾ÅÔÂ-2016 9:50:33
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "MyFrame.h"

BEGIN_MESSAGE_MAP(MyFrame,CFrameWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()
MyFrame::MyFrame(){
	this->Create(NULL, "The Hello Application");
}



MyFrame::~MyFrame(){

}

void MyFrame::OnPaint(){
	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	dc.DrawText("Hello,MFC", &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}