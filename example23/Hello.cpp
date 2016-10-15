///////////////////////////////////////////////////////////
//  Hello.cpp
//  Implementation of the Class Hello
//  Created on:      15-Ê®ÔÂ-2016 12:23:01
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "Hello.h"


Hello::Hello(){

}



Hello::~Hello(){

}


void hello(){
	std::cout << "Hello from thread" << std::endl;
}

int main(){
	std::thread t1(hello);
	t1.join();
	std::cout << "Main Thread" << std::endl;
	return 0;
}