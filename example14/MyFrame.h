///////////////////////////////////////////////////////////
//  MyFrame.h
//  Implementation of the Class MyFrame
//  Created on:      07-Ê®ÔÂ-2016 17:15:56
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_1B8ACD03_D14C_4738_93AB_F3E3AE944FDC__INCLUDED_)
#define EA_1B8ACD03_D14C_4738_93AB_F3E3AE944FDC__INCLUDED_
#include<afxwin.h>
class MyFrame : CFrameWnd
{

public:
	MyFrame();
	virtual ~MyFrame();
protected:DECLARE_DYNCREATE(MyFrame, CFrameWnd);
protected:DECLARE_MESSAGE_MAP(MyFrame, CFrameWnd);
};
#endif // !defined(EA_1B8ACD03_D14C_4738_93AB_F3E3AE944FDC__INCLUDED_)
