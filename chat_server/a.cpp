#include <afxwin.h>
#include "ConnSocket.h"

int main(){
	ConnSocket *cs = new ConnSocket;
	//cs->sendMsg();
	cs->receiveMsg();
	return 0;
}