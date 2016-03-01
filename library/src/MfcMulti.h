#ifndef MFCMULTI_H
#define MFCMULTI_H

#include <list>

class Client;
class CWinThread;
class RecvThread;
class StruInte;
class DrawFlag;

class MfcMulti
{
    public:
        MfcMulti(); 
        ~MfcMulti(); 
		void Start();
		std::list<StruInte *> * get_st();
		Client & getClientRef();

	private:
		Client * client;
		RecvThread *recvThread = nullptr;
		std::list<StruInte *> st;
		CWinThread *pThread = nullptr;
};  



#endif
