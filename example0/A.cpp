///////////////////////////////////////////////////////////
//  A.cpp
//  Implementation of the Class A
//  Created on:      24-ʮ����-2016 12:20:39
//  Original author: admin
///////////////////////////////////////////////////////////

#include "A.h"


A::A(){
	B b;
	C<B*> c;
	c.t(&b);
	//C<B*> *c = new C<B*>;
	
}



A::~A(){

}