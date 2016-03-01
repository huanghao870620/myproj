#include "Global.h"
#include "LoDiffeGlobal.h"


LoDiffeGlobal::LoDiffeGlobal() 
{
	std::string name = "common";
	std::string espi_name = "espi";
	for (int i = 0; i < 8; i++){
		Global * glob = new Global(8, name);
		this->bals[i] = glob;
	}

	Global * espi= new Global(10, espi_name);
	this->bals[8] = espi;
}

LoDiffeGlobal::~LoDiffeGlobal() 
{
	for (int i = 0; i < 9; i++){
		delete this->bals[i];
	}
}

void LoDiffeGlobal::count(){

}

void LoDiffeGlobal::weighing(){
	 
}

void LoDiffeGlobal::messUp(){

}