///////////////////////////////////////////////////////////
//  CSquaresView.h
//  Implementation of the Class CSquaresView
//  Created on:      29-°ËÔÂ-2016 17:23:50
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_948095E2_2506_4bdf_B54B_CAA0F6D14F54__INCLUDED_)
#define EA_948095E2_2506_4bdf_B54B_CAA0F6D14F54__INCLUDED_
#include<iostream>
#include<afxwin.h>
#include"CSquaresDoc.h"

class CSquaresView : public CView
{
	DECLARE_DYNCREATE(CSquaresView)

public:
	CSquaresView();
	virtual ~CSquaresView();

	
	CSquaresDoc * GetDocument();
	virtual void OnDraw(CDC* pDC);

	DECLARE_MESSAGE_MAP()
};
#endif // !defined(EA_948095E2_2506_4bdf_B54B_CAA0F6D14F54__INCLUDED_)
