///////////////////////////////////////////////////////////
//  MyFrame.h
//  Implementation of the Class MyFrame
//  Created on:      19-¾ÅÔÂ-2016 16:07:22
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_72F5FA6F_FD53_4152_8950_60F0074250B0__INCLUDED_)
#define EA_72F5FA6F_FD53_4152_8950_60F0074250B0__INCLUDED_
#include<afxwin.h>
class MyFrame : public CFrameWnd
{

public:
	MyFrame();
	virtual ~MyFrame();
protected:DECLARE_DYNCREATE(MyFrame,CFrameWnd)
protected:DECLARE_MESSAGE_MAP()
};
#endif // !defined(EA_72F5FA6F_FD53_4152_8950_60F0074250B0__INCLUDED_)
