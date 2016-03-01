#ifndef CLIENT_H
#define CLIENT_H
#include <list>

class parser_json;
class ReadIniFile;
class StruInte;

class Client
{

public:
	Client();
	~Client();

	void Close();
	void Recv();
	int Send(const char *msg);
	std::list<StruInte *> * get_st();

private:
	SOCKET soc;
	SOCKADDR_IN serveraddr;
	SOCKADDR_IN clientaddr;
	std::string buf;
	char recv_buf[10000];
	WSADATA wsa;
	parser_json *pj = nullptr;
	std::list<StruInte *> *st = nullptr;
	ReadIniFile * rif = nullptr;
};



#endif
