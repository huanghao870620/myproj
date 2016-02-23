#ifndef MFCMULTI_H
#define MFCMULTI_H
#include <list>
class Client;
class CWinThread;
class RecvThread;
struct StruInte;
class DrawFlag;


class MfcMulti
{


    public:

        MfcMulti(DrawFlag * df); 
		 
        ~MfcMulti(); 

		void Start();

		std::list<struct  StruInte *> * get_st();

		Client & getClientRef();
	private:

		Client *client;
		RecvThread *recvThread = nullptr;
		std::list<struct  StruInte *> st;
		CWinThread *pThread = nullptr;
		//DrawFlag * df = nullptr;

};  //end class MfcMulti



#endif
