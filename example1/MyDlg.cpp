// MyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// MyDlg �Ի���

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
: CDialogEx(MyDlg::IDD, pParent)
{

}

MyDlg::~MyDlg()
{
}

BOOL MyDlg::OnInitDialog(){
	CDialogEx::OnInitDialog();
	//this->ShowPic("http://47.88.105.195/12/454/2011825132301329511229904127423500507232517.png", this->pic.GetDC());
	GetHttp *gh = new GetHttp;
	gh->download();
	delete gh;
	return TRUE;
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_SHOWPNG, this->pic);
}


// ��ʾͼƬ, lpstrImgUrl ΪͼƬURL��ַ��hWnd Ϊ���ھ��      
HRESULT MyDlg::ShowPic(char *lpstrImgUrl, CDC*pDC)
{
	HDC hDC_Temp = pDC->m_hDC;
	IPicture *pPic;
	IStream *pStm;
	BOOL bResult;
	DWORD dwFileSize, dwByteRead;

	//��ȡ��ҳ��ͼƬ�ļ���ʵ���Ǹ�CHttpFileָ��   
	CInternetSession session("HttpClient");
	CFile* httpFile = (CFile*)session.OpenURL(lpstrImgUrl);

	if (httpFile != INVALID_HANDLE_VALUE)
	{
		dwFileSize = httpFile->GetLength();//��ȡ�ļ��ֽ���       
		if (dwFileSize == 0xFFFFFFFF){
			return E_FAIL;
		}
	}
	else
	{
		return E_FAIL;
	}


	//����ȫ�ִ洢�ռ�       
	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, dwFileSize);
	LPVOID pvData = NULL;

	if (hGlobal == NULL){
		return E_FAIL;
	}

	//���������ڴ��       
	if ((pvData = GlobalLock(hGlobal)) == NULL){
		return E_FAIL;
	}

	//���ļ������ڴ滺����       
	dwByteRead = httpFile->Read(pvData, dwFileSize);

	GlobalUnlock(hGlobal);

	CreateStreamOnHGlobal(hGlobal, TRUE, &pStm);

	//װ��ͼ���ļ�       
	bResult = OleLoadPicture(pStm, dwFileSize, TRUE, IID_IPicture, (LPVOID*)&pPic);

	if (FAILED(bResult)){
		return E_FAIL;
	}

	OLE_XSIZE_HIMETRIC hmWidth; //ͼƬ����ʵ���, ��λΪӢ��      
	OLE_YSIZE_HIMETRIC hmHeight; //ͼƬ����ʵ�߶�, ��λΪӢ��      
	pPic->get_Width(&hmWidth);
	pPic->get_Height(&hmHeight);

	//ת��hmWidth��hmHeightΪpixels���룬1Ӣ��=25.4����      
	int nWidth = MulDiv(hmWidth, GetDeviceCaps(hDC_Temp, LOGPIXELSX), 2540);
	int nHeight = MulDiv(hmHeight, GetDeviceCaps(hDC_Temp, LOGPIXELSY), 2540);

	//��ͼ���������Ļ�ϣ��е���BitBlt��       
	bResult = pPic->Render(hDC_Temp, 0, 0, nWidth, nHeight,
		0, hmHeight, hmWidth, -hmHeight, NULL);

	pPic->Release();

	httpFile->Close();//�رմ򿪵��ļ�       

	if (SUCCEEDED(bResult))
	{
		return S_OK;
	}
	else
	{
		return E_FAIL;
	}
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
END_MESSAGE_MAP()


// MyDlg ��Ϣ�������
