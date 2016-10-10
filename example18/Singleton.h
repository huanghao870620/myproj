///////////////////////////////////////////////////////////
//  Singleton.h
//  Implementation of the Class Singleton
//  Created on:      10-Ê®ÔÂ-2016 19:44:38
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_0B97A334_B23A_423b_922D_EAB14D4D4D82__INCLUDED_)
#define EA_0B97A334_B23A_423b_922D_EAB14D4D4D82__INCLUDED_
#include"A.h"
#include<list>
class Singleton
{

public:
	Singleton();
	virtual ~Singleton();
public:static Singleton* getInstance();
private:std::list<A*> aList;
public:void addA(A*a);
public:std::list<A*>* getAList();
};
#endif // !defined(EA_0B97A334_B23A_423b_922D_EAB14D4D4D82__INCLUDED_)
