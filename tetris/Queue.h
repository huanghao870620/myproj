///////////////////////////////////////////////////////////
//  Queue.h
//  Implementation of the Class Queue
//  Created on:      06-Ê®ÔÂ-2016 23:03:46
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_DC8550A1_F5F6_4d2b_A1CB_8C8CACC209FC__INCLUDED_)
#define EA_DC8550A1_F5F6_4d2b_A1CB_8C8CACC209FC__INCLUDED_
#include<list>
#include<queue>
#include"Combination.h"
#include"Random.h"
class Queue
{

public:
	virtual ~Queue();
	static Queue* getInstance();
	void add();
	Combination* get();
	int getSize();
	void remove();
private:
	Queue();
	std::queue<Combination*> comQueue;

};
#endif // !defined(EA_DC8550A1_F5F6_4d2b_A1CB_8C8CACC209FC__INCLUDED_)
