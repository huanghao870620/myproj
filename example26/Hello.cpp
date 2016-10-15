///////////////////////////////////////////////////////////
//  Hello.cpp
//  Implementation of the Class Hello
//  Created on:      15-Ê®ÔÂ-2016 23:08:31
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "Hello.h"


Hello::Hello(){

}



Hello::~Hello(){

}

int main(){
	A *a = new A;
	 std::queue<B*> *que = a->getQue();
	 std::cout << que->size() << std::endl;

	 B*b0 = new B;
	 a->add(b0);
	 std::cout << que->size() << std::endl;

	 a->remove();
	 std::cout << que->size() << std::endl;

	return 0;
}