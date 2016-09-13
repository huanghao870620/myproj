///////////////////////////////////////////////////////////
//  MyApp.h
//  Implementation of the Class MyApp
//  Created on:      12-¾ÅÔÂ-2016 17:45:58
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_526BAC9D_828B_429e_BCB3_999D448B839B__INCLUDED_)
#define EA_526BAC9D_828B_429e_BCB3_999D448B839B__INCLUDED_
#include"resource.h"
#include"MyDoc.h"
#include"CScrollDemoView.h"
#include"MyFrame.h"
#include<afxwin.h>
class MyApp : public CWinApp
{
	DECLARE_DYNCREATE(MyApp, CWinApp);
public:
	MyApp();
	virtual ~MyApp();
public:BOOL InitInstance();
	   DECLARE_MESSAGE_MAP()
};
#endif // !defined(EA_526BAC9D_828B_429e_BCB3_999D448B839B__INCLUDED_)
