// BaseCountryDlg.cpp : 实现文件
//

#include "../stdafx.h"
#include "BaseCountryDlg.h"
#include "afxdialogex.h"


// BaseCountryDlg 对话框

IMPLEMENT_DYNAMIC(BaseCountryDlg, CDialogEx)

BaseCountryDlg::BaseCountryDlg(CWnd* pParent /*=NULL*/)
: CDialogEx(BaseCountryDlg::IDD, pParent)
{
	this->cs = country_service::get_country_service();
	this->us = upload_service::get_upload_service();
}

BaseCountryDlg::~BaseCountryDlg()
{
}

void BaseCountryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_COUNTRY_NAME, this->nameEdit);
	DDX_Control(pDX, IDC_STATIC_COUNTRY_PIC, this->imgControl);
	DDX_Control(pDX, IDC_EDIT_COUNTRY_CODE, this->countryCodeEdit);
}


BOOL BaseCountryDlg::OnInitDialog(){
	CDialogEx::OnInitDialog();
	return TRUE;
}

void BaseCountryDlg::AddCountry(){
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

VOID BaseCountryDlg::SelPic(){
	this->localPath = Util::GetFilePathName();
	RECT rect;
	this->imgControl.GetClientRect(&rect);
	ShowJpg::ShowJpgGif(this->imgControl.GetDC(), this->localPath, rect.left, rect.top);


	/*Gdiplus::Graphics graphics(this->imgControl.GetDC()->m_hDC);
	Gdiplus::ImageAttributes imAtt;
	imAtt.SetColorKey(Gdiplus::Color(0, 0, 0), Gdiplus::Color(10, 10, 10), Gdiplus::ColorAdjustTypeDefault);
	graphics.SetSmoothingMode(Gdiplus::SmoothingModeAntiAlias);
	Gdiplus::Image imageBlue(L"");
	graphics.DrawImage(&imageYear, Rect(cx, 0, iYearWidth, iYearHeight), 0, iYearHeight, iYearWidth, iYearHeight, Gdiplus::UnitPixel, &imAtt);*/
}




BEGIN_MESSAGE_MAP(BaseCountryDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, AddCountry)
	ON_BN_CLICKED(IDC_BUTTON_SELCOUNTRYPIC, SelPic)
END_MESSAGE_MAP()


// BaseCountryDlg 消息处理程序
