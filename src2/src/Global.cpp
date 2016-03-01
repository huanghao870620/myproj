
#include "Global.h"

Global::Global(int weight, std::string & name)
{
	this->weight = weight;
	this->name = name;
}

Global::~Global() 
{
	std::cout << "1" << std::endl;
}
