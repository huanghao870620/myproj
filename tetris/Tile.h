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
public:Tile();
public:virtual ~Tile();
public:void createTile();
private:CPen *pen;
private:CDC*pDC;
private:int x1, x2, y1, y2;
private:CBrush *brush;
private:CRect brickCrect;
private:CRect innerBrickCrect;
private:COLORREF ref = RGB(0,0,0);
public:int getX1();
public:int getX2();
public:int getY1();
public:int getY2();
public:void setX1(int x1);
public:void setX2(int x2);
public:void setY1(int y1);
public:void setY2(int y2);
};
#endif // !defined(EA_AD2AB30C_C0D8_427f_85CF_12A5020644E8__INCLUDED_)
