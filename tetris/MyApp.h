///////////////////////////////////////////////////////////
//  MyApp.h
//  Implementation of the Class MyApp
//  Created on:      23-¾ÅÔÂ-2016 9:04:26
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
#include"Random.h"
#include"Queue.h"
#include"A.h"
#include"A0.h"
#define HAVE_REMOTE
#include"pcap.h"


//#include"remote-ext.h"
#define LINE_LEN 16

class MyApp : public CWinApp
{

public:
	MyApp();
	virtual ~MyApp();
public:virtual BOOL InitInstance();
};
#endif // !defined(EA_8496411F_19E6_409c_A706_78B46A0E10B2__INCLUDED_)
