///////////////////////////////////////////////////////////
//  SocketList.cpp
//  Implementation of the Class SocketList
//  Created on:      08-ÆßÔÂ-2016 15:46:13
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "SocketList.h"


SocketList::SocketList(){

}

SocketList::~SocketList(){

}


void SocketList::messaging(char * msg){
	std::list<SOCKET *>::iterator itor = this->socke_list.begin();
	for (; itor != this->socke_list.end(); itor++){
		send(**itor, msg, strlen(msg), 0);
	}
}

 SocketList * SocketList::getInstance(){
	if (instance == nullptr){
		instance = new SocketList;
	}
	return instance;
}

void SocketList::add(SOCKET * socket){
	this->socke_list.push_back(socket);
}