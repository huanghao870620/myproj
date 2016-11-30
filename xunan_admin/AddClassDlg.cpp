// AddClass.cpp : 实现文件
//

#include "stdafx.h"
#include"AddClassDlg.h"
#include "afxdialogex.h"


// AddClass 对话框

IMPLEMENT_DYNAMIC(AddClassDlg, CDialogEx)

AddClassDlg::AddClassDlg(CWnd* pParent /*=NULL*/)
: CDialogEx(AddClassDlg::IDD, pParent)
{

}

AddClassDlg::~AddClassDlg()
{
}

void AddClassDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_IMG, this->img);
}


//
//HBITMAP LoadJpegPicture(const char* fileName)  { 
//	FILE * jpegFile;
//	struct jpeg_error_mgr jerr;  
//	struct jpeg_decompress_struct cinfo; 
//	if ((jpegFile = fopen(fileName, "rb")) == NULL) {
//		return HBITMAP(0);
//	}  
//	cinfo.err = jpeg_std_error(&jerr);
//	jpeg_create_decompress(&cinfo);
//	jpeg_stdio_src(&cinfo, jpegFile); 
//	jpeg_read_header(&cinfo, TRUE);
//	jpeg_start_decompress(&cinfo); 
//	int rowSize = cinfo.output_width * cinfo.output_components;  
//	int width = cinfo.output_width; 
//	int height = cinfo.output_height;  
//	BYTE *bmpBuffer = new BYTE[(height + 1)*width * 3];  
//	BYTE **pBuffer = (*cinfo.mem->alloc_sarray)((j_common_ptr)&cinfo, JPOOL_IMAGE, rowSize, 1);  
//	while (cinfo.output_scanline < cinfo.output_height)  {
//		jpeg_read_scanlines(&cinfo, pBuffer, 1); 
//		int start = rowSize*(cinfo.output_scanline - 1); 
//		for (int i = 0; i < rowSize; i++)  {
//			bmpBuffer[start + i] = pBuffer[0][i]; 
//		} 
//	}  
//	jpeg_finish_decompress(&cinfo);  
//	jpeg_destroy_decompress(&cinfo);  
//	HBITMAP bitmap = CreateBitmapFromBuffer(bmpBuffer, width, height);  
//	fclose(jpegFile);   
//	delete[] bmpBuffer; 
//	return bitmap; 
//}



void LoadResImage(int nResID, Gdiplus::Image * &lpImage)
{
	HMODULE hModule = AfxGetInstanceHandle();
	HRSRC hRsrc = ::FindResource(hModule, MAKEINTRESOURCE(nResID), _T("PNG")); // type   
	if (!hRsrc)
		return;
	// load resource into memory   
	DWORD len = SizeofResource(hModule, hRsrc);
	BYTE* lpRsrc = (BYTE*)LoadResource(hModule, hRsrc);
	if (!lpRsrc)
		return;
	// Allocate global memory on which to create stream   
	HGLOBAL m_hMem = GlobalAlloc(GMEM_FIXED, len);
	BYTE* pmem = (BYTE*)GlobalLock(m_hMem);
	memcpy(pmem, lpRsrc, len);
	IStream* pstm;
	CreateStreamOnHGlobal(m_hMem, FALSE, &pstm);
	// load from stream   
	lpImage = Gdiplus::Image::FromStream(pstm);
	// free/release stuff   
	GlobalUnlock(m_hMem);
	pstm->Release();
	FreeResource(lpRsrc);
}

void AddClassDlg::uploadImg(){
	fileNamePath = Util::GetFilePathName();
	Gdiplus::Image *image = nullptr;
	LPWSTR path = L"";
	path = fileNamePath.AllocSysString();
	image = Gdiplus::Image::FromFile(path);
	CDC* pDC = GetDC();
	Gdiplus::Graphics graphics(pDC->m_hDC);
	RECT d;
	this->img.GetClientRect(&d);
	Gdiplus::Rect rect(d.right,d.bottom,d.right-d.left,d.bottom-d.top);
	graphics.DrawImage(image, rect);
}

BOOL AddClassDlg::OnInitDialog(){
	CDialogEx::OnInitDialog();
	Gdiplus::GdiplusStartupInput gi;
	ULONG_PTR gdiToken;
	GdiplusStartup(&gdiToken, &gi, NULL);
	return TRUE;
}

void AddClassDlg::AddClass(){
	//file* f = new file;
	//f->set_name("dd");
	//std::string file_path = this->fileNamePath.GetBuffer(0);
	//file_path = charset_util::GBKToUTF8(file_path);
	//f->set_path(file_path);
	//long fileTypeId = 11;
	//f->set_type_id(fileTypeId);
	//file_service*fs = file_service::get_file_service();
	//fs->add_file(*f);

	///*上传文件*/
	//UploadFile *uf = new UploadFile;
	//std::string id_str = Util::ltos(f->get_id());
	//std::string fileTypeIdStr = Util::ltos(fileTypeId);
	//std::string base;
	//uf->upload(this->fileNamePath, base, fileTypeIdStr.c_str(),id_str.c_str());/*上传文件*/
	//f->set_uri_path(base);
	//fs->update_file(*f);
	//delete uf;

	//CEdit*class_name_edit = (CEdit*) this->GetDlgItem(IDC_EDIT1); /*分类名称*/
	//CEdit *pid_edit = (CEdit*)this->GetDlgItem(IDC_EDIT2);
	//classification *classifi = new classification;
	//CString class_name;
	//class_name_edit->GetWindowTextA(class_name);
	//std::string className = class_name.GetBuffer(0);
	//className = charset_util::GBKToUTF8(className);
	//classifi->set_name(className);

	//CString pid_s;
	//pid_edit->GetWindowTextA(pid_s);
	//std::string pid= pid_s.GetBuffer(0);
	//classifi->set_pid(Util::stol(pid));
	//classifi->set_img_id(f->get_id());

	//classification_service *cs = classification_service::get_classification_service();
	//cs->add_classifi(*classifi);
}


BEGIN_MESSAGE_MAP(AddClassDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_UPLOAD_LOGO,AddClassDlg::uploadImg)
	ON_BN_CLICKED(IDOK,AddClassDlg::AddClass)
END_MESSAGE_MAP()


// AddClassDlg 消息处理程序
