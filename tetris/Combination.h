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
#include"Singleton.h"
#include"Constants.h"
#include"Screen.h"
/**
 * ×éºÏ
 */
class Combination
{

public:Combination(CDC*pDC,CBrush *brush);
public: Combination();
public: ~Combination();

public:Combination* getOne();
private: std::list<Tile*> tiles;
public:void DrawCom();
private:Tile *rect2;
private:Tile *c0;
private:Tile *c1;
private:Tile *c2;
private:CDC*pDC;
private:bool isStop = false;
private:Screen *scre;
public:void setCDC(CDC*pDC);
public:void setBrush(CBrush*brush);
private:CBrush *brush;
private:std::list<Tile*> tileList;
private:Coordinates *last;
private:void landing(); // ½µÂä
private:void init();

};
#endif // !defined(EA_32DFF089_B8A4_40b1_86E8_36519606DDFB__INCLUDED_)
