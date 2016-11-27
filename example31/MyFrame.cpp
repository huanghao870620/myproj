///////////////////////////////////////////////////////////
//  MyFrame.cpp
//  Implementation of the Class MyFrame
//  Created on:      16-十月-2016 22:43:36
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "MyFrame.h"

IMPLEMENT_DYNCREATE(MyFrame,CFrameWnd)

MyFrame::MyFrame(){
	std::cout << "aas" << std::endl;
}



MyFrame::~MyFrame(){

}

int MyFrame::OnCreate(LPCREATESTRUCT lpCreateStruct){
	if (!this->m_wndDlgDisplay.Create("跟踪目标信息显示", this, CRect(200, 100, 300, 300), TRUE, IDD_DIALOG_DISPLAY, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_BOTTOM | CBRS_FLOAT_MULTI, AFX_CBRS_REGULAR_TABS, AFX_CBRS_REGULAR_TABS| AFX_CBRS_AUTOHIDE | AFX_CBRS_RESIZE)){
		TRACE0("未能创建停靠窗口");
		return FALSE;
	}
	this->m_wndDlgDisplay.EnableDocking(CBRS_ALIGN_ANY);
	return 0;
}

BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()