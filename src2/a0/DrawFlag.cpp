#include "DrawFlag.h"


DrawFlag::DrawFlag() 
{
	this->flag = false;
}

DrawFlag::~DrawFlag() 
{
}

void DrawFlag::setFlag(bool  flag){
	this->flag = flag;
}

bool & DrawFlag::getFlag(){
	return  this->flag;
}
