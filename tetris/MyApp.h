///////////////////////////////////////////////////////////
//  MyApp.h
//  Implementation of the Class MyApp
//  Created on:      23-����-2016 9:04:26
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_8496411F_19E6_409c_A706_78B46A0E10B2__INCLUDED_)
#define EA_8496411F_19E6_409c_A706_78B46A0E10B2__INCLUDED_
#include"resource.h"
#include"MyDoc.h"
#include"MyView.h"
#include"MyFrame.h"
#include<afxwin.h>
#include"CSockThread.h"
class MyApp : public CWinApp
{

public:
	MyApp();
	virtual ~MyApp();
public:virtual BOOL InitInstance();
};
#endif // !defined(EA_8496411F_19E6_409c_A706_78B46A0E10B2__INCLUDED_)
