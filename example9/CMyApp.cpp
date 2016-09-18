///////////////////////////////////////////////////////////
//  CMyApp.cpp
//  Implementation of the Class CMyApp
//  Created on:      18-¾ÅÔÂ-2016 12:18:58
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "CMyApp.h"

extern CMyApp myApp;
CMyApp::CMyApp(){

}



CMyApp::~CMyApp(){

}

BOOL CMyApp::InitInstance(){
	AllocConsole();
	SetConsoleTitle("");
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w+t", stdout);
	this->m_pMainWnd = new CMainWindow;
	this->m_pMainWnd->ShowWindow(SW_SHOW);
	this->m_pMainWnd->UpdateWindow();
	return TRUE;
}