///////////////////////////////////////////////////////////
//  ArrayDto.h
//  Implementation of the Class ArrayDto
//  Created on:      26-¾ÅÔÂ-2016 17:15:47
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_49C927D5_A0C0_4005_BCFD_D04F402E9283__INCLUDED_)
#define EA_49C927D5_A0C0_4005_BCFD_D04F402E9283__INCLUDED_

class ArrayDto
{

public:
	ArrayDto();
	virtual ~ArrayDto();

private: int *xArray;
private:int *yArray;
public:void setXArray(int *xArray);
public:void setYArray(int *yArray);
public:int* getXArray();
public:int* getYArray();

};
#endif // !defined(EA_49C927D5_A0C0_4005_BCFD_D04F402E9283__INCLUDED_)
