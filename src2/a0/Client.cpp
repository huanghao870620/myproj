#include <stdio.h>  
#include <winsock2.h>  
#include "parser_json.h"

#include "ReadIniFile.h"
#include "DrawFlag.h"
#include "Client.h"

#pragma comment(lib,"ws2_32.lib")  


Client::Client(DrawFlag * df)
{
	this->df = df;
	this->rif = new ReadIniFile;
	WSAStartup(MAKEWORD(1, 1), &wsa); //initial Ws2_32.dll by a process  

	if ((soc = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) <= 0)   //create a tcp socket  
	{
		printf("Create socket fail!\n");
		return;
	}

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(4000);
	serveraddr.sin_addr.S_un.S_addr = inet_addr(this->rif->get_server_ip());

	if (connect(soc, (SOCKADDR *)&serveraddr, sizeof(serveraddr)) != 0)
	{
		printf("Connect fail!\n");
		return;
	}

	this->pj = new parser_json(this->df);
	
}

Client::~Client() 
{
	delete this->pj;
	delete this->rif;
}


/*¹Ø±Õ*/
void Client::Close() {
	WSACleanup(); 
}

void Client::Recv() {
	int r = recv(soc, recv_buf, 10000, 0);
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


std::list<struct  StruInte *> * Client::get_st(){
	return this->st;
}
