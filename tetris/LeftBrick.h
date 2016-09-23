///////////////////////////////////////////////////////////
//  LeftBrick.h
//  Implementation of the Class LeftBrick
//  Created on:      23-¾ÅÔÂ-2016 15:27:26
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_FFAE19A3_B91D_48d6_8BDB_D629A8A5C1BB__INCLUDED_)
#define EA_FFAE19A3_B91D_48d6_8BDB_D629A8A5C1BB__INCLUDED_
#include<afxwin.h>
/**
 * ×ó²à×©Í·
 */
class LeftBrick
{

public:
	LeftBrick();
	virtual ~LeftBrick();
public:LeftBrick(CDC *pDC, CRect leftBrickRect);
private:CDC *pDC;
public:void drawBrick(); // »­Ç½
private:CRect leftBrickRect;
};
#endif // !defined(EA_FFAE19A3_B91D_48d6_8BDB_D629A8A5C1BB__INCLUDED_)
