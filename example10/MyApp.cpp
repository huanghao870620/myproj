///////////////////////////////////////////////////////////
//  MyApp.cpp
//  Implementation of the Class MyApp
//  Created on:      19-¾ÅÔÂ-2016 16:07:23
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "MyApp.h"

MyApp app;
MyApp::MyApp(){

}



MyApp::~MyApp(){

}

BOOL MyApp::InitInstance(){
	AllocConsole();
	SetConsoleTitle("");
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w+t", stdout);

	CSingleDocTemplate *temp;
	temp = new CSingleDocTemplate(IDR_MAINFRAME, RUNTIME_CLASS(MyDoc), RUNTIME_CLASS(MyFrame), RUNTIME_CLASS(MyView));
	AddDocTemplate(temp);

	CCommandLineInfo info;
	ParseCommandLine(info);
	if (!ProcessShellCommand(info)){
		return FALSE;
	}

	this->m_pMainWnd->ShowWindow(SW_SHOW);
	this->m_pMainWnd->UpdateWindow();
	return TRUE;
}