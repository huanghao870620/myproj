///////////////////////////////////////////////////////////
//  MyFrame.cpp
//  Implementation of the Class MyFrame
//  Created on:      23-¾ÅÔÂ-2016 9:04:28
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "MyFrame.h"

IMPLEMENT_DYNCREATE(MyFrame,CFrameWnd)
BEGIN_MESSAGE_MAP(MyFrame,CFrameWnd)
END_MESSAGE_MAP()
MyFrame::MyFrame(){

}



MyFrame::~MyFrame(){

}

BOOL MyFrame::PreCreateWindow(CREATESTRUCT &cs){
	cs.style &= ~(WS_MAXIMIZEBOX | WS_THICKFRAME);
	cs.cx = 500;
	cs.cy = 600;
	CFrameWnd::PreCreateWindow(cs);
	return TRUE;
}