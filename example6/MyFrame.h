///////////////////////////////////////////////////////////
//  MyFrame.h
//  Implementation of the Class MyFrame
//  Created on:      16-¾ÅÔÂ-2016 10:53:28
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_2A84A857_4D3A_4962_A6A3_D96C053B0972__INCLUDED_)
#define EA_2A84A857_4D3A_4962_A6A3_D96C053B0972__INCLUDED_
#include<afxwin.h>
class MyFrame : public CFrameWnd
{

public:
	MyFrame();
	virtual ~MyFrame();
protected:DECLARE_MESSAGE_MAP(MyFrame, CFrameWnd);
public:afx_msg void OnPaint();
};
#endif // !defined(EA_2A84A857_4D3A_4962_A6A3_D96C053B0972__INCLUDED_)
