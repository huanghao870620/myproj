//#define _AFXDLL
#include <afxwin.h>
#include "Client.h"
#include "RecvThread.h"

UINT recvFun(LPVOID);
RecvThread::RecvThread(Client * client) 
{
	this->client = client;
	this->pThread = AfxBeginThread(recvFun, (LPVOID)this->client, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);
	this->pThread->ResumeThread(); // Æô¶¯Ïß³Ì
}

RecvThread::~RecvThread() 
{
}

UINT recvFun(LPVOID pParam){
	Client &client =  *(Client *)pParam;
	while (true)
	{
		client.Send("get\0");
		client.Recv();
		Sleep(1000);
	}

	return 0;
}
