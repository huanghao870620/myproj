
#include <WinSock2.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <exception>
#include <boost\locale.hpp>
#pragma comment(lib, "ws2_32.lib")

#include "ConnSocket.h"



ConnSocket::ConnSocket() 
{
	this->init();
}

ConnSocket::~ConnSocket() 
{
}


//初始化
void ConnSocket::init() 
{
	
	WORD myVersionRequest = MAKEWORD(1, 1); //; // request

	//开始
	err = WSAStartup(myVersionRequest, &wsaData);

	if (err != 0){
		printf("失败 !");
		return;
	}

	//创建socket
	SOCKET serSocket = socket(AF_INET, SOCK_STREAM, 0);

	//失败
	if (serSocket == INVALID_SOCKET){
		std::cout << "create socket fail!" << std::endl;
		return;
	}


	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	//设置端口
	addr.sin_port = htons(6000);

	//绑定
	bind(serSocket, (SOCKADDR*)&addr, sizeof(SOCKADDR));

	//监听
	listen(serSocket, 5);

	int len = sizeof(SOCKADDR);

    // 循环体
	//获取socket
	this->serConn = accept(serSocket, (SOCKADDR*)&clientsocket, &len);

	//格式化ip
	//sprintf(sendBuf, "welcome %s to bejing", inet_ntoa(clientsocket.sin_addr));

	//发送文本
	//send(serConn, sendBuf, strlen(sendBuf) + 1, 0);
	//this->sendMsg();

	//接收文本
	//recv(serConn, receiveBuf, strlen(receiveBuf) + 1, 0);

	//string c0 = boost::locale::conv::between(receiveBuf, "UTF-8", "gb2312");
}


void ConnSocket::sendMsg(){
 char sendBuf[100] = "from vs\0";
 send(this->serConn, sendBuf, strlen(sendBuf) + 1, 0);
}

void ConnSocket::receiveMsg(){
	char receiveBuf[100];
	recv(this->serConn, receiveBuf, strlen(receiveBuf) + 1, 0);
	std::cout << "33" << std::endl;
}

void ConnSocket::Close(){
	//关闭socket
	closesocket(this->serConn);

	//清理
	WSACleanup();
}


