///////////////////////////////////////////////////////////
//  MyApp.h
//  Implementation of the Class MyApp
//  Created on:      10-Ê®ÔÂ-2016 19:33:22
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_95935FD8_0D2E_4161_A056_B5240B8665BC__INCLUDED_)
#define EA_95935FD8_0D2E_4161_A056_B5240B8665BC__INCLUDED_
#include<afxwin.h>
#include<iostream>
#include"A.h"
#include"Singleton.h"

class MyApp : public CWinApp
{

public:
	MyApp();
	virtual ~MyApp();
public:BOOL InitInstance();
};
#endif // !defined(EA_95935FD8_0D2E_4161_A056_B5240B8665BC__INCLUDED_)
