///////////////////////////////////////////////////////////
//  Singleton.h
//  Implementation of the Class Singleton
//  Created on:      26-¾ÅÔÂ-2016 16:29:40
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_FE2C68F5_23B3_4e5b_9A5C_033183EFB853__INCLUDED_)
#define EA_FE2C68F5_23B3_4e5b_9A5C_033183EFB853__INCLUDED_
#include"Coordinates.h"
#include<list>
/**
 * µ¥Àý
 */
class Singleton
{

public:
	Singleton();
	virtual ~Singleton();
private: std::list<Coordinates*> *coors;
public: std::list<Coordinates*>* getCoors();
public: void setCoors(std::list<Coordinates*> *coors);
public:static Singleton* getSingleton();
private:static Singleton * instance;
};
#endif // !defined(EA_FE2C68F5_23B3_4e5b_9A5C_033183EFB853__INCLUDED_)
