///////////////////////////////////////////////////////////
//  MyCListCtrl.h
//  Implementation of the Class MyCListCtrl
//  Created on:      25-Ê®Ò»ÔÂ-2016 18:47:00
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_A55FA1B9_36F4_4ea7_8B46_A3EBE9D2D25B__INCLUDED_)
#define EA_A55FA1B9_36F4_4ea7_8B46_A3EBE9D2D25B__INCLUDED_

#include<afxcmn.h>
#include<iostream>
#include"../dlg/EditGoodDlg.h"
#include"../base_ctrl/BaseCtrl.h"
class MyCListCtrl : public BaseCtrl
{

public:
		MyCListCtrl();
		virtual ~MyCListCtrl();
protected:
		afx_msg void OnItemChanged(NMHDR*pNMHDR, LRESULT*pResult);
		afx_msg void OnDbClick(NMHDR*pNMHDR, LRESULT*pResult);
		DECLARE_MESSAGE_MAP(MyCListCtrl, CListCtrl)
		EditGoodDlg* pDlg;
};
#endif // !defined(EA_A55FA1B9_36F4_4ea7_8B46_A3EBE9D2D25B__INCLUDED_)
