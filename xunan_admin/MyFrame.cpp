///////////////////////////////////////////////////////////
//  MyFrame.cpp
//  Implementation of the Class MyFrame
//  Created on:      22-九月-2016 10:52:58
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "MyFrame.h"

IMPLEMENT_DYNCREATE(MyFrame,CFrameWnd)
BEGIN_MESSAGE_MAP(MyFrame,CFrameWnd)
END_MESSAGE_MAP()
MyFrame::MyFrame(){
	/*this->MessageBox("看看发生的");
	::MessageBox(NULL, "所发生的2", "粉色发多少2", MB_OK);*/
	std::cout << "框架构造" << std::endl;
}



MyFrame::~MyFrame(){
	
}