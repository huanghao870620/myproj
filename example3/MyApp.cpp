///////////////////////////////////////////////////////////
//  MyApp.cpp
//  Implementation of the Class MyApp
//  Created on:      14-����-2016 14:15:17
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
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);
	CCommandLineInfo info;
	ParseCommandLine(info);
	if (!ProcessShellCommand(info)){
		return False;
	}

	return TRUE;
}