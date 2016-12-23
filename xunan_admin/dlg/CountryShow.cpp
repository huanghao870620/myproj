// CountryShow.cpp : ʵ���ļ�
//

#include "../stdafx.h"
#include "CountryShow.h"
#include "afxdialogex.h"


// CountryShow �Ի���
IMPLEMENT_DYNAMIC(CountryShow, CDialogEx)

CountryShow::CountryShow(CWnd* pParent /*=NULL*/)
	: CDialogEx(CountryShow::IDD, pParent)
{
	this->cs = country_service::get_country_service();
}

CountryShow::~CountryShow()
{
}

void CountryShow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_COUNTRY, this->clistCtrl);
}

BOOL CountryShow::OnInitDialog(){
	CDialogEx::OnInitDialog();
	DWORD dwStyle;
	dwStyle = clistCtrl.GetExtendedStyle();
	dwStyle = dwStyle | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_SUBITEMIMAGES;
	clistCtrl.SetExtendedStyle(dwStyle);

	this->m_Imagelist.Create(45, 45, ILC_COLOR, 0, 40);



	CImage img;
	img.Load("d:\\test\\Chrysanthemum.jpg");//��ȡJPGͼƬ
	img.Save("d:\\test\\Chrysanthemum.bmp");//�����BMP��ʽ
	
	this->CompressImagePixel(L"d:\\test\\Chrysanthemum.bmp", L"d:\\test\\ChrysanthemumB.bmp", 100, 100);

	pBmp = new CBitmap();
	pBmp->LoadBitmap(IDB_BITMAP3);
	//pBmp->LoadBitmap("d:\\test\\Chrysanthemum.bmp");
	
	
	//pBmp->Detach();
	////���ļ�·������ͼƬ  
	//bitmap = (HBITMAP)::LoadImage(NULL, "d:\\test\\ChrysanthemumB.bmp", IMAGE_BITMAP, 0, 0,
	//	LR_CREATEDIBSECTION | LR_LOADFROMFILE | LR_DEFAULTSIZE);
	//pBmp->DeleteObject();

	//if (pBmp->Attach(bitmap)){
		this->m_Imagelist.Add(pBmp, RGB(0, 0, 0));
		//this->AddImage("d:\\test\\Chrysanthemum.jpg");
	//}


	//delete pBmp;

	/*pBmp = new CBitmap();
	pBmp->LoadBitmap(IDB_BITMAP1);
	m_Imagelist.Add(pBmp, RGB(0, 0, 0));
	delete pBmp;*/

	//ICONģʽ������һ�㣩  
	/*HICON hIcon;

	m_Imagelist.Create(32, 32, ILC_COLOR, 2, 20);

	hIcon = AfxGetApp()->LoadIconW(IDI_ICON_GREE);
	m_Imagelist.Add(hIcon);

	hIcon = AfxGetApp()->LoadIconW(IDI_ICON_READ);
	m_Imagelist.Add(hIcon);*/



	this->clistCtrl.SetImageList(&this->m_Imagelist, LVSIL_SMALL); //����Ҫʹ�ã�LVSIL_SMALL���  

	//�ġ���CListCtrl�ؼ���Ӷ���
	this->clistCtrl.InsertColumn(0, _T("ͼ����"), LVCFMT_CENTER, 100);
	clistCtrl.InsertColumn(1, _T("����"), LVCFMT_CENTER, 100);

	//�塢�������

		int nRow;  //��¼�к�  
	LVITEM lvItem = { 0 };

	//��һ������  
	lvItem.mask = LVIF_IMAGE | LVIF_TEXT | LVIF_STATE;  //���֡�ͼƬ��״̬  
	lvItem.iItem = 0;       //�к�(��һ��)  
	lvItem.iImage = 0;  //ͼƬ������(��һ��ͼƬ)  
	lvItem.iSubItem = 0;    //���к�  

	nRow = clistCtrl.InsertItem(&lvItem);     //��һ��ΪͼƬ  
	clistCtrl.SetItemText(nRow, 1, _T("PPP"));  //�ڶ���Ϊ����  

	//�ڶ�������  
	lvItem.mask = LVIF_IMAGE | LVIF_TEXT | LVIF_STATE;  //���֡�ͼƬ��״̬  
	lvItem.iItem = 1;       //�к�(�ڶ���)  
	lvItem.iImage = 1;  //ͼƬ������(�ڶ���ͼƬ)  
	lvItem.iSubItem = 0;    //���к�  

	nRow = clistCtrl.InsertItem(&lvItem);     //��һ��ΪͼƬ  
	clistCtrl.SetItemText(nRow, 1, _T("PPP2"));  //�ڶ���Ϊ����  

	return TRUE;
}



int CountryShow::AddImage(CString imgPath)
{
	CString strEnd = imgPath.Right(3);
	strEnd.MakeLower();
	if (strEnd.Compare(_T("jpg")) == 0 || strEnd.Compare(_T("gif")) == 0
		|| strEnd.Compare(_T("bmp")) == 0 || strEnd.Compare(_T("png")) == 0
		|| strEnd.Compare(_T("tga")) == 0)
	{
		int nStrLen = imgPath.GetLength();
		char* pCharBuf = imgPath.GetBuffer(0);
		imgPath.ReleaseBuffer();
		int nLen = MultiByteToWideChar(CP_ACP, 0, pCharBuf, nStrLen, NULL, 0);
		MultiByteToWideChar(CP_ACP, 0, pCharBuf, nStrLen, m_char16ImgName, nLen);
		m_char16ImgName[nLen] = '\0'; //����ַ�����β��ע�ⲻ��len+1*/

		Gdiplus::Bitmap image(m_char16ImgName);
		Gdiplus::Bitmap* pThumbnail = (Gdiplus::Bitmap*)image.GetThumbnailImage(m_nX, m_nY);
		HBITMAP hBmp;
		pThumbnail->GetHBITMAP(Gdiplus::Color(255, 255, 255), &hBmp);

		
		bmp.Attach(hBmp);
		int nResult = this->m_Imagelist.Add(&bmp, RGB(255, 255, 255));
		bmp.Detach();
		int nIndex = imgPath.ReverseFind(_T('\\'));
		CString strFileName = imgPath.Right(imgPath.GetLength() - (nIndex + 1));

		this->clistCtrl.InsertItem(m_nNum, strFileName, nResult);
		this->clistCtrl.SetItemData(m_nNum, (DWORD_PTR)strdup(imgPath));
		this->clistCtrl.RedrawItems(m_nNum, m_nNum);

		delete pThumbnail;
		m_nNum++;

		return 1;
	}

	return 0;
}


BOOL CountryShow::LoadBitmapToList(CString strFileName){
	Gdiplus::Bitmap bmp(strFileName.AllocSysString());
	int sourceWidth = 140; 
	int sourceHeight = 140;
	Gdiplus::Bitmap*pThumbnail = (Gdiplus::Bitmap*)bmp.GetThumbnailImage(sourceWidth, sourceHeight, NULL, NULL);
	HBITMAP hBmp;
	pThumbnail->GetHBITMAP(Gdiplus::Color(255, 255, 255), &hBmp);
	CBitmap*pImage= CBitmap::FromHandle(hBmp);
	int a= this->m_Imagelist.Add(pImage, RGB(255, 255, 255));
	pImage->DeleteObject();
	return TRUE;
}


bool CountryShow::CompressImagePixel(
	const WCHAR* pszOriFilePath,
	const WCHAR* pszDestFilePah,
	UINT ulNewHeigth,
	UINT ulNewWidth)
{
	//using namespace Gdiplus;
	// Initialize GDI+.  
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	Gdiplus::Status stat = Gdiplus::GenericError;
	stat = Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	if (Gdiplus::Ok != stat) {
		return false;
	}
	// ����״̬  
	stat = Gdiplus::GenericError;

	// Get an image from the disk.  
	Gdiplus::Image* pImage = new Gdiplus::Image(pszOriFilePath);

	do {
		if (NULL == pImage) {
			break;
		}

		// ��ȡ����  
		UINT unOriHeight = pImage->GetHeight();
		UINT unOriWidth = pImage->GetWidth();

		do {
			CLSID encoderClsid;
			if (unOriWidth < 1 || unOriHeight < 1) {
				break;
			}

			// Get the CLSID of the JPEG encoder.  
			if (!GetEncoderClsid(L"image/jpeg", &encoderClsid)) {
				break;
			}

			Gdiplus::REAL fSrcX = 0.0f;
			Gdiplus::REAL fSrcY = 0.0f;
			Gdiplus::REAL fSrcWidth = (Gdiplus::REAL)unOriWidth;
			Gdiplus::REAL fSrcHeight = (Gdiplus::REAL)unOriHeight;
			Gdiplus::RectF RectDest(0.0f, 0.0f, (Gdiplus::REAL)ulNewWidth, (Gdiplus::REAL)ulNewHeigth);

			Gdiplus::Bitmap* pTempBitmap = new Gdiplus::Bitmap(ulNewWidth, ulNewHeigth);
			Gdiplus::Graphics* graphics = NULL;

			do {
				if (!pTempBitmap) {
					break;
				}

				graphics = Gdiplus::Graphics::FromImage(pTempBitmap);
				if (!graphics) {
					break;
				}

				stat = graphics->SetInterpolationMode(Gdiplus::InterpolationModeHighQuality);
				if (Gdiplus::Ok != stat) {
					break;
				}

				stat = graphics->SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);
				if (Gdiplus::Ok != stat) {
					break;
				}

				stat = graphics->DrawImage(pImage, RectDest, fSrcX, fSrcY, fSrcWidth, fSrcHeight,
					Gdiplus::UnitPixel, NULL, NULL, NULL);
				if (Gdiplus::Ok != stat) {
					break;
				}

				stat = pTempBitmap->Save(pszDestFilePah, &encoderClsid, NULL);
				if (Gdiplus::Ok != stat) {
					break;
				}

			} while (0);

			if (NULL != graphics) {
				delete graphics;
				graphics = NULL;
			}

			if (NULL != pTempBitmap) {
				delete pTempBitmap;
				pTempBitmap = NULL;
			}
		} while (0);
	} while (0);

	if (pImage) {
		delete pImage;
		pImage = NULL;
	}

	Gdiplus::GdiplusShutdown(gdiplusToken);

	return ((Gdiplus::Ok == stat) ? true : false);
}



bool CountryShow::GetEncoderClsid(const WCHAR* pszFormat, CLSID* pClsid)
{

	using namespace Gdiplus;

	UINT  unNum = 0;          // number of image encoders  
	UINT  unSize = 0;         // size of the image encoder array in bytes  

	ImageCodecInfo* pImageCodecInfo = NULL;

	// How many encoders are there?  
	// How big (in bytes) is the array of all ImageCodecInfo objects?  
	GetImageEncodersSize(&unNum, &unSize);
	if (0 == unSize) {
		return false;  // Failure  
	}

	// Create a buffer large enough to hold the array of ImageCodecInfo  
	// objects that will be returned by GetImageEncoders.  
	pImageCodecInfo = (ImageCodecInfo*)(malloc(unSize));
	if (!pImageCodecInfo) {
		return false;  // Failure  
	}

	// GetImageEncoders creates an array of ImageCodecInfo objects  
	// and copies that array into a previously allocated buffer.   
	// The third argument, imageCodecInfos, is a pointer to that buffer.   
	GetImageEncoders(unNum, unSize, pImageCodecInfo);

	for (UINT j = 0; j < unNum; ++j) {
		if (wcscmp(pImageCodecInfo[j].MimeType, pszFormat) == 0) {
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			pImageCodecInfo = NULL;
			return true;  // Success  
		}
	}

	free(pImageCodecInfo);
	pImageCodecInfo = NULL;
	return false;  // Failure  
}

void CountryShow::t(){
	CBitmap bitmap;
	CImageList m_cImageList;

	m_cImageList.Create(100, 100, ILC_COLORDDB | ILC_MASK, 20, 1);
	this->clistCtrl.SetImageList(&m_cImageList, LVS_ICON);

	CImage img; //JPG / JPEG / GIF / PNG ��ʽ��ͼƬ  


	//// ����������ԴID�е�ͼƬ�����Բſ���һƪ���� ��Դ�е�JPG��CListCtrl����ʾ����ΪLoad֧��IStream���͵ļ���  
	HRESULT ret = img.Load("D:/doc/php/xunan/UploadUser/User/2015-10/20151007232216.png"); // strBmpPathΪͼƬ��·����  
	HBITMAP hbitmap = img.Detach();

	HANDLE hBB = CopyImage((HANDLE)hbitmap, IMAGE_BITMAP, 100, 100, LR_COPYRETURNORG);
	hbitmap = (HBITMAP)hBB;

	bitmap.Attach(hbitmap);

	int n = m_cImageList.Add(&bitmap, RGB(255, 0, 255));
	CString strItem = _T("����1");
	LVITEM lvi;
	lvi.mask = LVIF_IMAGE | LVIF_TEXT;
	lvi.iItem = 0;
	lvi.iSubItem = 0;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	lvi.iImage = 0;
	this->clistCtrl.InsertItem(&lvi);
}

BEGIN_MESSAGE_MAP(CountryShow, CDialogEx)
END_MESSAGE_MAP()


// CountryShow ��Ϣ�������




/*this->clistCtrl.InsertColumn(1, "ID", LVCFMT_CENTER, 40);
this->clistCtrl.InsertColumn(2,"����", LVCFMT_CENTER, 40);
this->clistCtrl.InsertColumn(3, "���Ҵ���", LVCFMT_CENTER, 50);
std::list<country*> c_list;
this->cs->query(c_list);
std::list<country*>::iterator iter = c_list.begin();
for (int i = 0; iter != c_list.end(); iter++, i++){
country *c = *iter;
long id = c->get_id();
std::string id_str = Util::ltos(id);
std::string &name = charset_util::UTF8ToGBK(c->get_name());
std::string&info = charset_util::UTF8ToGBK(c->get_country_code());
int nRow = this->clistCtrl.InsertItem(i + 1, id_str.c_str());
this->clistCtrl.SetItemText(nRow, 1, name.c_str());
this->clistCtrl.SetItemText(nRow, 2, info.c_str());*/




//����ListCtrl
//this->clistCtrl.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_EDITLABELS,
//	CRect(0, 0, 400, 200),
//	this, 0);
////����ListCtrl�ķ��
//this->clistCtrl.SetExtendedStyle(this->clistCtrl.GetExtendedStyle() |
//	LVS_EX_SUBITEMIMAGES);
////------����λͼ��
//Bitmap[0].LoadBitmap(IDB_BITMAP1);
//Bitmap[1].LoadBitmap(IDB_BITMAP1);
//Bitmap[2].LoadBitmap(IDB_BITMAP1);
//Bitmap[3].LoadBitmap(IDB_BITMAP1);
////��.��λͼ��ӵ�ImageList����
//m_Imagelist.Create(24, 24, ILC_COLOR4 | ILC_MASK, 4, 4);   //----- ʵ��ͼ���
////this->LoadBitmapToList("C:\\Users\\Public\\Pictures\\Sample Pictures\\Lighthouse.jpg");
//for (int i = 0; i < 3; i++)
//{
//	m_Imagelist.Add(&Bitmap[i], RGB(0, 0, 0));
//}
////��.��ImageList��ListCtrl�������ؼ�֮��
//clistCtrl.SetImageList(&m_Imagelist, LVSIL_SMALL);
////3����ʼ���б��ͷ
//clistCtrl.InsertColumn(0, _T("T1"), LVCFMT_LEFT, 80);
//clistCtrl.InsertColumn(1, _T("A1"), LVCFMT_LEFT, 32);
//clistCtrl.InsertColumn(2, _T("A2"), LVCFMT_LEFT, 32);
////4��listctrl ��������--
//CString str;
//for (int j = 0; j < 4; j++)
//{
//	clistCtrl.InsertItem(j, NULL, 1);
//	LVITEM item;                      //Item�ṹ����ȫ�Ķ���
//	item.iItem = j;                   //Item����
//	item.iSubItem = 0;                //SubItem����
//	//��.�趨��ʾ�ĸ�ʽ
//	item.mask = LVIF_IMAGE | LVIF_TEXT; //��ʾ�ı���ͼƬ
//	//��.�趨��ӦͼƬ������ֵ
//	item.iImage = j;                  //ͼƬ����ֵ
//	item.pszText = _T("Virqin");      //�ڵ�ǰItemҪ��ʾ���ı�
//	clistCtrl.SetItem(&item);        //�趨Item
//}




/*CImageList m_ImageList;
CBitmap m_bitmap;
m_ImageList.Create(16, 16, ILC_COLOR32, 1, 1);
m_bitmap.LoadBitmapA(IDI_ICON1);
m_ImageList.Add(&m_bitmap, RGB(0, 255, 255));

this->clistCtrl.SetImageList(&m_ImageList, LVSIL_SMALL);
this->clistCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_SUBITEMIMAGES);
this->clistCtrl.SetItem(nRow, 1, LVIF_IMAGE, NULL, 2, 0, 0, 0);*/
//}
