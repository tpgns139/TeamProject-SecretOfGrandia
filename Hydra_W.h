#pragma once
#include "Enemy.h"
#define EA 6
#define TAIL_SPEED 20
#define HEAD_SPEED 3


struct bodyInfo
{
	RECT rc;
	float x, y;
	image* bodyImg;
	animation* BodyAni;

	float Hdis;
	float Hang;
};

class Hydra_W :public Enemy
{

private:

	float ang;

	int count;
	int set;
	int gap[2];

	bool _isAttack;
	bodyInfo body[EA];

public:
	Hydra_W();
	~Hydra_W();
	virtual HRESULT init(POINT pos, int FPS, float SPEED);
	virtual void release();
	virtual void update();
	virtual void render();
};

