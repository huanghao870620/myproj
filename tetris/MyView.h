///////////////////////////////////////////////////////////
//  MyView.h
//  Implementation of the Class MyView
//  Created on:      23-¾ÅÔÂ-2016 9:04:27
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_043DDCAC_9485_4585_8D96_AE7288822F71__INCLUDED_)
#define EA_043DDCAC_9485_4585_8D96_AE7288822F71__INCLUDED_
#include<iostream>
#include"Tile.h"
#include"LeftBrick.h"
#include"resource.h"
#include<afxwin.h>
#include"Dto.h"
#include"Singleton.h"
class MyView : public CView
{

public:
	MyView();
	virtual ~MyView();
protected:DECLARE_DYNCREATE(MyView)
protected:DECLARE_MESSAGE_MAP()
protected:virtual void OnDraw(CDC*pDC);
private:static const int gap = 2;
private:static const int sideLength = 20;
private: Dto *dto;
};
#endif // !defined(EA_043DDCAC_9485_4585_8D96_AE7288822F71__INCLUDED_)
