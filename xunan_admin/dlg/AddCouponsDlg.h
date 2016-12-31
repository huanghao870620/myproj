///////////////////////////////////////////////////////////
//  AddCouponsDlg.h
//  Implementation of the Class AddCouponsDlg
//  Created on:      29-Ê®¶þÔÂ-2016 18:52:27
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_B0130C48_4D5A_4bba_BD1C_A717C729F1D3__INCLUDED_)
#define EA_B0130C48_4D5A_4bba_BD1C_A717C729F1D3__INCLUDED_
#include"../base_dlg/BaseCouponsDlg.h"
#include<iostream>
class AddCouponsDlg : public BaseCouponsDlg
{

public:
	AddCouponsDlg();
	virtual ~AddCouponsDlg();

protected:
	virtual BOOL OnInitDialog();

};
#endif // !defined(EA_B0130C48_4D5A_4bba_BD1C_A717C729F1D3__INCLUDED_)
