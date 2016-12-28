///////////////////////////////////////////////////////////
//  Config.cpp
//  Implementation of the Class Config
//  Created on:      21-Ê®¶þÔÂ-2016 16:29:45
//  Original author: admin
///////////////////////////////////////////////////////////

#include "Config.h"
#include<afxwin.h>



Config::Config(){
	std::string config_file_path = "conn.ini";
	TCHAR szFilePath[100 + 1] = { 0 };
	GetModuleFileName(NULL, szFilePath, MAX_PATH);
	std::string strFilePath(szFilePath);
	std::size_t last = strFilePath.find_last_of("\\") - 2;
	(strchr(szFilePath, '\\'))[last] = 0;
	
	iniFile.append(szFilePath).append("\\").append(config_file_path);
	//int b = GetPrivateProfileInt("SECTION1", "YPos", 1, s.c_str());
}



Config::~Config(){

}

/*mysql ip*/
char* Config::get_db_ip(){
	char *ip = new char[16];
	GetPrivateProfileString("mysql", "ip", NULL, ip, 16, iniFile.c_str());
	return ip;
}

/*mysql user*/
char* Config::get_db_user(){
	char *user=new char[20];
	GetPrivateProfileString("mysql", "username", NULL, user, 20, iniFile.c_str());
	return user;
}

/*mysql pass*/
char* Config::get_db_pass(){
	char *pass=new char[20];
	GetPrivateProfileString("mysql", "password", NULL, pass, 20, iniFile.c_str());
	return pass;
}

/*ftp ip*/
char* Config::get_ftp_ip(){
	char*ip = new char[20];
	GetPrivateProfileString("ftp", "ip", NULL, ip, 20, iniFile.c_str());
	return ip;
}

/**/
char* Config::get_ftp_pass(){
	char *pass = new char[20];
	GetPrivateProfileString("ftp", "password", NULL, pass, 20, iniFile.c_str());
	return pass;
}

/**/
char* Config::get_ftp_user(){
	char *user = new char[20];
	GetPrivateProfileString("ftp", "username", NULL, user, 20, iniFile.c_str());
	return user;
}

/**/
char* Config::get_img_ip(){
	char*ip = new char[20];
	GetPrivateProfileString("img", "ip", NULL, ip, 20, iniFile.c_str());
	return ip;
}

char* Config::get_local_path(){
	char*local = new char[20];
	GetPrivateProfileString("img", "local_path", NULL, local, 20, iniFile.c_str());
	return local;
}

char* Config::get_remote_path(){
	char*remote = new char[20];
	GetPrivateProfileString("img", "remote_base_path", NULL, remote, 20, iniFile.c_str());
	return remote;
}

