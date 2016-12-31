// D:\cppwork\myproj\xunan_admin\dlg\EditCountryDlg.cpp : 实现文件
//

#include "../stdafx.h"
#include "EditCountryDlg.h"


// EditCountryDlg 对话框
IMPLEMENT_DYNAMIC(EditCountryDlg, BaseCountryDlg)

EditCountryDlg::EditCountryDlg(LONG id, CWnd* pParent /*=NULL*/)
	: BaseCountryDlg(pParent)
{
	this->cs = country_service::get_country_service();
	this->fs = file_service::get_file_service();
	this->us = upload_service::get_upload_service();
	this->id = id;
}

EditCountryDlg::~EditCountryDlg()
{
}

BOOL EditCountryDlg::OnInitDialog(){
	BaseCountryDlg::OnInitDialog();
	this->SetWindowTextA("编辑国家");
	country &c= this->cs->findById(this->id);

	this->nameEdit.SetWindowTextA(c.get_name().c_str());
	this->countryCodeEdit.SetWindowTextA(c.get_country_code().c_str());
	
	file&f= fs->findById(c.get_img_id());

	char *local_path = Config::getConfig()->get_local_path();
	this->localPath = std::string(local_path).append(this->fs->downloadFtpFile(f.get_uri_path())).c_str();

	CRect rect;
	this->imgControl.GetClientRect(&rect);
	ShowJpg::ShowPng(this->imgControl.GetDC(), this->localPath, rect);
	return TRUE;
}


void EditCountryDlg::OnPaint(){
	BaseCountryDlg::OnPaint();

	CRect rect;
	this->imgControl.GetClientRect(&rect);
	ShowJpg::ShowPng(this->imgControl.GetDC(), this->localPath, rect);
}

void EditCountryDlg::DoDataExchange(CDataExchange* pDX)
{
	BaseCountryDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_COUNTRY_NAME, this->nameEdit);
	DDX_Control(pDX, IDC_STATIC_COUNTRY_PIC, this->imgControl);
	DDX_Control(pDX, IDC_EDIT_COUNTRY_CODE, this->countryCodeEdit);
}



void EditCountryDlg::EditCountry(){
	CString countryCode;
	CString csName;

	this->countryCodeEdit.GetWindowTextA(countryCode);
	this->nameEdit.GetWindowTextA(csName);

	std::string country_code = countryCode.GetBuffer(0);/*國家代碼*/
	std::string name = csName.GetBuffer(0); /*國家名稱*/
	std::string img_path = this->localPath.GetBuffer(0); /*國家圖片*/


	this->cs->edit_country(this->id, name, country_code, img_path, *this->us);
}

BOOL LoadImageFromIDResource(CImage *pImage, UINT nResID, LPCTSTR lpTyp)
{
	if (pImage == NULL)
		return false;
	pImage->Destroy();
	// 查找资源
	HRSRC hRsrc = ::FindResource(AfxGetResourceHandle(), MAKEINTRESOURCE(nResID), lpTyp);
	if (hRsrc == NULL)
		return false;
	// 加载资源
	HGLOBAL hImgData = ::LoadResource(AfxGetResourceHandle(), hRsrc);
	if (hImgData == NULL)
	{
		::FreeResource(hImgData);
		return false;
	}
	// 锁定内存中的指定资源
	LPVOID lpVoid = ::LockResource(hImgData);
	LPSTREAM pStream = NULL;
	DWORD dwSize = ::SizeofResource(AfxGetResourceHandle(), hRsrc);
	HGLOBAL hNew = ::GlobalAlloc(GHND, dwSize);
	LPBYTE lpByte = (LPBYTE)::GlobalLock(hNew);
	::memcpy(lpByte, lpVoid, dwSize);
	// 解除内存中的指定资源
	::GlobalUnlock(hNew);
	// 从指定内存创建流对象
	HRESULT ht = ::CreateStreamOnHGlobal(hNew, TRUE, &pStream);
	if (ht != S_OK)
	{
		GlobalFree(hNew);
	}
	else
	{
		// 加载图片
		pImage->Load(pStream);
		GlobalFree(hNew);
	}
	// 释放资源
	::FreeResource(hImgData);
	return true;
}
//
//VOID EditCountryDlg::SelPic(){
//	this->localPath = Util::GetFilePathName();
//	CRect rect;
//	this->imgControl.GetClientRect(&rect);
//	/*ShowJpg::ShowJpgGif(this->imgControl.GetDC(), this->localPath, rect.left, rect.top);*/
//	ShowJpg::ShowPng(this->imgControl.GetDC(), this->localPath, rect);
//}



BEGIN_MESSAGE_MAP(EditCountryDlg, BaseCountryDlg)
	ON_BN_CLICKED(IDC_BUTTON_SELCOUNTRYPIC, SelPic)
	ON_BN_CLICKED(IDOK, EditCountry)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// EditCountryDlg 消息处理程序


void EditCountryDlg::t(){
	USES_CONVERSION;
	LPWSTR lpwStr = A2W(this->localPath);
	Gdiplus::Image image(lpwStr); //载入指定路径的图像文件 
	CWnd* pwnd = GetDlgItem(IDC_STATIC_COUNTRY_PIC);
	CDC* dc = pwnd->GetDC(); //获取图像控件的设备上下文 
	CRect rect;
	this->imgControl.GetClientRect(&rect); //获取客户区域的信息 
	Gdiplus::Graphics graph(dc->GetSafeHdc());
	graph.DrawImage(&image, 0, 0, rect.Width(), rect.Height());
	//graph.DrawImage(&image, 0, 0, 400, 400);

	//在指定图像控件的区域中绘制图像 
	// 函数 DrawImage()的第 1 个参数为存放图像数据的内存地址 
	// 第 2 个参数和第 3 个参数是绘制的起点坐标 
	// 第 4 个参数和第 5 个参数是指定的宽度和高度 
	ReleaseDC(dc); //释放资源 
}