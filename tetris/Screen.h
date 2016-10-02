///////////////////////////////////////////////////////////
//  Screen.h
//  Implementation of the Class Screen
//  Created on:      01-Ê®ÔÂ-2016 10:26:01
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_C18E488B_5963_49dc_A7EB_76113F5C7E81__INCLUDED_)
#define EA_C18E488B_5963_49dc_A7EB_76113F5C7E81__INCLUDED_
#include"Singleton.h"
#include<iostream>
/**
 * É¸Ñ¡
 */
class Screen
{

public:
	Screen();
	virtual ~Screen();
private:Singleton *sing;
public:Coordinates* getBottomCoor();
};
#endif // !defined(EA_C18E488B_5963_49dc_A7EB_76113F5C7E81__INCLUDED_)
