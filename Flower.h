#pragma once
#include "Enemy.h"

class Flower :public Enemy
{
private:


public:
	Flower();
	~Flower();
	virtual HRESULT init(POINT pos, int FPS, float SPEED);
	virtual void release();
	virtual void update();
	virtual void render();
};
