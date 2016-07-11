///////////////////////////////////////////////////////////
//  CopyFile.cpp
//  Implementation of the Class CopyFile
//  Created on:      11-七月-2016 10:08:41
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include<afxwin.h>
#include <iostream>
#include <fstream>
#include<io.h>
#include "FileOperator.h"


FileOperator::FileOperator(){
	
}



FileOperator::~FileOperator(){

}

int FileOperator::copy_File(char * sourceFile, char * newFile){
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
	else{
		out << in.rdbuf();
		out.close();
		in.close();
		return 1;
	}
	
}


void FileOperator::deleteFile(char * source){
	if (!_access(source, 0)){
		SetFileAttributes(source, 0);
		if (DeleteFile(source)){
			std::cout << "已删除成功!" << std::endl;
		}
		else
		{
			std::cout << source << "不存在,无法删除" << std::endl;
		}
		std::cin.get();
	}
}