///////////////////////////////////////////////////////////
//  ShowJpg.cpp
//  Implementation of the Class ShowJpg
//  Created on:      17-十一月-2016 17:37:31
//  Original author: burgess
///////////////////////////////////////////////////////////

#include "ShowJpg.h"


ShowJpg::ShowJpg(){

}



ShowJpg::~ShowJpg(){

}



//************************************  
// 方法说明:    显示JPG和GIF、BMP图片  
// 参数说明:    CDC * pDC           设备环境对象  
// 参数说明:    CString strPath     要显示的图片路径   
// 参数说明:    int x               要显示的X位置  
// 参数说明:    int y               要显示的Y位置  
// 返回值:      BOOL                成功返回TRUE,否则返回FALSE  
//************************************  
BOOL ShowJpg::ShowJpgGif(CDC* pDC, CString strPath, int x, int y)

{
	CFileStatus fstatus;
	CFile file;
	ULONGLONG cb;

	 //strPath = charset_util::GBKToUTF8(strPath.GetBuffer(0)).c_str();
	// 打开文件并检测文件的有效性  
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

	// 根据文件大小分配内存空间,记得释放内存  
	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, (unsigned int)cb);
	if (hGlobal == NULL)
	{
		return FALSE;
	}

	// 锁定刚才分配的内存空间  
	LPVOID pvData = NULL;
	pvData = GlobalLock(hGlobal);
	if (pvData == NULL)
	{
		GlobalFree(hGlobal);  // 记得释放内存  
		return FALSE;
	}

	// 将文件放到流中  
	IStream *pStm;
	file.Read(pvData, (unsigned int)cb);
	GlobalUnlock(hGlobal);
	CreateStreamOnHGlobal(hGlobal, TRUE, &pStm);
	//CreateStreamOnHGlobal(pvData, FALSE, &pStm);

	// 从流中加载图片  
	// 显示JPEG和GIF格式的图片，GIF只能显示一帧，还不能显示动画，  
	// 要显示动画GIF请使用ACTIVE控件。  
	IPicture *pPic;
	HRESULT hr = OleLoadPicture(pStm, (LONG)fstatus.m_size, TRUE, IID_IPicture, (LPVOID*)&pPic);
	if (hr != S_OK)
	{
		GlobalFree(hGlobal);  // 记得释放内存  
		return FALSE;
	}

	//获取图像宽和高,注意这里的宽和高不是图像的分辨率  
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
		GlobalFree(hGlobal);  // 记得释放内存  
		return false;
	}

	pPic->Release();
	GlobalFree(hGlobal);  // 记得释放内存  
	return true;
}

//************************************  
// 方法说明:    显示JPG和GIF、BMP图片  
// 参数说明:    CDC * pDC           设备环境对象  
// 参数说明:    CString strPath     要显示的图片路径   
// 参数说明:    int x               要显示的X位置  
// 参数说明:    int y               要显示的Y位置  
// 返回值:      BOOL                成功返回TRUE,否则返回FALSE  
//************************************  
BOOL ShowJpg::ShowImage(CDC* pDC, CString strPath, int x, int y)
{

	IPicture *pPic = NULL;
	OleLoadPicturePath(CComBSTR(strPath.GetBuffer()), (LPUNKNOWN)NULL, 0, 0, IID_IPicture, (LPVOID*)&pPic);
	if (NULL == pPic)
	{
		return FALSE;
	}

	// 获取图像宽和高,注意这里的宽和高不是图像的分辨率  
	OLE_XSIZE_HIMETRIC hmWidth;
	OLE_YSIZE_HIMETRIC hmHeight;
	pPic->get_Width(&hmWidth);
	pPic->get_Height(&hmHeight);


	// 获取显示图片窗口的宽度和高度  
	RECT rtWnd;
	pDC->GetWindow()->GetWindowRect(&rtWnd);
	int iWndWidth = rtWnd.right - rtWnd.left;
	int iWndHeight = rtWnd.bottom - rtWnd.top;

	if (FAILED(pPic->Render(*pDC, x, y, iWndWidth, iWndHeight, 0, hmHeight, hmWidth, -hmHeight, NULL)))
	{
		pPic->Release();
		return false;
	}

	//记得释放资源，不然会导致内存泄露  
	pPic->Release();

	return true;
}

void ShowJpg::ShowPng(CDC*pDC, CString strPath,CRect&rect){
	CImage img;
	HRESULT ret = img.Load(strPath); //wuziqi.png是我要加载的图片名称，包含路径
	HBITMAP hbitmap = img.Detach();

	//像操作 BMP 图片一样处理图片 ,下面是显示图片的操作
	CBitmap cBitmap;
	BITMAP bitmap;
	CDC memdc;
	cBitmap.Attach(hbitmap);
	memdc.CreateCompatibleDC(pDC);
	memdc.SelectObject(hbitmap);
	cBitmap.GetBitmap(&bitmap);
	pDC->StretchBlt(rect.left, rect.top, rect.Width(), rect.Height(), &memdc, rect.left, rect.top, rect.Width(), rect.Height(), SRCCOPY);
}