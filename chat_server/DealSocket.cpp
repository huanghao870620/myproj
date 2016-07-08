///////////////////////////////////////////////////////////
//  DealSocket.cpp
//  Implementation of the Class DealSocket
//  Created on:      08-ÆßÔÂ-2016 13:53:00
//  Original author: huang.hao
///////////////////////////////////////////////////////////
#include<iostream>
#include "DealSocket.h"

UINT ThreadFun(LPVOID);

DealSocket::DealSocket(SOCKET * socket){	
	this->socket = socket;
	this->cwt = AfxBeginThread(ThreadFun, (LPVOID)this->socket, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);
}

UINT ThreadFun(LPVOID lParam){
	SOCKET * socket = (SOCKET*)lParam;
	//std::cout << "===bb====" << std::endl;
	char receiveBuf[100];
	recv(*socket, receiveBuf, strlen(receiveBuf) + 1, 0);
	int comp = strcmp(receiveBuf, "");
	if (comp){
		OutputDebugString("");
	}
	return 0;
}

DealSocket::~DealSocket(){

}

void DealSocket::Start(){
	this->cwt->ResumeThread();
}