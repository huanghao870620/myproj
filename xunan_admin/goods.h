///////////////////////////////////////////////////////////
//  goods.h
//  Implementation of the Class goods
//  Created on:      08-十一月-2016 16:02:44
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_67AE9961_74CF_4477_83B9_4D93D128056D__INCLUDED_)
#define EA_67AE9961_74CF_4477_83B9_4D93D128056D__INCLUDED_
#include <memory>   // std::auto_ptr
#include <iostream>
#include <odb/database.hxx>
#include <odb/transaction.hxx>

#include<odb/mysql/database.hxx>

#include<string>
#include<odb\core.hxx>


#pragma db object
class goods
{

public:goods();
public:goods(const std::string&name,
	const std::string&info, 
	const long&capacity) 
	: name_(name),info_(info),capacity_(capacity){
}
public:virtual ~goods();
//
private:friend class odb::access;
#pragma db id auto
private: unsigned long id_;
public:void set_id(long id){
	this->id_ = id;
}
public:long get_id(){
	return this->id_;
}

#pragma db get(name_) set(name_)
private:std::string name_; //百货名称
public:void set_name(std::string&name){
	this->name_ = name;
}
public:std::string&get_name(){
	return this->name_;
}

private:std::string info_; //描述
public:void set_info(std::string&info){
	this->info_ = info;
}
public:std::string&get_info(){
	return this->info_;
}

private:long capacity_; //容量
public:void set_capacity(long capacity){
	this->capacity_ = capacity;
}
public:long get_capacity(){
	return this->capacity_;
}

private:long lowest_price_; //最低价
public:void set_lowest_price(long lowest_price){
	this->lowest_price_ = lowest_price;
}
public:long get_lowest_price(){
	return this->lowest_price_;
}

private:long highest_price_; //最高价
public:void set_highestPrice(long highest_price){
	this->highest_price_ = highest_price;
}
public:long get_highest_price(){
	return this->highest_price_;
}
private:std::string purchasing_position_; //采购位置
public:void set_purchasing_position(std::string& purchasing_position){
	this->purchasing_position_ = purchasing_position;
}
public:std::string& get_purchasing_position(){
	return this->purchasing_position_;
}
private:std::string date_of_production_; //生产日期
public:void set_date_of_production(std::string& date_of_production){
	this->date_of_production_ = date_of_production;
}
public:std::string& get_dateOfProduction(){
	return this->date_of_production_;
}
private:std::string bar_code_; //条形码
public:void set_barCode(std::string& barCode){
	this->bar_code_ = barCode;
}
public:std::string& get_barCode(){
	return this->bar_code_;
}
private:std::string speed_awb_;//  速运单号
public:void set_speedAwb(std::string& speedAwb){
	this->speed_awb_ = speedAwb;
}
public:std::string& get_speedAwb(){
	return this->speed_awb_;
}
private:long goods_according_to_positive_; //商品正面照
public:void set_goodsAccordingToPositive(long goodsAccordingToPositive){
	this->goods_according_to_positive_ = goodsAccordingToPositive;
}
public:long get_goodsAccordingToPositive(){
	return this->goods_according_to_positive_;
}

private:long back_goods_according_to_; //商品背面照
public:void set_backGoodsAccordingTo(long backGoodsAccordingTo){
	this->back_goods_according_to_ = backGoodsAccordingTo;
}
public:long get_backGoodsAccording(){
	return this->back_goods_according_to_;
}
private:long product_profile_; //商品侧面照
public:void set_productProfile(long productProfile){
	this->product_profile_ = productProfile;
}	   
public:long get_productProfile(){
	return this->product_profile_;
}
private:long goods_invoice_; //商品发票
public:void set_goodsInvoice(long goodsInvoice){
	this->goods_invoice_ = goodsInvoice;
}
public:long get_goodsInvoice(){
	return this->goods_invoice_;
}
private:long express_single_; //快递单
public:void set_expressSingle(long expressSingle){
	this->express_single_ = expressSingle;
}
public:long get_expressSingle(){
	return this->express_single_;
}
private:int state; //状态
public:void set_state(int state){
	this->state = state;
}
	   public:int get_state(){
		   return this->state;
	   }
private:std::string add_time_; //添加时间
		public:void set_addTime(std::string& addTime){
			this->add_time_ = addTime;
		}
		public:std::string& get_addTime(){
			return this->add_time_;
		}



};
#endif // !defined(EA_67AE9961_74CF_4477_83B9_4D93D128056D__INCLUDED_)
