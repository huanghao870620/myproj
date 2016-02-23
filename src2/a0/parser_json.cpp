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

/*收集消息*/
void parser_json::colle_msg(char *ptr) {
	while (this->df->getFlag()){
		;
	}

	this->msg_list.clear(); // 清除所有元素
	this->str = ptr;
	std::stringstream ss(str);
	try{
		read_json(ss, this->pt);
	}
	catch (ptree_error & e){
		std::cout << "" << std::endl;
	}
	ptree * induf = & this->pt.get_child("industFull"); //行业研报全量
	ptree * indu_d = & this->pt.get_child("industDay"); //行业研报每日
	ptree * stockf = & this->pt.get_child("stockFull"); //个股研报全量
	ptree * stock_d = & this->pt.get_child("stockDay"); //个股研报每日
	ptree * macro_f = & this->pt.get_child("macroFull"); //宏观研报全量
	ptree * macro_d = & this->pt.get_child("macroDay"); //宏观研报每日
	ptree * border_f = & this->pt.get_child("borderFull"); //券商晨会全量
	ptree * border_d = & this->pt.get_child("borderDay"); //券商晨会每日
	ptree * new_f = & this->pt.get_child("newFull"); //新股研报全量
	ptree * new_d = &this->pt.get_child("newDay"); //新股研报每日
	ptree * stra_f = & this->pt.get_child("strategyFull"); //策略研报全量
	ptree * stra_d = & this->pt.get_child("strategyDay"); //策略研报每日

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

/*装载*/
void parser_json::loading(ptree * tree){
	const char * industFull = tree->data().data();

	if (strcmp("null", industFull) == 0){
	}
	else{
		const char * num = tree->get_child("num").data().data();// 总研报数量
		const char * pageNum = tree->get_child("pageNum").data().data();//页数
		const char * rowNum = tree->get_child("rowNum").data().data();// 行数
		const char * distBet = tree->get_child("distBet").data().data();
		const char * threadState = tree->get_child("threadState").data().data();// 线程状态
		const char * type = tree->get_child("type").data().data(); // 研报类型


		StruInte * si = new StruInte;

		if (strcmp("indust", type) == 0){ //行业研报
			type = "行业研报";
			strcpy_s(si->type, strlen(type)+1 , type);
		}
		else if (strcmp("stocks", type) == 0){ // 个股研报
			type = "个股研报";
			strcpy_s(si->type, strlen(type) + 1, type);
		}
		else if (strcmp("macro", type) == 0){ // 宏观研报
			type = "宏观研报";
			strcpy_s(si->type, strlen(type)  + 1, type);
		}
		else if (strcmp("new", type) == 0){ // 新股研报
			type = "新股研报";
			strcpy_s(si->type, strlen(type)  + 1, type);
		}
		else if (strcmp("strategy", type) == 0){ // 策略研报
			type = "策略研报";
			strcpy_s(si->type, strlen(type)  + 1, type);
		}
		else if (strcmp("broker", type) == 0){ //券商晨会
			type = "券商晨会";
			strcpy_s(si->type, strlen(type)  + 1, type);
		}

		strcpy_s(si->num, strlen(num) + 1, num);
		strcpy_s(si->pageNum, strlen(pageNum) + 1, pageNum);
		strcpy_s(si->rowNum, strlen(rowNum) + 1, rowNum);
		if (strcmp("false", threadState) == 0){
			threadState = "运行中";
		}
		else{
			threadState = "已停止";
		}
		strcpy_s(si->threadState, strlen(threadState) + 1, threadState);

		if (strcmp("false", distBet) == 0){
			distBet = "每日";
		}
		else{
			distBet = "全量";
		}
		strcpy_s(si->distBet, strlen(distBet) + 1, distBet);

		this->msg_list.push_back(si);
	}
}


void parser_json::append_dist_bet(const char * distBet,  char * type){
	char * t = nullptr;
	if (strcmp("true", distBet) == 0){
		t = "全量";
		strncpy(type, t, strlen(t)+1 );
	}
	else
	{
		t = "日增量";
		strncpy(type, t, strlen(t)+1);
	}
}

