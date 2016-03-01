#include "DrawFlag.h"



DrawFlag::~DrawFlag() 
{
}

void DrawFlag::setFlag(bool  flag){
	this->flag = flag;
}

bool & DrawFlag::getFlag(){
	return  this->flag;
}

