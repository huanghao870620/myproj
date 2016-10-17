///////////////////////////////////////////////////////////
//  MyApp.h
//  Implementation of the Class MyApp
//  Created on:      16-Ê®ÔÂ-2016 22:43:35
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_69A74627_47E1_4188_AC5A_50E905A23BB0__INCLUDED_)
#define EA_69A74627_47E1_4188_AC5A_50E905A23BB0__INCLUDED_
#include<afxwin.h>
#include<iostream>
#include"resource.h"
#include"MyDoc.h"
#include"MyView.h"
#include"MyFrame.h"
class MyApp : public CWinApp
{

public:
	MyApp();
	virtual ~MyApp();
public:BOOL InitInstance();
};
MyApp app;
#endif // !defined(EA_69A74627_47E1_4188_AC5A_50E905A23BB0__INCLUDED_)
