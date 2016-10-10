///////////////////////////////////////////////////////////
//  MyApp.h
//  Implementation of the Class MyApp
//  Created on:      10-Ê®ÔÂ-2016 20:28:45
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_B92F3AA5_6ECF_4796_B25F_5C7CE737ECBD__INCLUDED_)
#define EA_B92F3AA5_6ECF_4796_B25F_5C7CE737ECBD__INCLUDED_
#include<afxwin.h>
#include<iostream>

DWORD WINAPI ThreadProc(LPVOID lpParam);

class MyApp : public CWinApp
{

public:
	MyApp();
	virtual ~MyApp();
public:BOOL InitInstance();
protected:HANDLE m_hThread;
protected:DWORD m_nThread;
};


#endif // !defined(EA_B92F3AA5_6ECF_4796_B25F_5C7CE737ECBD__INCLUDED_)
