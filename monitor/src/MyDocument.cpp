///////////////////////////////////////////////////////////
//  MyDocument.cpp
//  Implementation of the Class MyDocument
//  Created on:      12-ÆßÔÂ-2016 10:22:38
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "MyDocument.h"


IMPLEMENT_DYNCREATE(MyDocument,CDocument)


BEGIN_MESSAGE_MAP(MyDocument,CDocument)
END_MESSAGE_MAP()

MyDocument::MyDocument(){
	std::cout << "mydocument constructor" << std::endl;
	this->c2 = new Client2;
	//this->SetModifiedFlag(true);
	//this->UpdateAllViews(nullptr);
}



MyDocument::~MyDocument(){

}

void MyDocument::sendMsg(char * msg){
	this->c2->sendMsg(msg);
}