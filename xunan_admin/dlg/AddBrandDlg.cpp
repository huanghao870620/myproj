//// AddBrandDlg.cpp : 实现文件
////
//
#include "../stdafx.h"
#include "AddBrandDlg.h"
#include "afxdialogex.h"
//
//
//// AddBrandDlg 对话框
//
IMPLEMENT_DYNAMIC(AddBrandDlg, CDialogEx)
//
AddBrandDlg::AddBrandDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(AddBrandDlg::IDD, pParent)
{
	this->bs = brand_service::get_brand_service();
	this->fs = file_service::get_file_service();
	this->us = upload_service::get_upload_service();
	this->uts = upload_type_service::get_upload_type_service();
}

AddBrandDlg::~AddBrandDlg()
{
}

void AddBrandDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, this->brandNameEdit);//品牌名称
	DDX_Control(pDX, IDC_STATIC_BRAND_IMG, this->brandImg);//品牌名称
	DDX_Control(pDX, IDC_EDIT_BRAND_INFO, this->brandInfo);//品牌描述
	DDX_Control(pDX, IDC_COMBO_UPLOAD_TYPE, this->uploadTypeComboBox);//上传者类型
}

BOOL AddBrandDlg::OnInitDialog(){
	CDialogEx::OnInitDialog();

	std::list<upload_type*> ut_list;
	this->uts->query(ut_list);
	std::list<upload_type*>::iterator iter = ut_list.begin();
	for (int i = 0; iter != ut_list.end(); iter++,i++){
		upload_type*ut = *iter;
		long id=ut->get_id();
		std::string&name=ut->get_name();
		name=charset_util::UTF8ToGBK(name);
		this->uploadTypeComboBox.AddString(name.c_str());
		this->uploadTypeComboBox.SetItemData(i, id);
	}
	return TRUE;
}


void AddBrandDlg::addBrand(){
	CString brandName;
	this->brandNameEdit.GetWindowTextA(brandName);
	brand b;
	std::string name = brandName.GetBuffer(0);
	b.set_name(name);
	
	file f;
	this->us->upload_file(f, this->filePath, 15);
	b.set_img_id(f.get_id());

	b.set_upload_type_id(this->uploadType);

	CString brandInfoText;
	this->brandInfo.GetWindowTextA(brandInfoText);
	std::string info = brandInfoText.GetBuffer(0);
	b.set_info(info);
	this->bs->add_brand(b);
}

void AddBrandDlg::selectImg(){
	this->filePath = Util::GetFilePathName();
	RECT rect;
	this->brandImg.GetClientRect(&rect);
	ShowJpg::ShowJpgGif(this->brandImg.GetDC(), this->filePath, rect.left, rect.top);
}

/*选择上传者类型*/
void AddBrandDlg::selUploadType(){
	int index = this->uploadTypeComboBox.GetCurSel();
	this->uploadTypeComboBox.SetCurSel(index);
	index = this->uploadTypeComboBox.GetCurSel();
	DWORD_PTR id = this->uploadTypeComboBox.GetItemData(index);
	this->uploadType = id;
}

BEGIN_MESSAGE_MAP(AddBrandDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, addBrand)
	ON_BN_CLICKED(IDC_BUTTON1,selectImg)
	ON_CBN_SELCHANGE(IDC_COMBO_UPLOAD_TYPE, selUploadType)
END_MESSAGE_MAP()
//
//
//// AddBrandDlg 消息处理程序
