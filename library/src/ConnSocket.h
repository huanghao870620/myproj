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


		//������Ϣ
        void sendMsg();

		//������Ϣ
		void receiveMsg();

		void Close();

		SOCKET * getSerConn();
private:
        void init(); 

private:
		int err; // error
		WSADATA wsaData; // data
		SOCKADDR_IN addr; // ����
		SOCKADDR_IN clientsocket; // �ͻ���
		char sendBuf[100]; // �����ַ���
		char receiveBuf[100]; // �����ַ���
		SOCKET serConn;
		SOCKET serSocket;

};  //end class ConnSocket



#endif
