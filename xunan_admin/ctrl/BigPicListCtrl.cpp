// D:\cppwork\myproj\xunan_admin\ctrl\BigPicListCtrl.cpp : 实现文件
//

#include "../stdafx.h"
#include "BigPicListCtrl.h"
#include "afxdialogex.h"


// BigPicListCtrl 对话框

IMPLEMENT_DYNAMIC(BigPicListCtrl, BaseCtrl)

BigPicListCtrl::BigPicListCtrl()
{

}

BigPicListCtrl::~BigPicListCtrl()
{
}


void BigPicListCtrl::OnDbClick(NMHDR*pNMHDR, LRESULT*pResult){
	std::cout << "" << std::endl;
	NM_LISTVIEW *pNMListView = (NM_LISTVIEW*)pNMHDR;
	int nItem = pNMListView->iItem;
	if (nItem >= 0 && nItem < this->GetItemCount()){//判断双击位置是否在有数据的列表项上面
		std::cout << "" << std::endl;
		int nItem = this->GetNextItem(-1, LVNI_SELECTED);
		CString id = this->GetItemText(nItem, 0);
		CString name = this->GetItemText(nItem, 1);
		CString info = this->GetItemText(nItem, 2);

		std::cout << name << std::endl;
		long lid = Util::stol(id.GetBuffer(0));

		EditBigPic4GoodDlg*dlg = new EditBigPic4GoodDlg(lid);
		dlg->Create(EditBigPic4GoodDlg::IDD, this);
		dlg->ShowWindow(SW_SHOW);
	}
	*pResult = 0;
}
//
//int BigPicListCtrl::GetFirsetSelectedItem()
//{
//	int nItem = -1;
//
//	for (int iItem = 0; iItem < MAX_LISTITEM; ++iItem)
//	{
//		if (m_bItemCheckState[iItem])
//		{
//			nItem = iItem;//返回第一个被选中项
//			break;
//		}
//	}
//	return nItem;
//}
//
//
//int BigPicListCtrl::GetNextSelectedItem(int nItem)
//{
//	int nNextItem = -1;
//	for (int iItem = nItem + 1; iItem < MAX_LISTITEM; ++iItem)
//	{
//		if (m_bItemCheckState[iItem])
//		{
//			nNextItem = iItem;
//			break;
//		}
//	}
//	return nNextItem;
//}
//
//BOOL BigPicListCtrl::GetCheckBoxItemState(int nItem)
//{
//	return m_bItemCheckState[nItem];
//}
//
//void BigPicListCtrl::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
//{
//	if (lpDrawItemStruct->CtlType != ODT_LISTVIEW)
//		return;
//
//	RECT rectiSubItem = { 0 };
//	RECT rectCheckBox = { 0 };
//
//	char szBuffer[50] = { 0 };
//	int nTotalColumn = 0;
//
//	CHeaderCtrl* pListHeader = NULL;
//	LV_ITEM lvi = { 0 };
//
//	pListHeader = (CHeaderCtrl*)GetDlgItem(0);
//	nTotalColumn = pListHeader->GetItemCount();
//
//	//最后一列是要显示复选框的一列
//	pListHeader->GetItemRect(nTotalColumn - 1, &rectCheckBox);
//
//	//循环地绘制列表控件各个子项
//	for (int iColumn = 0; iColumn < nTotalColumn; ++iColumn)
//	{
//		lvi.mask = LVIF_TEXT | LVIF_PARAM;
//		lvi.iItem = lpDrawItemStruct->itemID;
//		lvi.iSubItem = iColumn;
//		lvi.pszText = szBuffer;
//		lvi.cchTextMax = sizeof(szBuffer);
//		VERIFY(GetItem(&lvi));
//
//		pListHeader->GetItemRect(iColumn, &rectiSubItem);
//		lpDrawItemStruct->rcItem.left = rectiSubItem.left;
//		lpDrawItemStruct->rcItem.right += rectiSubItem.right - rectiSubItem.left;
//
//		if (iColumn == nTotalColumn - 1)
//		{
//			rectCheckBox.top = lpDrawItemStruct->rcItem.top;
//			rectCheckBox.bottom = lpDrawItemStruct->rcItem.bottom;
//
//			//绘制复选框
//			if (m_bItemCheckState[lpDrawItemStruct->itemID])
//			{
//				DrawFrameControl(lpDrawItemStruct->hDC, &rectCheckBox,
//					DFC_BUTTON, DFCS_CHECKED);//已选中
//			}
//			else
//			{
//				DrawFrameControl(lpDrawItemStruct->hDC, &rectCheckBox,
//					DFC_BUTTON, DFCS_BUTTONCHECK);//未选中
//			}
//
//		}
//		else
//		{
//			DrawText(lpDrawItemStruct->hDC, szBuffer, strlen(szBuffer),
//				&lpDrawItemStruct->rcItem, DT_LEFT);
//		}
//	}
//
//
//}
//
//BOOL BigPicListCtrl::SetCheckBoxItemState(int nItem, BOOL bNewState)
//{
//	BOOL bOldState = FALSE;
//
//	bOldState = m_bItemCheckState[nItem];
//	m_bItemCheckState[nItem] = bNewState;
//
//	//刷新复选框状态
//	InvalidateRect(NULL, FALSE);
//
//	return bOldState;
//}




void BigPicListCtrl::OnItemChanged(NMHDR*pNMHDR, LRESULT*pResult){
	//int nItem = this->GetNextItem(-1, LVNI_SELECTED);
	//CString id = this->GetItemText(nItem, 0);
	//CString name = this->GetItemText(nItem, 1);
	//CString info = this->GetItemText(nItem, 2);


	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here 

	if ((pNMLV->uOldState & INDEXTOSTATEIMAGEMASK(1)) /* old state : unchecked */
		&& (pNMLV->uNewState & INDEXTOSTATEIMAGEMASK(2)) /* new state : checked */
		)
	{
		TRACE("Item %d is checked\n", pNMLV->iItem);
	}
	else if ((pNMLV->uOldState & INDEXTOSTATEIMAGEMASK(2)) /* old state : checked */
		&& (pNMLV->uNewState & INDEXTOSTATEIMAGEMASK(1)) /* new state : unchecked */
		)
	{
		TRACE("Item %d is unchecked\n", pNMLV->iItem);
	}
	else
	{
		TRACE("Item %d does't change the check-status\n", pNMLV->iItem);
	}








	*pResult = 0;
}



BEGIN_MESSAGE_MAP(BigPicListCtrl, BaseCtrl)
	ON_NOTIFY_REFLECT(LVN_ITEMCHANGED, OnItemChanged)
	ON_NOTIFY_REFLECT(NM_DBLCLK, OnDbClick)
END_MESSAGE_MAP()


// BigPicListCtrl 消息处理程序
