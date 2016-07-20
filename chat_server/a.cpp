#include <afxwin.h>
#include "ConnSocket.h"
#include "DealSocket2.h"
#include "SocketList.h"

int main(){
	//_CrtSetBreakAlloc(405);
	ConnSocket *cs = new ConnSocket();
	//cs->sendMsg();
	//cs->receiveMsg();

	SOCKET * socket = cs->getSerConn();
	SocketList * sl = SocketList::getInstance();
	sl->add(socket);

	DealSocket2 * ds = new DealSocket2(cs->getSerConn());
	ds->Start();
	return 0;
}