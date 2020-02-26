#pragma once
#include <vector>
#include "Enemy.h"
#include "Rabbit.h"
#include "Slime.h"
#include "Flower.h"
#include "Hydra_W.h"
#include"singletonBase.h"

class EnemyManager:public singletonBase<EnemyManager>
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
	void setEnemy(Enemy* enemy); //에너미 세팅
	void eraseEnemy(int idx);
	vector<Enemy*>getEnemy() { return _vEm; }

};





