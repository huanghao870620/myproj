#pragma once
#include "afxcmn.h"
#include<iostream>
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

