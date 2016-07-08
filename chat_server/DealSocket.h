///////////////////////////////////////////////////////////
//  DealSocket.h
//  Implementation of the Class DealSocket
//  Created on:      08-ÆßÔÂ-2016 13:53:00
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_8316CDF3_A3A6_425e_A72D_03DF36BA6C6F__INCLUDED_)
#define EA_8316CDF3_A3A6_425e_A72D_03DF36BA6C6F__INCLUDED_
#include <afxwin.h>
class DealSocket
{

public:
	DealSocket(SOCKET * socket);
	virtual ~DealSocket();
	void Start();

private:
	SOCKET * socket;
	CWinThread * cwt;
};
#endif // !defined(EA_8316CDF3_A3A6_425e_A72D_03DF36BA6C6F__INCLUDED_)
