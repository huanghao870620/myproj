#include <afxwin.h>
#include "ConnSocket.h"
#include "DealSocket.h"

int main(){
	//_CrtSetBreakAlloc(405);
	ConnSocket *cs = new ConnSocket();
	//cs->sendMsg();
	//cs->receiveMsg();
	DealSocket * ds = new DealSocket(cs->getSerConn());
	ds->Start();
	return 0;
}