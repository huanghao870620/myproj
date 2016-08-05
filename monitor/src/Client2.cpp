///////////////////////////////////////////////////////////
//  Client.cpp
//  Implementation of the Class Client
//  Created on:      20-七月-2016 13:37:45
//  Original author: huang.hao
///////////////////////////////////////////////////////////
#include "ReadIniFile.h"
#include "Client2.h"

#define DEFAULT_BUFLEN 512

Client2::Client2(){
	WSADATA wsaData;
	WORD versionRequested = MAKEWORD(1, 1);
	WSAStartup(versionRequested, &wsaData); //初始化dll
	this->sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // 创建socket
	if (sock <= 0){
		::MessageBox(NULL, _T("创建socket失败"), _T(""), MB_OK);
		return;
	}

	SOCKADDR_IN sockaddr_in;
	sockaddr_in.sin_family = AF_INET;
	sockaddr_in.sin_port = htons(6000);

	char server_ip[100];
	ReadIniFile::get_server_ip(server_ip);
	sockaddr_in.sin_addr.S_un.S_addr = inet_addr(server_ip);
	int resp = connect(sock, (SOCKADDR*)& sockaddr_in, sizeof(sockaddr_in));
	if (resp != 0){
		::MessageBox(NULL, _T("socket连接失败"), _T(""), MB_OK);
		return;
	}
	/*char buf[DEFAULT_BUFLEN];
	send(sock, buf, DEFAULT_BUFLEN, 0);*/
}



Client2::~Client2(){

}

void Client2::sendMsg(char * msg){
	send(this->sock, msg, strlen(msg), 0);
}