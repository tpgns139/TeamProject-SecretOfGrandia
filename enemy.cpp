#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}
HRESULT Enemy::init()
{
	return S_OK;
}

HRESULT Enemy::init(POINT pos, int FPS, float SPEED)
{
	en.x = pos.x;
	en.y = pos.y;
	en.SPEED = SPEED;

	return S_OK;
}

void Enemy::release()
{
}



void Enemy::update()
{
}

void Enemy::render()
{
}

