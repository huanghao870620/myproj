#include <afxwin.h>
#include "ConnSocket.h"
#include "DealSocket2.h"
#include "SocketList.h"

int main(){
	//_CrtSetBreakAlloc(405);
	ConnSocket *cs = new ConnSocket();
	//cs->sendMsg();
	//cs->receiveMsg();

	SOCKET * sock = cs->getSerConn();
	SocketList * sl = SocketList::getInstance();
	sl->add(sock);

	DealSocket2 * ds = new DealSocket2(sock);
	ds->Start();
	return 0;
}