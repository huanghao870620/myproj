#include <iostream>
#include <afxwin.h>
#include <afxdisp.h>
#include "CMyFrameWnd.h"
#include "CMyWinApp.h"

using namespace std;

CMyWinApp::CMyWinApp() 
{
}

CMyWinApp::~CMyWinApp() 
{
}

CMyWinApp theApp;
BOOL CMyWinApp::InitInstance() {
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
