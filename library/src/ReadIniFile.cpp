#include <afxwin.h>
#include "ReadIniFile.h"


ReadIniFile::ReadIniFile() 
{
}

ReadIniFile::~ReadIniFile() 
{
}

char * ReadIniFile::get_path(){
	char * path = "c:/test/test.ini";
	return  path;
}


//void ReadIniFile::read(){
//	int m_nXPos,len;
//	char buf[100];
//	m_nXPos = GetPrivateProfileInt(_T("SECTION1"), _T("XPos"), 0, get_path());
//	len = GetPrivateProfileString(_T("SECTION2"), _T("Text"), _T("No Text"), buf, 256, get_path());
//}


std::string & ReadIniFile::get_dbuser(){
	char dbuser[100];
	GetPrivateProfileString(_T("SECTION3"), _T("dbuser"), _T(""), dbuser, 256, get_path());
	return std::string(dbuser);
}

std::string & ReadIniFile::get_dbpass(){
	char dbpass[100];
	GetPrivateProfileString(_T("SECTION3"), _T("dbpass"), _T(""), dbpass, 256, get_path());
	return std::string(dbpass);
}

std::string & ReadIniFile::get_dbip(){
	char dbip[100];
	GetPrivateProfileString(_T("SECTION3"), _T("dbip"), _T(""), dbip, 256, get_path());
	return std::string(dbip);
}

std::string & ReadIniFile::get_dbname(){
	char dbname[100];
	GetPrivateProfileString(_T("SECTION3"), _T("dbname"), _T(""), dbname, 256, get_path());
	return std::string(dbname);
}


void ReadIniFile::get_server_ip(char * server_ip){
	GetPrivateProfileString(_T("SOCKET_CLIENT"), _T("server_ip"), _T(""), server_ip, 256, get_path());
}



