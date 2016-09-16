///////////////////////////////////////////////////////////
//  MyApp.cpp
//  Implementation of the Class MyApp
//  Created on:      16-¾ÅÔÂ-2016 15:38:57
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "MyApp.h"


MyApp::MyApp(){

}



MyApp::~MyApp(){

}

BOOL MyApp::InitInstance(){
	AllocConsole();
	SetConsoleTitle("");
	freopen("", "", stdin);
	freopen("", "", stdout);

	CSingleDocTemplate *temp;

	return TRUE;
}