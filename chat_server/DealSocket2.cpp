///////////////////////////////////////////////////////////
//  DealSocket.cpp
//  Implementation of the Class DealSocket
//  Created on:      08-����-2016 13:53:00
//  Original author: huang.hao
///////////////////////////////////////////////////////////
#include<iostream>
#include "SocketList.h"
#include "DealSocket2.h"

UINT ThreadFun(LPVOID);

DealSocket2::DealSocket2(SOCKET * socket){	
	this->socket = socket;
	this->cwt = AfxBeginThread(ThreadFun, (LPVOID)this->socket, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);
}

UINT ThreadFun(LPVOID lParam){
	char receiveBuf[100];
	SOCKET * socket = (SOCKET*)lParam;
	recv(*socket, receiveBuf, strlen(receiveBuf) + 1, 0);
	int comp = strcmp(receiveBuf, "");

	SocketList * sockList = SocketList::getInstance();
	sockList->messaging(receiveBuf);
	return 0;
}

DealSocket2::~DealSocket2(){

}

void DealSocket2::Start(){
	this->cwt->ResumeThread();
}