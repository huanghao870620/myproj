///////////////////////////////////////////////////////////
//  CDrawView.h
//  Implementation of the Class CDrawView
//  Created on:      09-°ËÔÂ-2016 16:09:34
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_8AA7A857_155C_41cf_942E_C45CB3286775__INCLUDED_)
#define EA_8AA7A857_155C_41cf_942E_C45CB3286775__INCLUDED_

#include<afxwin.h>
class CDrawView : public CScrollView
{
	DECLARE_DYNCREATE(CDrawView)

public:
	CDrawView();
	virtual ~CDrawView();

	void OnDraw(CDC *pDC);

	//DECLARE_MESSAGE_MAP();

};
#endif // !defined(EA_8AA7A857_155C_41cf_942E_C45CB3286775__INCLUDED_)
