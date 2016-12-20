#include "MyCTreeCtrl.h"


MyCTreeCtrl::MyCTreeCtrl()
{
	std::cout << "" << std::endl;
}


MyCTreeCtrl::~MyCTreeCtrl()
{
}
BEGIN_MESSAGE_MAP(MyCTreeCtrl, CTreeCtrl)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &MyCTreeCtrl::OnTvnSelchanged)
END_MESSAGE_MAP()


BOOL MyCTreeCtrl::OnInitDialog(){
	std::cout << "" << std::endl;
	return TRUE;
}

void MyCTreeCtrl::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;
	CString strText;
	HTREEITEM root = this->GetRootItem();
	HTREEITEM hItem = this->GetSelectedItem();
	strText = this->GetItemText(hItem);
	std::cout << "" << std::endl;
	//SetDlgItemText(0, strText);
}
