///////////////////////////////////////////////////////////
//  Random.cpp
//  Implementation of the Class Random
//  Created on:      02-Ê®ÔÂ-2016 18:04:32
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "Random.h"


Random::Random(){

}



Random::~Random(){

}

Combination* Random::getRandomCom(int rand){
	switch (rand)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	default:
		break;
	}
	return nullptr;
}

int Random::getRandomInt(){
	srand(time(0));
	return random(7);
}