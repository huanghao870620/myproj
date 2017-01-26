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
#include"Singleton.h"
#include"ArrayDto.h"
#include"Adto.h"
#include "Combination.h"
#include"Random.h"
#include"Queue.h"
#include"StopQueue.h"

class MyView : public CView
{

public:
	MyView();
	~MyView();
	void OnMouseMove(UINT nFlags, CPoint point);

protected:
	DECLARE_DYNCREATE(MyView)
	DECLARE_MESSAGE_MAP()
	virtual void OnDraw(CDC*pDC);

private:
	int r = 15;
	int x = 0, y = 0;

};
#endif // !defined(EA_043DDCAC_9485_4585_8D96_AE7288822F71__INCLUDED_)
