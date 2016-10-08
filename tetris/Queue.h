///////////////////////////////////////////////////////////
//  Queue.h
//  Implementation of the Class Queue
//  Created on:      06-Ê®ÔÂ-2016 23:03:46
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_DC8550A1_F5F6_4d2b_A1CB_8C8CACC209FC__INCLUDED_)
#define EA_DC8550A1_F5F6_4d2b_A1CB_8C8CACC209FC__INCLUDED_
#include<list>
#include"Combination.h"
class Queue
{

private:Queue();
public:
	virtual ~Queue();
private:std::list<Combination*> comList;
public:static Queue* getInstance();

};
#endif // !defined(EA_DC8550A1_F5F6_4d2b_A1CB_8C8CACC209FC__INCLUDED_)
