// AddCountryDlg.cpp : 实现文件
//

#include "../stdafx.h"
#include "AddCountryDlg.h"
#include "afxdialogex.h"


// AddCountryDlg 对话框

IMPLEMENT_DYNAMIC(AddCountryDlg, BaseCountryDlg)

AddCountryDlg::AddCountryDlg(CWnd* pParent /*=NULL*/)
	: BaseCountryDlg( pParent)
{
	this->cs = country_service::get_country_service();
	this->us = upload_service::get_upload_service();
}

AddCountryDlg::~AddCountryDlg()
{
}

void AddCountryDlg::DoDataExchange(CDataExchange* pDX)
{
	BaseCountryDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_COUNTRY_NAME, this->nameEdit);
	DDX_Control(pDX, IDC_STATIC_COUNTRY_PIC, this->imgControl);
	DDX_Control(pDX, IDC_EDIT_COUNTRY_CODE, this->countryCodeEdit);
}


BOOL AddCountryDlg::OnInitDialog(){
	BaseCountryDlg::OnInitDialog();
	return TRUE;
}

void AddCountryDlg::AddCountry(){
	CString countryCode;
	this->countryCodeEdit.GetWindowTextA(countryCode);
	std::string country_code = countryCode.GetBuffer(0);

	CString csName;
	this->nameEdit.GetWindowTextA(csName);
	country c;
	file f;
	this->us->upload_file(f, this->localPath, 16);
	c.set_img_id(f.get_id());

	std::string name = csName.GetBuffer(0);
	c.set_name(name);
	c.set_country_code(country_code);
	this->cs->add_country(c);
}



BEGIN_MESSAGE_MAP(AddCountryDlg, BaseCountryDlg)
	ON_BN_CLICKED(IDOK, AddCountry)
	ON_BN_CLICKED(IDC_BUTTON_SELCOUNTRYPIC,SelPic)
END_MESSAGE_MAP()


// AddCountryDlg 消息处理程序
