///////////////////////////////////////////////////////////
//  ScrapingOfPage.cpp
//  Implementation of the Class ScrapingOfPage
//  Created on:      21-¾ÅÔÂ-2016 9:47:37
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "ScrapingOfPage.h"


ScrapingOfPage::ScrapingOfPage(){

}



ScrapingOfPage::~ScrapingOfPage(){

}

void ScrapingOfPage::grab(){
	CInternetSession session("HttpClient");
	char * url = "http://www.baidu.com";
	CHttpFile *pfile = (CHttpFile*) session.OpenURL(url);
	DWORD dwStatusCode;
	pfile->QueryInfoStatusCode(dwStatusCode);
	if (dwStatusCode == HTTP_STATUS_OK){
		CString	content;
		CString data;
		while (pfile->ReadString(data))
		{
			content += data + "\r\n";
		}
		content.TrimRight();
		printf("%s\n", content);
	}
	pfile->Close();
	delete pfile;
	session.Close();
}