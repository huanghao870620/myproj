// D:\cppwork\myproj\xunan_admin\dlg\EditGoodDlg.cpp : ʵ���ļ�
//

#include "../stdafx.h"
#include"EditGoodDlg.h"


// EditGoodDlg �Ի���

IMPLEMENT_DYNAMIC(EditGoodDlg, BaseGoodDlg)


void EditGoodDlg::DoDataExchange(CDataExchange* pDX)
{
	BaseGoodDlg::DoDataExchange(pDX);

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



EditGoodDlg::EditGoodDlg(CWnd* pParent /*=NULL*/)
	: BaseGoodDlg(/*EditGoodDlg::IDD,*/ pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif
	this->init();
}

EditGoodDlg::EditGoodDlg(long goodId)
	: BaseGoodDlg(){
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

	this->goodId = goodId;
	this->init();
}

EditGoodDlg::~EditGoodDlg()
{
}

/*��݋��Ʒ*/
void EditGoodDlg::editGood(){

	/*��Ʒ����*/
	CString cs0;
	this->nameEdit.GetWindowTextA(cs0);
	MyDoc * myDoc = (MyDoc*)((MyFrame*)AfxGetApp()->GetMainWnd())->GetActiveDocument();
	std::string name = cs0.GetBuffer(0);
	name = charset_util::GBKToUTF8(name);

	if (name.compare("") == 0){
		this->MessageBox(charset_util::UTF8ToGBK("����д��Ʒ����").c_str());
		return;
	}


	/*����*/
	CString info;
	infoEdit.GetWindowTextA(info);
	std::string info_str = info.GetBuffer(0);
	info_str = charset_util::GBKToUTF8(info_str);
	if (info_str.compare("") == 0){
		this->MessageBox("����д��Ʒ����");
		return;
	}

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
	if (adv_path_str.compare("") == 0){
		this->MessageBox(charset_util::UTF8ToGBK("δѡ����ͼ!").c_str());
		return;
	}

	/*�Ƽ�*/
	CString recom;
	this->GetRecom(recom);
	std::string is_recom_str = recom.GetBuffer(0);
	/*ʱ���*/
	std::string addTime = "2015/11/21";



	std::list<file_dto*> big_list;

	DWORD advHelpId= advPic.GetWindowContextHelpId();

	

	std::cout << "" << std::endl;
	this->gs->edit_good(
		name, //��Ʒ����
		selClass, // ��Ʒ����
		info_str,  // ��Ʒ����
		capl,  // ���
		dop,   // ��������
		lp,  // ��ͼ�
		hp,   //��߼�
		price,  // ʵ�ʼ۸�
		purchPostion,   // 
		addTime,   //  �޸�ʱ��
		goodId,    // ��Ʒid
		thumbFileId,   // ����ͼid
		thumb_path_str,  // ����ͼ·��
		adv_path_str,   // ���ͼ·��
		this->us,    // upload_service
		is_recom_str,
		*this->fs,    // file_service
		4,
		big_list,
		this->adv_pic_id
		);


}
//
///*�s�ԈD*/
//void EditGoodDlg::uploadFileGatp(){
//	this->gatp.GetClientRect(&thumbRect);
//	this->thumbPath = Util::GetFilePathName();
//	//ShowJpg::ShowJpgGif(this->gatp.GetDC(), thumbPath, thumbRect.left, thumbRect.top);
//	ShowJpg::ShowPng(this->gatp.GetDC(), thumbPath, thumbRect);
//}
//
///*�ϴ����ͼ*/
//void EditGoodDlg::uploadAdvPic(){
//	this->advPic.GetClientRect(&this->advRect);
//	this->advPath = Util::GetFilePathName();
//	ShowJpg::ShowJpgGif(this->advPic.GetDC(), this->advPath, this->advRect.left, this->advRect.top);
//}

/*��Ʒ��D1*/
void EditGoodDlg::uploadFileBig1(){
	this->big1.GetClientRect(&this->big1Rect);
	this->big1Path = Util::GetFilePathName();
	ShowJpg::ShowJpgGif(this->big1.GetDC(), this->big1Path, big1Rect.left, big1Rect.top);
}

/*�ЈD1*/
void EditGoodDlg::uploadCutFigure1(){
	RECT d;
	this->cutFigure1.GetClientRect(&d);
	this->cutFigure1Path = Util::GetFilePathName();
	ShowJpg::ShowJpgGif(this->cutFigure1.GetDC(), cutFigure1Path, d.left, d.top);
}

/*�ЈD2*/
void EditGoodDlg::uploadCutFigure2(){
	RECT d;
	/*this->cutFigure2.GetClientRect(&d);
	this->cutFigure2Path = Util::GetFilePathName();
	ShowJpg::ShowJpgGif(this->cutFigure2.GetDC(), cutFigure2Path, d.left, d.top);*/
}

/*�ػ�*/
void EditGoodDlg::OnPaint(){
	BaseGoodDlg::OnPaint();
	/*�ػ�����ͼ*/
	ShowJpg::ShowJpgGif(this->gatp.GetDC(), this->thumbPath, thumbRect.left, thumbRect.top);
	//ShowJpg::ShowJpgGif(this->gatp.GetDC(), thumbPath, thumbRect.left, thumbRect.top);

	ShowJpg::ShowJpgGif(this->advPic.GetDC(), this->advPath, advRect.left, advRect.top);//���ͼ
	/*�ػ��ͼ*/
	

	CString*bigPathArr = new CString[8]{
		this->big1Path
	};

	for (int i = 0; i < 8; i++){
		RECT bigRect;
		bigCsList[i]->GetClientRect(&bigRect);
		ShowJpg::ShowJpgGif(bigCsList[i]->GetDC(), bigPathArr[i], bigRect.left, bigRect.top);
	}




	/*�ػ���ͼ*/
	CStatic**cutCsList = new CStatic*[20]{
		&this->cutFigure1
	};

	Config*config= Config::getConfig();
	std::list<file>::iterator cutIter = this->cutFileList.begin();
	for (int i = 0; cutIter != this->cutFileList.end(); cutIter++, i++){
		file f = *cutIter;
		std::string lpPath = config->get_local_path() + f.get_uri_path();
		RECT cutRect;
		cutCsList[i]->GetClientRect(&cutRect);
		ShowJpg::ShowJpgGif(cutCsList[i]->GetDC(), lpPath.c_str(), cutRect.left, cutRect.top);
	}
	//delete[]cutCsList;



}



BOOL EditGoodDlg::OnEraseBkgnd(CDC*pDC){
	return BaseGoodDlg::OnEraseBkgnd(pDC);
}

/*��ʼ������*/
BOOL EditGoodDlg::OnInitDialog(){
	typedef std::auto_ptr<odb::database> data;
	typedef odb::core::transaction tran;
	typedef odb::transaction t;
	tran *tx = NULL;
	data db= db_util::get_db_util()->get_db();
	try{
	if (!t::has_current()){
		tx = new tran(db->begin());
	}
	else
	{
		tx = &(t::current());
	}

	BaseGoodDlg::OnInitDialog();
	this->SetWindowTextA(charset_util::UTF8ToGBK("�༭��Ʒ").c_str());
	this->isNotRecom.SetCheck(TRUE);
	Gdiplus::GdiplusStartupInput gi;
	ULONG_PTR gdiToken;
	GdiplusStartup(&gdiToken, &gi, NULL);
	t::current().commit();
	}
	catch (odb::exception&e){
		std::cout << e.what() << std::endl;
		t::current().rollback();
	}
	return TRUE;
}

/*���һ������*/
void EditGoodDlg::SetSecondClass(){
	int index = this->firstClass.GetCurSel();
	this->firstClass.SetCurSel(index);

	index = this->firstClass.GetCurSel();
	DWORD_PTR id = this->firstClass.GetItemData(index);
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
void EditGoodDlg::SetThirdClass(){
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
void EditGoodDlg::SelThirdClass(){
	CComboBox*box = (CComboBox*) this->GetDlgItem(IDC_COMBO1);
	int index = box->GetCurSel();
	box->SetCurSel(index);
	index = box->GetCurSel();
	DWORD_PTR id = box->GetItemData(index);
	this->selClass = id;
}

void EditGoodDlg::f1(){
	//std::cout << "" << std::endl;
	//CComboBox *box = (CComboBox*) this->GetDlgItem(IDC_COMBO_BIG_CLASS);
	////box->GetCurSel();
	//DWORD_PTR id = box->GetItemData(box->GetCurSel());
	//CString content;
	//box->GetWindowTextA(content);
	//std::cout << "" << std::endl;
}

void EditGoodDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar){
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


void EditGoodDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
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
void EditGoodDlg::selRecommended(){
	this->isRecom.SetCheck(TRUE);
	this->isNotRecom.SetCheck(FALSE);
}

/*���Ƽ�*/
void EditGoodDlg::selNotRecommended(){
	this->isNotRecom.SetCheck(TRUE);
	this->isRecom.SetCheck(FALSE);
}

/*��ȡ�Ƽ�״̬*/
void EditGoodDlg::GetRecom(CString&recom){
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

void EditGoodDlg::showBigPic(){
	BigPicDlg *dlg = new BigPicDlg(this->goodId);
	dlg->Create(IDD_DIALOG_BIG_PIC, this);
	dlg->ShowWindow(SW_SHOW);
}



BEGIN_MESSAGE_MAP(EditGoodDlg, BaseGoodDlg)
	ON_BN_CLICKED(IDOK, editGood)
	ON_BN_CLICKED(IDC_BUTTON_UPLOAD_GOODS_IMG, uploadFileGatp)/*����ͼ*/
	ON_BN_CLICKED(IDC_BUTTON_SHOW_BIGPIC, showBigPic) /*��ʾ��ͼ�б�*/
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

// EditGoodDlg ��Ϣ�������

