//// AddBrandDlg.cpp : 实现文件
////
//
#include "stdafx.h"
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
}

AddBrandDlg::~AddBrandDlg()
{
}

void AddBrandDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, this->brandNameEdit);//品牌名称
	DDX_Control(pDX, IDC_STATIC_BRAND_IMG, this->brandImg);//品牌名称
}

BOOL AddBrandDlg::OnInitDialog(){
	CDialogEx::OnInitDialog();

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
	this->bs->add_brand(b);
}

void AddBrandDlg::selectImg(){
	this->filePath = Util::GetFilePathName();
	RECT rect;
	this->brandImg.GetClientRect(&rect);
	ShowJpg::ShowJpgGif(this->brandImg.GetDC(), this->filePath, rect.left, rect.top);
}


BEGIN_MESSAGE_MAP(AddBrandDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, addBrand)
	ON_BN_CLICKED(IDC_BUTTON1,selectImg)
END_MESSAGE_MAP()
//
//
//// AddBrandDlg 消息处理程序
