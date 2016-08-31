///////////////////////////////////////////////////////////
//  CMainFrame.h
//  Implementation of the Class CMainFrame
//  Created on:      29-°ËÔÂ-2016 17:19:22
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_6F00035C_D40A_4d75_B073_243BDAC40E00__INCLUDED_)
#define EA_6F00035C_D40A_4d75_B073_243BDAC40E00__INCLUDED_
#include<iostream>
#include<afxwin.h>

class CMainFrame : public CFrameWnd
{

	DECLARE_DYNCREATE(CMainFrame)
public:
	CMainFrame();
	virtual ~CMainFrame();

	DECLARE_MESSAGE_MAP()
};
#endif // !defined(EA_6F00035C_D40A_4d75_B073_243BDAC40E00__INCLUDED_)
