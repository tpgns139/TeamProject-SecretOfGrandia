#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
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


Enemy::~Enemy()
{
}

void Enemy::update()
{
}

void Enemy::render()
{
}

