///////////////////////////////////////////////////////////
//  CDBOperation.h
//  Implementation of the Class CDBOperation
//  Created on:      18-ÁùÔÂ-2016 15:10:42
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_9862B630_991D_4004_974A_9E8248E61A81__INCLUDED_)
#define EA_9862B630_991D_4004_974A_9E8248E61A81__INCLUDED_

#pragma	once
#import "C:\\Program Files\\Common Files\\System\\ado\\msado15.dll" no_namespace rename("EOF", "adoEOF") 

class CDBOperation
{

public:
	CDBOperation();
	~CDBOperation();

	bool ConnToDB(char *ConnectionString, char *UserID, char *Password);

	_RecordsetPtr ExecuteWithResSQL(const char *);

private:
	void PrintErrorInfo(_com_error &);

	_ConnectionPtr CreateConnPtr();
	_CommandPtr CreateCommPtr();
	_RecordsetPtr CreateRecsetPtr();

private:
	_ConnectionPtr m_pConnection;
	_CommandPtr m_pCommand;

};
#endif // !defined(EA_9862B630_991D_4004_974A_9E8248E61A81__INCLUDED_)
