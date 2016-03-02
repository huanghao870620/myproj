#include "ConnMysql.h"
#include <iostream>
#include <mysql.h>
#include "rr_report.h"
#include "DataCollection.h"

DataCollection::DataCollection() 
{
}

DataCollection::~DataCollection() 
{
 	std::list<rr_report * >::iterator iter =  this->report_list.begin();
	for (; iter != this->report_list.end(); iter++){
		delete *iter;
	}
}

int DataCollection::Delete(){
	ConnMysql * conn =  ConnMysql::getInstance();
	return conn->Delete(" delete from rr_report  where id in( \
		select t4.id from(\
		select id from rr_report  where id not in(select t.id from( \
		select pdf_url, id from rr_report where pdf_url is not null) as t \
		group by t.pdf_url having count(1) = 1) \
		and id not in(select t.id from( \
		select t2.pdf_url, count(1), t2.id from \
		(select pdf_url, id from rr_report where pdf_url is not null) as t2 \
		group by pdf_url having count(1)>1) as t) \
		and id not in(select id from rr_report where pdf_url is null) \
		) as t4 \
		) \
		  ");
}

void DataCollection::colle(){
	ConnMysql * conn = ConnMysql::getInstance();
	MYSQL_RES * res = conn->select(" select id  from rr_report  where id not in (select t.id from ( \
		select pdf_url, id from rr_report where pdf_url is not null) as t  \
		group by t.pdf_url having count(1) = 1)  \
		and id not in(select t.id from(  \
		select t2.pdf_url, count(1), t2.id from \
		(select pdf_url, id from rr_report where pdf_url is not null) as t2 \
		group by pdf_url having count(1)>1) as t) \
		and id not in(select id from rr_report where pdf_url is null)  \
		");
	MYSQL_FIELD * field = nullptr;
	MYSQL_ROW row;
	while (field = mysql_fetch_field(res)){
		//std::cout << field->name << "\t" << std::endl;
	}
	
	std::size_t num = mysql_num_fields(res);
	while (row = mysql_fetch_row(res)){
		for (std::size_t i = 0; i < num; i++){
			this->fields.push_back(row[i]);
		}
	}
}

std::list<char * > * DataCollection::get_fields(){
	return  & this->fields;
}

void DataCollection::colle_all(){
	ConnMysql * conn = ConnMysql::getInstance();
	MYSQL_RES * res = conn->select(" select * from rr_report  where id not in (select t.id from ( \
				select pdf_url, id from rr_report where pdf_url is not null) as t  \
				group by t.pdf_url having count(1) = 1)  \
				and id not in(select t.id from(  \
				select t2.pdf_url, count(1), t2.id from \
				(select pdf_url, id from rr_report where pdf_url is not null) as t2 \
				group by pdf_url having count(1)>1) as t) \
				and id not in(select id from rr_report where pdf_url is null)  \
				");
	MYSQL_FIELD * field = nullptr;
	MYSQL_ROW row;
	while (field = mysql_fetch_field(res)){
		std::cout << field->name << "\t" << std::endl;
	}

	std::size_t num = mysql_num_fields(res);
	while (row = mysql_fetch_row(res)){
		rr_report * report = new rr_report;
		if (row[0] != NULL){
			report->id = row[0];
		}

		if (row[1] != NULL){
			report->tick = row[1];
		}

		if (row[2] != NULL){
			report->name = row[2];
		}

		if (row[3] != NULL){
			report->dateft = row[3];
		}

		if (row[4] != NULL){
			report->orgid = row[4];
		}

		if (row[5] != NULL){
			report->org = row[5];
		}

		if (row[6] != NULL){
			report->resname = row[6];
		}

		if (row[7] != NULL){
			report->type = row[7];
		}

		if (row[8] != NULL){
			report->title = row[8];
		}

		if (row[9] != NULL){
			report->full_abs = row[9];
		}

		if (row[10] != NULL){
			report->short_abs = row[10];
		}

		if (row[11] != NULL){
			report->price = row[11];
		}

		if (row[12] != NULL){
			report->rating = row[12];
		}

		if (row[13] != NULL){
			report->rating_change = row[13];
		}

		if (row[14] != NULL){
			report->pdf_url = row[14];
		}

		if (row[15] != NULL){
			report->pdf_size = row[15];
		}

		if (row[16] != NULL){
			report->pdf_path = row[16];
		}

		if (row[17] != NULL){
			report->timestamp = row[17];
		}

		if (row[18] != NULL){
			report->checkr = row[18];
		}

		this->report_list.push_back(report);
	}
}


std::list<rr_report * > *  DataCollection::get_report_list(){
	return  & this->report_list;
}
