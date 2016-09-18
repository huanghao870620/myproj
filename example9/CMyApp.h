///////////////////////////////////////////////////////////
//  CMyApp.h
//  Implementation of the Class CMyApp
//  Created on:      18-¾ÅÔÂ-2016 12:18:58
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_2FB18509_3797_4a9d_9425_CB49C74BDAA6__INCLUDED_)
#define EA_2FB18509_3797_4a9d_9425_CB49C74BDAA6__INCLUDED_
#include<afxwin.h>
#include"CMainWindow.h"
class CMyApp : public CWinApp
{

public:
	CMyApp();
	virtual ~CMyApp();
public:virtual BOOL InitInstance();

};
#endif // !defined(EA_2FB18509_3797_4a9d_9425_CB49C74BDAA6__INCLUDED_)
