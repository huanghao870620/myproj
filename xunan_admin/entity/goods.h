///////////////////////////////////////////////////////////
//  goods.h
//  Implementation of the Class goods
//  Created on:      08-ʮһ��-2016 16:02:44
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_67AE9961_74CF_4477_83B9_4D93D128056D__INCLUDED_)
#define EA_67AE9961_74CF_4477_83B9_4D93D128056D__INCLUDED_
#include <memory>   // std::auto_ptr
#include <iostream>
#include <odb/database.hxx>
#include <odb/transaction.hxx>

//#include<odb/mysql/database.hxx>

#include<string>
#include<odb\core.hxx>


#pragma db object
class goods
{

public:
	goods();
	goods(const std::string&name,const std::string&info, const long&capacity) : name_(name),info_(info),capacity_(capacity){

	}
	virtual ~goods();

	void set_id(long id){
		this->id_ = id;
	}
	long get_id(){
		return this->id_;
	}
	void set_name(std::string&name){
		this->name_ = name;
	}
	std::string&get_name(){
		return this->name_;
	}

	void set_info(std::string&info){
		this->info_ = info;
	}

	std::string&get_info(){
		return this->info_;
	}

	void set_capacity(long capacity){
		this->capacity_ = capacity;
	}

	long get_capacity(){
		return this->capacity_;
	}

	void set_lowest_price(float lowest_price){
		this->lowest_price_ = lowest_price;
	}
	float get_lowest_price(){
		return this->lowest_price_;
	}

	void set_highestPrice(float highest_price){
		this->highest_price_ = highest_price;
	}
	float get_highest_price(){
		return this->highest_price_;
	}

	void set_price(float price){
		this->price_ = price;
	}
	float get_price(){
		return this->price_;
	}

	void set_purchasing_position(std::string& purchasing_position){
		this->purchasing_position_ = purchasing_position;
	}
	std::string& get_purchasing_position(){
		return this->purchasing_position_;
	}

	void set_date_of_production(std::string& date_of_production){
		this->date_of_production_ = date_of_production;
	}
	std::string& get_dateOfProduction(){
		return this->date_of_production_;
	}

	void set_barCode(std::string& barCode){
		this->bar_code_ = barCode;
	}
	std::string& get_barCode(){
		return this->bar_code_;
	}

	void set_speedAwb(std::string& speedAwb){
		this->speed_awb_ = speedAwb;
	}
	std::string& get_speedAwb(){
		return this->speed_awb_;
	}

	void set_goodsAccordingToPositive(long goodsAccordingToPositive){
		this->goods_according_to_positive_ = goodsAccordingToPositive;
	}
	long get_goodsAccordingToPositive(){
		return this->goods_according_to_positive_;
	}

	void set_left_photo(long left_photo){
		this->left_photo_ = left_photo;
	}
	long get_left_photo(){
		return this->left_photo_;
	}

	void set_right_photo(long right_photo){
		this->right_photo_ = right_photo;
	}
	long  get_right_photo(){
		return this->right_photo_;
	}

	void set_goodsInvoice(long goodsInvoice){
		this->goods_invoice_ = goodsInvoice;
	}
	long get_goodsInvoice(){
		return this->goods_invoice_;
	}

	void set_expressSingle(long expressSingle){
		this->express_single_ = expressSingle;
	}
	long get_expressSingle(){
		return this->express_single_;
	}

	void set_state(int state){
		this->state = state;
	}
	int get_state(){
		return this->state;
	}

	void set_addTime(std::string& addTime){
		this->add_time_ = addTime;
	}
	std::string& get_addTime(){
		return this->add_time_;
	}

	void set_classid(long classid){
		this->classid_ = classid;
	}
	long get_classid(){
		return this->classid_;
	}

	void set_adv_pic(long adv_pic){
		this->adv_pic_ = adv_pic;
	}
	long get_adv_pic(){
		return this->adv_pic_;
	}

private:
	friend class odb::access;
	#pragma db id auto
	unsigned long id_;
	#pragma db get(name_) set(name_)
	std::string name_; //�ٻ�����
	std::string info_; //����
	long capacity_; //����
	float lowest_price_; //��ͼ�
	float highest_price_; //��߼�
	float price_ = 0.0f ; /*��Ʒʵ�ʼ۸�*/
	std::string purchasing_position_; //�ɹ�λ��
	std::string date_of_production_; //��������
	std::string bar_code_; //������
	std::string speed_awb_;//  ���˵���
	long goods_according_to_positive_; //��Ʒ����ͼ
	long left_photo_;//��Ʒ�����ͼ
	long right_photo_;//��Ʒ�Ҳ���ͼ
	long goods_invoice_; //��Ʒ��Ʊ
	long express_single_; //��ݵ�
	int state; //״̬
	std::string add_time_; //���ʱ��
	long classid_;//����id
	long adv_pic_;//���ͼ	   
};
#endif // !defined(EA_67AE9961_74CF_4477_83B9_4D93D128056D__INCLUDED_)
