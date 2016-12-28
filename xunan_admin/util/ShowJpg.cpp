///////////////////////////////////////////////////////////
//  ShowJpg.cpp
//  Implementation of the Class ShowJpg
//  Created on:      17-ʮһ��-2016 17:37:31
//  Original author: burgess
///////////////////////////////////////////////////////////

#include "ShowJpg.h"


ShowJpg::ShowJpg(){

}



ShowJpg::~ShowJpg(){

}



//************************************  
// ����˵��:    ��ʾJPG��GIF��BMPͼƬ  
// ����˵��:    CDC * pDC           �豸��������  
// ����˵��:    CString strPath     Ҫ��ʾ��ͼƬ·��   
// ����˵��:    int x               Ҫ��ʾ��Xλ��  
// ����˵��:    int y               Ҫ��ʾ��Yλ��  
// ����ֵ:      BOOL                �ɹ�����TRUE,���򷵻�FALSE  
//************************************  
BOOL ShowJpg::ShowJpgGif(CDC* pDC, CString strPath, int x, int y)

{
	CFileStatus fstatus;
	CFile file;
	ULONGLONG cb;

	 //strPath = charset_util::GBKToUTF8(strPath.GetBuffer(0)).c_str();
	// ���ļ�������ļ�����Ч��  
	if (!file.Open(strPath, CFile::modeRead))
	{
		return FALSE;
	}
	if (!file.GetStatus(strPath, fstatus))
	{
		return FALSE;
	}
	if ((cb = fstatus.m_size) <= 0)
	{
		return FALSE;
	}

	// �����ļ���С�����ڴ�ռ�,�ǵ��ͷ��ڴ�  
	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, (unsigned int)cb);
	if (hGlobal == NULL)
	{
		return FALSE;
	}

	// �����ղŷ�����ڴ�ռ�  
	LPVOID pvData = NULL;
	pvData = GlobalLock(hGlobal);
	if (pvData == NULL)
	{
		GlobalFree(hGlobal);  // �ǵ��ͷ��ڴ�  
		return FALSE;
	}

	// ���ļ��ŵ�����  
	IStream *pStm;
	file.Read(pvData, (unsigned int)cb);
	GlobalUnlock(hGlobal);
	CreateStreamOnHGlobal(hGlobal, TRUE, &pStm);
	//CreateStreamOnHGlobal(pvData, FALSE, &pStm);

	// �����м���ͼƬ  
	// ��ʾJPEG��GIF��ʽ��ͼƬ��GIFֻ����ʾһ֡����������ʾ������  
	// Ҫ��ʾ����GIF��ʹ��ACTIVE�ؼ���  
	IPicture *pPic;
	HRESULT hr = OleLoadPicture(pStm, (LONG)fstatus.m_size, TRUE, IID_IPicture, (LPVOID*)&pPic);
	if (hr != S_OK)
	{
		GlobalFree(hGlobal);  // �ǵ��ͷ��ڴ�  
		return FALSE;
	}

	//��ȡͼ���͸�,ע������Ŀ�͸߲���ͼ��ķֱ���  
	OLE_XSIZE_HIMETRIC hmWidth;
	OLE_YSIZE_HIMETRIC hmHeight;
	pPic->get_Width(&hmWidth);
	pPic->get_Height(&hmHeight);

	//use render function display image  
	RECT rtWnd;
	pDC->GetWindow()->GetWindowRect(&rtWnd);
	int iWndWidth = rtWnd.right - rtWnd.left;
	int iWndHeight = rtWnd.bottom - rtWnd.top;

	if (FAILED(pPic->Render(*pDC, x, y, iWndWidth, iWndHeight, 0, hmHeight, hmWidth, -hmHeight, NULL)))
	{
		pPic->Release();
		GlobalFree(hGlobal);  // �ǵ��ͷ��ڴ�  
		return false;
	}

	pPic->Release();
	GlobalFree(hGlobal);  // �ǵ��ͷ��ڴ�  
	return true;
}

//************************************  
// ����˵��:    ��ʾJPG��GIF��BMPͼƬ  
// ����˵��:    CDC * pDC           �豸��������  
// ����˵��:    CString strPath     Ҫ��ʾ��ͼƬ·��   
// ����˵��:    int x               Ҫ��ʾ��Xλ��  
// ����˵��:    int y               Ҫ��ʾ��Yλ��  
// ����ֵ:      BOOL                �ɹ�����TRUE,���򷵻�FALSE  
//************************************  
BOOL ShowJpg::ShowImage(CDC* pDC, CString strPath, int x, int y)
{

	IPicture *pPic = NULL;
	OleLoadPicturePath(CComBSTR(strPath.GetBuffer()), (LPUNKNOWN)NULL, 0, 0, IID_IPicture, (LPVOID*)&pPic);
	if (NULL == pPic)
	{
		return FALSE;
	}

	// ��ȡͼ���͸�,ע������Ŀ�͸߲���ͼ��ķֱ���  
	OLE_XSIZE_HIMETRIC hmWidth;
	OLE_YSIZE_HIMETRIC hmHeight;
	pPic->get_Width(&hmWidth);
	pPic->get_Height(&hmHeight);


	// ��ȡ��ʾͼƬ���ڵĿ�Ⱥ͸߶�  
	RECT rtWnd;
	pDC->GetWindow()->GetWindowRect(&rtWnd);
	int iWndWidth = rtWnd.right - rtWnd.left;
	int iWndHeight = rtWnd.bottom - rtWnd.top;

	if (FAILED(pPic->Render(*pDC, x, y, iWndWidth, iWndHeight, 0, hmHeight, hmWidth, -hmHeight, NULL)))
	{
		pPic->Release();
		return false;
	}

	//�ǵ��ͷ���Դ����Ȼ�ᵼ���ڴ�й¶  
	pPic->Release();

	return true;
}

void ShowJpg::ShowPng(CDC*pDC, CString strPath,CRect&rect){
	CImage img;
	HRESULT ret = img.Load(strPath); //wuziqi.png����Ҫ���ص�ͼƬ���ƣ�����·��
	HBITMAP hbitmap = img.Detach();

	//����� BMP ͼƬһ������ͼƬ ,��������ʾͼƬ�Ĳ���
	CBitmap cBitmap;
	BITMAP bitmap;
	CDC memdc;
	cBitmap.Attach(hbitmap);
	memdc.CreateCompatibleDC(pDC);
	memdc.SelectObject(hbitmap);
	cBitmap.GetBitmap(&bitmap);
	pDC->StretchBlt(rect.left, rect.top, rect.Width(), rect.Height(), &memdc, rect.left, rect.top, rect.Width(), rect.Height(), SRCCOPY);
}