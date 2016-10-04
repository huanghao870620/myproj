///////////////////////////////////////////////////////////
//  Random.h
//  Implementation of the Class Random
//  Created on:      02-Ê®ÔÂ-2016 18:04:32
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_7F334E5A_F81B_47ff_9CFA_200253CC4997__INCLUDED_)
#define EA_7F334E5A_F81B_47ff_9CFA_200253CC4997__INCLUDED_
#include"Combination.h"
#include<stdio.h>
#include<stdlib.h>

#define random(x) (rand()%x)
class Random
{

public:
	Random();
	virtual ~Random();

public:Combination* getRandomCom(int rand);
public:int getRandomInt();

};
#endif // !defined(EA_7F334E5A_F81B_47ff_9CFA_200253CC4997__INCLUDED_)
