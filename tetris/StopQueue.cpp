#include "StopQueue.h"


StopQueue::StopQueue()
{
}


StopQueue::~StopQueue()
{
}

void StopQueue::addCom(Combination com){
	this->comVector.push_back(com);
}

std::vector<Combination>  StopQueue::getComs(){
	return this->comVector;
}

void StopQueue::draw(CDC pDC, CBrush brush){
	for (int i = 0; i < this->comVector.size(); i++){
		Combination com= this->comVector.at(i);
		com.DrawCom(&pDC,&brush);
	}
}
