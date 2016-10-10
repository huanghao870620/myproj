///////////////////////////////////////////////////////////
//  MyApp.cpp
//  Implementation of the Class MyApp
//  Created on:      10-Ê®ÔÂ-2016 20:28:45
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "MyApp.h"

volatile BYTE m_nShowFlag = 31;
MyApp::MyApp(){

}



MyApp::~MyApp(){

}

BOOL MyApp::InitInstance(){
	//this->m_nThread = CreateThread(NULL, 0, ThreadProc, NULL, 0, &this->m_hThread);
	return TRUE;
}

