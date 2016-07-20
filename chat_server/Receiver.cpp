///////////////////////////////////////////////////////////
//  Receiver.cpp
//  Implementation of the Class Receiver
//  Created on:      19-七月-2016 19:02:24
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "Receiver.h"


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

	SOCKADDR_IN client_sock_addr_in;
	SOCKET client_socket;

	SOCKADDR * client_sock_addr = (SOCKADDR *)& client_sock_addr_in;
	int len = sizeof(SOCKADDR); // 
	accept(client_socket, client_sock_addr, & len); //

}



Receiver::~Receiver(){

}