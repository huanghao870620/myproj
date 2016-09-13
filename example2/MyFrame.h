///////////////////////////////////////////////////////////
//  MyFrame.h
//  Implementation of the Class MyFrame
//  Created on:      12-¾ÅÔÂ-2016 17:45:49
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_2FFFC463_60B7_44ab_8B52_CC69B8CDFBD1__INCLUDED_)
#define EA_2FFFC463_60B7_44ab_8B52_CC69B8CDFBD1__INCLUDED_
#include<afxwin.h>
class MyFrame : public CFrameWnd
{
	DECLARE_DYNCREATE(MyFrame,CFrameWnd)
public:
	MyFrame();
	virtual ~MyFrame();

	DECLARE_MESSAGE_MAP()

};
#endif // !defined(EA_2FFFC463_60B7_44ab_8B52_CC69B8CDFBD1__INCLUDED_)
