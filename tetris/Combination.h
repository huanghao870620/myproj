///////////////////////////////////////////////////////////
//  Combination.h
//  Implementation of the Class Combination
//  Created on:      26-¾ÅÔÂ-2016 15:40:26
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_32DFF089_B8A4_40b1_86E8_36519606DDFB__INCLUDED_)
#define EA_32DFF089_B8A4_40b1_86E8_36519606DDFB__INCLUDED_
#include<list>
#include"Tile.h"
#include"Template.h"
#include"Coordinates.h"
#include"MyView.h"
#include"Singleton.h"
/**
 * ×éºÏ
 */
class Combination
{

public:
	Combination(CDC*pDC,CBrush *brush);
	virtual ~Combination();

public:Combination* getOne();
private: std::list<Tile*> tiles;
public:void DrawCom();
private:CRect *rect2;
private:CRect *c0;
private:CRect *c1;
private:CRect *c2;
private:CDC*pDC;
private:CBrush *brush;
private:std::list<CRect*> rectList;
private:void landing(); // ½µÂä

};
#endif // !defined(EA_32DFF089_B8A4_40b1_86E8_36519606DDFB__INCLUDED_)
