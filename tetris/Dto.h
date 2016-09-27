///////////////////////////////////////////////////////////
//  Dto.h
//  Implementation of the Class Dto
//  Created on:      26-九月-2016 16:53:12
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_B286CCF8_BA09_4c02_86B4_C0D9760E0429__INCLUDED_)
#define EA_B286CCF8_BA09_4c02_86B4_C0D9760E0429__INCLUDED_
#include<list>
#include"Coordinates.h"
/**
 * 数据传输对象
 */
class Dto
{

public:
	Dto();
	virtual ~Dto();
private: std::list<Coordinates*> *xList;
private: std::list<Coordinates*> *yList;
public: void setXList(std::list<Coordinates*> *xList);
public: std::list<Coordinates*>* getXList();
public:void setYList(std::list<Coordinates*>* yList);
public:std::list<Coordinates*>* getYList();
	
};
#endif // !defined(EA_B286CCF8_BA09_4c02_86B4_C0D9760E0429__INCLUDED_)
