///////////////////////////////////////////////////////////
//  CDBOperation.cpp
//  Implementation of the Class CDBOperation
//  Created on:      18-ÁùÔÂ-2016 15:10:42
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

void CDBOperation::PrintErrorInfo(_com_error &e){
	std::cout << "Error information are as follows" << std::endl;
	std::cout << "ErrorNo: " << e.Error() << std::endl;
	std::cout << "Error Message :" << e.ErrorMessage() << std::endl;
	std::cout << "Source : " << e.Source() << std::endl; 
	std::cout << "Error Description : " << e.Description() << std::endl;
}

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

_RecordsetPtr CDBOperation::CreateRecsetPtr(){
	HRESULT hr;
	_RecordsetPtr recsetPtr;
	hr = recsetPtr.CreateInstance(__uuidof(Command));
	if (FAILED(hr) == TRUE){
		return NULL;
	}
	return recsetPtr;
}
