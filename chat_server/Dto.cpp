///////////////////////////////////////////////////////////
//  Dto.cpp
//  Implementation of the Class Dto
//  Created on:      21-七月-2016 10:28:51
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "Dto.h"


Dto::Dto(){

}



Dto::~Dto(){

}

void Dto::setServerSocket(SOCKET * serverSocket){
	this->serverSocket = serverSocket;
}

//添加客户端
void Dto::addClientSocket(SOCKET * client){
	this->clients.push_back(client);
}