#include "stdafx.h"
#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
}


EnemyManager::~EnemyManager()
{
}

HRESULT EnemyManager::init()
{
	setEnemy();
	En = new Enemy;
	En->init();

	return S_OK;
}

void EnemyManager::release()
{
	En->release();
}

void EnemyManager::update()
{
	KEYANIMANAGER->update();
	En->update();
	for (int i = 0;i < _vEm.size();i++)
	{
		_vEm[i]->update();
	}
}

void EnemyManager::render()
{
	for (int i = 0;i < _vEm.size();i++)
	{
		_vEm[i]->render();
	}
}

void EnemyManager::setEnemy()
{
	Enemy* R;
	R = new Rabbit;
	R->init(PointMake(WINSIZEX / 2, WINSIZEY / 2), 15, 0.5f);

	
	_vEm.push_back(R);

	/*Enemy* S;
	S = new Slime;
	S->init(PointMake(WINSIZEX / 2-100, WINSIZEY / 2), 10, 2);

	_vEm.push_back(S);

	Enemy* F;
	F = new Flower;
	F->init(PointMake(WINSIZEX / 2 + 100, WINSIZEY / 2), 10, 2);

	_vEm.push_back(F);*/

	/*Enemy* B_W;
	B_W = new Hydra_W;
	B_W->init(PointMake(WINSIZEX / 2, WINSIZEY / 2), 10, 2);

	_vEm.push_back(B_W);*/
}



