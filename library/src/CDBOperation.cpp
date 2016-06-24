///////////////////////////////////////////////////////////
//  CDBOperation.cpp
//  Implementation of the Class CDBOperation
//  Created on:      18-六月-2016 15:10:42
//  Original author: huang.hao
///////////////////////////////////////////////////////////
#include <iostream>
#include "CDBOperation.h"


CDBOperation::CDBOperation(){
	CoInitialize(NULL);
	this->m_pConnection = this->CreateConnPtr();
	this->m_pCommand = this->CreateCommPtr();
}



CDBOperation::~CDBOperation(){
	this->m_pConnection->Close();
}

/*执行sql*/
_RecordsetPtr CDBOperation::ExecuteWithResSQL(const char *sql){
	this->m_pCommand->CommandText = _bstr_t(sql);
	_RecordsetPtr pRst = this->m_pCommand->Execute(NULL, NULL, adCmdText);
	return pRst;
}

/*连接数据库*/
bool CDBOperation::ConnToDB(char *ConnectionString, char *UserID, char *Password){
	if (NULL == this->m_pConnection){
		std::cout << "Failed to create connection." << std::endl;
		return false;
	}

	try{
		HRESULT hr = this->m_pConnection->Open(ConnectionString, UserID, Password, NULL);
		if (TRUE == FAILED(hr)){
			return false;
		}
		this->m_pCommand->ActiveConnection = this->m_pConnection;
		return true;
	}
	catch (_com_error &e){
		this->PrintErrorInfo(e);
		return false;
	}
}

/*打印错误消息*/
void CDBOperation::PrintErrorInfo(_com_error &e){
	std::cout << "Error information are as follows" << std::endl;
	std::cout << "ErrorNo: " << e.Error() << std::endl;
	std::cout << "Error Message :" << e.ErrorMessage() << std::endl;
	std::cout << "Source : " << e.Source() << std::endl; 
	std::cout << "Error Description : " << e.Description() << std::endl;
}

/*创建连接*/
_ConnectionPtr CDBOperation::CreateConnPtr()
{
	HRESULT hr;
	_ConnectionPtr connPtr;
	hr = connPtr.CreateInstance(__uuidof(Connection));
	if (FAILED(hr) == TRUE){
		return NULL;
	}
	return connPtr;
}

/*创建命令*/
_CommandPtr CDBOperation::CreateCommPtr()
{
	HRESULT hr;
	_CommandPtr commPtr;
	hr = commPtr.CreateInstance(__uuidof(Command));
	if (FAILED(hr) == TRUE){
		return NULL;
	}
	return commPtr;
}

/*创建结果*/
_RecordsetPtr CDBOperation::CreateRecsetPtr(){
	HRESULT hr;
	_RecordsetPtr recsetPtr;
	hr = recsetPtr.CreateInstance(__uuidof(Command));
	if (FAILED(hr) == TRUE){
		return NULL;
	}
	return recsetPtr;
}
