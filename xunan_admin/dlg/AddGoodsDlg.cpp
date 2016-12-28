// AddGoodsDlg.cpp : 实现文件
//

#include "../stdafx.h"
#include "AddGoodsDlg.h"
#include "afxdialogex.h"
#pragma execution_character_set("utf-8")

// AddGoodsDlg 对话框

IMPLEMENT_DYNAMIC(AddGoodsDlg, BaseGoodDlg)

AddGoodsDlg::AddGoodsDlg(CWnd* pParent /*=NULL*/)
	: BaseGoodDlg(pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif
	this->init();
}

AddGoodsDlg::AddGoodsDlg(long goodId)
: BaseGoodDlg(){
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

	this->goodId = goodId;
	this->init();
}

AddGoodsDlg::~AddGoodsDlg()
{
}
//
//void AddGoodsDlg::init(){
//	this->fs = file_service::get_file_service();
//	this->gfs = good_file_service::get_good_file_service();
//	this->cs = classification_service::get_classification_service();
//	this->gs = good_service::get_good_service();
//	this->us = upload_service::get_upload_service();
//	this->bs = brand_service::get_brand_service();
//}

/**/
void AddGoodsDlg::DoDataExchange(CDataExchange* pDX)
{
	BaseGoodDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_GATP, this->gatp);//縮略圖
	DDX_Control(pDX, IDC_STATIC_ADV_PIC, this->advPic);//商品广告图
	DDX_Control(pDX, IDC_STATIC_BGAT, this->big1);//大圖1
	
	DDX_Control(pDX, IDC_STATIC_CUT1, this->cutFigure1);//切圖1
	DDX_Control(pDX, IDC_EDIT_DEPARTMENT_NAME_EDIT_BOX, this->nameEdit);/*商品名称*/
	DDX_Control(pDX, IDC_EDIT_DESCRIBE, this->infoEdit);/*商品描述*/
	DDX_Control(pDX, IDC_EDIT_CAPACITY, this->capacityEdit);/*容量*/
	DDX_Control(pDX, IDC_DATETIMEPICKER1, this->dateOfProductionControl);/*生产日期*/
	DDX_Control(pDX, IDC_LOWEST_PRICE, this->lowestPriceEdit);/*最低价*/
	DDX_Control(pDX, IDC_HIGHEST_PRICE, this->highestPriceEdit);/*最高价*/
	DDX_Control(pDX, IDC_EDIT_REAL_PRICE, this->priceEdit);/*商品实际价格*/
	DDX_Control(pDX, IDC_EDIT_PURCHASING_POSITION, this->purchasPositonEdit);/*采购位置*/
	DDX_Control(pDX, IDC_COMBO_BIG_CLASS, this->firstClass);/*一级分类*/
	DDX_Control(pDX, IDC_COMBO_CHILD_CLASS, this->secondClass);/*二级分类*/
	DDX_Control(pDX, IDC_COMBO1, this->thirdClass);/*三级分类*/

	DDX_Control(pDX, IDC_RADIO_RECOMMENDED, this->isRecom);/*推荐*/
	DDX_Control(pDX, IDC_RADIO_NOT_RECOMMENDED, this->isNotRecom);/*不推荐*/

	DDX_Control(pDX, IDC_COMBO_BRAND, this->brandSel); /*品牌*/
	
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

	std::list<brand*> brand_list;
	this->bs->get_brands(brand_list);
	std::list<brand*>::iterator brand_iter = brand_list.begin();
	for (int i = 0; brand_iter != brand_list.end(); brand_iter++, i++){
		brand*b = *brand_iter;
	}


}



/*添加商品*/
void AddGoodsDlg::addGood(){
	//goods good;

	/*商品名称*/
	CString cs0;
	this->nameEdit.GetWindowTextA(cs0);
	MyDoc * myDoc = (MyDoc*)((MyFrame*)AfxGetApp()->GetMainWnd())->GetActiveDocument();
	std::string name = cs0.GetBuffer(0);
	name = charset_util::GBKToUTF8(name);
	if (name.compare("") == 0){
		this->MessageBox("未填写商品名称");
		return;
	}

	/*描述*/
	CString info;
	infoEdit.GetWindowTextA(info);
	std::string info_str = info.GetBuffer(0);
	info_str = charset_util::GBKToUTF8(info_str);
	if (info_str.compare("") == 0){
		this->MessageBox("未填写商品描述");
		return;
	}

	/*容量*/
	CString capacity;
	this->capacityEdit.GetWindowTextA(capacity);
	long capl = Util::stol(capacity.GetBuffer(0));

	/*生产日期*/
	CString dateOfProduction;
	this->dateOfProductionControl.GetWindowTextA(dateOfProduction);
	std::string dop = dateOfProduction.GetBuffer(0);

	/*最低价*/
	CString lowestPrice;
	this->lowestPriceEdit.GetWindowTextA(lowestPrice);
	float lp = Util::stof(lowestPrice.GetBuffer(0));

	/*最高价*/
	CString highestPrice;
	this->highestPriceEdit.GetWindowTextA(highestPrice);
	float hp = Util::stof(highestPrice.GetBuffer(0));

	/*实际价格*/
	CString realPrice;
	this->priceEdit.GetWindowTextA(realPrice);
	float price = Util::stof(realPrice.GetBuffer(0));


	/*采购位置*/
	CString purchasPositon;
	this->purchasPositonEdit.GetWindowTextA(purchasPositon);
	std::string purchPostion = purchasPositon.GetBuffer(0);
	purchPostion = charset_util::GBKToUTF8(purchPostion);

	std::string thumb_path_str = this->thumbPath.GetBuffer(0);
	if (thumb_path_str.compare("") == 0){
		this->MessageBox(charset_util::UTF8ToGBK("請選擇缩略图").c_str());
		return;
	}


	/*广告图*/
	std::string adv_path_str = this->advPath.GetBuffer(0);
	std::cout << "" << std::endl;
		if (adv_path_str.compare("")==0)
		{
			this->MessageBox(charset_util::UTF8ToGBK("請選擇廣告圖").c_str());
			return;
		}
	/*推荐*/
	CString recom;
	this->GetRecom(recom);
	std::string is_recom_str = recom.GetBuffer(0);
	/*时间戳*/
	std::string addTime = "2015/11/21";



	std::string big1_path = this->big1Path.GetBuffer(0);//大图1


	std::string cut1_path = this->cutFigure1Path.GetBuffer(0);//切图1


	this->gs->add_good(
		name, //商品名称 
		selClass,   //商品分类 
		info_str, // 商品描述
		capl,  // 容量 规格
		dop,  // 生产日期
		lp,  // 最低价
		hp,  // 最高价
		price,  //实际价格
		purchPostion,   //
		addTime,   // 添加时间
		thumb_path_str,  // 缩略图路径
		adv_path_str, // 广告图路径
		this->us,   // upload_service
		is_recom_str, // 是否推荐
		*this->fs,    //file_service
		big1_path,
		cut1_path
	);

	
}

/*縮略圖*/
void AddGoodsDlg::uploadFileGatp(){
	this->gatp.GetClientRect(&thumbRect);
	this->thumbPath = Util::GetFilePathName();
	ShowJpg::ShowJpgGif(this->gatp.GetDC(), thumbPath, thumbRect.left, thumbRect.top);
}

/*上传广告图*/
void AddGoodsDlg::uploadAdvPic(){
	this->advPic.GetClientRect(&this->advRect);
	this->advPath = Util::GetFilePathName();
	ShowJpg::ShowJpgGif(this->advPic.GetDC(), this->advPath, this->advRect.left, this->advRect.top);
}

/*商品大圖1*/
void AddGoodsDlg::uploadFileBig1(){
	this->big1.GetClientRect(&this->big1Rect);
	this->big1Path = Util::GetFilePathName();
	ShowJpg::ShowJpgGif(this->big1.GetDC(), this->big1Path, big1Rect.left, big1Rect.top);
}

/*商品大圖2*/
void AddGoodsDlg::uploadFileBig2(){
	RECT d;
	/*this->big2.GetClientRect(&d);
	CString big2Path = Util::GetFilePathName();
	ShowJpg::ShowJpgGif(this->big2.GetDC(), big2Path, d.left, d.top);*/
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
	/*this->cutFigure2.GetClientRect(&d);
	this->cutFigure2Path = Util::GetFilePathName();
	ShowJpg::ShowJpgGif(this->cutFigure2.GetDC(), cutFigure2Path, d.left, d.top);*/
}

/*重绘*/
void AddGoodsDlg::OnPaint(){
	BaseGoodDlg::OnPaint();
	/*重绘缩略图*/
	ShowJpg::ShowJpgGif(this->gatp.GetDC(), this->thumbPath, thumbRect.left, thumbRect.top);
	//ShowJpg::ShowJpgGif(this->gatp.GetDC(), thumbPath, thumbRect.left, thumbRect.top);

	/*重绘大图*/
	CStatic**bigCsList = new CStatic*[8]{
	  &this->big1
	};

	CString*bigPathArr = new CString[8]{
			this->big1Path
	};

	for (int i = 0; i < 8; i++){
		RECT bigRect;
		bigCsList[i]->GetClientRect(&bigRect);
		ShowJpg::ShowJpgGif(bigCsList[i]->GetDC(), bigPathArr[i], bigRect.left, bigRect.top);
	}




	/*重绘切图*/
	CStatic**cutCsList = new CStatic*[20]{
			&this->cutFigure1
	};

	Config*config= Config::getConfig();
	std::list<file*>::iterator cutIter = this->cutFileList.begin();
	for (int i=0; cutIter != this->cutFileList.end(); cutIter++,i++){
		file*f = *cutIter;
		std::string lpPath = config->get_local_path() + f->get_uri_path();
		RECT cutRect;
		cutCsList[i]->GetClientRect(&cutRect);
		ShowJpg::ShowJpgGif(cutCsList[i]->GetDC(), lpPath.c_str(), cutRect.left, cutRect.top);
	}
	//delete[]cutCsList;

	
	
}


BOOL AddGoodsDlg::OnEraseBkgnd(CDC*pDC){
	return BaseGoodDlg::OnEraseBkgnd(pDC);
}

/*初始化数据*/
BOOL AddGoodsDlg::OnInitDialog(){
	BaseGoodDlg::OnInitDialog();
	this->isNotRecom.SetCheck(TRUE);
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
	this->selClass = id;
	CString content;
	this->firstClass.GetWindowTextA(content);

	CComboBox *secondClass = (CComboBox*)this->GetDlgItem(IDC_COMBO_CHILD_CLASS);/*二级分类控件*/
	MyDoc * myDoc = (MyDoc*)((MyFrame*)AfxGetApp()->GetMainWnd())->GetActiveDocument();
	std::list<classification*> *ls = new std::list<classification*>;
	this->cs->query_class_bypid(ls,id);

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
	this->cs->query_class_bypid(ls, id);

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

/*推荐*/
void AddGoodsDlg::selRecommended(){
	this->isRecom.SetCheck(TRUE);
	this->isNotRecom.SetCheck(FALSE);
}

/*不推荐*/
void AddGoodsDlg::selNotRecommended(){
	this->isNotRecom.SetCheck(TRUE);
	this->isRecom.SetCheck(FALSE);
}

/*获取推荐状态*/
void AddGoodsDlg::GetRecom(CString&recom){
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

BEGIN_MESSAGE_MAP(AddGoodsDlg, BaseGoodDlg)
	ON_BN_CLICKED(IDOK, addGood)
	ON_BN_CLICKED(IDC_BUTTON_UPLOAD_GOODS_IMG, uploadFileGatp)/*缩略图*/
	ON_BN_CLICKED(IDC_BUTTON1, uploadFileBig1)/*大图1*/
	ON_BN_CLICKED(IDC_BUTTON2, uploadFileBig2)/*大图2*/
	ON_BN_CLICKED(IDC_BUTTON9, uploadCutFigure1) /*切圖1*/
	ON_BN_CLICKED(IDC_BUTTON10, uploadCutFigure2) /*切圖2*/
	ON_BN_CLICKED(IDC_BUTTON_ADV_PIC, uploadAdvPic)/*广告图*/
	ON_BN_CLICKED(IDC_RADIO_RECOMMENDED, selRecommended) /*推荐*/
	ON_BN_CLICKED(IDC_RADIO_NOT_RECOMMENDED, selNotRecommended) /*不推荐*/
	ON_CBN_SELCHANGE(IDC_COMBO_BIG_CLASS, SetSecondClass)
	ON_CBN_SELCHANGE(IDC_COMBO_CHILD_CLASS, SetThirdClass)
	ON_CBN_SELCHANGE(IDC_COMBO1, SelThirdClass)/**/
	ON_CBN_SETFOCUS(IDC_COMBO_BIG_CLASS,f1)
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

