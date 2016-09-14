///////////////////////////////////////////////////////////
//  MyFrame.h
//  Implementation of the Class MyFrame
//  Created on:      14-¾ÅÔÂ-2016 14:15:28
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_CAF353A8_BE0B_43f8_8B00_1F6405CD9738__INCLUDED_)
#define EA_CAF353A8_BE0B_43f8_8B00_1F6405CD9738__INCLUDED_
#include<afxwin.h>
class MyFrame : public CFrameWnd
{
protected:DECLARE_DYNCREATE(MyFrame,CFrameWnd)
protected:DECLARE_MESSAGE_MAP()
public:
	MyFrame();
	virtual ~MyFrame();

};
#endif // !defined(EA_CAF353A8_BE0B_43f8_8B00_1F6405CD9738__INCLUDED_)
