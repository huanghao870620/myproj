///////////////////////////////////////////////////////////
//  MyApp.h
//  Implementation of the Class MyApp
//  Created on:      16-Ê®ÔÂ-2016 20:35:52
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_5D612358_045D_41b5_B5E8_EFBD82E1CB3D__INCLUDED_)
#define EA_5D612358_045D_41b5_B5E8_EFBD82E1CB3D__INCLUDED_
#include<afxwin.h>
#include<afxmt.h>
#include<iostream>
#include"A.h"
class MyApp : public CWinApp
{

public:
	MyApp();
	virtual ~MyApp();
public:BOOL InitInstance();
};

MyApp app;
CEvent g_event;
#endif // !defined(EA_5D612358_045D_41b5_B5E8_EFBD82E1CB3D__INCLUDED_)
