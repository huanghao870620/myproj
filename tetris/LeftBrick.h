///////////////////////////////////////////////////////////
//  LeftBrick.h
//  Implementation of the Class LeftBrick
//  Created on:      23-����-2016 15:27:26
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_FFAE19A3_B91D_48d6_8BDB_D629A8A5C1BB__INCLUDED_)
#define EA_FFAE19A3_B91D_48d6_8BDB_D629A8A5C1BB__INCLUDED_
#include<afxwin.h>
/**
 * ���שͷ
 */
class LeftBrick
{

public:
	LeftBrick();
	virtual ~LeftBrick();
public:LeftBrick(CDC *pDC, CRect *leftBrickRect,CBrush *brush, CPen *pen);
//private:CDC *pDC;
//public:void drawBrick(); // ��ǽ
//public:void drawBack();
//private:CRect *leftBrickRect;
//private:CBrush *brush;
//private:CPen *pen;
};
#endif // !defined(EA_FFAE19A3_B91D_48d6_8BDB_D629A8A5C1BB__INCLUDED_)
