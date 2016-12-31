// D:\cppwork\myproj\xunan_admin\base_dlg\BaseCouponsDlg.cpp : 实现文件
//

#include "../stdafx.h"
#include "BaseCouponsDlg.h"



// BaseCouponsDlg 对话框

IMPLEMENT_DYNAMIC(BaseCouponsDlg, CDialogEx)

BaseCouponsDlg::BaseCouponsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(BaseCouponsDlg::IDD, pParent)
{
	this->cs = classification_service::get_classification_service();
	this->bs= brand_service::get_brand_service();
}

BaseCouponsDlg::~BaseCouponsDlg()
{
}

void BaseCouponsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_PRICE, this->priceEdit);
	DDX_Control(pDX, IDC_EDIT_SILL, this->sillEdit);
	DDX_Control(pDX, IDC_DATETIMEPICKER_LIMIT_START, this->limitStart);
	DDX_Control(pDX, IDC_DATETIMEPICKER_LIMIT_END, this->limitEnd);
	DDX_Control(pDX, IDC_COMBO_CLASS_ID, this->classBox);
	DDX_Control(pDX, IDC_COMBO_BRAND_ID, this->brandBox);
}

/*加载分类*/
void BaseCouponsDlg::loadClass(){
	std::list<classification*> ls;
	this->cs->query_classification(&ls);

	std::list<classification*>::iterator iter = ls.begin();
	for (int i = 0; iter != ls.end(); iter++, i++){
		classification *classi = *iter;
		classi->set_name(charset_util::UTF8ToGBK(classi->get_name()));

		this->classBox.AddString(classi->get_name().c_str());
		long id = classi->get_id();
		this->classBox.SetItemData(i, id);
	}
}

/*加载品牌*/
void BaseCouponsDlg::loadBrand(){
	std::list<brand> b_list= this->bs->get_brands();
	std::cout << "" << std::endl;
}


BOOL BaseCouponsDlg::OnInitDialog(){
	CDialogEx::OnInitDialog();

	this->loadClass();
	this->loadBrand();

	return TRUE;
}

BEGIN_MESSAGE_MAP(BaseCouponsDlg, CDialogEx)
END_MESSAGE_MAP()


// BaseCouponsDlg 消息处理程序
