///////////////////////////////////////////////////////////
//  MyTest.cpp
//  Implementation of the Class MyTest
//  Created on:      08-ÆßÔÂ-2016 17:58:34
//  Original author: huang.hao
///////////////////////////////////////////////////////////
#include <iostream>
#include "FileOperator.h"
#include "MyTest.h"


MyTest::MyTest(){

}



MyTest::~MyTest(){

}

void MyTest::testDelete(){
	std::cout << "" << std::endl;
	FileOperator * fo = new FileOperator;
	char * source = "D:/cppwork/myproj/monitor/src/Debug/test.ini";
	fo->deleteFile(source);
}

void MyTest::testCopy(){
	FileOperator * fo = new FileOperator;
	char * sourceFile = "D:/cppwork/myproj/monitor/src/test.ini";
	char * newFile = "D:/cppwork/myproj/monitor/src/Debug/test.ini";
	fo->copy_File(sourceFile, newFile);
}

void MyTest::testCopy2TestDir(){
	FileOperator * fo = new FileOperator;
	char * sourceFile = "D:/cppwork/myproj/monitor/src/test.ini";
	char * newFile = "D:/cppwork/myproj/test/src/Debug/test.ini";
	fo->copy_File(sourceFile, newFile);
}