//#define _AFXDLL
#include <afxwin.h>
#include <iostream>
#include "ReadIniFile.h"


ReadIniFile::ReadIniFile() 
{
	strcpy_s(this->path, _T("c:/test/test.ini"));
	GetPrivateProfileString(_T("SECTION3"), _T("dbuser"), _T(""), this->dbuser, 256, this->path);
	GetPrivateProfileString(_T("SECTION3"), _T("dbpass"), _T(""), this->dbpass, 256, this->path);
	GetPrivateProfileString(_T("SECTION3"), _T("dbip"), _T(""), this->dbip, 256, this->path);
	GetPrivateProfileString(_T("SECTION3"), _T("dbname"), _T(""), this->dbname, 256, this->path);
	GetPrivateProfileString(_T("SOCKET_CLIENT"), _T("server_ip"), _T(""), this->server_ip, 256, this->path);
}

ReadIniFile::~ReadIniFile() 
{
}

void ReadIniFile::read(){
	int m_nXPos,len;
	m_nXPos = GetPrivateProfileInt(_T("SECTION1"), _T("XPos"), 0, this->path);
	std::cout << m_nXPos << std::endl;

	char buf[100];
	len = GetPrivateProfileString(_T("SECTION2"), _T("Text"), _T("No Text"), buf, 256, this->path);
	printf("%s\n", buf);

}


char * ReadIniFile::get_dbuser(){
	return this->dbuser;
}

char * ReadIniFile::get_dbpass(){
	return this->dbpass;
}

char * ReadIniFile::get_dbip(){
	return this->dbip;
}

char * ReadIniFile::get_dbname(){
	return this->dbname;
}


char * ReadIniFile::get_server_ip(){
	return this->server_ip;
}


