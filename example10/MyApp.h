///////////////////////////////////////////////////////////
//  MyApp.h
//  Implementation of the Class MyApp
//  Created on:      19-¾ÅÔÂ-2016 16:07:23
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_0D0730EA_6CBB_49ff_9B7F_690B9F328F68__INCLUDED_)
#define EA_0D0730EA_6CBB_49ff_9B7F_690B9F328F68__INCLUDED_
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
public:virtual BOOL InitInstance();
};
#endif // !defined(EA_0D0730EA_6CBB_49ff_9B7F_690B9F328F68__INCLUDED_)
