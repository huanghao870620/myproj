///////////////////////////////////////////////////////////
//  MyCListCtrl.cpp
//  Implementation of the Class MyCListCtrl
//  Created on:      25-十一月-2016 18:47:00
//  Original author: admin
///////////////////////////////////////////////////////////

#include "MyCListCtrl.h"


MyCListCtrl::MyCListCtrl(){

}



MyCListCtrl::~MyCListCtrl(){

}

void MyCListCtrl::OnItemChanged(NMHDR*pNMHDR, LRESULT*pResult){
	int nItem = this->GetNextItem(-1, LVNI_SELECTED);
	CString id = this->GetItemText(nItem, 0);
	CString name = this->GetItemText(nItem, 1);
	CString info = this->GetItemText(nItem, 2);

	std::cout << name << std::endl;
}

/**/
void MyCListCtrl::OnDbClick(NMHDR*pNMHDR, LRESULT*pResult){
	NM_LISTVIEW *pNMListView = (NM_LISTVIEW*)pNMHDR;
	int nItem = pNMListView->iItem;
	if (nItem >= 0 && nItem < this->GetItemCount()){//判断双击位置是否在有数据的列表项上面
		std::cout << "" << std::endl;
		int nItem = this->GetNextItem(-1, LVNI_SELECTED);
		CString id = this->GetItemText(nItem, 0);
		CString name = this->GetItemText(nItem, 1);
		CString info = this->GetItemText(nItem, 2);

		std::cout << name << std::endl;
		long lid= Util::stol(id.GetBuffer(0));
		std::cout << "id : " << lid << std::endl;
		this->pDlg = new EditGoodDlg(lid);
		pDlg->Create(IDD_DIALOG_ADD_GOODS, this);
		pDlg->ShowWindow(SW_SHOW);
	}
	*pResult = 0;
}


BEGIN_MESSAGE_MAP(MyCListCtrl,CListCtrl)
	ON_NOTIFY_REFLECT(LVN_ITEMCHANGED, OnItemChanged)
	ON_NOTIFY_REFLECT(NM_DBLCLK,OnDbClick)
END_MESSAGE_MAP()

