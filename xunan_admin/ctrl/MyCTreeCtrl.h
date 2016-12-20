#pragma once
#include "afxcmn.h"
#include<iostream>
class MyCTreeCtrl :
	public CTreeCtrl
{
public:
	MyCTreeCtrl();
	~MyCTreeCtrl();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult);
protected:virtual BOOL OnInitDialog();
};

