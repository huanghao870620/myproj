#include <afxwin.h>
#include "ReadIniFile.h"


ReadIniFile::ReadIniFile() 
{
	
}

ReadIniFile::~ReadIniFile() 
{
}

char * ReadIniFile::get_path(char * path,  char  szAppPath[]){
	GetModuleFileName(NULL, szAppPath, MAX_PATH);
	strrchr(szAppPath, '\\')[1] = 0;
	strcat_s(szAppPath,MAX_PATH, path);
	return  szAppPath;
}


//void ReadIniFile::read(){
//	int m_nXPos,len;
//	char buf[100];
//	m_nXPos = GetPrivateProfileInt(_T("SECTION1"), _T("XPos"), 0, get_path());
//	len = GetPrivateProfileString(_T("SECTION2"), _T("Text"), _T("No Text"), buf, 256, get_path());
//}


void ReadIniFile::get_dbuser(char * dbuser){
	GetPrivateProfileString(_T("SECTION3"), _T("dbuser"), _T(""), dbuser, 256, get_path(0,0));
}

void ReadIniFile::get_dbpass(char * dbpass){
	GetPrivateProfileString(_T("SECTION3"), _T("dbpass"), _T(""), dbpass, 256, get_path(0,0));
}

void ReadIniFile::get_dbip(char * dbip){
	GetPrivateProfileString(_T("SECTION3"), _T("dbip"), _T(""), dbip, 256, get_path(0,0));
}

void ReadIniFile::get_dbname(char * dbname){
	GetPrivateProfileString(_T("SECTION3"), _T("dbname"), _T(""), dbname, 256, get_path(0,0));
}


void ReadIniFile::get_server_ip(char * server_ip){
	char * path = "test.ini";
	char szAppPath[MAX_PATH];
	GetPrivateProfileString(_T("SOCKET_CLIENT"), _T("server_ip"), _T(""), server_ip, 256, get_path(path,szAppPath));
}



