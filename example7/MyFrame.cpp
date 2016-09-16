///////////////////////////////////////////////////////////
//  MyFrame.cpp
//  Implementation of the Class MyFrame
//  Created on:      16-¾ÅÔÂ-2016 15:38:59
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "MyFrame.h"

IMPLEMENT_DYNCREATE(MyFrame,CFrameWnd)
BEGIN_MESSAGE_MAP(MyFrame,CFrameWnd)
END_MESSAGE_MAP()
MyFrame::MyFrame(){
	CRect rect(0, 0, 100, 100);
	this->m_wndPushButton.Create("ddd", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, rect, this, IDC_BUTTON);
}



MyFrame::~MyFrame(){

}