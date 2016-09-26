///////////////////////////////////////////////////////////
//  Tile.h
//  Implementation of the Class Tile
//  Created on:      26-¾ÅÔÂ-2016 15:05:46
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_AD2AB30C_C0D8_427f_85CF_12A5020644E8__INCLUDED_)
#define EA_AD2AB30C_C0D8_427f_85CF_12A5020644E8__INCLUDED_
#include<afxwin.h>
/**
 * ´É×©
 */
class Tile
{

public:
	Tile(int x1, int x2, int y1, int y2);
	virtual ~Tile();
public:void createTile();
//private:CPen *pen;
//private:CDC*pDC;
//private:int x1, x2, y1, y2;
//private:CBrush *brush;
		//CRect brickCrect(leftBrickRect.right + gap + gap, leftBrickRect.top + gap, leftBrickRect.right + gap + gap + sideLength, leftBrickRect.top + gap + sideLength);
//private:CRect brickCrect;
		//CRect innerBrickCrect(brickCrect.left + gap * 2, brickCrect.top + gap * 2, brickCrect.right - gap * 2, brickCrect.bottom - gap * 2);
//private:CRect innerBrickCrect;
//private:COLORREF ref = RGB(0,0,0);
};
#endif // !defined(EA_AD2AB30C_C0D8_427f_85CF_12A5020644E8__INCLUDED_)
