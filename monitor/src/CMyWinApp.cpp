#include <iostream>
#include <afxwin.h>
#include <afxdisp.h>
#include "CMyFrameWnd.h"
#include "CMyWinApp.h"
#include "vld.h"

using namespace std;

CMyWinApp::CMyWinApp() 
{
	//this->init();
}

CMyWinApp::~CMyWinApp() 
{
	//FreeConsole();
}

CMyWinApp theApp;
BOOL CMyWinApp::InitInstance() {
	//AfxOleInitModule();
	AfxOleInit();
	
	this->m_pMainWnd = new CMyFrameWnd;
	this->m_pMainWnd->ShowWindow(this->m_nCmdShow);
	this->m_pMainWnd->UpdateWindow();
	return TRUE;
}

void CMyWinApp::init() {
	AllocConsole();
	freopen("CONOUT$", "w+t", stdout);
	printf("hello world! \n");
}
