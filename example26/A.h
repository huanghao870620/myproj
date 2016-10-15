///////////////////////////////////////////////////////////
//  A.h
//  Implementation of the Class A
//  Created on:      15-Ê®ÔÂ-2016 23:11:58
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_8C62FCE3_6037_4cf4_A087_015A625BC136__INCLUDED_)
#define EA_8C62FCE3_6037_4cf4_A087_015A625BC136__INCLUDED_
#include<queue>
#include"B.h"
class A
{

public:
	A();
	virtual ~A();
private:std::queue<B*> que;
public:void add(B*b);
public:std::queue<B*>* getQue();
public:void remove();
};
#endif // !defined(EA_8C62FCE3_6037_4cf4_A087_015A625BC136__INCLUDED_)
