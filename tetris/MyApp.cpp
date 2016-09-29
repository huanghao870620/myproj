///////////////////////////////////////////////////////////
//  MyApp.cpp
//  Implementation of the Class MyApp
//  Created on:      23-¾ÅÔÂ-2016 9:04:26
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "MyApp.h"

MyApp app;
MyApp::MyApp(){

}



MyApp::~MyApp(){

}

long a = 0;
void f(){
	std::cout << "111111111111112222222222222" << std::endl;
	while (true){
		a++;
		std::cout << a << std::endl;
	}
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
	//AFX_THREADPROC d;
	CWinThread *cwin = AfxBeginThread((AFX_THREADPROC)f, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED,0,0);
	cwin->ResumeThread();
	//cwin->r
	return TRUE;
}