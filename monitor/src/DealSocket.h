///////////////////////////////////////////////////////////
//  DealSocket.h
//  Implementation of the Class DealSocket
//  Created on:      19-ÆßÔÂ-2016 14:31:10
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_4E0708CA_5717_432e_B10F_8111FBE62866__INCLUDED_)
#define EA_4E0708CA_5717_432e_B10F_8111FBE62866__INCLUDED_
#include<afxwin.h>
class DealSocket
{

public:
	DealSocket(SOCKET * socket);
	virtual ~DealSocket();

private:
	SOCKET * socket;
	CWinThread * cwt;
};
#endif // !defined(EA_4E0708CA_5717_432e_B10F_8111FBE62866__INCLUDED_)
