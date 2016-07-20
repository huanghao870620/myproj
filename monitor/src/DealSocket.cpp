///////////////////////////////////////////////////////////
//  DealSocket.cpp
//  Implementation of the Class DealSocket
//  Created on:      19-ÆßÔÂ-2016 14:31:10
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "DealSocket.h"

UINT fun(LPVOID lParam){
	return 0;
}

DealSocket::DealSocket(SOCKET * socket){
	this->socket = socket;
	this->cwt = AfxBeginThread(fun, (LPVOID)socket, THREAD_PRIORITY_NORMAL, 0,CREATE_SUSPENDED);
	this->cwt->ResumeThread();
}



DealSocket::~DealSocket(){

}