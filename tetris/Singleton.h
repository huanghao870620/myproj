///////////////////////////////////////////////////////////
//  Singleton.h
//  Implementation of the Class Singleton
//  Created on:      26-����-2016 16:29:40
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_FE2C68F5_23B3_4e5b_9A5C_033183EFB853__INCLUDED_)
#define EA_FE2C68F5_23B3_4e5b_9A5C_033183EFB853__INCLUDED_
#include"Coordinates.h"
#include<list>
/**
 * ����
 */
class Singleton
{

private:Singleton();
public:virtual ~Singleton();
private: std::list<Coordinates*> coors;
public:void addCoor(Coordinates *coor);
public: std::list<Coordinates*>* getCoors();
public:static Singleton* getSingleton(){
	static Singleton instance;
	return &instance;
}
};
#endif // !defined(EA_FE2C68F5_23B3_4e5b_9A5C_033183EFB853__INCLUDED_)
