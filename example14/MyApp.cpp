///////////////////////////////////////////////////////////
//  MyApp.cpp
//  Implementation of the Class MyApp
//  Created on:      07-Ê®ÔÂ-2016 17:15:52
//  Original author: huanghao
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
	temp = new CSingleDocTemplate(0, RUNTIME_CLASS(MyDoc), RUNTIME_CLASS(MyFrame), RUNTIME_CLASS(MyView));
	AddDocTemplate(temp);



	return TRUE;
}