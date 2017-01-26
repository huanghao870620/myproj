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

public:
	Combination();
	Combination(int pat);
	~Combination();
	Coordinates* getFirstCoor();
	void DrawCom(CDC*pDC,CBrush*brush);
	bool getIsStop();
	Coordinates getBottomCoor();

private:
	Tile *c0;
	Tile *c1;
	Tile *c2;
	Tile *c3;
	bool isStop = false;
	Screen *scre;
	std::list<Tile*> tileList;
	Coordinates *last;
	void landing(); // ½µÂä
	void init(int pat);

};
#endif // !defined(EA_32DFF089_B8A4_40b1_86E8_36519606DDFB__INCLUDED_)
