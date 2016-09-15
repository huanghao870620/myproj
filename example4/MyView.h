///////////////////////////////////////////////////////////
//  MyView.h
//  Implementation of the Class MyView
//  Created on:      15-¾ÅÔÂ-2016 15:16:02
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_4CDCA07D_9021_4184_A748_CF557CCF8606__INCLUDED_)
#define EA_4CDCA07D_9021_4184_A748_CF557CCF8606__INCLUDED_
#include<afxcview.h>
#include<afxwin.h>
class MyView : public CTreeView
{
protected:DECLARE_DYNCREATE(MyView, CTreeView)
protected:DECLARE_MESSAGE_MAP(MyView, CTreeView)
public:MyView();
public:virtual ~MyView();
public:virtual void OnDraw(CDC *pDC);

};
#endif // !defined(EA_4CDCA07D_9021_4184_A748_CF557CCF8606__INCLUDED_)
