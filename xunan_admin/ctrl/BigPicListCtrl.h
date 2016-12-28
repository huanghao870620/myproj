#pragma once
#include"../resource.h"
#include<iostream>
#include<afxcmn.h>
#include"../util/Util.h"
#include"../dlg/EditBigPic4GoodDlg.h"
// BigPicListCtrl 对话框

#define MAX_LISTITEM 1000

class BigPicListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC(BigPicListCtrl)

public:
	BigPicListCtrl();   // 标准构造函数
	virtual ~BigPicListCtrl();

	//取得被选中的第一项
	int GetFirsetSelectedItem();

	//返回下一个选中项
	int GetNextSelectedItem(int nItem);

	//判断某项的选择状态
	BOOL GetCheckBoxItemState(int nItem);

	//设置某项的选择状态
	BOOL SetCheckBoxItemState(int nItem, BOOL bNewState);

	//自绘列表控件
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);


private:
	BOOL m_bItemCheckState[MAX_LISTITEM];

protected:
	afx_msg void OnDbClick(NMHDR*pNMHDR, LRESULT*pResult);
	afx_msg void OnItemChanged(NMHDR*pNMHDR, LRESULT*pResult);
	DECLARE_MESSAGE_MAP()
};
