#pragma once
#include"../resource.h"
#include<iostream>
#include<afxcmn.h>
#include"../util/Util.h"
#include"../dlg/EditBigPic4GoodDlg.h"
// BaseCtrl �Ի���

#define MAX_LISTITEM 1000

class BaseCtrl : public CListCtrl
{
	DECLARE_DYNAMIC(BaseCtrl)

public:
	BaseCtrl();   // ��׼���캯��
	virtual ~BaseCtrl();

	//ȡ�ñ�ѡ�еĵ�һ��
	int GetFirsetSelectedItem();

	//������һ��ѡ����
	int GetNextSelectedItem(int nItem);

	//�ж�ĳ���ѡ��״̬
	BOOL GetCheckBoxItemState(int nItem);

	//����ĳ���ѡ��״̬
	BOOL SetCheckBoxItemState(int nItem, BOOL bNewState);

	//�Ի��б�ؼ�
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);


private:
	BOOL m_bItemCheckState[MAX_LISTITEM];

protected:
	afx_msg void OnDbClick(NMHDR*pNMHDR, LRESULT*pResult);
	afx_msg void OnItemChanged(NMHDR*pNMHDR, LRESULT*pResult);
	DECLARE_MESSAGE_MAP()
};
