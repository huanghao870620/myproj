///////////////////////////////////////////////////////////
//  Hello.cpp
//  Implementation of the Class Hello
//  Created on:      15-ʮ��-2016 18:17:37
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "Hello.h"


Hello::Hello(){

}



Hello::~Hello(){

}

int main(){
	std::vector<std::thread> threads;
	for (int i = 0; i < 5; i++){
		threads.push_back(std::thread([](){
			std::cout << "Hello from lamda thread" << std::this_thread::get_id() << std::endl;
		}));
	}

	for (auto& thread : threads){
		thread.join();
	}

	std::cout << "Main Thread" << "\t" << std::this_thread::get_id() << std::endl;
	return 0;
}