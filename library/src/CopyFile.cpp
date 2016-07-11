///////////////////////////////////////////////////////////
//  CopyFile.cpp
//  Implementation of the Class CopyFile
//  Created on:      11-ÆßÔÂ-2016 10:08:41
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include "CopyFile.h"


CopyFile::CopyFile(){
	
}



CopyFile::~CopyFile(){

}

int CopyFile::copyFile(char * sourceFile, char * newFile){
	std::ifstream in;
	std::ofstream out;
	in.open(sourceFile, std::ios::binary);
	if (in.fail()){
		std::cout << "Error 1: Fail to open the source file." << std::endl;
		in.close();
		out.close();
		return 0;
	}

	out.open(newFile, std::ios::binary);
	if (out.fail()){
		std::cout << "" << std::endl;
		out.close();
		in.close();
		return 1;
	}
}