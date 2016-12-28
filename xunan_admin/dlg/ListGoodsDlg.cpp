// ListGoodsDlg.cpp : 实现文件
//

#include "../stdafx.h"
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
	this->listCtrl.InsertColumn(1, "ID", LVCFMT_CENTER, 40);
	
	this->listCtrl.InsertColumn(2, charset_util::UTF8ToGBK("商品名称").c_str(), LVCFMT_LEFT, 300);
	this->listCtrl.InsertColumn(3, charset_util::UTF8ToGBK("商品描述").c_str(), LVCFMT_LEFT, 400);
	//int nRow = this->listCtrl.InsertItem(1, "asddas");
	//this->listCtrl.SetItemText(nRow, 1, "fddfdf");
	
	good_service*gs = good_service::get_good_service();
	std::list<goods*> glist;
	gs->query_list(&glist);

	std::list<goods*>::iterator iter = glist.begin();
	for (int i=0; iter != glist.end(); iter++,i++){
		goods *g = *iter;
		long id = g->get_id();
		std::string id_str = Util::ltos(id);
		std::string &name = charset_util::UTF8ToGBK(g->get_name());
		std::string&info = charset_util::UTF8ToGBK(g->get_info());
		int nRow = this->listCtrl.InsertItem(i + 1, id_str.c_str());
		this->listCtrl.SetItemText(nRow, 1, name.c_str());
		this->listCtrl.SetItemText(nRow, 2, info.c_str());
	}
	return TRUE;
}

void ListGoodsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, this->listCtrl);
	std::cout << "" << std::endl;
}


void ListGoodsDlg::OnPaint(){
	std::cout << "" << std::endl;
}



BEGIN_MESSAGE_MAP(ListGoodsDlg, CDialogEx)
	//ON_NOTIFY_REFLECT(LVN_ITEMCHANGED,OnItemChanged)
END_MESSAGE_MAP()


// ListGoodsDlg 消息处理程序
