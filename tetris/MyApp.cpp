///////////////////////////////////////////////////////////
//  MyApp.cpp
//  Implementation of the Class MyApp
//  Created on:      23-九月-2016 9:04:26
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "MyApp.h"
#include <TlHelp32.h>

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

void addCom(LPVOID lParam){
	while (true)
	{
		Queue *queue = Queue::getInstance();
		queue->add();
		//std::cout << "=======================" << std::endl;
		std::cout << "size : " << queue->getSize() << std::endl;
		Sleep(5000);
	}
}


void TestProcessGetThreadNumber(){
	int i = 0;
	char Buff[9];
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(pe32);

	HANDLE hProcessSnap= CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE){
		//std::cout << "CreateToolhelp32Snapshot 调用失败." << std::endl;
		return;
	}

	BOOL bMore= Process32First(hProcessSnap, &pe32);
	HANDLE hProcess;
	std::cout << "" << std::endl;
	while (bMore)
	{
		/*std::cout << pe32.szExeFile << std::endl;
		std::cout << pe32.th32ProcessID << std::endl;
		std::cout << pe32.th32ParentProcessID << std::endl;
		std::cout << pe32.cntThreads << std::endl;*/
		bMore= Process32Next(hProcessSnap, &pe32);
		i++;
	}

	HANDLE currentProcess= GetCurrentProcess();
	HANDLE currentThread= GetCurrentThread();

	HANDLE hThread;
	DuplicateHandle(GetCurrentProcess(), GetCurrentThread(), GetCurrentProcess(), &hThread, 0, FALSE, DUPLICATE_SAME_ACCESS);

	std::cout << "进程数: " << i << std::endl;



	HANDLE hSnapshort= CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
	if (hSnapshort == INVALID_HANDLE_VALUE){
		std::cout << "CreateToolhelp32Snapshot调用失败" << std::endl;
		return;
	}

	THREADENTRY32 stcThreadInfo;
	stcThreadInfo.dwSize = sizeof(stcThreadInfo);
	BOOL bRet= Thread32First(hSnapshort, &stcThreadInfo);
	DWORD dwProId = -1;
	unsigned unCount = 0;

	while (bRet)
	{
		if (dwProId != stcThreadInfo.th32OwnerProcessID){
			if (dwProId != -1){
				std::cout << dwProId <<"\t"<< unCount << std::endl;
				unCount = 0;
				std::cout << "" << std::endl;
			}
			dwProId= stcThreadInfo.th32OwnerProcessID;
			std::cout << dwProId << std::endl;
		}
		std::cout << stcThreadInfo.th32ThreadID << stcThreadInfo.th32OwnerProcessID
			<< stcThreadInfo.tpBasePri << std::endl;
		bRet = Thread32Next(hSnapshort, &stcThreadInfo);
	}
	std::cout << dwProId << unCount << std::endl;
	unCount = 0;
	CloseHandle(hSnapshort);


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
	TestProcessGetThreadNumber();
	return TRUE;
}