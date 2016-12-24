#pragma once
#include "afxcmn.h"
#include<iostream>
#include"../util/Util.h"
#include"../dlg/EditCountryDlg.h"
class CountryListCtrl :
	public CListCtrl
{
public:
	CountryListCtrl();
	~CountryListCtrl();


protected:afx_msg void OnItemChanged(NMHDR*pNMHDR, LRESULT*pResult);
protected:afx_msg void OnDbClick(NMHDR*pNMHDR, LRESULT*pResult);
protected:DECLARE_MESSAGE_MAP(MyCListCtrl, CListCtrl)
};

