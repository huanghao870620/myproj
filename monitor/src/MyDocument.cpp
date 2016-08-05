///////////////////////////////////////////////////////////
//  MyDocument.cpp
//  Implementation of the Class MyDocument
//  Created on:      12-ÆßÔÂ-2016 10:22:38
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "MyDocument.h"


//IMPLEMENT_DYNAMIC(MyDocument,CDocument)
IMPLEMENT_DYNCREATE(MyDocument,CDocument)
MyDocument::MyDocument(){
	std::cout << "mydocument constructor" << std::endl;
	this->c2 = new Client2;
}



MyDocument::~MyDocument(){

}

void MyDocument::sendMsg(char * msg){

}