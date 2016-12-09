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
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif
	this->init();
}

AddGoodsDlg::AddGoodsDlg(long goodId)
: CDialogEx(){
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

	std::cout << "1" << std::endl;
	this->goodId = goodId;
	this->init();
}

AddGoodsDlg::~AddGoodsDlg()
{
}

void AddGoodsDlg::init(){
	this->fs = file_service::get_file_service();
	this->gfs = good_file_service::get_good_file_service();
	this->cs = classification_service::get_classification_service();
	this->gs = good_service::get_good_service();
	this->us = upload_service::get_upload_service();
}

/**/
void AddGoodsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_GATP, this->gatp);//縮略圖
	DDX_Control(pDX, IDC_STATIC_ADV_PIC, this->advPic);//商品广告图
	DDX_Control(pDX, IDC_STATIC_BGAT, this->big1);//大圖1
	DDX_Control(pDX, IDC_STATIC_PP, this->big2); //大圖2
	DDX_Control(pDX, IDC_STATIC_BIG3, this->big3);//大圖3
	DDX_Control(pDX, IDC_STATIC_BIG4, this->big4);//大圖4
	DDX_Control(pDX, IDC_STATIC_BIG5, this->big5);//大圖5
	DDX_Control(pDX, IDC_STATIC_BIG6, this->big6);//大圖6
	DDX_Control(pDX, IDC_STATIC_BIG7, this->big7);//大圖7
	DDX_Control(pDX, IDC_STATIC_BIG8, this->big8);//大圖8
	
	DDX_Control(pDX, IDC_STATIC_CUT1, this->cutFigure1);//切圖1
	DDX_Control(pDX, IDC_STATIC_CUT2, this->cutFigure2);//切圖2
	DDX_Control(pDX, IDC_STATIC_CUT3, this->cutFigure3);//切图3
	DDX_Control(pDX, IDC_STATIC_CUT4, this->cutFigure4);//切图4
	DDX_Control(pDX, IDC_STATIC_CUT5, this->cutFigure5);//切图5
	DDX_Control(pDX, IDC_STATIC_CUT6, this->cutFigure6);//切图6
	DDX_Control(pDX, IDC_STATIC_CUT7, this->cutFigure7);//切图7
	DDX_Control(pDX, IDC_STATIC_CUT8, this->cutFigure8);//切图8
	DDX_Control(pDX, IDC_STATIC_CUT9, this->cutFigure9);//切图9
	DDX_Control(pDX, IDC_STATIC_CUT10, this->cutFigure10);//切图10
	DDX_Control(pDX, IDC_STATIC_CUT11, this->cutFigure11);//切图11
	DDX_Control(pDX, IDC_STATIC_CUT12, this->cutFigure12);//切图12
	DDX_Control(pDX, IDC_STATIC_CUT13, this->cutFigure13);//切图13
	DDX_Control(pDX, IDC_STATIC_CUT14, this->cutFigure14);//切图14
	DDX_Control(pDX, IDC_STATIC_CUT15, this->cutFigure15);//切图15
	DDX_Control(pDX, IDC_STATIC_CUT16, this->cutFigure16);//切图16
	DDX_Control(pDX, IDC_STATIC_CUT17, this->cutFigure17);//切图17
	DDX_Control(pDX, IDC_STATIC_CUT18, this->cutFigure18);//切图18
	DDX_Control(pDX, IDC_STATIC_CUT19, this->cutFigure19);//切图19
	DDX_Control(pDX, IDC_STATIC_CUT20, this->cutFigure20);//切图20
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

	/*编辑商品信息*/
	if (this->goodId > 0){
		good_service *gs = good_service::get_good_service();
		goods g;
		gs->findById(&g, this->goodId);

		good_file_service *gfs = good_file_service::get_good_file_service();
		 std::list<file*> fileList;
		 gfs->findFileByGoodId(this->goodId, 12, &fileList);/*商品缩略图*/
		 file *thumbFile = fileList.front();/*缩略图*/
		 this->thumbFileId = thumbFile->get_id(); /*缩略图文件id*/

		 this->thumbPath  = std::string(Constants::local_base_path + thumbFile->get_uri_path()).c_str();/*ftp下载到本地的路径*/
		 this->downloadFtpFile(thumbFile);/*下载缩略图*/
		
		this->gatp.GetClientRect(&thumbRect);


		gfs->findFileByGoodId(this->goodId, 13, &this->bigFileList);/*商品大图*/

		std::list<file*>::iterator bigIter = this->bigFileList.begin();
		for (; bigIter != this->bigFileList.end(); bigIter++){
			file*f = *bigIter;
			this->downloadFtpFile(f);
		}

		gfs->findFileByGoodId(this->goodId, 14, &this->cutFileList);/*商品切图*/
		std::list<file*>::iterator cutIter = this->cutFileList.begin();
		for (; cutIter != this->cutFileList.end(); cutIter++){
			file*f = *cutIter;
			this->downloadFtpFile(f);
		}


		this->nameEdit.SetWindowTextA(charset_util::UTF8ToGBK(g.get_name()).c_str());/*名称*/
		this->infoEdit.SetWindowTextA(charset_util::UTF8ToGBK(g.get_info()).c_str());/*描述*/
		this->capacityEdit.SetWindowTextA(Util::ltos(g.get_capacity()).c_str());/*容量*/
		this->dateOfProductionControl.SetWindowTextA(g.get_dateOfProduction().c_str());/*生产日期*/
		this->lowestPriceEdit.SetWindowTextA(Util::ltos(g.get_lowest_price()).c_str());/*最低价*/
		this->highestPriceEdit.SetWindowTextA(Util::ltos(g.get_highest_price()).c_str());/*最高价*/
		this->purchasPositonEdit.SetWindowTextA(charset_util::UTF8ToGBK(g.get_purchasing_position()).c_str());/*采购位置*/

		long classid = g.get_classid();
		classification clas;
		
		std::list<long> ids;
		do
		{
			this->cs->getParentClass(&clas,classid);
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

/*下载文件*/
void AddGoodsDlg::downloadFtpFile(file*f){
	std::string url_str = "";
	url_str = Constants::server_base_path + f->get_uri_path();/*服务器上ftp的路径*/
	localPath = Constants::local_base_path + f->get_uri_path();/*ftp下载到本地的路径*/

	std::string resultPath; /*截取结果*/
	std::string filename; /*文件名*/
	resultPath = this->getPath(localPath, filename);/*获取路径*/
	resultPath = this->myReplaceAll(resultPath, "/", "\\");/*替换文件路径*/
	if (!PathIsDirectory(resultPath.c_str())){
		/*不存在则创建*/
		this->CreateMuliteDirectory(resultPath.c_str());
	}

	UploadFile *uf = new UploadFile;
	uf->download(url_str.c_str(), localPath.c_str()); /*下载文件到本地*/
	delete uf;
}

/**/
std::string AddGoodsDlg::myReplaceAll(const std::string& str, std::string org_str, std::string rep_str) // 把org_str 替换为rep_str; 
{
	std::vector<std::string>  delimVec = mySplit(str, org_str);
	if (delimVec.size() <= 0)
	{
		std::cout << "can not find" << std::endl;
		return str;
	}
	std::string target("");
	std::vector<std::string>::iterator it = delimVec.begin();
	for (; it != delimVec.end(); ++it)
	{
		target = target + (*it) + rep_str;
	}
	//target = target +(*it); 
	return target;
}



std::vector<std::string> AddGoodsDlg::mySplit(const std::string& str, std::string sp_string)  // split(), str 是要分割的string
{
	std::vector<std::string> vecString;
	int sp_stringLen = sp_string.size();
	int lastPosition = 0;
	int index = -1;
	while (-1 != (index = str.find(sp_string, lastPosition)))
	{
		vecString.push_back(str.substr(lastPosition, index - lastPosition));
		lastPosition = index + sp_stringLen;
	}
	std::string lastStr = str.substr(lastPosition);
	if (!lastStr.empty())
	{
		vecString.push_back(lastStr);
	}
	return vecString;
}

BOOL AddGoodsDlg::FolderExists(CString s)
{
	DWORD attr;
	attr = GetFileAttributes(s);
	return (attr != (DWORD)(-1)) && (attr & FILE_ATTRIBUTE_DIRECTORY);
}


BOOL AddGoodsDlg::CreateMuliteDirectory(CString P)
{
	int len = P.GetLength();
	if (len <2) return false;
	if ('\\' == P[len - 1])
	{
		P = P.Left(len - 1);
		len = P.GetLength();
	}
	if (len <= 0) return false;
	if (len <= 3)
	{
		if (FolderExists(P))return true;
		else return false;
	}
	if (FolderExists(P))return true;
	CString Parent;
	Parent = P.Left(P.ReverseFind('\\'));
	if (Parent.GetLength() <= 0)return false;
	BOOL Ret = CreateMuliteDirectory(Parent);
	if (Ret)
	{
		SECURITY_ATTRIBUTES sa;
		sa.nLength = sizeof(SECURITY_ATTRIBUTES);
		sa.lpSecurityDescriptor = NULL;
		sa.bInheritHandle = 0;
		Ret = (CreateDirectory(P, &sa) == TRUE);
		return Ret;
	}
	else
		return FALSE;
}

/*截取文件名*/
std::string AddGoodsDlg::getPath(std::string&path,std::string&filename){
	int lastp = path.find_last_of("/");
	std::string b = path.substr(0, lastp);
	filename =path.substr(lastp+1);
	return b;
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
	goods good;

	/*商品名称*/
	CString cs0;
	this->nameEdit.GetWindowTextA(cs0);
	MyDoc * myDoc = (MyDoc*)((MyFrame*)AfxGetApp()->GetMainWnd())->GetActiveDocument();
	std::string name = cs0.GetBuffer(0);
	name = charset_util::GBKToUTF8(name);

	/*描述*/
	CString info;
	infoEdit.GetWindowTextA(info);
	std::string info_str = info.GetBuffer(0);
	info_str = charset_util::GBKToUTF8(info_str);

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

	/*广告图*/
	std::string adv_path_str = this->advPath.GetBuffer(0);

	/*推荐*/
	CString recom;
	this->GetRecom(recom);
	std::string is_recom_str = recom.GetBuffer(0);
	/*时间戳*/
	std::string addTime = "2015/11/21";
	this->gs->add_good(name, 
		selClass, 
		info_str,
		capl,
		dop, 
		lp,
		hp,
		price,
		purchPostion, 
		addTime, 
		goodId, 
		thumbFileId, 
		thumb_path_str,
		adv_path_str,
		this->us,
		is_recom_str,
		good);

	/*图片*/

	/*縮略圖*/
	if (thumbFileId > 0){ 
		/*修改缩略图*/
		if (thumbPath != ""){
			this->fs->update_and_upload_file(this->thumbFileId, thumb_path_str, 12);
		}
	}
	else{ 
		/*添加缩略图*/
		this->fs->add_good_file(thumb_path_str, good.get_id(), 12);
	}

	/*添加商品大图1*/
	std::string big1_path_str = this->big1Path.GetBuffer(0);
	this->fs->add_good_file(big1_path_str, good.get_id(), 13);

	/*添加切图1*/
	std::string cut1_path_str = this->cutFigure1Path.GetBuffer(0);
	this->fs->add_good_file(cut1_path_str, good.get_id(), 14);

	
	
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
	this->big2.GetClientRect(&d);
	CString big2Path = Util::GetFilePathName();
	ShowJpg::ShowJpgGif(this->big2.GetDC(), big2Path, d.left, d.top);
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

/*重绘*/
void AddGoodsDlg::OnPaint(){
	/*重绘缩略图*/
	ShowJpg::ShowJpgGif(this->gatp.GetDC(), this->thumbPath, thumbRect.left, thumbRect.top);
	//ShowJpg::ShowJpgGif(this->gatp.GetDC(), thumbPath, thumbRect.left, thumbRect.top);

	/*重绘大图*/
	CStatic**bigCsList = new CStatic*[8]{
	  &this->big1,
	  &this->big2,
	  &this->big3,
	  &this->big4,
	  &this->big5,
	  &this->big6,
	  &this->big7,
	  &this->big8
	};

	CString*bigPathArr = new CString[8]{
			this->big1Path,
		  this->big2Path,
		  this->big3Path,
		  this->big4Path,
		  this->big5Path,
		  this->big6Path,
		  this->big7Path,
		  this->big8Path
	};

	for (int i = 0; i < 8; i++){
		RECT bigRect;
		bigCsList[i]->GetClientRect(&bigRect);
		ShowJpg::ShowJpgGif(bigCsList[i]->GetDC(), bigPathArr[i], bigRect.left, bigRect.top);
	}




	/*重绘切图*/
	CStatic**cutCsList = new CStatic*[20]{
			&this->cutFigure1,
			&this->cutFigure2,
			&this->cutFigure3,
			&this->cutFigure4,
			&this->cutFigure5,
			&this->cutFigure6,
			&this->cutFigure7,
			&this->cutFigure8,
			&this->cutFigure9,
			&this->cutFigure10,
			&this->cutFigure11,
			&this->cutFigure12,
			&this->cutFigure13,
			&this->cutFigure14,
			&this->cutFigure15,
			&this->cutFigure16,
			&this->cutFigure17,
			&this->cutFigure18,
			&this->cutFigure19,
			&this->cutFigure20
	};

	std::list<file*>::iterator cutIter = this->cutFileList.begin();
	for (int i=0; cutIter != this->cutFileList.end(); cutIter++,i++){
		file*f = *cutIter;
		std::string lpPath = Constants::local_base_path + f->get_uri_path();
		RECT cutRect;
		cutCsList[i]->GetClientRect(&cutRect);
		ShowJpg::ShowJpgGif(cutCsList[i]->GetDC(), lpPath.c_str(), cutRect.left, cutRect.top);
	}
	//delete[]cutCsList;

	CDialogEx::OnPaint();
	
}


HRESULT AddGoodsDlg::ShowPic(CDC* pDC, CString strImgUrl, CRect rect)
{
	HDC hDC_Temp = pDC->GetSafeHdc();

	IPicture *pPic;
	IStream *pStm;

	HRESULT bResult;// = FALSE;        

	DWORD dwFileSize, dwByteRead;

	//读取网页上图片文件，实际是个CHttpFile指针    
	CInternetSession session("HttpClient");
	CFile* httpFile = (CFile*)session.OpenURL(strImgUrl);

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
	int nWidth = MulDiv(hmWidth, GetDeviceCaps(hDC_Temp, LOGPIXELSX), 2540);
	int nHeight = MulDiv(hmHeight, GetDeviceCaps(hDC_Temp, LOGPIXELSY), 2540);

	//缩放图片
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

	//将图形输出到屏幕上（有点像BitBlt）        
	bResult = pPic->Render(hDC_Temp, rect.left, rect.top, rect.Width(), rect.Height(),
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


BOOL AddGoodsDlg::OnEraseBkgnd(CDC*pDC){
	return CDialogEx::OnEraseBkgnd(pDC);
}

/*初始化数据*/
BOOL AddGoodsDlg::OnInitDialog(){
	CDialogEx::OnInitDialog();
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

BEGIN_MESSAGE_MAP(AddGoodsDlg, CDialogEx)
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


// AddGoodsDlg 消息处理程序
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