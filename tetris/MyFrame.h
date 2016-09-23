///////////////////////////////////////////////////////////
//  MyFrame.h
//  Implementation of the Class MyFrame
//  Created on:      23-¾ÅÔÂ-2016 9:04:28
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_7326DB1D_D818_4548_A664_D03CC0FFA8CF__INCLUDED_)
#define EA_7326DB1D_D818_4548_A664_D03CC0FFA8CF__INCLUDED_
#include<afxwin.h>
class MyFrame : public CFrameWnd
{

public:
	MyFrame();
	virtual ~MyFrame();
protected:DECLARE_DYNCREATE(MyFrame,CFrameWnd)
protected:DECLARE_MESSAGE_MAP(MyFrame,CFrameWnd)
};
#endif // !defined(EA_7326DB1D_D818_4548_A664_D03CC0FFA8CF__INCLUDED_)
