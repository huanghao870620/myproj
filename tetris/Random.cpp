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

Combination* Random::getRandomCom(int rand,CDC*pDC,CBrush*brush){
	return new Combination(rand,pDC,brush);
}

Combination* Random::getRandomCom(int rand){
	return new Combination(rand);
}

int Random::getRandomInt(){
	srand(time(0));
	return random(7);
}