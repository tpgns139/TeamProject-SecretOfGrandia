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

	return S_OK;
}

void EnemyManager::release()
{
}

void EnemyManager::update()
{
	KEYANIMANAGER->update();


	for (int i = 0;i < _vEm.size();i++)
	{
		_vEm[i]->update();
	}
}

void EnemyManager::setEnemy(Enemy* enemy)
{
	_vEm.push_back(enemy);
}



