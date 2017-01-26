#pragma once
#include<vector>
#include"Combination.h"
class StopQueue
{
public:
	~StopQueue();

	void addCom(Combination com);
	std::vector<Combination>  getComs();
	void draw(CDC pDC, CBrush brush);

	static StopQueue* getStopQueue(){
		static StopQueue queue;
		return &queue;
	}
private:
	StopQueue();
	std::vector<Combination> comVector;
};

