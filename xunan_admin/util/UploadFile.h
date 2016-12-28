///////////////////////////////////////////////////////////
//  UploadFile.h
//  Implementation of the Class UploadFile
//  Created on:      14-十一月-2016 19:56:37
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_88FD5E0E_6120_4bac_B100_DA61ADD05B5B__INCLUDED_)
#define EA_88FD5E0E_6120_4bac_B100_DA61ADD05B5B__INCLUDED_

#include<afxinet.h>
#include<iostream>
#include"generate_random.h"
#include"Config.h"


class UploadFile
{

public:
	UploadFile();
	virtual ~UploadFile();

public:BOOL upload(_In_ LPCSTR lpszLocalFile, std::string &buf, LPCSTR fileTypeId, LPCSTR id);/*上传*/
public:BOOL download(_In_ LPCSTR lpszRemoteFile,_In_ LPCSTR lpszNewFile);/*下载*/
public:void Close();/*关闭*/

private:HINTERNET hConnect;
private:HINTERNET hInternet;
};
#endif // !defined(EA_88FD5E0E_6120_4bac_B100_DA61ADD05B5B__INCLUDED_)
