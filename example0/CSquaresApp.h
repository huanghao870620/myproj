///////////////////////////////////////////////////////////
//  CSquaresApp.h
//  Implementation of the Class CSquaresApp
//  Created on:      29-°ËÔÂ-2016 16:41:48
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_A573E559_5E48_479c_8055_85AE500DA2E8__INCLUDED_)
#define EA_A573E559_5E48_479c_8055_85AE500DA2E8__INCLUDED_
#include<afxwin.h>
#include"A.h"
class CSquaresApp : public CWinApp
{

public:
	CSquaresApp();
	virtual ~CSquaresApp();

	BOOL InitInstance();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};
#endif // !defined(EA_A573E559_5E48_479c_8055_85AE500DA2E8__INCLUDED_)
