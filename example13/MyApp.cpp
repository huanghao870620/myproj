///////////////////////////////////////////////////////////
//  MyApp.cpp
//  Implementation of the Class MyApp
//  Created on:      22-¾ÅÔÂ-2016 10:52:55
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "MyApp.h"

MyApp app;
MyApp::MyApp(){
	this->a = new A;
}



MyApp::~MyApp(){

}

HANDLE hEvents[2];

CCriticalSection d;

void f0(LPVOID lParam){
	while (true){
		//d.Lock();
	//EnterCriticalSection(d);
	std::cout << "A : " ;
	A * a0 = app.getA();
	a0->add();
	int aInt = a0->getA();
	std::cout << aInt << std::endl;
	//LeaveCriticalSection(d);
	Sleep(1000);
	}

}

void f1(LPVOID lParam){
	while (true){
	std::cout << "B";
	Sleep(1000);
	}
}

void f2(LPVOID lParam){
	while (true){
		std::cout << "C";
		Sleep(1000);
	}
}

A* MyApp::getA(){
	return this->a;
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

	CWinThread *th0 = AfxBeginThread((AFX_THREADPROC)f0, 0, THREAD_PRIORITY_NORMAL, CREATE_SUSPENDED);
	th0->ResumeThread();

	CWinThread *th1 = AfxBeginThread((AFX_THREADPROC)f1, 0, THREAD_PRIORITY_NORMAL, CREATE_SUSPENDED);
	th1->ResumeThread();

	CWinThread *th2 = AfxBeginThread((AFX_THREADPROC)f2, 0, THREAD_PRIORITY_NORMAL, CREATE_SUSPENDED);
	th2->ResumeThread();
	return TRUE;
}