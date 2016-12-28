///////////////////////////////////////////////////////////
//  UploadFile.cpp
//  Implementation of the Class UploadFile
//  Created on:      14-十一月-2016 19:56:37
//  Original author: admin
///////////////////////////////////////////////////////////

#include "UploadFile.h"

/**/
UploadFile::UploadFile(){
	hInternet = InternetOpen("A3GS Sample", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, INTERNET_FLAG_NO_CACHE_WRITE);
	if (NULL == hInternet){
		std::cout << GetLastError() << std::endl;
		return;
	}

	Config *config= Config::getConfig();

	hConnect = InternetConnect(hInternet, config->get_ftp_ip(), INTERNET_DEFAULT_FTP_PORT, config->get_ftp_user(), config->get_ftp_pass(), INTERNET_SERVICE_FTP, INTERNET_FLAG_EXISTING_CONNECT || INTERNET_FLAG_PASSIVE, 0);
	if (NULL == hConnect){
		std::cout << GetLastError() << std::endl;
		InternetCloseHandle(hInternet);
		return;
	}
}

/**/
UploadFile::~UploadFile(){
	this->Close();
}

/*上传*/
BOOL UploadFile::upload(LPCSTR lpszLocalFile, std::string &buf,LPCSTR fileTypeId,  LPCSTR id){
	DWORD size;
	CHAR b[100];
	FtpGetCurrentDirectory(this->hConnect,b,&size);
	
	LPSTR basePath =Config::getConfig()->get_remote_path();
	
	FtpSetCurrentDirectory(this->hConnect, basePath);
	FtpCreateDirectory(this->hConnect, fileTypeId);
	
	std::string buf_local(basePath);
	buf.append("/");
	buf.append(fileTypeId);
	CString b0 = buf.c_str();
	buf_local.append(b0);
	FtpSetCurrentDirectory(this->hConnect, buf_local.c_str());
	FtpCreateDirectory(this->hConnect, id);
	
	buf.append("/");
	buf.append(id);
	buf.append("/");
	buf.append(generate_random::get_random().append(".png"));
	buf_local.append(buf);

	std::string buf2(basePath);
	buf2.append("/").append(buf);
	return FtpPutFile(hConnect, lpszLocalFile, buf2.c_str(), FTP_TRANSFER_TYPE_ASCII, 0);
}

/*下载*/
BOOL UploadFile::download(_In_ LPCSTR lpszRemoteFile,_In_ LPCSTR lpszNewFile){
	return FtpGetFile(hConnect, lpszRemoteFile, lpszNewFile, FALSE, FILE_ATTRIBUTE_ARCHIVE, FTP_TRANSFER_TYPE_UNKNOWN, 0);
}

/*关闭*/
void UploadFile::Close(){
	InternetCloseHandle(hConnect);
	InternetCloseHandle(hInternet);
}