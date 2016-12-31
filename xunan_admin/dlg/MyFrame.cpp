///////////////////////////////////////////////////////////
//  MyFrame.cpp
//  Implementation of the Class MyFrame
//  Created on:      22-九月-2016 10:52:58
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "MyFrame.h"

IMPLEMENT_DYNCREATE(MyFrame,CFrameWnd)

MyFrame::MyFrame(){
	std::cout << "框架构造" << std::endl;
}

BOOL  MyFrame::OnCreate(LPCREATESTRUCT lpStruct){
	CFrameWnd::OnCreate(lpStruct);
	HICON ico = AfxGetApp()->LoadIcon(IDI_ICON1);
	SetIcon(ico, true);
	return TRUE;
}



MyFrame::~MyFrame(){
	
}

BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()