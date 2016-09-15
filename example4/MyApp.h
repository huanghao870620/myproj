///////////////////////////////////////////////////////////
//  MyApp.h
//  Implementation of the Class MyApp
//  Created on:      15-¾ÅÔÂ-2016 15:15:57
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_CFC00FE4_19B1_4738_A289_05041E2C05F0__INCLUDED_)
#define EA_CFC00FE4_19B1_4738_A289_05041E2C05F0__INCLUDED_
#include"MyDoc.h"
#include"MyView.h"
#include"MyFrame.h"
#include<afxwin.h>
class MyApp : public CWinApp
{

public:
	MyApp();
	virtual ~MyApp();
public:BOOL InitInstance();
};
#endif // !defined(EA_CFC00FE4_19B1_4738_A289_05041E2C05F0__INCLUDED_)
