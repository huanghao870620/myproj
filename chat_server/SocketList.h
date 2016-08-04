///////////////////////////////////////////////////////////
//  SocketList.h
//  Implementation of the Class SocketList
//  Created on:      08-七月-2016 15:46:13
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_7E4F0D70_6266_4b22_8289_C06485EE59AB__INCLUDED_)
#define EA_7E4F0D70_6266_4b22_8289_C06485EE59AB__INCLUDED_
#include<list>
#include<afxwin.h>

class SocketList
{

public:
	SocketList();
	virtual ~SocketList();

	static SocketList * getInstance();
	void add(SOCKET * socket);
	/*消息群发*/
	void messaging(char * msg);

private:
	std::list<SOCKET*> socke_list;
};
	static SocketList * instance;
#endif // !defined(EA_7E4F0D70_6266_4b22_8289_C06485EE59AB__INCLUDED_)
