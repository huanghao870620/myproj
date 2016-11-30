///////////////////////////////////////////////////////////
//  MyView.cpp
//  Implementation of the Class MyView
//  Created on:      22-九月-2016 10:52:57
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "MyView.h"

IMPLEMENT_DYNCREATE(MyView,CView)

MyView::MyView(){
	std::cout << "视图构造" << std::endl;
}



MyView::~MyView(){

}

void MyView::OnDraw(CDC*pDC){
	/*CWnd *d0= AfxGetApp()->GetMainWnd()->GetDlgItem(IDD_DIALOG1);
	std::cout << "fsfd" << std::endl;*/
}

//
AddGoodsDlg* MyView::getAddGoodDlg(){
	return  this->pDlg;
}

BOOL MyView::OnCreate(LPCREATESTRUCT lpcs){

	return TRUE;
}

/*添加商品对话框*/
void MyView::AddGood(){
	this->pDlg = new AddGoodsDlg;
	this->pDlg->Create(IDD_DIALOG_ADD_GOODS, this);
	this->pDlg->ShowWindow(SW_SHOW);	
}

/*查看分类对话框*/
void MyView::watchClass(){
	this->watchClassDlg = new WatchClassDlg;
	this->watchClassDlg->Create(IDD_WATCH_CLASS, this);
	this->watchClassDlg->ShowWindow(SW_SHOW);
}

/*添加分类对话框*/
void MyView::AddClass(){
	this->addClassDlg = new AddClassDlg;
	this->addClassDlg->Create(IDD_ADD_CLASS, this);
	this->addClassDlg->ShowWindow(SW_SHOW);
}

/*测试对话框*/
void MyView::ShowTestDlg(){
	this->testDlg = new TestDlg;
	this->testDlg->Create(IDD_DIALOG1, this);
	this->testDlg->ShowWindow(SW_SHOW);
}

/*查看商品列表*/
void MyView::watchGoods(){
	this->listGoodsDlg = new ListGoodsDlg;
	this->listGoodsDlg->Create(IDD_DIALOG2, this);
	this->listGoodsDlg->ShowWindow(SW_SHOW);
}

/*添加品牌*/
void MyView::addBrand(){
	this->brandDlg = new AddBrandDlg;
	this->brandDlg->Create(IDD_DIALOG_ADDBRAND, this);
	this->brandDlg->ShowWindow(SW_SHOW);
}

/*添加国家*/
void MyView::addCountry(){
	this->addCountryDlg = new AddCountryDlg;
	this->addCountryDlg->Create(IDD_DIALOG_ADD_COUNTRY, this);
	this->addCountryDlg->ShowWindow(SW_SHOW);
}

BEGIN_MESSAGE_MAP(MyView, CView)
	ON_COMMAND(ID_ADD_GOOD, MyView::AddGood)/*添加商品*/
	ON_COMMAND(ID_40011, MyView::addBrand)/*添加品牌*/
	ON_COMMAND(ID_ADD_COUNTRY, MyView::addCountry)/*添加国家*/
	ON_COMMAND(ID_WATCH_CLASS, MyView::watchClass)
	ON_COMMAND(ID_ADD_CLASS, MyView::AddClass)
	ON_COMMAND(ID_TEST, MyView::ShowTestDlg)
	ON_COMMAND(ID_40010, MyView::watchGoods) /*商品列表*/
END_MESSAGE_MAP()