// D:\cppwork\myproj\xunan_admin\dlg\BigPicDlg.cpp : 实现文件
//

#include "../stdafx.h"
#include "BigPicDlg.h"
#include "afxdialogex.h"


// BigPicDlg 对话框

IMPLEMENT_DYNAMIC(BigPicDlg, CDialogEx)

BigPicDlg::BigPicDlg(long goodId, CWnd* pParent /*=NULL*/)
	: CDialogEx(BigPicDlg::IDD, pParent)
{
	gfs = good_file_service::get_good_file_service();
	this->goodId = goodId;
}

BigPicDlg::~BigPicDlg()
{
}

void BigPicDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_LIST_BIGPIC, this->clistCtrl);
}



BOOL BigPicDlg::OnInitDialog(){
	CDialogEx::OnInitDialog();
	ListView_SetExtendedListViewStyle(this->clistCtrl.GetSafeHwnd(), this->clistCtrl.GetExStyle() | LVS_EX_CHECKBOXES);
	DWORD dwStyle;
	dwStyle = clistCtrl.GetExtendedStyle();
	dwStyle = dwStyle | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_SUBITEMIMAGES;
	clistCtrl.SetExtendedStyle(dwStyle);
	this->clistCtrl.InsertColumn(1, "ID", LVCFMT_CENTER, 200);
	this->clistCtrl.InsertColumn(2, "uri_path", LVCFMT_CENTER, 200);
	this->refresh();
	return TRUE;
}

void BigPicDlg::addBigPic(){
	AddBigPic4GoodDlg *dlg = new AddBigPic4GoodDlg(this->goodId);
	dlg->Create(IDD_DIALOG_ADD_BIGPIC, this);
	dlg->ShowWindow(SW_SHOW);
}

/*刷新*/
void BigPicDlg::refresh(){
	std::list<file> ls;
	gfs->findFileByGoodId(this->goodId, GOOD_BIG_PHOTO, &ls);
	clistCtrl.DeleteAllItems();
	std::list<file>::iterator iter = ls.begin();
	for (int i = 0; iter != ls.end(); iter++, i++){
		file f = *iter;
		long id = f.get_id();
		std::string & uri_path = f.get_uri_path();
		std::cout << "" << std::endl;
		std::string id_str = Util::ltos(id);
		/*std::string &name = charset_util::UTF8ToGBK(c->get_name());
		std::string&info = charset_util::UTF8ToGBK(c->get_country_code());*/
		int nRow = this->clistCtrl.InsertItem(i + 1, id_str.c_str());
		this->clistCtrl.SetItemText(nRow, 1, uri_path.c_str());
		//this->clistCtrl.SetItemText(nRow, 2, uri_path);
	}
}

void BigPicDlg::delBigPic(){
	int nItem= this->clistCtrl.GetFirsetSelectedItem();
	CString img = this->clistCtrl.GetItemText(nItem, 0);
	std::cout << "" << std::endl;
 	long img_id = Util::stol(img.GetBuffer(0));
	this->gfs->deleteGoodFile(img_id);
}

BEGIN_MESSAGE_MAP(BigPicDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ADD_BIGPIC, addBigPic)
	ON_BN_CLICKED(IDC_BUTTON_FRESH_BIGPICLIST, refresh)
	ON_BN_CLICKED(IDC_BUTTON_DEL_BIGPIC,delBigPic)
END_MESSAGE_MAP()


// BigPicDlg 消息处理程序
