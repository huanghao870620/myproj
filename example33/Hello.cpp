///////////////////////////////////////////////////////////
//  Hello.cpp
//  Implementation of the Class Hello
//  Created on:      31-Ê®ÔÂ-2016 20:06:05
//  Original author: admin
///////////////////////////////////////////////////////////

#include "Hello.h"
#include"testdll.h"

Hello::Hello(){

}



Hello::~Hello(){

}

int i = 0;
JNIEXPORT jint JNICALL Java_testdll_get
(JNIEnv *, jclass){
	return i;
}

JNIEXPORT void JNICALL Java_testdll_set
(JNIEnv *, jclass, jint j){
	i = j;
}

