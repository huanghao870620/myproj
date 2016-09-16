///////////////////////////////////////////////////////////
//  MyFrame.h
//  Implementation of the Class MyFrame
//  Created on:      16-¾ÅÔÂ-2016 15:38:59
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_12368F47_6F84_49c2_98C4_E08F2F09F72D__INCLUDED_)
#define EA_12368F47_6F84_49c2_98C4_E08F2F09F72D__INCLUDED_
#include"resource.h"
#include<afxwin.h>
class MyFrame : public CFrameWnd
{

public:
	MyFrame();
	virtual ~MyFrame();
protected:DECLARE_DYNCREATE(MyFrame, CFrameWnd)
protected:DECLARE_MESSAGE_MAP(MyFrame, CFrameWnd)
private:CButton m_wndPushButton;
};
#endif // !defined(EA_12368F47_6F84_49c2_98C4_E08F2F09F72D__INCLUDED_)
