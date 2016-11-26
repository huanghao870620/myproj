///////////////////////////////////////////////////////////
//  MyCListCtrl.h
//  Implementation of the Class MyCListCtrl
//  Created on:      25-Ê®Ò»ÔÂ-2016 18:47:00
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_A55FA1B9_36F4_4ea7_8B46_A3EBE9D2D25B__INCLUDED_)
#define EA_A55FA1B9_36F4_4ea7_8B46_A3EBE9D2D25B__INCLUDED_

//#include<afxwin.h>
#include<afxcmn.h>
#include<iostream>
#include"AddGoodsDlg.h"
class MyCListCtrl : public CListCtrl
{

public:
	MyCListCtrl();
	virtual ~MyCListCtrl();
protected:afx_msg void OnItemChanged(NMHDR*pNMHDR, LRESULT*pResult);
protected:afx_msg void OnDbClick(NMHDR*pNMHDR, LRESULT*pResult);
protected:DECLARE_MESSAGE_MAP(MyCListCtrl,CListCtrl)
};
#endif // !defined(EA_A55FA1B9_36F4_4ea7_8B46_A3EBE9D2D25B__INCLUDED_)
