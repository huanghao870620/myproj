///////////////////////////////////////////////////////////
//  MyFrame.h
//  Implementation of the Class MyFrame
//  Created on:      16-Ê®ÔÂ-2016 22:43:36
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_58D9A09A_F716_414d_AAE6_0A6EB272648E__INCLUDED_)
#define EA_58D9A09A_F716_414d_AAE6_0A6EB272648E__INCLUDED_
#include<afxwin.h>
class MyFrame : CFrameWnd
{

public:
	MyFrame();
	virtual ~MyFrame();
protected:DECLARE_DYNCREATE(MyFrame,CFrameWnd)
protected:DECLARE_MESSAGE_MAP(MyFrame,CFrameWnd)
};
#endif // !defined(EA_58D9A09A_F716_414d_AAE6_0A6EB272648E__INCLUDED_)
