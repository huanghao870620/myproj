// D:\cppwork\myproj\xunan_admin\dlg\EditCountryDlg.cpp : ʵ���ļ�
//

#include "../stdafx.h"
#include "EditCountryDlg.h"


// EditCountryDlg �Ի���
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
	this->SetWindowTextA("�༭����");
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

	std::string country_code = countryCode.GetBuffer(0);/*���Ҵ��a*/
	std::string name = csName.GetBuffer(0); /*�������Q*/
	std::string img_path = this->localPath.GetBuffer(0); /*���҈DƬ*/


	this->cs->edit_country(this->id, name, country_code, img_path, *this->us);
}

BOOL LoadImageFromIDResource(CImage *pImage, UINT nResID, LPCTSTR lpTyp)
{
	if (pImage == NULL)
		return false;
	pImage->Destroy();
	// ������Դ
	HRSRC hRsrc = ::FindResource(AfxGetResourceHandle(), MAKEINTRESOURCE(nResID), lpTyp);
	if (hRsrc == NULL)
		return false;
	// ������Դ
	HGLOBAL hImgData = ::LoadResource(AfxGetResourceHandle(), hRsrc);
	if (hImgData == NULL)
	{
		::FreeResource(hImgData);
		return false;
	}
	// �����ڴ��е�ָ����Դ
	LPVOID lpVoid = ::LockResource(hImgData);
	LPSTREAM pStream = NULL;
	DWORD dwSize = ::SizeofResource(AfxGetResourceHandle(), hRsrc);
	HGLOBAL hNew = ::GlobalAlloc(GHND, dwSize);
	LPBYTE lpByte = (LPBYTE)::GlobalLock(hNew);
	::memcpy(lpByte, lpVoid, dwSize);
	// ����ڴ��е�ָ����Դ
	::GlobalUnlock(hNew);
	// ��ָ���ڴ洴��������
	HRESULT ht = ::CreateStreamOnHGlobal(hNew, TRUE, &pStream);
	if (ht != S_OK)
	{
		GlobalFree(hNew);
	}
	else
	{
		// ����ͼƬ
		pImage->Load(pStream);
		GlobalFree(hNew);
	}
	// �ͷ���Դ
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


// EditCountryDlg ��Ϣ�������


void EditCountryDlg::t(){
	USES_CONVERSION;
	LPWSTR lpwStr = A2W(this->localPath);
	Gdiplus::Image image(lpwStr); //����ָ��·����ͼ���ļ� 
	CWnd* pwnd = GetDlgItem(IDC_STATIC_COUNTRY_PIC);
	CDC* dc = pwnd->GetDC(); //��ȡͼ��ؼ����豸������ 
	CRect rect;
	this->imgControl.GetClientRect(&rect); //��ȡ�ͻ��������Ϣ 
	Gdiplus::Graphics graph(dc->GetSafeHdc());
	graph.DrawImage(&image, 0, 0, rect.Width(), rect.Height());
	//graph.DrawImage(&image, 0, 0, 400, 400);

	//��ָ��ͼ��ؼ��������л���ͼ�� 
	// ���� DrawImage()�ĵ� 1 ������Ϊ���ͼ�����ݵ��ڴ��ַ 
	// �� 2 �������͵� 3 �������ǻ��Ƶ�������� 
	// �� 4 �������͵� 5 ��������ָ���Ŀ�Ⱥ͸߶� 
	ReleaseDC(dc); //�ͷ���Դ 
}