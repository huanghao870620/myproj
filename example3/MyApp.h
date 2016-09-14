///////////////////////////////////////////////////////////
//  MyApp.h
//  Implementation of the Class MyApp
//  Created on:      14-¾ÅÔÂ-2016 14:15:17
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_949E9351_8808_449e_A67A_54367363C3BB__INCLUDED_)
#define EA_949E9351_8808_449e_A67A_54367363C3BB__INCLUDED_
#include"resource.h"
#include"MyDoc.h"
#include"MyFrame.h"
#include"MyView.h"
#include<afxwin.h>
class MyApp : public CWinApp
{

public:
	MyApp();
	virtual ~MyApp();
protected:BOOL InitInstance();
};
#endif // !defined(EA_949E9351_8808_449e_A67A_54367363C3BB__INCLUDED_)
