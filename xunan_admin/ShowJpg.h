///////////////////////////////////////////////////////////
//  ShowJpg.h
//  Implementation of the Class ShowJpg
//  Created on:      17-Ê®Ò»ÔÂ-2016 17:37:31
//  Original author: burgess
///////////////////////////////////////////////////////////

#if !defined(EA_8207EE03_0362_4090_A6CC_78C6A437B3B0__INCLUDED_)
#define EA_8207EE03_0362_4090_A6CC_78C6A437B3B0__INCLUDED_

#include<afxwin.h>
#include<afxdlgs.h>
#include"charset_util.h"

class ShowJpg
{

public:
	ShowJpg();
	virtual ~ShowJpg();
public:static BOOL ShowJpg::ShowJpgGif(CDC* pDC, CString strPath, int x, int y);
public:static BOOL ShowJpg::ShowImage(CDC* pDC, CString strPath, int x, int y);
};
#endif // !defined(EA_8207EE03_0362_4090_A6CC_78C6A437B3B0__INCLUDED_)
