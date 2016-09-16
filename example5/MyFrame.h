///////////////////////////////////////////////////////////
//  MyFrame.h
//  Implementation of the Class MyFrame
//  Created on:      16-¾ÅÔÂ-2016 9:50:33
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_EEF95D16_F3EB_43c7_AE0F_78446CE4E7D5__INCLUDED_)
#define EA_EEF95D16_F3EB_43c7_AE0F_78446CE4E7D5__INCLUDED_
#include<afxwin.h>
class MyFrame : public CFrameWnd
{

public:
	MyFrame();
	virtual ~MyFrame();
protected:DECLARE_MESSAGE_MAP(MyFrame, CFrameWnd)
public:afx_msg void OnPaint();
};
#endif // !defined(EA_EEF95D16_F3EB_43c7_AE0F_78446CE4E7D5__INCLUDED_)
