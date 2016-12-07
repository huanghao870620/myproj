// CountryShow.cpp : 实现文件
//

#include "stdafx.h"
#include "CountryShow.h"
#include "afxdialogex.h"


// CountryShow 对话框
IMPLEMENT_DYNAMIC(CountryShow, CDialogEx)

CountryShow::CountryShow(CWnd* pParent /*=NULL*/)
	: CDialogEx(CountryShow::IDD, pParent)
{
	this->cs = country_service::get_country_service();
}

CountryShow::~CountryShow()
{
}

void CountryShow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_COUNTRY, this->clistCtrl);
}

BOOL CountryShow::OnInitDialog(){
	CDialogEx::OnInitDialog();
	this->clistCtrl.InsertColumn(1, "ID", LVCFMT_CENTER, 40);
	this->clistCtrl.InsertColumn(2,"国家", LVCFMT_CENTER, 40);
	this->clistCtrl.InsertColumn(3, "国家代码", LVCFMT_CENTER, 50);
	std::list<country*> c_list;
	this->cs->query(c_list);
	std::list<country*>::iterator iter = c_list.begin();
	for (int i = 0; iter != c_list.end(); iter++, i++){
		country *c = *iter;
		long id = c->get_id();
		std::string id_str = Util::ltos(id);
		std::string &name = charset_util::UTF8ToGBK(c->get_name());
		std::string&info = charset_util::UTF8ToGBK(c->get_country_code());
		int nRow = this->clistCtrl.InsertItem(i + 1, id_str.c_str());
		this->clistCtrl.SetItemText(nRow, 1, name.c_str());
		this->clistCtrl.SetItemText(nRow, 2, info.c_str());
	}
	return TRUE;
}

BEGIN_MESSAGE_MAP(CountryShow, CDialogEx)
END_MESSAGE_MAP()


// CountryShow 消息处理程序
