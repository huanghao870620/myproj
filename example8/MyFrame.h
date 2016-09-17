///////////////////////////////////////////////////////////
//  MyFrame.h
//  Implementation of the Class MyFrame
//  Created on:      17-¾ÅÔÂ-2016 19:24:57
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_E6FCAC3C_70BC_4638_B5CA_EA6C280DEAEB__INCLUDED_)
#define EA_E6FCAC3C_70BC_4638_B5CA_EA6C280DEAEB__INCLUDED_
#include<afxwin.h>
class MyFrame : public CFrameWnd
{
protected:DECLARE_DYNCREATE(MyFrame,CFrameWnd)
protected:DECLARE_MESSAGE_MAP()
public:
	MyFrame();
	virtual ~MyFrame();

};
#endif // !defined(EA_E6FCAC3C_70BC_4638_B5CA_EA6C280DEAEB__INCLUDED_)
