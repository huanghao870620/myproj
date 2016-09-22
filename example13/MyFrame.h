///////////////////////////////////////////////////////////
//  MyFrame.h
//  Implementation of the Class MyFrame
//  Created on:      22-¾ÅÔÂ-2016 10:52:58
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_1E093D91_8212_495e_A61A_4FAE230D9A40__INCLUDED_)
#define EA_1E093D91_8212_495e_A61A_4FAE230D9A40__INCLUDED_
#include<afxwin.h>
class MyFrame : public CFrameWnd
{

public:
	MyFrame();
	virtual ~MyFrame();
protected:DECLARE_DYNCREATE(MyFrame,CFrameWnd)
protected:DECLARE_MESSAGE_MAP()
};
#endif // !defined(EA_1E093D91_8212_495e_A61A_4FAE230D9A40__INCLUDED_)
