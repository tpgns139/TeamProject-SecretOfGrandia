#pragma once
#include "Enemy.h"
class Slime :public Enemy
{
private:



public:
	Slime();
	~Slime();
	virtual HRESULT init(POINT pos, int FPS, float SPEED);
	virtual void release();
	virtual void update();
	virtual void render();
};

