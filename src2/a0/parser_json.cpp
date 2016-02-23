#include <iostream>
#include "StruInte.h"
#include "DrawFlag.h"
#include "parser_json.h"

using namespace boost::property_tree;

parser_json::parser_json(DrawFlag * df) 
{
	this->df = df;
}

parser_json::~parser_json() 
{
}

/*�ռ���Ϣ*/
void parser_json::colle_msg(char *ptr) {
	while (this->df->getFlag()){
		;
	}

	this->msg_list.clear(); // �������Ԫ��
	this->str = ptr;
	std::stringstream ss(str);
	try{
		read_json(ss, this->pt);
	}
	catch (ptree_error & e){
		std::cout << "" << std::endl;
	}
	ptree * induf = & this->pt.get_child("industFull"); //��ҵ�б�ȫ��
	ptree * indu_d = & this->pt.get_child("industDay"); //��ҵ�б�ÿ��
	ptree * stockf = & this->pt.get_child("stockFull"); //�����б�ȫ��
	ptree * stock_d = & this->pt.get_child("stockDay"); //�����б�ÿ��
	ptree * macro_f = & this->pt.get_child("macroFull"); //����б�ȫ��
	ptree * macro_d = & this->pt.get_child("macroDay"); //����б�ÿ��
	ptree * border_f = & this->pt.get_child("borderFull"); //ȯ�̳���ȫ��
	ptree * border_d = & this->pt.get_child("borderDay"); //ȯ�̳���ÿ��
	ptree * new_f = & this->pt.get_child("newFull"); //�¹��б�ȫ��
	ptree * new_d = &this->pt.get_child("newDay"); //�¹��б�ÿ��
	ptree * stra_f = & this->pt.get_child("strategyFull"); //�����б�ȫ��
	ptree * stra_d = & this->pt.get_child("strategyDay"); //�����б�ÿ��

	std::list<ptree * > plist;
	plist.push_back(induf);
	plist.push_back(indu_d);
	plist.push_back(stockf);
	plist.push_back(stock_d);
	plist.push_back(macro_f);
	plist.push_back(macro_d);
	plist.push_back(border_f);
	plist.push_back(border_d);
	plist.push_back(new_f);
	plist.push_back(new_d);
	plist.push_back(stra_f);
	plist.push_back(stra_d);

	std::list<ptree * >::iterator iter = plist.begin();
	while (iter != plist.end())
	{
		ptree * tree = *iter;
		this->loading(tree);
		iter++;
	}
}

std::list<struct  StruInte *> * parser_json::get_msg_list(){
	return &this->msg_list;
}

/*װ��*/
void parser_json::loading(ptree * tree){
	const char * industFull = tree->data().data();

	if (strcmp("null", industFull) == 0){
	}
	else{
		const char * num = tree->get_child("num").data().data();// ���б�����
		const char * pageNum = tree->get_child("pageNum").data().data();//ҳ��
		const char * rowNum = tree->get_child("rowNum").data().data();// ����
		const char * distBet = tree->get_child("distBet").data().data();
		const char * threadState = tree->get_child("threadState").data().data();// �߳�״̬
		const char * type = tree->get_child("type").data().data(); // �б�����


		StruInte * si = new StruInte;

		if (strcmp("indust", type) == 0){ //��ҵ�б�
			type = "��ҵ�б�";
			strcpy_s(si->type, strlen(type)+1 , type);
		}
		else if (strcmp("stocks", type) == 0){ // �����б�
			type = "�����б�";
			strcpy_s(si->type, strlen(type) + 1, type);
		}
		else if (strcmp("macro", type) == 0){ // ����б�
			type = "����б�";
			strcpy_s(si->type, strlen(type)  + 1, type);
		}
		else if (strcmp("new", type) == 0){ // �¹��б�
			type = "�¹��б�";
			strcpy_s(si->type, strlen(type)  + 1, type);
		}
		else if (strcmp("strategy", type) == 0){ // �����б�
			type = "�����б�";
			strcpy_s(si->type, strlen(type)  + 1, type);
		}
		else if (strcmp("broker", type) == 0){ //ȯ�̳���
			type = "ȯ�̳���";
			strcpy_s(si->type, strlen(type)  + 1, type);
		}

		strcpy_s(si->num, strlen(num) + 1, num);
		strcpy_s(si->pageNum, strlen(pageNum) + 1, pageNum);
		strcpy_s(si->rowNum, strlen(rowNum) + 1, rowNum);
		if (strcmp("false", threadState) == 0){
			threadState = "������";
		}
		else{
			threadState = "��ֹͣ";
		}
		strcpy_s(si->threadState, strlen(threadState) + 1, threadState);

		if (strcmp("false", distBet) == 0){
			distBet = "ÿ��";
		}
		else{
			distBet = "ȫ��";
		}
		strcpy_s(si->distBet, strlen(distBet) + 1, distBet);

		this->msg_list.push_back(si);
	}
}


void parser_json::append_dist_bet(const char * distBet,  char * type){
	char * t = nullptr;
	if (strcmp("true", distBet) == 0){
		t = "ȫ��";
		strncpy(type, t, strlen(t)+1 );
	}
	else
	{
		t = "������";
		strncpy(type, t, strlen(t)+1);
	}
}

