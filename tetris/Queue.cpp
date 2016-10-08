///////////////////////////////////////////////////////////
//  Queue.cpp
//  Implementation of the Class Queue
//  Created on:      06-Ê®ÔÂ-2016 23:03:46
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "Queue.h"


Queue::Queue(){

}



Queue::~Queue(){

}

Queue* Queue::getInstance(){
	static Queue instance;
	return &instance;
}