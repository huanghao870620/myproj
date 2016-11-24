///////////////////////////////////////////////////////////
//  Util.h
//  Implementation of the Class Util
//  Created on:      17-十一月-2016 15:16:50
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_2F110B58_39A7_489e_9866_F2AB9E36DC5D__INCLUDED_)
#define EA_2F110B58_39A7_489e_9866_F2AB9E36DC5D__INCLUDED_

#include<iostream>
#include "stdafx.h"
#include<sstream>
/**
 * 工具类
 */
class Util
{

public:
	Util();
	virtual ~Util();
public:static long stol(std::string str);
public:static std::string Util::ltos(long l);

public:static CString GetFilePathName(){
	CFileDialog filedlg(true);
	CString FilePathName;
	filedlg.m_ofn.lpstrTitle = "打开";
	filedlg.m_ofn.lpstrFilter = "Text Files(*.txt)/0*.txt/0All Files(*.*)/0*.*/0/0";
	if (IDOK == filedlg.DoModal()){
		FilePathName = filedlg.GetPathName();
	}
	return CString(FilePathName);
}
};
#endif // !defined(EA_2F110B58_39A7_489e_9866_F2AB9E36DC5D__INCLUDED_)
