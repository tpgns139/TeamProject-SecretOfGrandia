#pragma once
#include <vector>
#include "gameNode.h"
#include "Enemy.h"
#include "Rabbit.h"
#include "Slime.h"
#include "Flower.h"
#include "Hydra_W.h"


class EnemyManager : public gameNode
{
private:
	typedef vector<Enemy*>				vEnemy;
	typedef vector<Enemy*>::iterator	viEnemy;

private:
	vEnemy _vEm;
	viEnemy _viEm;
	Enemy* En;



public:
	EnemyManager();
	~EnemyManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	void setEnemy(); //에너미 세팅



};



