#ifndef RECVTHREAD_H
#define RECVTHREAD_H

class Client;


class RecvThread
{



    public:

        RecvThread(Client *client); 


        ~RecvThread(); 

private:
	CWinThread *pThread = nullptr;

	Client *client = nullptr;

};  //end class RecvThread



#endif
