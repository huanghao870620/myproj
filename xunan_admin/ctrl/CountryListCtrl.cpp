#include "CountryListCtrl.h"


CountryListCtrl::CountryListCtrl()
{
}


CountryListCtrl::~CountryListCtrl()
{
}


void CountryListCtrl::OnItemChanged(NMHDR*pNMHDR, LRESULT*pResult){
	int nItem = this->GetNextItem(-1, LVNI_SELECTED);
	CString id = this->GetItemText(nItem, 0);
	CString name = this->GetItemText(nItem, 1);
	CString info = this->GetItemText(nItem, 2);

	std::cout << name << std::endl;
}

/**/
void CountryListCtrl::OnDbClick(NMHDR*pNMHDR, LRESULT*pResult){
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
		long lid= Util::stol(id.GetBuffer(0));
		std::cout << "id : " << lid << std::endl;


		EditCountryDlg*editCountryDlg = new EditCountryDlg;
		editCountryDlg->Create(IDD_DIALOG_ADD_COUNTRY, this);
		editCountryDlg->ShowWindow(SW_SHOW);
	}
	*pResult = 0;
}

BEGIN_MESSAGE_MAP(CountryListCtrl, CListCtrl)
	ON_NOTIFY_REFLECT(LVN_ITEMCHANGED, OnItemChanged)
	ON_NOTIFY_REFLECT(NM_DBLCLK, OnDbClick)
END_MESSAGE_MAP()