///////////////////////////////////////////////////////////
//  Receiver.h
//  Implementation of the Class Receiver
//  Created on:      19-����-2016 19:02:24
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_C7D6747E_1F8C_4dd1_9924_DEF5C0CB5B25__INCLUDED_)
#define EA_C7D6747E_1F8C_4dd1_9924_DEF5C0CB5B25__INCLUDED_
#include<list>
#include<afxwin.h>
/**
 * ���ն�
 */
class Receiver
{

public:
	Receiver();
	virtual ~Receiver();

private:
	std::list<SOCKET *> clients; // ����socket�ͻ���
};
#endif // !defined(EA_C7D6747E_1F8C_4dd1_9924_DEF5C0CB5B25__INCLUDED_)
