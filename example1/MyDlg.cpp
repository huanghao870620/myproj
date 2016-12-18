// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// MyDlg 对话框

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


// 显示图片, lpstrImgUrl 为图片URL地址，hWnd 为窗口句柄      
HRESULT MyDlg::ShowPic(char *lpstrImgUrl, CDC*pDC)
{
	HDC hDC_Temp = pDC->m_hDC;
	IPicture *pPic;
	IStream *pStm;
	BOOL bResult;
	DWORD dwFileSize, dwByteRead;

	//读取网页上图片文件，实际是个CHttpFile指针   
	CInternetSession session("HttpClient");
	CFile* httpFile = (CFile*)session.OpenURL(lpstrImgUrl);

	if (httpFile != INVALID_HANDLE_VALUE)
	{
		dwFileSize = httpFile->GetLength();//获取文件字节数       
		if (dwFileSize == 0xFFFFFFFF){
			return E_FAIL;
		}
	}
	else
	{
		return E_FAIL;
	}


	//分配全局存储空间       
	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, dwFileSize);
	LPVOID pvData = NULL;

	if (hGlobal == NULL){
		return E_FAIL;
	}

	//锁定分配内存块       
	if ((pvData = GlobalLock(hGlobal)) == NULL){
		return E_FAIL;
	}

	//把文件读入内存缓冲区       
	dwByteRead = httpFile->Read(pvData, dwFileSize);

	GlobalUnlock(hGlobal);

	CreateStreamOnHGlobal(hGlobal, TRUE, &pStm);

	//装入图形文件       
	bResult = OleLoadPicture(pStm, dwFileSize, TRUE, IID_IPicture, (LPVOID*)&pPic);

	if (FAILED(bResult)){
		return E_FAIL;
	}

	OLE_XSIZE_HIMETRIC hmWidth; //图片的真实宽度, 单位为英寸      
	OLE_YSIZE_HIMETRIC hmHeight; //图片的真实高度, 单位为英寸      
	pPic->get_Width(&hmWidth);
	pPic->get_Height(&hmHeight);

	//转换hmWidth和hmHeight为pixels距离，1英寸=25.4毫米      
	int nWidth = MulDiv(hmWidth, GetDeviceCaps(hDC_Temp, LOGPIXELSX), 2540);
	int nHeight = MulDiv(hmHeight, GetDeviceCaps(hDC_Temp, LOGPIXELSY), 2540);

	//将图形输出到屏幕上（有点像BitBlt）       
	bResult = pPic->Render(hDC_Temp, 0, 0, nWidth, nHeight,
		0, hmHeight, hmWidth, -hmHeight, NULL);

	pPic->Release();

	httpFile->Close();//关闭打开的文件       

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


// MyDlg 消息处理程序
