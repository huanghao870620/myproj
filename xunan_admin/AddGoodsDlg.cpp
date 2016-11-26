// AddGoodsDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "AddGoodsDlg.h"
#include "afxdialogex.h"
#pragma execution_character_set("utf-8")

// AddGoodsDlg 对话框

IMPLEMENT_DYNAMIC(AddGoodsDlg, CDialogEx)

AddGoodsDlg::AddGoodsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(AddGoodsDlg::IDD, pParent)
{
	std::cout << "但对方是否" << std::endl;
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

AddGoodsDlg::AddGoodsDlg(long goodId)
: CDialogEx(){
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

	std::cout << "1" << std::endl;
	this->goodId = goodId;

}

AddGoodsDlg::~AddGoodsDlg()
{
	std::cout << "fdsfsd" << std::endl;
}

/**/
void AddGoodsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_GATP, this->gatp);//縮略圖
	DDX_Control(pDX, IDC_STATIC_BGAT, this->bgat);//商品大圖1
	DDX_Control(pDX, IDC_STATIC_PP, this->pp); //商品大圖2
	DDX_Control(pDX, IDC_STATIC1, this->cutFigure1); // 切圖1
	DDX_Control(pDX, IDC_STATIC2, this->cutFigure2);//切圖2
	DDX_Control(pDX, IDC_EDIT_DEPARTMENT_NAME_EDIT_BOX, this->nameEdit);/*商品名称*/
	DDX_Control(pDX, IDC_EDIT_DESCRIBE, this->infoEdit);/*商品描述*/
	DDX_Control(pDX, IDC_EDIT_CAPACITY, this->capacityEdit);/*容量*/
	DDX_Control(pDX, IDC_DATETIMEPICKER1, this->dateOfProductionControl);/*生产日期*/
	DDX_Control(pDX, IDC_LOWEST_PRICE, this->lowestPriceEdit);/*最低价*/
	DDX_Control(pDX, IDC_HIGHEST_PRICE, this->highestPriceEdit);/*最高价*/
	DDX_Control(pDX, IDC_EDIT_PURCHASING_POSITION, this->purchasPositonEdit);/*采购位置*/
	DDX_Control(pDX, IDC_COMBO_BIG_CLASS, this->firstClass);/*一级分类*/
	DDX_Control(pDX, IDC_COMBO_CHILD_CLASS, this->secondClass);/*二级分类*/
	DDX_Control(pDX, IDC_COMBO1, this->thirdClass);/*三级分类*/
	MyDoc * myDoc = (MyDoc*)((MyFrame*)AfxGetApp()->GetMainWnd())->GetActiveDocument();
	std::list<classification*> *ls = new std::list<classification*>;
	myDoc->query_classification(ls);

	std::list<classification*>::iterator iter = ls->begin();
	for (int i = 0; iter != ls->end(); iter++, i++){
		classification *classi = (classification*)*iter;
		classi->set_name(charset_util::UTF8ToGBK(classi->get_name()));
		this->firstClass.AddString(classi->get_name().c_str());
		long id = classi->get_id();
		this->firstClass.SetItemData(i, id);
	}
	long d0 = this->firstClass.GetItemData(0);
	long d1 = this->firstClass.GetItemData(1);
	long d2 = this->firstClass.GetItemData(2);

	if (this->goodId > 0){
		good_dao*gd = good_dao::get_good_dao();
		goods g;
		gd->findById(&g, this->goodId);

		 good_file_dao*gfd = good_file_dao::get_good_file_dao();
		 std::list<file*> fileList;
		 gfd->findFileByGoodId(this->goodId, 12, &fileList);/*商品缩略图*/
		 file *thumbFile = fileList.front();/*缩略图*/
		 std::cout << "" << std::endl;
		 std::string url_str = "http://192.168.1.102" + thumbFile->get_uri_path();
		 url_str = "http://pic7.nipic.com/20100611/2113444_004433009618_2.jpg";
		 this->ShowPic(url_str.c_str(), this->gatp.GetDC());
		 //ShowJpg::ShowJpgGif(this->gatp.GetDC(), url_str.c_str(), 0, 0);
		
		this->nameEdit.SetWindowTextA(charset_util::UTF8ToGBK(g.get_name()).c_str());/*名称*/
		this->infoEdit.SetWindowTextA(charset_util::UTF8ToGBK(g.get_info()).c_str());/*描述*/
		this->capacityEdit.SetWindowTextA(Util::ltos(g.get_capacity()).c_str());/*容量*/
		this->dateOfProductionControl.SetWindowTextA(g.get_dateOfProduction().c_str());/*生产日期*/
		this->lowestPriceEdit.SetWindowTextA(Util::ltos(g.get_lowest_price()).c_str());/*最低价*/
		this->highestPriceEdit.SetWindowTextA(Util::ltos(g.get_highest_price()).c_str());/*最高价*/
		this->purchasPositonEdit.SetWindowTextA(charset_util::UTF8ToGBK(g.get_purchasing_position()).c_str());/*采购位置*/

		long classid = g.get_classid();
		classification clas;
		classification_dao*cd = classification_dao::get_classification_dao();
		std::list<long> ids;
		do
		{
			cd->getParentClass(&clas,classid);
			classid = clas.get_pid();
			ids.push_back(clas.get_id());
		} while (clas.get_pid() != -1);

		
		CComboBox **boxArr = new CComboBox*[3]{
			  &this->firstClass,
				&this->secondClass,
				&this->thirdClass
		};

		CComboBox *b0 = boxArr[0];
		CComboBox*b1 = boxArr[1];
		CComboBox*b2 = boxArr[2];

		int len = ids.size();
		for (int i = 0; i < len; i++){
			long id= this->getClassId(&ids, len-i-1);
			CComboBox *box = boxArr[i];
			this->SetCurSel(box, id,i);
		}

		delete[]boxArr;
	}
}


HRESULT AddGoodsDlg::ShowPic(const char *lpstrImgUrl, CDC*pDC)
{
	//HDC hDC_Temp = GetDC(hWnd);

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

		if (dwFileSize == 0xFFFFFFFF)
			return E_FAIL;
	}
	else
	{
		return E_FAIL;
	}


	//分配全局存储空间        
	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, dwFileSize);
	LPVOID pvData = NULL;

	if (hGlobal == NULL)
		return E_FAIL;

	if ((pvData = GlobalLock(hGlobal)) == NULL)//锁定分配内存块        
		return E_FAIL;

	//把文件读入内存缓冲区        
	dwByteRead = httpFile->Read(pvData, dwFileSize);

	GlobalUnlock(hGlobal);

	CreateStreamOnHGlobal(hGlobal, TRUE, &pStm);

	//装入图形文件        
	bResult = OleLoadPicture(pStm, dwFileSize, TRUE, IID_IPicture, (LPVOID*)&pPic);

	if (FAILED(bResult))
		return E_FAIL;

	OLE_XSIZE_HIMETRIC hmWidth; //图片的真实宽度, 单位为英寸       
	OLE_YSIZE_HIMETRIC hmHeight; //图片的真实高度, 单位为英寸       
	pPic->get_Width(&hmWidth);
	pPic->get_Height(&hmHeight);

	//转换hmWidth和hmHeight为pixels距离，1英寸=25.4毫米       
	int nWidth = MulDiv(hmWidth, GetDeviceCaps(pDC->m_hDC, LOGPIXELSX), 2540);
	int nHeight = MulDiv(hmHeight, GetDeviceCaps(pDC->m_hDC, LOGPIXELSY), 2540);

	//将图形输出到屏幕上（有点像BitBlt）        
	bResult = pPic->Render(pDC->m_hDC, 10, 40, nWidth, nHeight,
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


void AddGoodsDlg::SetCurSel(CComboBox *box, long id, int k){
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

long AddGoodsDlg::getClassId(std::list<long> *ls, int index){
	std::list<long>::iterator iter = ls->begin();
	for (int i=0; iter != ls->end(); iter++,i++){
		if (i == index){
			return *iter;
		}
	}
}

/**/
CStringW AddGoodsDlg::ConvertUTF82CStringW(char* instr)
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


//UTF8转化为GBK格式
void ConvertUtf8ToGBK(CString &strUtf8)
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

/*添加商品*/
void AddGoodsDlg::addGood(){

	/*商品名称*/
	//CWnd *c2 = this->GetDlgItem(IDC_EDIT_DEPARTMENT_NAME_EDIT_BOX);
	CString cs0;
	this->nameEdit.GetWindowTextA(cs0);
	
	MyDoc * myDoc = (MyDoc*) ((MyFrame*)AfxGetApp()->GetMainWnd())->GetActiveDocument();
	std::string name = cs0.GetBuffer(0);
	name = charset_util::GBKToUTF8(name);
	goods good;
	good.set_name(name);
	good.set_classid(this->selClass);
	/*描述*/
	CString info;
	//CWnd *infoEdit = this->GetDlgItem(IDC_EDIT_DESCRIBE);
	infoEdit.GetWindowTextA(info);
	std::string info_str = info.GetBuffer(0);
	info_str = charset_util::GBKToUTF8(info_str);
	good.set_info(info_str);
	
	/*容量*/
	CString capacity;
	this->capacityEdit.GetWindowTextA(capacity);
	long capl = Util::stol(capacity.GetBuffer(0));
	good.set_capacity(capl);

	/*生产日期*/
	CString dateOfProduction;
	this->dateOfProductionControl.GetWindowTextA(dateOfProduction);
	std::string dop = dateOfProduction.GetBuffer(0);
	good.set_date_of_production(dop);

	/*最低价*/
	CString lowestPrice;
	this->lowestPriceEdit.GetWindowTextA(lowestPrice);
	long lp = Util::stol(lowestPrice.GetBuffer(0));
	good.set_lowest_price(lp);


	/*最高价*/
	CString highestPrice;
	this->highestPriceEdit.GetWindowTextA(highestPrice);
	long hp = Util::stol(highestPrice.GetBuffer(0));
	good.set_highestPrice(hp);

	/*采购位置*/
	CString purchasPositon;
	this->purchasPositonEdit.GetWindowTextA(purchasPositon);
	std::string purchPostion = purchasPositon.GetBuffer(0);
	purchPostion = charset_util::GBKToUTF8(purchPostion);
	good.set_purchasing_position(purchPostion);


	/*时间戳*/
	std::string addTime = "2015/11/21";
	good.set_addTime(addTime);


	good.set_backGoodsAccordingTo(2);
	good.set_expressSingle(2);
	good.set_goodsAccordingToPositive(2);
	good.set_goodsInvoice(2);
	good.set_productProfile(2);

	myDoc->addGood(good);

	file_dao*fd = file_dao::get_file_dao();
	good_file_dao*gfd = good_file_dao::get_good_file_dao();

	/*图片*/

	/*縮略圖*/
	file*f0 = new file;
	f0->set_name("");
	std::string path = "";
	f0->set_path(path);
	f0->set_type_id(12);
	std::string uri_path = "";
	f0->set_uri_path(uri_path);
	fd->add_file(*f0);

	UploadFile *uf = new UploadFile;
	std::string base;
	std::string id_str = Util::ltos(f0->get_id());
	long fileTypeId = 11;
	std::string fileTypeIdStr = Util::ltos(fileTypeId);
	uf->upload(this->thumbPath, base, fileTypeIdStr.c_str(), id_str.c_str());
	f0->set_uri_path(base);
	fd->update_file(*f0);

	good_file *gf = new good_file;
	gf->set_file_id(f0->get_id());
	gf->set_good_id(good.get_id());
	gfd->add_good_file(*gf);

	/*商品大图1*/
	/*file*big1File = new file;
	big1File->set_name("");
	big1File->set_path("");
	big1File->set_type_id(2);*/
	//big1File->set_uri_path(base);
}

/*縮略圖*/
void AddGoodsDlg::uploadFileGatp(){
	//CString FilePathName;
	//CFileDialog filedlg(true);
	//filedlg.m_ofn.lpstrTitle = "打开";
	//filedlg.m_ofn.lpstrFilter = "Text Files(*.txt)/0*.txt/0All Files(*.*)/0*.*/0/0";
	//if (IDOK == filedlg.DoModal()){
		//FilePathName = filedlg.GetPathName();
		//UpdateData(FALSE);
	//}
	//SetDlgItemText(IDC_EDIT1, FilePathName);

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
	
	
	this->gatp.GetClientRect(&thumbRect);
	this->thumbPath = Util::GetFilePathName();
	ShowJpg::ShowJpgGif(this->gatp.GetDC(), thumbPath, thumbRect.left, thumbRect.top);
}

/*商品大圖1*/
void AddGoodsDlg::uploadFileBig1(){
	this->bgat.GetClientRect(&this->big1Rect);
	this->Big1path = Util::GetFilePathName();
	ShowJpg::ShowJpgGif(this->bgat.GetDC(), Big1path, big1Rect.left, big1Rect.top);
}

/*商品大圖2*/
void AddGoodsDlg::uploadFileBig2(){
	RECT d;
	this->pp.GetClientRect(&d);
	CString big2Path = Util::GetFilePathName();
	ShowJpg::ShowJpgGif(this->pp.GetDC(), big2Path, d.left, d.top);
}

/*切圖1*/
void AddGoodsDlg::uploadCutFigure1(){
	RECT d;
	this->cutFigure1.GetClientRect(&d);
	this->cutFigure1Path = Util::GetFilePathName();
	ShowJpg::ShowJpgGif(this->cutFigure1.GetDC(), cutFigure1Path, d.left, d.top);
}

/*切圖2*/
void AddGoodsDlg::uploadCutFigure2(){
	RECT d;
	this->cutFigure2.GetClientRect(&d);
	this->cutFigure2Path = Util::GetFilePathName();
	ShowJpg::ShowJpgGif(this->cutFigure2.GetDC(), cutFigure2Path, d.left, d.top);
}

void AddGoodsDlg::OnPaint(){
	ShowJpg::ShowJpgGif(this->gatp.GetDC(), thumbPath, thumbRect.left, thumbRect.top);
	//ShowJpg::ShowJpgGif(this->bgat.GetDC(), this->Big1path, this->big1Rect.left, this->big1Rect.top);

	/*std::string url_str = "http://pic7.nipic.com/20100611/2113444_004433009618_2.jpg";
	this->ShowPic(url_str.c_str(), this->gatp.GetDC());*/

	CDialogEx::OnPaint();
	
}

BOOL AddGoodsDlg::OnEraseBkgnd(CDC*pDC){
	return CDialogEx::OnEraseBkgnd(pDC);
}

/*初始化数据*/
BOOL AddGoodsDlg::OnInitDialog(){
	CDialogEx::OnInitDialog();
	Gdiplus::GdiplusStartupInput gi;
	ULONG_PTR gdiToken;
	GdiplusStartup(&gdiToken, &gi, NULL);
	return TRUE;
}

/*点击一级分类*/
void AddGoodsDlg::SetSecondClass(){
	int index = this->firstClass.GetCurSel();
	this->firstClass.SetCurSel(index);
	
	index = this->firstClass.GetCurSel();
	DWORD_PTR id = this->firstClass.GetItemData(index);
	CString content;
	this->firstClass.GetWindowTextA(content);

	CComboBox *secondClass = (CComboBox*)this->GetDlgItem(IDC_COMBO_CHILD_CLASS);/*二级分类控件*/
	MyDoc * myDoc = (MyDoc*)((MyFrame*)AfxGetApp()->GetMainWnd())->GetActiveDocument();
	std::list<classification*> *ls = new std::list<classification*>;
	myDoc->query_class_bypid(ls,id);

	std::list<classification*>::iterator iter = ls->begin();
	secondClass->ResetContent();
	for (int i=0; iter != ls->end(); iter++,i++){
		classification*classi = *iter;
		classi->set_name(charset_util::UTF8ToGBK(classi->get_name()));
		secondClass->AddString(classi->get_name().c_str());
		long id_second = classi->get_id();
		secondClass->SetItemData(i, id_second);
	}
}

/*点击二级分类*/
void AddGoodsDlg::SetThirdClass(){
	int index = this->secondClass.GetCurSel();
	this->secondClass.SetCurSel(index);
	index = this->secondClass.GetCurSel();
	DWORD_PTR id = this->secondClass.GetItemData(index);
	this->selClass = id;
	CString content;
	this->secondClass.GetWindowTextA(content);
	CComboBox *thirdClass = (CComboBox*)this->GetDlgItem(IDC_COMBO1);/*三级分类控件*/
	MyDoc * myDoc = (MyDoc*)((MyFrame*)AfxGetApp()->GetMainWnd())->GetActiveDocument();
	std::list<classification*> *ls = new std::list<classification*>;
	myDoc->query_class_bypid(ls, id);

	std::list<classification*>::iterator iter = ls->begin();
	thirdClass->ResetContent();
	for (int i=0; iter != ls->end(); iter++,i++){
		classification*classi = *iter;
		classi->set_name(charset_util::UTF8ToGBK(classi->get_name()));
		thirdClass->AddString(classi->get_name().c_str());
		thirdClass->SetItemData(i,classi->get_id());
	}
}

/*点击三级分类*/
void AddGoodsDlg::SelThirdClass(){
	CComboBox*box=(CComboBox*) this->GetDlgItem(IDC_COMBO1);
	int index= box->GetCurSel();
	box->SetCurSel(index);
	index = box->GetCurSel();
	DWORD_PTR id = box->GetItemData(index);
	this->selClass = id;
}

void AddGoodsDlg::f1(){
	//std::cout << "" << std::endl;
	//CComboBox *box = (CComboBox*) this->GetDlgItem(IDC_COMBO_BIG_CLASS);
	////box->GetCurSel();
	//DWORD_PTR id = box->GetItemData(box->GetCurSel());
	//CString content;
	//box->GetWindowTextA(content);
	//std::cout << "" << std::endl;
}

void AddGoodsDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar){
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
		// MessageBox("SB_ENDSCROLL");
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


void AddGoodsDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
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


BEGIN_MESSAGE_MAP(AddGoodsDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, addGood)
	ON_BN_CLICKED(IDC_BUTTON_UPLOAD_GOODS_IMG, uploadFileGatp)
	ON_BN_CLICKED(IDC_BUTTON1,uploadFileBig1)
	ON_BN_CLICKED(IDC_BUTTON2,uploadFileBig2)
	ON_BN_CLICKED(IDC_BUTTON9, uploadCutFigure1) /*切圖1*/
	ON_BN_CLICKED(IDC_BUTTON10, uploadCutFigure2) /*切圖2*/
	ON_CBN_SELCHANGE(IDC_COMBO_BIG_CLASS, SetSecondClass)
	ON_CBN_SELCHANGE(IDC_COMBO_CHILD_CLASS, SetThirdClass)
	ON_CBN_SELCHANGE(IDC_COMBO1, SelThirdClass)/**/
	ON_CBN_SETFOCUS(IDC_COMBO_BIG_CLASS,f1)
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// AddGoodsDlg 消息处理程序
