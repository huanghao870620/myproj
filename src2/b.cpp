#define BOOST_TEST_MODULE stringtest
#include <boost/test/included/unit_test.hpp>
//#include <boost/property_tree/ptree.hpp>
//#include <boost/property_tree/json_parser.hpp>
//#include <iostream>
//#include <DataOperator.h>
//#include <ConnSocket.h>
//#include <Client.h>
//#include <test.h>
//#include <malloc.h>
//#include "Crawler.h"
//#include <MfcMulti.h>
//#include <ConnMysql.h>
//#include <DataCollection.h>
//#include <ReadIniFile.h>
//#include <InteObj.h>
#include <LoDiffeGlobal.h>
#include "vld.h"


//using namespace std;

#pragma comment(lib, "hello.lib")
#pragma comment(lib,"libmysql.lib")


BOOST_AUTO_TEST_SUITE(stringtest)

/*
BOOST_AUTO_TEST_CASE(test1){
	Crawler  cra;
	cra.getSource("ss1.bdstatic.com");
	//MessageBox(NULL, "ABC", "DEF", MB_OK);
}

BOOST_AUTO_TEST_CASE(test2){
	
	DataOperator *dataOperator = new DataOperator();
	dataOperator->insert("insert into rr_report(title) values('cccc')");
	delete dataOperator;
	dataOperator = NULL;
}

BOOST_AUTO_TEST_CASE(test3){
	ConnSocket cs;
	//cs.init();
}
*/

/*
BOOST_AUTO_TEST_CASE(test4){
	size_t a = 5;
	wchar_t *b;
	char c0[100] = { "草泥马" };
	char *str = "你好";
	int c = strlen(str) + 1;
	b =(wchar_t*) malloc(c * sizeof(wchar_t));
	mbstowcs_s(&a, b, c,str, _TRUNCATE);
	cout << "" << endl;
}

BOOST_AUTO_TEST_CASE(test5){
	const char *a = "%E8%8D%89%E6%B3%A5%E9%A9%AC";
	ConnSocket con;
	string b = con.URLDecode(a);
	cout << b << endl;
}

BOOST_AUTO_TEST_CASE(test6){
	ConnSocket con;
	const char * input = "%E8%8D%89%E6%B3%A5%E9%A9%AC";
	char *output = (char *)malloc(strlen(input) + 1);
	con.urldecode2(output, input);
	cout << output << endl;

	test t;
	t.CalOfByte(output);
}

BOOST_AUTO_TEST_CASE(test7){
	HBITMAP hBitmap;
	LoadImage(NULL, "", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

}

BOOST_AUTO_TEST_CASE(test8){
	ConnSocket cs;
	cs.sendMsg();
	cs.receiveMsg();
	cs.Close();
}


BOOST_AUTO_TEST_CASE(test9){
	const std::string file_path = "d:\\test_json.txt";
	boost::property_tree::ptree root;
	boost::property_tree::ptree items;
	boost::property_tree::ptree item1;

	item1.put("ID", "1");
	item1.put("Name", "wang");
	items.push_back(std::make_pair("1", item1));

	root.put_child("user", items);

	//boost::property_tree::write_json(file_path, root);

	std::stringstream s;
	boost::property_tree::write_json(s, root);
	std::string image_item = s.str();
	std::cout << image_item << std::endl;
	std::cout << "================================" << std::endl;
}



BOOST_AUTO_TEST_CASE(test11){
	int aa = 30;
	char c[8];
	itoa(aa, c, 10);
	std::cout << c << std::endl;
}

BOOST_AUTO_TEST_CASE(test12){

}
BOOST_AUTO_TEST_CASE(test10){
	Client client;
	client.init();
	//client.Send();
	client.Recv();
	client.Close();
}
BOOST_AUTO_TEST_CASE(test13){
//	char *p = "{\"borderDay\":null, \"borderFull\" : null, \"industDay\" : null, \"industFull\" : null, \"macroDay\" : null, \"macroFull\" : null, \"newDay\" : null, \"newFull\" : null, \"stockDay\" : null, \"stockFull\" : null, \"strategyDay\" : null, \"strategyFull\" : null}";
	char *p = "{}";
	boost::property_tree::ptree root;
	boost::property_tree::ptree items;
	boost::property_tree::read_json<boost::property_tree::ptree>(p, root);

	items = root.get_child("borderDay");
	std::cout << "33333333" << std::endl;
}

BOOST_AUTO_TEST_CASE(test14){
	std::string str = "{}";
	using namespace boost::property_tree;
	std::stringstream ss(str);
	ptree pt;
	try{
		read_json(ss, pt);
	}
	catch (ptree_error & e){
		std::cout << "" << std::endl;
	}
}

BOOST_AUTO_TEST_CASE(test15){
	char *str = "{\"borderDay\":null, \"borderFull\" : null, \"industDay\" : null, \"industFull\" : null, \"macroDay\" : null, \"macroFull\" : null, \"newDay\" : null, \"newFull\" : null, \"stockDay\" : null, \"stockFull\" : null, \"strategyDay\" : null, \"strategyFull\" : null}";
	using namespace boost::property_tree;
	std::stringstream ss(str);
	ptree pt;
	try{
		read_json(ss, pt);
	}
	catch (ptree_error & e){
		std::cout << "" << std::endl;
	}
	ptree t = pt.get_child("borderDay");
	std::cout << "" << std::endl;
}


BOOST_AUTO_TEST_CASE(test16){
	
	char *str = "{\"borderDay\":null,\"borderFull\":null,\"industDay\":null,\"industFull\":{\"num\":9800,\"pageNum\":0,\"rowNum\":5,\"threadState\":false,\"time\":{\"date\":31,\"day\":5,\"hours\":0,\"minutes\":0,\"month\":6,\"seconds\":0,\"time\":1438272000000,\"timezoneOffset\":-480,\"year\":115},\"type\":\"kjkk\"},\"macroDay\":null,\"macroFull\":null,\"newDay\":null,\"newFull\":null,\"stockDay\":null,\"stockFull\":null,\"strategyDay\":null,\"strategyFull\":null}";
	//char *str = "{\"a\":4,\"b\":6,\"time\":{\"a\":5,\"b\":6}}";
	using namespace boost::property_tree;
	std::stringstream ss(str);
	ptree pt;
	try{
		read_json(ss, pt);
	}
	catch (ptree_error & e){
		std::cout << "" << std::endl;
	}
	ptree t = pt.get_child("industFull");
	ptree t2 = pt.get_child("borderDay");
	ptree num = t.get_child("num");
	std::cout << "" << std::endl;
}

BOOST_AUTO_TEST_CASE(test17){
	MfcMulti mm;
	mm.Start();
}

BOOST_AUTO_TEST_CASE(test18){
	char *distBet = "false";
	//char type[100];
	char * type = new char[100];
	char * t = nullptr;
	char *b = "行业研报";
	if (strcmp("true", distBet) == 0){
		t = "全量";
		strncpy(type, t, strlen(t) + 1);
	}
	else
	{
		t = "日增量";
		strncpy(type, t, strlen(t) + 1);
	}

	strcat_s(type, strlen(b)+strlen(type)+1, b);
	std::cout << "" << std::endl;
}

BOOST_AUTO_TEST_CASE(test19){
	ConnMysql *cm = new ConnMysql;
	cm->init();
	delete cm;
}

BOOST_AUTO_TEST_CASE(test20){
	ConnMysql * cm = new ConnMysql;
	cm->select("select * from rr_report limit 1");
}

BOOST_AUTO_TEST_CASE(test21){
	DataCollection *dc = new DataCollection;
	dc->colle();

	std::list<char *>  * list = dc->get_fields();
	std::list<char * > ::iterator iter = list->begin();
	for (; iter != list->end(); iter++){
		char * ch = *iter;
		printf("%s", ch);
	}
}

BOOST_AUTO_TEST_CASE(test22){
	DataCollection *dc = new DataCollection;
	dc->colle_all();

	std::list<char *>  * list = dc->get_fields();
	std::list<char * > ::iterator iter = list->begin();
	for (; iter != list->end(); iter++){
		char * ch = *iter;
		printf("%s", ch);
	}
}

BOOST_AUTO_TEST_CASE(test23){
	time_t start = clock();
	time_t end = clock();
	char c[100];
	sprintf_s(c, "the running time is : %.0f\n", double(end - start) / CLOCKS_PER_SEC);
	printf("%s\n",c);
}

BOOST_AUTO_TEST_CASE(test24){
	ReadIniFile * rif = new ReadIniFile;
	rif->read();
	delete rif;
}

BOOST_AUTO_TEST_CASE(test25){
	//InteObj * io = new InteObj;
	//CString exe = "notepad.exe";
	//io->KillProcessFromName(exe);
	//delete io;
}
*/

BOOST_AUTO_TEST_CASE(test26){
	LoDiffeGlobal * ldg = new LoDiffeGlobal;
	ldg->count();
	delete ldg;
}

BOOST_AUTO_TEST_SUITE_END()