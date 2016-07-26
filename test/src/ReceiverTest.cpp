///////////////////////////////////////////////////////////
//  ReceiverTest.cpp
//  Implementation of the Class ReceiverTest
//  Created on:      20-ÆßÔÂ-2016 10:28:55
//  Original author: huang.hao
///////////////////////////////////////////////////////////
#include "Receiver.h"
#include "ReceiverTest.h"


UINT fun2(LPVOID lParam){
	::OutputDebugString("-- fun2 --");
	Receiver * receiver = new Receiver;
	return 0;
}

ReceiverTest::ReceiverTest(){

}



ReceiverTest::~ReceiverTest(){

}

void ReceiverTest::testConstructor(){
	CWinThread * cwt = AfxBeginThread(fun2, (LPVOID)0, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);
	cwt->ResumeThread();
}