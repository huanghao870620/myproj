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
	this->gfs = good_file_service::get_good_file_service();
	this->gs = good_service::get_good_service();
	this->fs = file_service::get_file_service();
}

ListGoodsDlg::~ListGoodsDlg()
{
}

BOOL ListGoodsDlg::OnInitDialog(){
	CDialogEx::OnInitDialog();
	this->listCtrl.InsertColumn(1, "ID", LVCFMT_CENTER, 40);

	this->listCtrl.InsertColumn(2, charset_util::UTF8ToGBK("商品名称").c_str(), LVCFMT_LEFT, 300);
	this->listCtrl.InsertColumn(3, charset_util::UTF8ToGBK("商品描述").c_str(), LVCFMT_LEFT, 400);
	this->listCtrl.InsertColumn(4, charset_util::UTF8ToGBK("商品价格").c_str(), LVCFMT_LEFT, 200);
	this->Refresh(); 
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

/*删除商品*/
void ListGoodsDlg::delGood(){
	typedef std::auto_ptr<odb::database> data;
	typedef odb::core::transaction tran;
	typedef odb::transaction t;
	data db= db_util::get_db_util()->get_db();
	tran *tx = NULL;
	try{
	if (!t::has_current()){
		tx = new tran(db->begin());
	}
	else
	{
		tx = &(t::current());
	}

	int nItem = this->listCtrl.GetFirsetSelectedItem();
	CString img = this->listCtrl.GetItemText(nItem, 0);
	long good_id = Util::stol(img.GetBuffer(0));
	goods good= this->gs->findById(good_id);
	file thumbFile = this->gfs->getThumbFile4GoodId(good_id);
	this->gfs->deleteGoodFile(thumbFile.get_id()); //删除
	this->gs->deleteById(good_id);
	this->fs->deleteById(good.get_adv_pic());//广告图
	t::current().commit();
	}
	catch (odb::exception&e){
		std::cout << e.what() << std::endl;
		t::current().rollback();
	}
	this->Refresh();
}


void ListGoodsDlg::Refresh(){
	typedef odb::core::transaction tran;
	typedef odb::transaction t;
	typedef std::auto_ptr<odb::database> data;
	data db = db_util::get_db_util()->get_db();
	tran *tx = NULL;
	try{

		if (!t::has_current()){
			tx = new tran(db->begin());
		}
		else
		{
			tx = &(t::current());
		}
		listCtrl.DeleteAllItems();
		ListView_SetExtendedListViewStyle(this->listCtrl.GetSafeHwnd(), this->listCtrl.GetExStyle() | LVS_EX_CHECKBOXES);
		DWORD dwStyle;
		dwStyle = listCtrl.GetExtendedStyle();
		dwStyle = dwStyle | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_SUBITEMIMAGES;
		listCtrl.SetExtendedStyle(dwStyle);

		

		good_service*gs = good_service::get_good_service();
		std::list<goods> glist;
		glist= gs->query_list();

		std::list<goods>::iterator iter = glist.begin();
		for (int i = 0; iter != glist.end(); iter++, i++){
			goods g = *iter;
			long id = g.get_id();
			std::string id_str = Util::ltos(id);
			std::string &name = charset_util::UTF8ToGBK(g.get_name());
			std::string&info = charset_util::UTF8ToGBK(g.get_info());
			float price= g.get_price();
			std::string price_str = Util::ftos(price);
			int nRow = this->listCtrl.InsertItem(i + 1, id_str.c_str());
			this->listCtrl.SetItemText(nRow, 1, name.c_str());
			this->listCtrl.SetItemText(nRow, 2, info.c_str());
			this->listCtrl.SetItemText(nRow, 3, price_str.append(charset_util::UTF8ToGBK("元")).c_str());
		}
		t::current().commit();
	}
	catch (odb::exception&e){
		std::cout << e.what() << std::endl;
		t::current().rollback();
	}
}


void ListGoodsDlg::AddGood(){
	this->addGoodDlg.DoModal();
}

BEGIN_MESSAGE_MAP(ListGoodsDlg, CDialogEx)
	//ON_NOTIFY_REFLECT(LVN_ITEMCHANGED,OnItemChanged)
	ON_BN_CLICKED(IDC_BUTTON_DEL_GOOD, delGood)//
	ON_BN_CLICKED(IDC_BUTTON_GOOD_REFRESH,Refresh)
	ON_BN_CLICKED(IDC_BUTTON_ADD_GOOD, AddGood)
END_MESSAGE_MAP()


// ListGoodsDlg 消息处理程序
