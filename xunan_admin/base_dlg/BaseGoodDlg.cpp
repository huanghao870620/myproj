// BaseGoodDlg.cpp : ʵ���ļ�
//

#include "../stdafx.h"
#include"BaseGoodDlg.h"
#include "afxdialogex.h"
#pragma execution_character_set("utf-8")

// BaseGoodDlg �Ի���

IMPLEMENT_DYNAMIC(BaseGoodDlg, CDialogEx)

BaseGoodDlg::BaseGoodDlg(CWnd* pParent /*=NULL*/)
: CDialogEx(BaseGoodDlg::IDD, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif
	this->init();
}

BaseGoodDlg::BaseGoodDlg(long goodId)
	: CDialogEx(){
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

	this->goodId = goodId;
	this->init();
}

BaseGoodDlg::~BaseGoodDlg()
{
}

void BaseGoodDlg::init(){
	this->fs = file_service::get_file_service();
	this->gfs = good_file_service::get_good_file_service();
	this->cs = classification_service::get_classification_service();
	this->gs = good_service::get_good_service();
	this->us = upload_service::get_upload_service();
	this->bs = brand_service::get_brand_service();

	
}

/**/
void BaseGoodDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_GATP, this->gatp);//�s�ԈD
	DDX_Control(pDX, IDC_STATIC_ADV_PIC, this->advPic);//��Ʒ���ͼ
	DDX_Control(pDX, IDC_STATIC_BGAT, this->big1);//��D1

	DDX_Control(pDX, IDC_STATIC_CUT1, this->cutFigure1);//�ЈD1
	DDX_Control(pDX, IDC_EDIT_DEPARTMENT_NAME_EDIT_BOX, this->nameEdit);/*��Ʒ����*/
	DDX_Control(pDX, IDC_EDIT_DESCRIBE, this->infoEdit);/*��Ʒ����*/
	DDX_Control(pDX, IDC_EDIT_CAPACITY, this->capacityEdit);/*����*/
	DDX_Control(pDX, IDC_DATETIMEPICKER1, this->dateOfProductionControl);/*��������*/
	DDX_Control(pDX, IDC_LOWEST_PRICE, this->lowestPriceEdit);/*��ͼ�*/
	DDX_Control(pDX, IDC_HIGHEST_PRICE, this->highestPriceEdit);/*��߼�*/
	DDX_Control(pDX, IDC_EDIT_REAL_PRICE, this->priceEdit);/*��Ʒʵ�ʼ۸�*/
	DDX_Control(pDX, IDC_EDIT_PURCHASING_POSITION, this->purchasPositonEdit);/*�ɹ�λ��*/
	DDX_Control(pDX, IDC_COMBO_BIG_CLASS, this->firstClass);/*һ������*/
	DDX_Control(pDX, IDC_COMBO_CHILD_CLASS, this->secondClass);/*��������*/
	DDX_Control(pDX, IDC_COMBO1, this->thirdClass);/*��������*/

	DDX_Control(pDX, IDC_RADIO_RECOMMENDED, this->isRecom);/*�Ƽ�*/
	DDX_Control(pDX, IDC_RADIO_NOT_RECOMMENDED, this->isNotRecom);/*���Ƽ�*/

	DDX_Control(pDX, IDC_COMBO_BRAND, this->brandSel); /*Ʒ��*/




}


void BaseGoodDlg::SetCurSel(CComboBox *box, long id, int k){
	int count = box->GetCount();
	for (int i = 0; i < count; i++){
		DWORD_PTR data = box->GetItemData(i);
		std::cout << "" << std::endl;
		if (data == id){
			box->SetCurSel(i);
			//box->SendMessage(CBN_SELCHANGE);
			if (k == 0){
				this->SetSecondClass();
			}
			else if (k == 1){
				this->SetThirdClass();
			}
			else if (k == 2){
				this->SelThirdClass();
			}
			break;
		}
	}
}

long BaseGoodDlg::getClassId(std::list<long> *ls, int index){
	std::list<long>::iterator iter = ls->begin();
	for (int i = 0; iter != ls->end(); iter++, i++){
		if (i == index){
			return *iter;
		}
	}
}

/**/
CStringW BaseGoodDlg::ConvertUTF82CStringW(char* instr)
{
	CStringW wstr;
	int wlen = MultiByteToWideChar(CP_UTF8, NULL, instr, strlen(instr), NULL, NULL);
	wchar_t* wstrnew = new wchar_t[wlen + 1];
	memset(wstrnew, 0, sizeof(wchar_t)*(wlen + 1));
	MultiByteToWideChar(CP_UTF8, NULL, instr, -1, wstrnew, wlen);
	wstrnew[wlen + 1] = '\0';
	wstr.SetString(wstrnew);
	return wstr;
}


//UTF8ת��ΪGBK��ʽ
void BaseGoodDlg::ConvertUtf8ToGBK(CString &strUtf8)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, (LPCTSTR)strUtf8, -1, NULL, 0);
	wchar_t * wszGBK = new wchar_t[len];
	memset(wszGBK, 0, len);
	MultiByteToWideChar(CP_UTF8, 0, (LPCTSTR)strUtf8, -1, wszGBK, len);

	len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
	char *szGBK = new char[len + 1];
	memset(szGBK, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, NULL, NULL);

	strUtf8 = szGBK;
	delete[] szGBK;
	delete[] wszGBK;
}

/*�����Ʒ*/
void BaseGoodDlg::addGood(){
	//goods good;

	/*��Ʒ����*/
	CString cs0;
	this->nameEdit.GetWindowTextA(cs0);
	MyDoc * myDoc = (MyDoc*)((MyFrame*)AfxGetApp()->GetMainWnd())->GetActiveDocument();
	std::string name = cs0.GetBuffer(0);
	name = charset_util::GBKToUTF8(name);

	/*����*/
	CString info;
	infoEdit.GetWindowTextA(info);
	std::string info_str = info.GetBuffer(0);
	info_str = charset_util::GBKToUTF8(info_str);

	/*����*/
	CString capacity;
	this->capacityEdit.GetWindowTextA(capacity);
	long capl = Util::stol(capacity.GetBuffer(0));

	/*��������*/
	CString dateOfProduction;
	this->dateOfProductionControl.GetWindowTextA(dateOfProduction);
	std::string dop = dateOfProduction.GetBuffer(0);

	/*��ͼ�*/
	CString lowestPrice;
	this->lowestPriceEdit.GetWindowTextA(lowestPrice);
	float lp = Util::stof(lowestPrice.GetBuffer(0));

	/*��߼�*/
	CString highestPrice;
	this->highestPriceEdit.GetWindowTextA(highestPrice);
	float hp = Util::stof(highestPrice.GetBuffer(0));

	/*ʵ�ʼ۸�*/
	CString realPrice;
	this->priceEdit.GetWindowTextA(realPrice);
	float price = Util::stof(realPrice.GetBuffer(0));


	/*�ɹ�λ��*/
	CString purchasPositon;
	this->purchasPositonEdit.GetWindowTextA(purchasPositon);
	std::string purchPostion = purchasPositon.GetBuffer(0);
	purchPostion = charset_util::GBKToUTF8(purchPostion);

	std::string thumb_path_str = this->thumbPath.GetBuffer(0);

	/*���ͼ*/
	std::string adv_path_str = this->advPath.GetBuffer(0);

	/*�Ƽ�*/
	CString recom;
	this->GetRecom(recom);
	std::string is_recom_str = recom.GetBuffer(0);
	/*ʱ���*/
	std::string addTime = "2015/11/21";



	std::string big1_path = this->big1Path.GetBuffer(0);//��ͼ1


	std::string cut1_path = this->cutFigure1Path.GetBuffer(0);//��ͼ1


	this->gs->add_good(
		name, //��Ʒ���� 
		selClass,   //��Ʒ���� 
		info_str, // ��Ʒ����
		capl,  // ���� ���
		dop,  // ��������
		lp,  // ��ͼ�
		hp,  // ��߼�
		price,  //ʵ�ʼ۸�
		purchPostion,   //
		addTime,   // ���ʱ��
		thumb_path_str,  // ����ͼ·��
		adv_path_str, // ���ͼ·��
		this->us,   // upload_service
		is_recom_str, // �Ƿ��Ƽ�
		*this->fs,    //file_service
		big1_path,
		cut1_path
		);

	/*ͼƬ*/

	///*�s�ԈD*/
	//if (thumbFileId > 0){ 
	//	/*�޸�����ͼ*/
	//	if (thumbPath != ""){
	//		this->fs->update_and_upload_file(this->thumbFileId, thumb_path_str, 12);
	//	}
	//}
	//else{ 
	//	/*�������ͼ*/
	//	this->fs->add_good_file(thumb_path_str, good.get_id(), 12);
	//}





}

/*�s�ԈD*/
void BaseGoodDlg::uploadFileGatp(){
	this->gatp.GetClientRect(&thumbRect);
	this->thumbPath = Util::GetFilePathName();
	//ShowJpg::ShowJpgGif(this->gatp.GetDC(), thumbPath, thumbRect.left, thumbRect.top);
	ShowJpg::ShowPng(this->gatp.GetDC(), thumbPath, thumbRect);
}

/*�ϴ����ͼ*/
void BaseGoodDlg::uploadAdvPic(){
	this->advPic.GetClientRect(&this->advRect);
	this->advPath = Util::GetFilePathName();
	//ShowJpg::ShowJpgGif(this->advPic.GetDC(), this->advPath, this->advRect.left, this->advRect.top);
	ShowJpg::ShowPng(this->advPic.GetDC(), this->advPath, this->advRect);
}

/*��Ʒ��D1*/
void BaseGoodDlg::uploadFileBig1(){
	this->big1.GetClientRect(&this->big1Rect);
	this->big1Path = Util::GetFilePathName();
	ShowJpg::ShowJpgGif(this->big1.GetDC(), this->big1Path, big1Rect.left, big1Rect.top);
}

/*��Ʒ��D2*/
void BaseGoodDlg::uploadFileBig2(){
	RECT d;
	/*this->big2.GetClientRect(&d);
	CString big2Path = Util::GetFilePathName();
	ShowJpg::ShowJpgGif(this->big2.GetDC(), big2Path, d.left, d.top);*/
}

/*�ЈD1*/
void BaseGoodDlg::uploadCutFigure1(){
	RECT d;
	this->cutFigure1.GetClientRect(&d);
	this->cutFigure1Path = Util::GetFilePathName();
	ShowJpg::ShowJpgGif(this->cutFigure1.GetDC(), cutFigure1Path, d.left, d.top);
}

/*�ЈD2*/
void BaseGoodDlg::uploadCutFigure2(){
	RECT d;
	/*this->cutFigure2.GetClientRect(&d);
	this->cutFigure2Path = Util::GetFilePathName();
	ShowJpg::ShowJpgGif(this->cutFigure2.GetDC(), cutFigure2Path, d.left, d.top);*/
}

/*�ػ�*/
void BaseGoodDlg::OnPaint(){
	CDialogEx::OnPaint();
}


HRESULT BaseGoodDlg::ShowPic(CDC* pDC, CString strImgUrl, CRect rect)
{
	HDC hDC_Temp = pDC->GetSafeHdc();

	IPicture *pPic;
	IStream *pStm;

	HRESULT bResult;// = FALSE;        

	DWORD dwFileSize, dwByteRead;

	//��ȡ��ҳ��ͼƬ�ļ���ʵ���Ǹ�CHttpFileָ��    
	CInternetSession session("HttpClient");
	CFile* httpFile = (CFile*)session.OpenURL(strImgUrl);

	if (httpFile != INVALID_HANDLE_VALUE)
	{
		dwFileSize = httpFile->GetLength();//��ȡ�ļ��ֽ���        

		if (dwFileSize == 0xFFFFFFFF)
			return E_FAIL;
	}
	else
	{
		return E_FAIL;
	}


	//����ȫ�ִ洢�ռ�        
	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, dwFileSize);
	LPVOID pvData = NULL;

	if (hGlobal == NULL)
		return E_FAIL;

	if ((pvData = GlobalLock(hGlobal)) == NULL)//���������ڴ��        
		return E_FAIL;

	//���ļ������ڴ滺����        
	dwByteRead = httpFile->Read(pvData, dwFileSize);

	GlobalUnlock(hGlobal);

	CreateStreamOnHGlobal(hGlobal, TRUE, &pStm);

	//װ��ͼ���ļ�        
	bResult = OleLoadPicture(pStm, dwFileSize, TRUE, IID_IPicture, (LPVOID*)&pPic);

	if (FAILED(bResult))
		return E_FAIL;

	OLE_XSIZE_HIMETRIC hmWidth; //ͼƬ����ʵ���, ��λΪӢ��       
	OLE_YSIZE_HIMETRIC hmHeight; //ͼƬ����ʵ�߶�, ��λΪӢ��       
	pPic->get_Width(&hmWidth);
	pPic->get_Height(&hmHeight);

	//ת��hmWidth��hmHeightΪpixels���룬1Ӣ��=25.4����       
	int nWidth = MulDiv(hmWidth, GetDeviceCaps(hDC_Temp, LOGPIXELSX), 2540);
	int nHeight = MulDiv(hmHeight, GetDeviceCaps(hDC_Temp, LOGPIXELSY), 2540);

	//����ͼƬ
	int nWZoom = nWidth / rect.Width();
	int nHZoom = nHeight / rect.Height();
	int nZoom = 1;
	nZoom = (nWZoom > nHZoom) ? nWZoom : nHZoom;
	nWidth /= nZoom;
	nHeight /= nZoom;
	int midW = (rect.left + rect.right) / 2;
	int midH = (rect.top + rect.bottom) / 2;
	rect.left = midW - nWidth / 2;
	rect.right = midW + nWidth / 2;
	rect.top = midH - nHeight / 2;
	rect.bottom = midH + nHeight / 2;

	//��ͼ���������Ļ�ϣ��е���BitBlt��        
	bResult = pPic->Render(hDC_Temp, rect.left, rect.top, rect.Width(), rect.Height(),
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


BOOL BaseGoodDlg::OnEraseBkgnd(CDC*pDC){
	return CDialogEx::OnEraseBkgnd(pDC);
}

/*��ʼ������*/
BOOL BaseGoodDlg::OnInitDialog(){
	CDialogEx::OnInitDialog();
	std::list<classification*> *ls = new std::list<classification*>;
	this->cs->query_classification(ls);

	std::list<classification*>::iterator iter = ls->begin();
	for (int i = 0; iter != ls->end(); iter++, i++){
		classification *classi = *iter;
		classi->set_name(charset_util::UTF8ToGBK(classi->get_name()));
		this->firstClass.AddString(classi->get_name().c_str());
		long id = classi->get_id();
		this->firstClass.SetItemData(i, id);
	}


	std::list<brand> &brand_list = this->bs->get_brands();
	std::list<brand>::iterator brand_iter = brand_list.begin();
	for (int i = 0; brand_iter != brand_list.end(); brand_iter++, i++){
		brand b = *brand_iter;
	}
	this->isNotRecom.SetCheck(TRUE);
	Gdiplus::GdiplusStartupInput gi;
	ULONG_PTR gdiToken;
	GdiplusStartup(&gdiToken, &gi, NULL);
	return TRUE;
}

/*���һ������*/
void BaseGoodDlg::SetSecondClass(){
	int index = this->firstClass.GetCurSel();
	this->firstClass.SetCurSel(index);

	index = this->firstClass.GetCurSel();
	DWORD_PTR id = this->firstClass.GetItemData(index);
	this->selClass = id;
	CString content;
	this->firstClass.GetWindowTextA(content);

	CComboBox *secondClass = (CComboBox*)this->GetDlgItem(IDC_COMBO_CHILD_CLASS);/*��������ؼ�*/
	MyDoc * myDoc = (MyDoc*)((MyFrame*)AfxGetApp()->GetMainWnd())->GetActiveDocument();
	std::list<classification*> *ls = new std::list<classification*>;
	this->cs->query_class_bypid(ls, id);

	std::list<classification*>::iterator iter = ls->begin();
	secondClass->ResetContent();
	for (int i = 0; iter != ls->end(); iter++, i++){
		classification*classi = *iter;
		classi->set_name(charset_util::UTF8ToGBK(classi->get_name()));
		secondClass->AddString(classi->get_name().c_str());
		long id_second = classi->get_id();
		secondClass->SetItemData(i, id_second);
	}
}

/*�����������*/
void BaseGoodDlg::SetThirdClass(){
	int index = this->secondClass.GetCurSel();
	this->secondClass.SetCurSel(index);
	index = this->secondClass.GetCurSel();
	DWORD_PTR id = this->secondClass.GetItemData(index);
	this->selClass = id;
	CString content;
	this->secondClass.GetWindowTextA(content);
	CComboBox *thirdClass = (CComboBox*)this->GetDlgItem(IDC_COMBO1);/*��������ؼ�*/
	MyDoc * myDoc = (MyDoc*)((MyFrame*)AfxGetApp()->GetMainWnd())->GetActiveDocument();
	std::list<classification*> *ls = new std::list<classification*>;
	this->cs->query_class_bypid(ls, id);

	std::list<classification*>::iterator iter = ls->begin();
	thirdClass->ResetContent();
	for (int i = 0; iter != ls->end(); iter++, i++){
		classification*classi = *iter;
		classi->set_name(charset_util::UTF8ToGBK(classi->get_name()));
		thirdClass->AddString(classi->get_name().c_str());
		thirdClass->SetItemData(i, classi->get_id());
	}
}

/*�����������*/
void BaseGoodDlg::SelThirdClass(){
	CComboBox*box = (CComboBox*) this->GetDlgItem(IDC_COMBO1);
	int index = box->GetCurSel();
	box->SetCurSel(index);
	index = box->GetCurSel();
	DWORD_PTR id = box->GetItemData(index);
	this->selClass = id;
}

void BaseGoodDlg::f1(){
	//std::cout << "" << std::endl;
	//CComboBox *box = (CComboBox*) this->GetDlgItem(IDC_COMBO_BIG_CLASS);
	////box->GetCurSel();
	//DWORD_PTR id = box->GetItemData(box->GetCurSel());
	//CString content;
	//box->GetWindowTextA(content);
	//std::cout << "" << std::endl;
}

void BaseGoodDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar){
	SCROLLINFO scrollinfo;
	GetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
	switch (nSBCode)
	{
	case SB_BOTTOM:
		ScrollWindow(0, (scrollinfo.nPos - scrollinfo.nMax) * 10);
		scrollinfo.nPos = scrollinfo.nMax;
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);

		break;
	case SB_TOP:
		ScrollWindow(0, (scrollinfo.nPos - scrollinfo.nMin) * 10);
		scrollinfo.nPos = scrollinfo.nMin;
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
		break;
	case SB_LINEUP:
		scrollinfo.nPos -= 1;
		if (scrollinfo.nPos<scrollinfo.nMin)
		{
			scrollinfo.nPos = scrollinfo.nMin;
			break;
		}
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
		ScrollWindow(0, 15);
		break;
	case SB_LINEDOWN:
		scrollinfo.nPos += 1;
		if (scrollinfo.nPos>scrollinfo.nMax)
		{
			scrollinfo.nPos = scrollinfo.nMax;
			break;
		}
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
		ScrollWindow(0, -15);
		break;
	case SB_PAGEUP:
		scrollinfo.nPos -= 5;
		if (scrollinfo.nPos<scrollinfo.nMin)
		{
			scrollinfo.nPos = scrollinfo.nMin;
			break;
		}
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
		ScrollWindow(0, 10 * 5);
		break;
	case SB_PAGEDOWN:
		scrollinfo.nPos += 5;
		if (scrollinfo.nPos>scrollinfo.nMax)
		{
			scrollinfo.nPos = scrollinfo.nMax;
			break;
		}
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
		ScrollWindow(0, -10 * 5);
		break;
	case SB_ENDSCROLL:
		break;
	case SB_THUMBPOSITION:
		// ScrollWindow(0,(scrollinfo.nPos-nPos)*10);
		// scrollinfo.nPos = nPos;
		// SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);
		break;
	case SB_THUMBTRACK:
		ScrollWindow(0, (scrollinfo.nPos - nPos) * 15);
		scrollinfo.nPos = nPos;
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
		break;
	}

	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}


void BaseGoodDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	SCROLLINFO si = { sizeof(si) };
	si.fMask = SIF_ALL;
	GetScrollInfo(SB_HORZ, &si);

	int nPrevPos = si.nPos;
	switch (nSBCode)
	{
	case SB_LEFT:
		si.nPos = si.nMin;
		break;
	case SB_RIGHT:
		si.nPos = si.nMax;
		break;
	case SB_LINELEFT:
		si.nPos -= 15;
		break;
	case SB_LINERIGHT:
		si.nPos += 15;
		break;
	case SB_PAGELEFT:
		si.nPos -= si.nPage;
		break;
	case SB_PAGERIGHT:
		si.nPos += si.nPage;
		break;
	case SB_THUMBTRACK:
		si.nPos = si.nTrackPos;
		break;
	default:
		break;
	}
	si.fMask = SIF_POS;
	SetScrollInfo(SB_HORZ, &si, TRUE);
	if (si.nPos != nPrevPos)
	{
		m_nXPos += si.nPos - nPrevPos;
		ScrollWindow(nPrevPos - si.nPos, 0, NULL, NULL);
		Invalidate(FALSE);
		UpdateWindow();
	}

	CDialog::OnHScroll(nSBCode, nPrevPos, pScrollBar);
}

/*�Ƽ�*/
void BaseGoodDlg::selRecommended(){
	this->isRecom.SetCheck(TRUE);
	this->isNotRecom.SetCheck(FALSE);
}

/*���Ƽ�*/
void BaseGoodDlg::selNotRecommended(){
	this->isNotRecom.SetCheck(TRUE);
	this->isRecom.SetCheck(FALSE);
}

/*��ȡ�Ƽ�״̬*/
void BaseGoodDlg::GetRecom(CString&recom){
	CButton **recoms = new CButton*[2]{
		&this->isRecom,
			&this->isNotRecom
	};
	for (int i = 0; i < 2; i++){
		if (recoms[i]->GetCheck()){
			recoms[i]->GetWindowTextA(recom);
			break;
		}
	}
}

BEGIN_MESSAGE_MAP(BaseGoodDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, addGood)
	ON_BN_CLICKED(IDC_BUTTON_UPLOAD_GOODS_IMG, uploadFileGatp)/*����ͼ*/
	ON_BN_CLICKED(IDC_BUTTON1, uploadFileBig1)/*��ͼ1*/
	ON_BN_CLICKED(IDC_BUTTON2, uploadFileBig2)/*��ͼ2*/
	ON_BN_CLICKED(IDC_BUTTON9, uploadCutFigure1) /*�ЈD1*/
	ON_BN_CLICKED(IDC_BUTTON10, uploadCutFigure2) /*�ЈD2*/
	ON_BN_CLICKED(IDC_BUTTON_ADV_PIC, uploadAdvPic)/*���ͼ*/
	ON_BN_CLICKED(IDC_RADIO_RECOMMENDED, selRecommended) /*�Ƽ�*/
	ON_BN_CLICKED(IDC_RADIO_NOT_RECOMMENDED, selNotRecommended) /*���Ƽ�*/
	ON_CBN_SELCHANGE(IDC_COMBO_BIG_CLASS, SetSecondClass)
	ON_CBN_SELCHANGE(IDC_COMBO_CHILD_CLASS, SetThirdClass)
	ON_CBN_SELCHANGE(IDC_COMBO1, SelThirdClass)/**/
	ON_CBN_SETFOCUS(IDC_COMBO_BIG_CLASS, f1)
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// BaseGoodDlg ��Ϣ�������
/*CString gatpFileNamePath = Util::GetFilePathName();
Gdiplus::Image *gatpImage = nullptr;
LPWSTR path = gatpFileNamePath.AllocSysString();
gatpImage = Gdiplus::Image::FromFile(path);
CDC *pDC = this->GetDC();
Gdiplus::Graphics graphics(pDC->m_hDC);
RECT d;
this->gatp.GetWindowRect(&d);
this->ScreenToClient(&d);
Gdiplus::Rect rect(d.left, d.top, d.right - d.left, d.bottom - d.top);
graphics.DrawImage(gatpImage, rect);*/