///////////////////////////////////////////////////////////
//  Receiver.cpp
//  Implementation of the Class Receiver
//  Created on:      19-七月-2016 19:02:24
//  Original author: huang.hao
///////////////////////////////////////////////////////////
#include<iostream>
#define DEFAULT_BUFLEN 512
#include "SocketList.h"
#include "Receiver.h"


UINT fun(LPVOID lParam){
	SOCKET * client_socket = (SOCKET *)lParam;
	char recv_msg[DEFAULT_BUFLEN];
	recv(*client_socket, recv_msg, DEFAULT_BUFLEN, 0);
	char * b = recv_msg;
	for (int i = 0; i < DEFAULT_BUFLEN; i++, b++){
		if (*b == -52){
			*b = '\0';
			break;
		}
	}

	SocketList * sockList = SocketList::getInstance();
	return 0;
}

Receiver::Receiver(){
	WORD reqVersion = MAKEWORD(1, 1);
	WSADATA data;
	int success = WSAStartup(reqVersion, &data);
	if (success != 0){
		::MessageBox(NULL, _T("初始化dll失败"), _T(""), MB_OK);
		return;
	}

	SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0); // 服务端socket
	if (serverSocket == INVALID_SOCKET){
		::MessageBox(NULL, _T("创建服务端socket失败"), _T(""), MB_OK);
		return;
	}
	
	SOCKADDR_IN server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(6000);

	SOCKADDR * server_sock_addr = (SOCKADDR *)& server_addr;
	bind(serverSocket, server_sock_addr, sizeof(SOCKADDR));
	listen(serverSocket, 5);

	SOCKADDR_IN client_sock_addr_in;
	SOCKADDR * client_sock_addr = (SOCKADDR *)& client_sock_addr_in;
	int len = sizeof(SOCKADDR); // 
	OutputDebugString("--- front accept --");
	while (true){
	SOCKET client_socket = accept(serverSocket, client_sock_addr, & len); //
	this->clients.push_back(&client_socket);
	CWinThread * cwt = AfxBeginThread(fun, (LPVOID)&client_socket, THREAD_PRIORITY_HIGHEST, 0, CREATE_SUSPENDED);
	cwt->ResumeThread(); // 恢复线程
	}
}


Receiver::~Receiver(){

}