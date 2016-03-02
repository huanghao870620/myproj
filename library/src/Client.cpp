#include <stdio.h>  
#include <winsock2.h>  
#include "parser_json.h"

#include "ReadIniFile.h"
#include "DrawFlag.h"
#include "StruInte.h"
#include "Client.h"

#pragma comment(lib,"ws2_32.lib")  


Client::Client()
{
	char  server_ip[100];
	WSAStartup(MAKEWORD(1, 1), &wsa); //initial Ws2_32.dll by a process  

	if ((soc = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) <= 0)   //create a tcp socket  
	{
		::MessageBox(NULL, "Connect socket fail!", "Connect socket fail!", MB_OK);
		return;
	}

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(4000);
	
	ReadIniFile::get_server_ip(server_ip);
	serveraddr.sin_addr.S_un.S_addr = inet_addr(server_ip);

	if (connect(soc, (SOCKADDR *)&serveraddr, sizeof(serveraddr)) != 0)
	{
		::MessageBox(NULL, "Connect fail!", "Connect fail!", MB_OK);
		return;
	}

	this->pj = new parser_json();
}

Client::~Client() 
{
	delete this->pj;
}


/*¹Ø±Õ*/
void Client::Close() {
	WSACleanup(); 
}

void Client::Recv() {
	int r = recv(soc, this->recv_buf, 10000, 0);
	if (r == SOCKET_ERROR){

	}
	else{
		this->recv_buf[r] = '\0';
		
		pj->colle_msg(this->recv_buf);
		this->st = pj->get_msg_list();
	}
}

int Client::Send(const char *msg) {
	int r = send(soc, msg, 4, 0);
	if (r == SOCKET_ERROR){

	}
	else{

	}
	return 0;
}


std::list<StruInte *> * Client::get_st(){
	return this->st;
}
