///////////////////////////////////////////////////////////
//  Hello.cpp
//  Implementation of the Class Hello
//  Created on:      15-Ê®ÔÂ-2016 18:40:32
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "Hello.h"


Hello::Hello(){

}



Hello::~Hello(){

}

int main(){

	std::mutex m;
	std::thread t1([&m](){
		std::this_thread::sleep_for(std::chrono::seconds(10));
		for (int i = 0; i < 10; i++){
			m.lock();
			std::cout << "In t1 ThreadID : " << std::this_thread::get_id() << " : " << i << std::endl;
			m.unlock();
		}
	});

	std::thread t2([&m](){
		std::this_thread::sleep_for(std::chrono::seconds(1));
		for (int i = 0; i < 10; i++){
			m.lock();
			std::cout << "In t2 ThreadID : " << std::this_thread::get_id() << ":" << i << std::endl;
			m.unlock();
		}
	});


	t1.join();
	t2.join();
	std::cout << "Main Thread" << std::endl;

	return 0;
}