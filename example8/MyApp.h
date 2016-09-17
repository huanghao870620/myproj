///////////////////////////////////////////////////////////
//  MyApp.h
//  Implementation of the Class MyApp
//  Created on:      17-¾ÅÔÂ-2016 19:24:50
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_4BE7CCA5_7769_454f_B49F_2D6A9AE1505C__INCLUDED_)
#define EA_4BE7CCA5_7769_454f_B49F_2D6A9AE1505C__INCLUDED_
#include"MyDoc.h"
#include"MyFrame.h"
#include"MyView.h"
#include<afxwin.h>
class MyApp : public CWinApp
{

public:
	MyApp();
	virtual ~MyApp();
public:virtual BOOL InitInstance();
};
#endif // !defined(EA_4BE7CCA5_7769_454f_B49F_2D6A9AE1505C__INCLUDED_)
