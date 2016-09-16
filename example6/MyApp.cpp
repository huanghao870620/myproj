///////////////////////////////////////////////////////////
//  MyApp.cpp
//  Implementation of the Class MyApp
//  Created on:      16-¾ÅÔÂ-2016 10:53:27
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "MyApp.h"

//BEGIN_MESSAGE_MAP(MyApp,CWinApp)
//END_MESSAGE_MAP()

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

	std::cout << "ddddd" << std::endl;

	//this->m_wndPushButton.Create("",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON)

	return TRUE;
}