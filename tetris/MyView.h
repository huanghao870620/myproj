///////////////////////////////////////////////////////////
//  MyView.h
//  Implementation of the Class MyView
//  Created on:      23-¾ÅÔÂ-2016 9:04:27
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_043DDCAC_9485_4585_8D96_AE7288822F71__INCLUDED_)
#define EA_043DDCAC_9485_4585_8D96_AE7288822F71__INCLUDED_
#include<iostream>
#include<exception>
#include"Tile.h"
#include"LeftBrick.h"
#include"resource.h"
#include<afxwin.h>
#include"Dto.h"
#include"Singleton.h"
#include"ArrayDto.h"
#include"Adto.h"
#include "Combination.h"
#include"Random.h"

class MyView : public CView
{

public:
	MyView();
	 ~MyView();
private: Combination *com;
protected:DECLARE_DYNCREATE(MyView)
protected:DECLARE_MESSAGE_MAP()
protected:virtual void OnDraw(CDC*pDC);
private:Dto *dto;
private:ArrayDto *arrayDto;
private:Adto *adto;
private:CRect *c0;
private:CRect *c1;
private:CRect *c2;
private:CRect *rect2;

};
#endif // !defined(EA_043DDCAC_9485_4585_8D96_AE7288822F71__INCLUDED_)
