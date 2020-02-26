#pragma once
#include"Enemy.h"
#define KNIGHTSPEED 2.5f


class knight : public Enemy
{
private:
	bool _findPlayer;
	int _frameCount;
	vector<RECT*>	_colider;
	
public:
	knight();
	~knight();

	virtual HRESULT init(POINT pos);
	void release();
	void update();
	void render();
	void colWithWall();
	void findPlayer();
	void attackWait();
	void attackPlayer();
	void setState();
	bool findRect(RECT* rc);
	void finishAttack();
	void eraseRect(RECT *rc);

};
