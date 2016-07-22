///////////////////////////////////////////////////////////
//  Dto.h
//  Implementation of the Class Dto
//  Created on:      21-七月-2016 10:28:51
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_C550C720_F69C_4b2a_8F4F_65F7ECF8CF36__INCLUDED_)
#define EA_C550C720_F69C_4b2a_8F4F_65F7ECF8CF36__INCLUDED_
#include<list>
#include<afxwin.h>
class Dto
{

public:
	Dto();
	virtual ~Dto();

	void addClientSocket(SOCKET * client);
	void setServerSocket(SOCKET * serverSocket);

private:
	std::list<SOCKET *> clients; // 所有客户端
	SOCKET * serverSocket; // 服务端socket
};
#endif // !defined(EA_C550C720_F69C_4b2a_8F4F_65F7ECF8CF36__INCLUDED_)
