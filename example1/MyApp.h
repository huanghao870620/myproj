///////////////////////////////////////////////////////////
//  MyApp.h
//  Implementation of the Class MyApp
//  Created on:      09-����-2016 13:56:08
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_25FB0572_E466_45f2_BE40_C2975D602FEC__INCLUDED_)
#define EA_25FB0572_E466_45f2_BE40_C2975D602FEC__INCLUDED_
#include<vld.h>
#include"resource.h"
#include"MyDoc.h"
#include"MyView.h"
#include"MyMainFrame.h"
#include<afxwin.h>
#include"MyDlg.h"
class MyApp : public CWinApp
{
public:
	MyApp();
	virtual ~MyApp();
public:BOOL InitInstance();
};
#endif // !defined(EA_25FB0572_E466_45f2_BE40_C2975D602FEC__INCLUDED_)
