#include <iostream>
#include <afxwin.h>
#include "RecvThread.h"

#include "StruInte.h"
#include "Client.h"
#include "DrawFlag.h"
#include "MfcMulti.h"

using namespace std;

UINT ThreadFun(LPVOID);

MfcMulti::MfcMulti() 
{
	this->client = new Client();
	this->recvThread = new RecvThread(this->client);

	pThread = AfxBeginThread(ThreadFun, (LPVOID)this->client, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);
}

MfcMulti::~MfcMulti() 
{
	delete this->client;
	delete this->recvThread;
	delete this->pThread;
}


UINT ThreadFun(LPVOID pParam){
	Client * client = (Client *)pParam;
	while (true)
	{
		RECT rect;
		std::list<StruInte *> * list =  client->get_st();
		CWnd *pMainWnd = AfxGetMainWnd();
		LPARAM time = GetCurrentTime();
		pMainWnd->GetClientRect(&rect);
		::PostMessageA(pMainWnd->m_hWnd, WM_PAINT, 0, (LPARAM)list);
		::InvalidateRect(pMainWnd->m_hWnd, &rect, FALSE);
		Sleep(1000);
	}
	return 0;
}

/*启动线程*/
void MfcMulti::Start() {
	pThread->ResumeThread();
}

/*获取消息*/
std::list<StruInte *> *  MfcMulti::get_st(){
	return &this->st;
}

Client & MfcMulti::getClientRef(){
	return *this->client;
}


