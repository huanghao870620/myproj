///////////////////////////////////////////////////////////
//  A.h
//  Implementation of the Class A
//  Created on:      09-Ê®ÔÂ-2016 18:41:18
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_AEDD5542_A198_4a33_993A_0543029809D2__INCLUDED_)
#define EA_AEDD5542_A198_4a33_993A_0543029809D2__INCLUDED_
#include<afxwin.h>
#include"Singleton.h"
#include"ArrayDto.h"
#include"Adto.h"
#include"Constants.h"
#include"Queue.h"
#include"Combination.h"
class A
{

public:
	A();
	virtual ~A();
public:void init();
private:ArrayDto *arrayDto;
private:Adto *adto;
private:Combination *com;
};
#endif // !defined(EA_AEDD5542_A198_4a33_993A_0543029809D2__INCLUDED_)
