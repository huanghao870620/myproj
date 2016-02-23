#include <string>
#include <iostream>
#include <fstream>
#include <time.h>
#include <WinSock2.h>
#include "Crawler.h"


using namespace std;

#define DEFAULT_PAGE_BUF_SIZE 1048576

#pragma comment(lib, "ws2_32.lib")

Crawler::Crawler() 
{
}

Crawler::~Crawler() 
{
}

void Crawler::getSource(char *host) {

	WSADATA wsaData;
	int err;

	err = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (err != 0){
		return;
	}

	clock_t	start, finish;
	double duration;
	start = clock();

	//char host[] = "www.sina.com.cn";
	//char host[] = "www.baidu.com";
	char bb[1000] = "GET / HTTP/1.0\r\nHost: ";
	char *request = bb;
	strcat(request, "ss1.bdstatic.com/5eN1bjq8AAUYm2zgoY3K/r/www/cache/static/protocol/https/global/js/all_async_search_2245a19e.js");

	strcat(request, "\r\nConnection: Close\r\n\r\n");
	//www.sina.com.cn
		//"\r\nConnection: Close\r\n\r\n";

	struct  hostent *hp; 
	
	hp = gethostbyname(host);
	
	if (hp == NULL){
		cout << "gethostbyname() error in GetIpByHost : " << host << endl;
		return;
	}

	struct in_addr inAddr;
	LPSTR lpAddr;
	
	lpAddr = hp->h_addr;
	memmove(&inAddr, lpAddr, 4);

	int sock, ret = 0, optval = 1;
	struct sockaddr_in sa;
	sa.sin_family = AF_INET;
	sa.sin_port = htons(80);
	sa.sin_addr.s_addr = inet_addr(inet_ntoa(inAddr));

	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	connect(sock, (SOCKADDR*)&sa, sizeof(sa));

	if (sock == -1){
		return;
	}

	if (sock == -2){
		return;
	}


	ret = send(sock, request, strlen(request), 0);

	int m_nContentLength = DEFAULT_PAGE_BUF_SIZE;

	char *pageBuf;
	//pageBuf = (char *)malloc(m_nContentLength)
	pageBuf = new char(m_nContentLength);
	memset(pageBuf, 0, m_nContentLength);

	int bytesRead = 0;

	while (ret > 0){
		ret = recv(sock, pageBuf + bytesRead, m_nContentLength - bytesRead, 0);

		if (ret > 0){
			bytesRead += ret;
		}
	}

	pageBuf[bytesRead] = '\0';

	cout << pageBuf << endl;
	free(pageBuf);
	closesocket(sock);

	WSACleanup();

	//finish = clock();

	//duration = (double)(finish - start) / CLOCKS_PER_SEC;

	//cout << "have cost" << duration << " seconds\n";
}
