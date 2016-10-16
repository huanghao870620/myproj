///////////////////////////////////////////////////////////
//  MyApp.cpp
//  Implementation of the Class MyApp
//  Created on:      16-Ê®ÔÂ-2016 16:39:22
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "MyApp.h"


MyApp::MyApp(){

}



MyApp::~MyApp(){

}

CEvent g_event;

UINT f0(LPVOID lParam){
	return(0);
}

UINT f1(LPVOID lParam){
	return(0);
}


MyApp app;
BOOL MyApp::InitInstance(){
	AllocConsole();
	SetConsoleTitle("");
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w+t", stdout);

	AfxBeginThread(f0, NULL);
	AfxBeginThread(f1, NULL);
	return TRUE;
}