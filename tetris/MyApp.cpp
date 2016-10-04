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
void f(LPVOID lParam){
	CWnd *wnd = (CWnd*)lParam;
	while (true)
	{
		wnd->Invalidate();
		Sleep(1000);
	}
}

void f0(LPVOID lParam){
	std::cout << "44444444444444444444444444" << std::endl;
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

	CWinThread *cwin0 = AfxBeginThread((AFX_THREADPROC)f0, (LPVOID)0, THREAD_PRIORITY_NORMAL, CREATE_SUSPENDED, 0, 0);
	cwin0->ResumeThread();

	Random *ran = new Random;
	ran->getRandomInt();
	return TRUE;
}