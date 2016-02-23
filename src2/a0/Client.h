#ifndef CLIENT_H
#define CLIENT_H
#include <list>

class parser_json;
class ReadIniFile;
class DrawFlag;

class Client
{

    public:

		Client(DrawFlag * df);

		~Client(); 

 void Close();
 void Recv();
 int Send(const char *msg);


 std::list<struct  StruInte *> * get_st();



private:
	SOCKET soc;
	SOCKADDR_IN serveraddr;
	SOCKADDR_IN clientaddr;
	char buf[1024];
	char recv_buf[10000];
	WSADATA wsa;
	parser_json *pj = nullptr;

	std::list<struct  StruInte *> *st = nullptr;

	ReadIniFile * rif = nullptr;
	DrawFlag * df = nullptr;
};  //end class Client



#endif
