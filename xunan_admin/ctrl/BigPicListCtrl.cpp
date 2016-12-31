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
