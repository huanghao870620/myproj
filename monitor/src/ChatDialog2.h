///////////////////////////////////////////////////////////
//  ChatDialog2.h
//  Implementation of the Class ChatDialog2
//  Created on:      08-����-2016 11:36:04
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_920BDF9C_A865_4b15_A032_C3140C50E331__INCLUDED_)
#define EA_920BDF9C_A865_4b15_A032_C3140C50E331__INCLUDED_
#include"resource.h"
#include"CDrawView.h"

class ChatDialog2 : public CDialog
{

public:
	ChatDialog2();
	virtual ~ChatDialog2();
	afx_msg BOOL OnInitDialog();


	

private:
	CDrawView * m_pDrawView;
	CStatic * text;
	CDrawView * m_pView;
	
};
#endif // !defined(EA_920BDF9C_A865_4b15_A032_C3140C50E331__INCLUDED_)
