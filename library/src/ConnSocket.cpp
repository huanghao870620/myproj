
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


//��ʼ��
void ConnSocket::init() 
{
	
	WORD myVersionRequest = MAKEWORD(1, 1); //; // request

	//��ʼ
	err = WSAStartup(myVersionRequest, &wsaData);

	if (err != 0){
		printf("ʧ�� !");
		return;
	}

	//����socket
	SOCKET serSocket = socket(AF_INET, SOCK_STREAM, 0);

	//ʧ��
	if (serSocket == INVALID_SOCKET){
		std::cout << "create socket fail!" << std::endl;
		return;
	}


	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	//���ö˿�
	addr.sin_port = htons(6000);

	//��
	bind(serSocket, (SOCKADDR*)&addr, sizeof(SOCKADDR));

	//����
	listen(serSocket, 5);

	int len = sizeof(SOCKADDR);

    // ѭ����
	//��ȡsocket
	this->serConn = accept(serSocket, (SOCKADDR*)&clientsocket, &len);

	//��ʽ��ip
	//sprintf(sendBuf, "welcome %s to bejing", inet_ntoa(clientsocket.sin_addr));

	//�����ı�
	//send(serConn, sendBuf, strlen(sendBuf) + 1, 0);
	//this->sendMsg();

	//�����ı�
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
	//�ر�socket
	closesocket(this->serConn);

	//����
	WSACleanup();
}


