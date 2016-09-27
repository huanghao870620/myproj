///////////////////////////////////////////////////////////
//  Adto.h
//  Implementation of the Class Adto
//  Created on:      27-¾ÅÔÂ-2016 14:47:45
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_F6272E14_C79E_4559_9877_D9528904441B__INCLUDED_)
#define EA_F6272E14_C79E_4559_9877_D9528904441B__INCLUDED_
#include<list>
class Adto
{

public:
	Adto();
	virtual ~Adto();
private:std::list<int> xList;
private:std::list<int> yList;
public:void addX(int x);
public:std::list<int>* getXList();
public:void addY(int y);
public:std::list<int>* getYList();
};
#endif // !defined(EA_F6272E14_C79E_4559_9877_D9528904441B__INCLUDED_)
