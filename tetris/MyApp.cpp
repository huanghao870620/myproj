///////////////////////////////////////////////////////////
//  MyApp.cpp
//  Implementation of the Class MyApp
//  Created on:      23-╬етб-2016 9:04:26
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "MyApp.h"
#include <TlHelp32.h>

MyApp app;
MyApp::MyApp(){

}



MyApp::~MyApp(){

}




void f(LPVOID lParam){
	A0*a = new A0;
	char **c = new char*[2]{"aaa0", "d:/test/bbb0"};
	a->test6(2, c);
	
	delete a;
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
	CWinThread *cwin = AfxBeginThread((AFX_THREADPROC)f, (LPVOID)this->m_pMainWnd,THREAD_PRIORITY_NORMAL,  CREATE_SUSPENDED,0,0);
	cwin->ResumeThread();
	return TRUE;
}

