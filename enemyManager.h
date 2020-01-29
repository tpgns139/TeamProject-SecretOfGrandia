#pragma once
#include <vector>
#include "GameObject.h"
#include "Enemy.h"
#include "Rabbit.h"
#include "Slime.h"
#include "Flower.h"
#include "Hydra_W.h"


class EnemyManager : public GameObject
{
private:
	typedef vector<Enemy*>				vEnemy;
	typedef vector<Enemy*>::iterator	viEnemy;

private:
	vEnemy _vEm;
	viEnemy _viEm;



public:
	EnemyManager();
	~EnemyManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	void setEnemy(Enemy* enemy); //에너미 세팅



};



