///////////////////////////////////////////////////////////
//  Coordinates.cpp
//  Implementation of the Class Coordinates
//  Created on:      26-¾ÅÔÂ-2016 16:23:48
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "Coordinates.h"


Coordinates::Coordinates(int x,int y){
	this->x = x;
	this->y = y;
}


Coordinates::Coordinates(){

}


Coordinates::~Coordinates(){

}

int Coordinates::getX(){
	return this->x;
}

int Coordinates::getY(){
	return this->y;
}

void Coordinates::setX(int x){
	this->x = x;
}

void Coordinates::setY(int y){
	this->y = y;
}