// ListGoodsDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ListGoodsDlg.h"
#include "afxdialogex.h"


// ListGoodsDlg 对话框

IMPLEMENT_DYNAMIC(ListGoodsDlg, CDialogEx)

ListGoodsDlg::ListGoodsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ListGoodsDlg::IDD, pParent)
{

}

ListGoodsDlg::~ListGoodsDlg()
{
}

BOOL ListGoodsDlg::OnInitDialog(){
	CDialogEx::OnInitDialog();
	std::cout << "" << std::endl;
	this->listCtrl.InsertColumn(1, "商品名称",LVCFMT_CENTER,40);
	this->listCtrl.InsertColumn(2, "商品描述",LVCFMT_CENTER,50);
	//int nRow = this->listCtrl.InsertItem(1, "asddas");
	//this->listCtrl.SetItemText(nRow, 1, "fddfdf");
	
	good_dao*gd= good_dao::get_good_dao();
	std::list<goods*> glist;
	gd->query_list(&glist);

	std::list<goods*>::iterator iter = glist.begin();
	for (int i=0; iter != glist.end(); iter++,i++){
		goods *g = *iter;
		int nRow = this->listCtrl.InsertItem(i+1, g->get_name().c_str());
		this->listCtrl.SetItemText(nRow, 1, g->get_info().c_str());
	}
	return TRUE;
}

void ListGoodsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, this->listCtrl);
	std::cout << "" << std::endl;
}


BEGIN_MESSAGE_MAP(ListGoodsDlg, CDialogEx)
END_MESSAGE_MAP()


// ListGoodsDlg 消息处理程序
