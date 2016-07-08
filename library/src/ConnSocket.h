#ifndef CONNSOCKET_H
#define CONNSOCKET_H
//Begin section for file ConnSocket.h
//TODO: Add definitions that you want preserved
//End section for file ConnSocket.h




//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
class ConnSocket
{


    public:

        ConnSocket(); 

        ~ConnSocket(); 


		//发送消息
        void sendMsg();

		//接收消息
		void receiveMsg();

		void Close();

		SOCKET * getSerConn();
private:
        void init(); 

private:
		int err; // error
		WSADATA wsaData; // data
		SOCKADDR_IN addr; // 本地
		SOCKADDR_IN clientsocket; // 客户端
		char sendBuf[100]; // 发送字符串
		char receiveBuf[100]; // 接收字符串
		SOCKET serConn;
		SOCKET serSocket;

};  //end class ConnSocket



#endif
