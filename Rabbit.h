#pragma once
#include"Enemy.h"
class Rabbit:public Enemy
{
	bool move;
	bool atk;
	int count;
	int Movecheck;

	RECT rc;


public:
	Rabbit();
	~Rabbit();
	virtual HRESULT init(POINT pos, int FPS, float SPEED);
	virtual void release();
	virtual void update();
	virtual void render();
	void moving();
	void attack();




	void R_state();
	void R_control();
};

