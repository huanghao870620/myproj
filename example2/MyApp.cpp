///////////////////////////////////////////////////////////
//  MyApp.cpp
//  Implementation of the Class MyApp
//  Created on:      12-¾ÅÔÂ-2016 17:45:58
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "MyApp.h"


BEGIN_MESSAGE_MAP(MyApp,CWinApp)
END_MESSAGE_MAP()

MyApp app;
MyApp::MyApp(){

}

IMPLEMENT_DYNCREATE(MyApp,CWinApp)


MyApp::~MyApp(){

}

BOOL MyApp::InitInstance(){
	AllocConsole();
	SetConsoleTitle("");
	freopen("CONOUT$", "r", stdin);
	freopen("CONIN$", "w+t", stdout);

	CSingleDocTemplate *temp;
	temp = new CSingleDocTemplate(IDR_MAINFRAME, RUNTIME_CLASS(MyDoc), RUNTIME_CLASS(MyFrame), RUNTIME_CLASS(CScrollDemoView));
	AddDocTemplate(temp);
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);
	CCommandLineInfo info;
	ParseCommandLine(info);
	if (!ProcessShellCommand(info)){
		return FALSE;
	}

	return TRUE;
}