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


void EnemyManager::setEnemy(Enemy* enemy)
{
	_vEm.push_back(enemy);
}

void EnemyManager::eraseEnemy(int idx)
{
}

