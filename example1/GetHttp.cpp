///////////////////////////////////////////////////////////
//  GetHttp.cpp
//  Implementation of the Class GetHttp
//  Created on:      18-Ê®¶şÔÂ-2016 15:03:08
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "GetHttp.h"


GetHttp::GetHttp(){
	/*CInternetSession session;
	CHttpConnection *conn= session.GetHttpConnection("www.baidu.com");
	CHttpFile *file= conn->OpenRequest("GET", "/index.html");
	file->SendRequest();
	CString mystr;
	CString tmp;
	while (file->ReadString(tmp))
	{
		mystr += tmp;
	}

	std::cout << mystr << std::endl;
	file->Close();
	conn->Close();
	session.Close();
	delete file;
	delete conn;
	file = NULL;
	conn = NULL;*/
}



GetHttp::~GetHttp(){

}

void GetHttp::download(){
	const int dwBufSize = 1024;
	CInternetSession *session = new CInternetSession;
	CHttpFile *pHttpFile = NULL;
	CStdioFile pLocalFile;
	DWORD dwlen;
	LPBYTE lpBuf = new byte[dwBufSize];
	pLocalFile.Open("d:/test.png", CFile::modeCreate|CFile::modeWrite|CFile::typeBinary);
	pHttpFile=(CHttpFile*) session->OpenURL("http://47.88.105.195/12/454/2011825132301329511229904127423500507232517.png", 1, INTERNET_FLAG_TRANSFER_BINARY | INTERNET_FLAG_RELOAD | INTERNET_FLAG_DONT_CACHE, NULL, 0);
	while (dwlen=pHttpFile->Read(lpBuf,dwBufSize-1))
	{
		pLocalFile.Write(lpBuf, dwlen);
	}
	pLocalFile.Close();
	pHttpFile->Close();
	pHttpFile = NULL;
	delete[]lpBuf;
}


LRESULT GetHttp::OnRender(WPARAM wParam, LPARAM lParam)
{
	/*DWORD    dwLen = m_pComRec->m_nFrameSize;
	BYTE*    lpFrame = m_pComRec->m_buffFrame;

	HGLOBAL    hMem = GlobalAlloc(GMEM_FIXED, dwLen);
	BYTE*    pMem = (BYTE*)GlobalLock(hMem);
	memcpy(pMem, lpFrame, dwLen);
	IStream* pIStm;
	CreateStreamOnHGlobal(hMem, FALSE, &pIStm);

	m_picFrame.Load(pIStm);

	GlobalUnlock(hMem);
	pIStm->Release();

	Invalidate();
	m_pComRec->Send("go on", 5);*/

	return    1;
}