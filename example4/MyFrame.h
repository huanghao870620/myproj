///////////////////////////////////////////////////////////
//  MyFrame.h
//  Implementation of the Class MyFrame
//  Created on:      15-����-2016 15:15:59
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_B79E89E9_7098_47d5_BFFB_CD8305F24BB6__INCLUDED_)
#define EA_B79E89E9_7098_47d5_BFFB_CD8305F24BB6__INCLUDED_
#include<afxwin.h>
class MyFrame : public CFrameWnd
{
protected:DECLARE_DYNCREATE(MyFrame,CFrameWnd)
protected:DECLARE_MESSAGE_MAP(MyFrame,CFrameWnd)
public:
	MyFrame();
	virtual ~MyFrame();

};
#endif // !defined(EA_B79E89E9_7098_47d5_BFFB_CD8305F24BB6__INCLUDED_)
