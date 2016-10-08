///////////////////////////////////////////////////////////
//  MyApp.h
//  Implementation of the Class MyApp
//  Created on:      07-Ê®ÔÂ-2016 17:15:52
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_062E5BC8_AD39_46d4_89A4_1B6B71F87316__INCLUDED_)
#define EA_062E5BC8_AD39_46d4_89A4_1B6B71F87316__INCLUDED_
#include<afxwin.h>
#include"MyDoc.h"
#include"MyFrame.h"
#include"MyView.h"
class MyApp : public CWinApp
{

public:
	MyApp();
	virtual ~MyApp();
public:BOOL InitInstance();
};
#endif // !defined(EA_062E5BC8_AD39_46d4_89A4_1B6B71F87316__INCLUDED_)
