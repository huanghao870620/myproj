///////////////////////////////////////////////////////////
//  A0.cpp
//  Implementation of the Class A0
//  Created on:      13-¶þÔÂ-2017 20:43:27
//  Original author: admin
///////////////////////////////////////////////////////////

#include "A0.h"


A0::A0(){

}



A0::~A0(){

}

void A0::test0(){
	pcap_if_t *alldevs;
	pcap_if_t *d;
	int i = 0;
	char errbuf[PCAP_ERRBUF_SIZE];

	if (pcap_findalldevs_ex(PCAP_SRC_IF_STRING, NULL, &alldevs, errbuf) == -1){
		fprintf(stderr, "Error in pcap_findalldevs_ex: %s\n", errbuf);
		exit(1);
	}

	for (d = alldevs; d != NULL; d = d->next){
		printf("%d. %s", ++i, d->name);
		if (d->description){
			printf("(%s)\n", d->description);
		}
		else
		{
			printf("(No description available)\n");
		}
	}

	if (i == 0){
		printf("\nNo interfaces found! Make sure WinPcap is installed.\n");
		return;
	}

	pcap_freealldevs(alldevs);
}

void A0::test1(){
	pcap_if_t *alldevs;
	pcap_if_t *d;
	int inum;
	int i = 0;
	pcap_t *adhandle;
	int res;
	char errbuf[PCAP_ERRBUF_SIZE];
	tm ltime;
	char timestr[16];
	pcap_pkthdr *header;
	const u_char *pkt_data;
	time_t local_tv_sec;

	if (pcap_findalldevs_ex(PCAP_SRC_IF_STRING, NULL, &alldevs, errbuf) == -1){
		fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
		exit(1);
	}

	for (d = alldevs; d; d = d->next){
		printf("%d. %s", ++i, d->name);
		if (d->description){
			printf("(%s)\n", d->description);
		}
		else
		{
			printf("(No description available)\n");
		}
	}

	if (i == 0){
		printf("\n No interfaces found! Make sure WinPcap is installed.\n");
		return;
	}

	printf("Enter the interface number (1-%d):", i);
	scanf_s("%d", &inum);

	if (inum<1 || inum>i){
		printf("\nInterface number out of range.\n");
		pcap_freealldevs(alldevs);
		return;
	}

	for (d = alldevs, i = 0; i < inum - 1; d = d->next, i++){

	}

	if ((adhandle = pcap_open(d->name, 65536, PCAP_OPENFLAG_PROMISCUOUS, 1000, NULL, errbuf)) == NULL){
		fprintf(stderr, "\nUnable to open the adapter. %s is not supported by WinPcap\n", d->name);
		pcap_freealldevs(alldevs);
		return;
	}

	printf("\nlistening on %s...\n", d->description);
	pcap_freealldevs(alldevs);

	while ((res = pcap_next_ex(adhandle, &header, &pkt_data)) >= 0){
		if (res == 0){
			continue;
		}

		local_tv_sec = header->ts.tv_sec;
		localtime_s(&ltime, &local_tv_sec);
		strftime(timestr, sizeof timestr, "%H:%M:%S", &ltime);
		printf("%s,%.6d len:%d\n", timestr, header->ts.tv_usec, header->len);
	}

	if (res == -1){
		printf("Error reading the packets:%s\n", pcap_geterr(adhandle));
	}
}

void A0::test2(int argc, char **argv){
	pcap_if_t *alldevs, *d;
	pcap_t *fp;
	u_int inum, i = 0;
	char errbuf[PCAP_ERRBUF_SIZE];
	printf("kdump: saves the network traffic to file using WinPcap kernel-level dump faeature.\n");
	printf("\t Usage: %s [adapter] | dump_file_name max_size max_packs\n", argv[0]);
	printf("\t Where: max_size is the maximum size that the dump file will reach (0 means no limit)\n");
	printf("\t Where: max_packs is the maximum number of packets that will be saved (0 means no limit)\n\n");

	if (argc < 5){
		if (pcap_findalldevs(&alldevs, errbuf) == -1){
			fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
			exit(1);
		}

		for (d = alldevs; d; d = d->next){
			printf("%d. %s", ++i, d->name);
			if (d->description){
				printf("(%s)\n", d->description);
			}
			else
			{
				printf("(No description available)\n");
			}
		}

		if (i == 0){
			printf("\nNo interfaces found! Make sure WinPcap is installed.\n");
			return;
		}

		printf("Enter the interface number (1-%d):", i);
		scanf("%d", &inum);

		if (inum<1 || inum>i){
			printf("\nInterface number out of range.\n");
			return;
		}

		for (d = alldevs, i = 0; i < inum - 1; d = d->next, i++){
		}

		if ((fp = pcap_open_live(d->name, 100, 1, 20, errbuf)) == NULL){
			fprintf(stderr, "\nError opening adapter\n");
			return;
		}

		pcap_freealldevs(alldevs);
		
		/*if (pcap_live_dump(fp, argv[1], atoi(argv[2]), atoi(argv[3])) == -1){

		}*/

		
	}
}




void A0::test3(){
	pcap_if_t *alldevs;
	pcap_if_t*d;
	int inum;
	int i = 0;
	pcap_t *adhandle;
	char errbuf[PCAP_ERRBUF_SIZE];
	u_int netmask;
	char packet_filter[] = "ip and udp";
	bpf_program fcode;

	if (pcap_findalldevs_ex(PCAP_SRC_IF_STRING, NULL, &alldevs, errbuf) == -1){
		fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
		exit(1);
	}

	for (d = alldevs; d; d = d->next){
		printf("%d. %s", ++i, d->name);
		if (d->description){
			printf(" (%s)\n", d->description);
		}
		else
		{
			printf("(No description available)\n");
		}
	}

	if (i == 0){
		printf("\nNo intefaces found! Make sure WinPcap is installed.\n");
		return;
	}

	printf("Enter the interface number (1-%d):", i);
	scanf_s("%d", &inum);

	if (inum<1 || inum>i){
		printf("\nInterface number out of range.\n");
		pcap_freealldevs(alldevs);
		return;
	}

	for (d = alldevs, i = 0; i < inum - 1; d = d->next, i++){

	}

	if ((adhandle = pcap_open(d->name, 65536, PCAP_OPENFLAG_PROMISCUOUS, 1000, NULL, errbuf)) == NULL){
		fprintf(stderr, "\nUnable to open the adapter. %s is not supported by WinPcap\n");
		pcap_freealldevs(alldevs);
		return;
	}

	if (pcap_datalink(adhandle) != DLT_EN10MB){
		pcap_freealldevs(alldevs);
		return;
	}

	if (d->addresses != NULL){
		netmask = ((sockaddr_in*)(d->addresses->netmask))->sin_addr.S_un.S_addr;
	}
	else
	{
		netmask = 0xffffff;
	}

	if (pcap_compile(adhandle, &fcode, packet_filter, 1, netmask) < 0){
		fprintf(stderr, "\nUnable to compile the packet filter. Check the syntax.\n");
		pcap_freealldevs(alldevs);
	}

	if (pcap_setfilter(adhandle, &fcode) < 0){
		fprintf(stderr, "\nError setting the filter.\n");
		pcap_freealldevs(alldevs);
		return;
	}

	printf("\nlistening on %s...\n", d->description);
	pcap_freealldevs(alldevs);
	pcap_loop(adhandle, 0, packet_handler, NULL);
}

void packet_handler(u_char*param, const pcap_pkthdr *header, const u_char *pkt_data){
	tm ltime;
	char timestr[16];
	ip_header *ih;
	udp_header *uh;
	u_int ip_len;
	u_short sport, dport;
	time_t local_tv_sec;

	(VOID)(param);

	local_tv_sec = header->ts.tv_sec;
	localtime_s(&ltime, &local_tv_sec);
	strftime(timestr, sizeof timestr, "%H:%M:%S", &ltime);

	printf("%s.%.6d len:%d ", timestr, header->ts.tv_sec, header->len);

	ih = (ip_header*)(pkt_data + 14);
	ip_len = (ih->ver_ihl & 0xf) * 4;
	uh = (udp_header*)((u_char*)ih + ip_len);

	sport = ntohs(uh->sport);
	dport = ntohs(uh->dport);

	printf("%d.%d.%d.%d.%d -> %d.%d.%d.%d.%d\n", ih->saddr.byte1,
		ih->saddr.byte2, ih->saddr.byte3, ih->saddr.byte4, sport,
		ih->daddr.byte1, ih->daddr.byte2, ih->daddr.byte3, ih->daddr.byte4, dport);
}


void A0::test4(int argc, char**argv){
	pcap_if_t*alldevs;
	pcap_if_t *d;
	int inum;
	int i = 0;
	pcap_t *adhandle;
	char errbuf[PCAP_ERRBUF_SIZE];
	pcap_dumper_t *dumpfile;

	if (argc != 2){
		printf("usage: %s filename", argv[0]);
		return;
	}

	if (pcap_findalldevs_ex(PCAP_SRC_IF_STRING, NULL, &alldevs, errbuf) == -1){
		fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
		exit(1);
	}

	for (d = alldevs; d; d = d->next){
		printf("%d. %s", ++i, d->name);
		if (d->description){
			printf("(%s)\n", d->description);
		}
		else
		{
			printf("(No description available)\n");
		}
	}

	if (i == 0){
		printf("\nNo interfaces found! Make sure WinPcap is installed.\n");
		return;
	}

	printf("Enter the interface number (1-%d):", i);
	scanf_s("%d", &inum);

	if (inum<1 || inum>i){
		printf("\nInterface number out of range.\n");
		pcap_freealldevs(alldevs);
		return;
	}

	for (d = alldevs, i = 0; i < inum - 1; d = d->next, i++);

	if ((adhandle = pcap_open(d->name, 65536, PCAP_OPENFLAG_PROMISCUOUS, 1000, NULL, errbuf)) == NULL){
		fprintf(stderr, "\nUnable to open the adapter. %s is not supported by WinPcap\n", d->name);
		pcap_freealldevs(alldevs);
		return;
	}

	dumpfile= pcap_dump_open(adhandle, argv[1]);
	if (dumpfile == NULL){
		fprintf(stderr, "\nError opening output file\n");
		return;
	}

	printf("\nlistening on %s... Press Ctrl+C to stop...\n", d->description);
	pcap_freealldevs(alldevs);

	pcap_loop(adhandle, 0, packet_handler0, (unsigned char *)dumpfile);
}

void packet_handler0(u_char*dumpfile, const pcap_pkthdr *header, const u_char *pkt_data){
	pcap_dump(dumpfile, header, pkt_data);
}

void A0::test5(int argc, char** argv){
	pcap_t *fp;
	char errbuf[PCAP_ERRBUF_SIZE];
	char source[PCAP_BUF_SIZE];
	pcap_if_t*alldevs;
	pcap_if_t *d;
	int inum;
	int i = 0;
	if (pcap_findalldevs_ex(PCAP_SRC_IF_STRING, NULL, &alldevs, errbuf) == -1){
		fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
		exit(1);
	}

	for (d = alldevs; d; d = d->next){
		printf("%d. %s", ++i, d->name);
		if (d->description){
			printf("(%s)\n", d->description);
		}
		else
		{
			printf("(No description available)\n");
		}
	}

	if (i == 0){
		printf("\nNo interfaces found! Make sure WinPcap is installed.\n");
		return;
	}

	printf("Enter the interface number (1-%d):", i);
	scanf_s("%d", &inum);

	if (inum<1 || inum>i){
		printf("\nInterface number out of range.\n");
		pcap_freealldevs(alldevs);
		return;
	}

	for (d = alldevs, i = 0; i < inum - 1; d = d->next, i++);

	if (argc != 2){
		printf("usage: %s filename", argv[0]);
		return;
	}

	if (pcap_createsrcstr(d->name, PCAP_SRC_FILE, NULL, NULL, argv[1], errbuf) != 0){
		fprintf(stderr, "\nUnable to open the file %s.\n", source);
		return;
	}

	if ((fp = pcap_open(d->name, 65536, PCAP_OPENFLAG_PROMISCUOUS, 1000, NULL, errbuf)) == NULL){
		fprintf(stderr, "\nUnable to open the file %s.\n", source);
		return;
	}

	pcap_loop(fp, 0, dispatcher_handler, NULL);
}

void dispatcher_handler(u_char *temp1, const pcap_pkthdr *header, const u_char* pkt_data){
	u_int i = 0;
	(VOID)temp1;
	printf("%ld:%ld (%ld)\n", header->ts.tv_sec, header->ts.tv_usec, header->len);

	for (i = 1; (i < header->caplen + 1); i++){
		printf("%.2x", pkt_data[i - 1]);
		if ((i%LINE_LEN) == 0){
			printf("\n");
		}
	}
	printf("\n\n");
}


void A0::test6(int argc, char** argv){
	pcap_if_t *alldevs;
	pcap_if_t *d;
	int inum;
	int i = 0;
	pcap_t *adhandle;
	char errbuf[PCAP_ERRBUF_SIZE];
	pcap_dumper_t *dumpfile;

	if (argc != 2){
		printf("usage: %s filename", argv[0]);
		return;
	}

	if (pcap_findalldevs_ex(PCAP_SRC_IF_STRING, NULL, &alldevs, errbuf) == -1){
		fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
		exit(1);
	}

	for (d = alldevs; d; d = d->next){
		printf("%d. %s", ++i, d->name);
		if (d->description){
			printf("%s\n", d->description);
		}
		else
		{
			printf(" (No description available)\n");
		}
	}

	if (i == 0){
		printf("No interfaces found! Make sure WinPcap is installed.\n");
		return;
	}

	printf("Enter the interface number (1-%d):", i);
	scanf_s("%d", &inum);

	if (inum<1 || inum>i){
		printf("\nInterface number out of range.\n");
		pcap_freealldevs(alldevs);
		return;
	}

	for (d = alldevs, i = 0; i < inum - 1; d = d->next, i++);

	if ((adhandle = pcap_open(d->name, 65536, PCAP_OPENFLAG_PROMISCUOUS, 1000, NULL, errbuf)) == NULL){
		fprintf(stderr, "\nUnable to open the adapter. %s is not supported by WinPcap\n", d->name);
		pcap_freealldevs(alldevs);
		return;
	}

	dumpfile= pcap_dump_open(adhandle, argv[1]);
	if (dumpfile == NULL){
		fprintf(stderr, "\nError opening output file\n");
		return;
	}

	printf("\nlistening on %s... Press Ctrl+C to stop...\n", d->description);
	pcap_freealldevs(alldevs);

	pcap_loop(adhandle, 0, packet_handler, (unsigned char *)dumpfile);
}

void A0::test7(int argc, char** argv){
	pcap_t *fp;
	char errbuf[PCAP_ERRBUF_SIZE];
	char source[PCAP_BUF_SIZE];

	if (argc != 2){
		printf("usage: %s filename", argv[0]);
		return;
	}

	if (pcap_createsrcstr(source, PCAP_SRC_FILE, NULL, NULL, argv[1], errbuf) != 0){
		fprintf(stderr, "\nError creating a source string\n");
		return;
	}

	if ((fp = pcap_open(source, 65536, PCAP_OPENFLAG_PROMISCUOUS, 1000, NULL, errbuf)) == NULL){
		fprintf(stderr, "\nUnable to open the file %s.\n", source);
		return;
	}

	pcap_loop(fp, 0, dispatcher_handler0, NULL);
}

void dispatcher_handler0(u_char *temp1, const pcap_pkthdr *header, const u_char *pkt_data){
	u_int i = 0;
	(VOID)temp1;
	printf("%ld:%ld (%ld)\n", header->ts.tv_sec, header->ts.tv_usec, header->len);

	for (i = 1; (i < header->caplen + 1); i++){
		printf("%.2x", pkt_data[i - 1]);
		if ((i%LINE_LEN) == 0){
			printf("\n");
		}
	}

	printf("\n\n");
}