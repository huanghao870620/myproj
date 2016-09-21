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
	CStdioFile * pfile = session.OpenURL(url);
	DWORD dwStatusCode;
	CFileStatus fileStatus;
	pfile->GetStatus(fileStatus);
	CTime atime = fileStatus.m_atime;
	fileStatus.m_attribute;
	CTime ctime = fileStatus.m_ctime;
	CTime mtime = fileStatus.m_mtime;
	fileStatus.m_size;
	fileStatus.m_szFullName;
	atime.GetDay();
}