///////////////////////////////////////////////////////////
//  MyApp.cpp
//  Implementation of the Class MyApp
//  Created on:      16-¾ÅÔÂ-2016 10:53:27
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
	freopen("", "", stdin);
	freopen("", "", stdout);


	return TRUE;
}