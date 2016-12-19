///////////////////////////////////////////////////////////
//  GetHttp.h
//  Implementation of the Class GetHttp
//  Created on:      18-Ê®¶þÔÂ-2016 15:03:08
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_96EB68C6_9428_41ac_8654_B86ED2F14482__INCLUDED_)
#define EA_96EB68C6_9428_41ac_8654_B86ED2F14482__INCLUDED_
#include<afxinet.h>
#include<iostream>
class GetHttp
{

public:
	GetHttp();
	virtual ~GetHttp();
public:void download();
public:LRESULT OnRender(WPARAM wParam, LPARAM lParam);
};
#endif // !defined(EA_96EB68C6_9428_41ac_8654_B86ED2F14482__INCLUDED_)
