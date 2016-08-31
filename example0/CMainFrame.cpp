///////////////////////////////////////////////////////////
//  CMainFrame.cpp
//  Implementation of the Class CMainFrame
//  Created on:      29-°ËÔÂ-2016 17:19:22
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "CMainFrame.h"

BEGIN_MESSAGE_MAP(CMainFrame,CFrameWnd)
END_MESSAGE_MAP()


IMPLEMENT_DYNCREATE(CMainFrame,CFrameWnd)

CMainFrame::CMainFrame(){
	std::cout << "create cmainframe" << std::endl;
}



CMainFrame::~CMainFrame(){

}