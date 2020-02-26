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

HRESULT Enemy::init(POINT pos)
{
	_center.x = pos.x;
	_center.y = pos.y;
	_ani = new _EnemyAniMap;
	_bodyRect.insert(make_pair("body", RectMakeCenter(_center.x, _center.y, 100, 100)));
	_bodyRect.insert(make_pair("bottom", RectMakeCenter(_center.x, _center.y, 100, 100)));
	_bodyRect.insert(make_pair("rightBody", RectMakeCenter(_center.x, _center.y, 100, 100)));
	_bodyRect.insert(make_pair("leftBody", RectMakeCenter(_center.x, _center.y, 100, 100)));
	
	_elipseTime = 0.5f;
	return S_OK;
}

void Enemy::release()
{
}



void Enemy::update()
{
	_countFrameTime++;
	if (_flying)
	{
		_flyTime += _elipseTime;
	}
	else
	{
		_flyTime = 0.0f;
	}

	setEnemyImage();
	setFrameNum();

	_center.x += _xSpeed;
	_center.y += (_ySpeed*_elipseTime + (Gravity * _flyTime*_elipseTime) / 2.0f);
}

void Enemy::render()
{
}

void Enemy::insertEnemyImage(EnemyKinds enemyKinds, EnemyState enemyState, image * enemyImage)
{
	unordered_map<EnemyState, image*> ins;
	ins.insert(make_pair((enemyState), enemyImage));
	_ani->insert(make_pair(enemyKinds, ins));
}

void Enemy::setEnemyImage()
{
	if (_nowPK == _prePK && _nowPS == _prePS && _preDir == _nowDir)return;
	typedef _EnemyAniMap::iterator	mapIter;
	typedef ani::iterator							aniIter;
	pair<mapIter, mapIter>  result = _ani->equal_range(_nowPK);
	for (mapIter it = result.first; it != result.second; it++)
	{
		for (aniIter iter = it->second.begin(); iter != it->second.end(); iter++)
		{
			if (iter->first == _nowPS)
			{
				_image = iter->second;
				break;
			}
		}
	}
	_prePS = _nowPS;
	_prePK = _nowPK;
	if (_nowDir == p_right)
	{
		_currentFrame.y = 0;
		_currentFrame.x = 0;
	}
	else
	{
		_currentFrame.y = 1;

		_currentFrame.x = _image->getMaxFrameX() - 1;
	}
	
	_preDir = _nowDir;
}

void Enemy::setFrameNum()
{
	if (_preDir == p_right)
	{
		if (_countFrameTime > _frameTerm)
		{
			_currentFrame.x += 1;
			_countFrameTime = 0.0f;
		}
		if (_currentFrame.x >= _image->getMaxFrameX())
		{
			if (_nowPS == E_attack)
			{
				_nowPS = E_idle;
			}
			else if (_nowPS == E_Hit)
			{
				_image = _ani->find(_nowPK)->second.find(E_idle)->second;
				_xSpeed = 0;
				if (waitTime(5.0f))
				{
					_nowPS = E_idle;
				}
				
			}
			_currentFrame.x = 0;
		}
	}
	else
	{
		if (_countFrameTime > _frameTerm)
		{
			_currentFrame.x -= 1;
			_countFrameTime = 0.0f;
		}
		if (_currentFrame.x < 0)
		{
			if (_nowPS == E_attack)
			{
				_nowPS = E_idle;
			}
			else if (_nowPS == E_Hit)
			{
				_image = _ani->find(_nowPK)->second.find(E_idle)->second;
				_xSpeed = 0;
				if (waitTime(5.0f))
				{
					_nowPS = E_idle;
				}
			}
			_currentFrame.x = _image->getMaxFrameX()-1;
		}
	}
}

void Enemy::setRect(POINT size)
{
	unordered_map<string, RECT>::iterator	iRect;
	_size = size;
	for (iRect = _bodyRect.begin(); iRect != _bodyRect.end(); iRect++)
	{
		if (iRect->first == "body")
		{
			iRect->second = RectMakeCenter(_center.x, _center.y, size.x, size.y);
		}
		if (iRect->first == "bottom")
		{
			iRect->second = RectMakeCenter(_center.x, _center.y + (size.y)/2+1, size.x, 2);
		}
		if (iRect->first == "rightBody")
		{
			iRect->second = RectMakeCenter(_center.x + (size.x)/2+1, _center.y, 2, size.y);
		}
		if (iRect->first == "leftBody")
		{
			iRect->second = RectMakeCenter(_center.x - (size.x)/2-1, _center.y, 2, size.y);
		}
		if (iRect->first == "checkPlayer")
		{
			iRect->second = RectMakeCenter(_center.x , _center.y, size.x*10, size.y);
		}
	}
}

void Enemy::setnomalAttackRange(POINT size, direction _dir)
{
	unordered_map<string, RECT>::iterator	iRect;
	for (iRect = _bodyRect.begin(); iRect != _bodyRect.end(); iRect++)
	{
		if (iRect->first == "attackRange")
		{
			if(_dir ==E_RIGHT)
			iRect->second = RectMakeCenter(_center.x+size.x/2, _center.y, size.x, size.y);
			else
				iRect->second = RectMakeCenter(_center.x - size.x / 2, _center.y, size.x, size.y);
			break;
		}
	}
}

RECT * Enemy::getBodyRect()
{
	unordered_map<string, RECT>::iterator	iRect;
	for (iRect = _bodyRect.begin(); iRect != _bodyRect.end(); iRect++)
	{
		if (iRect->first == "body")
		{
			return &iRect->second;
			break;
		}
	}
	return nullptr;
}

void Enemy::hit(float damage)
{
	_enemyInfo.hp -= damage;
	_nowPS = E_Hit;
	if (_nowDir == E_LEFT)
	{
		_xSpeed = 5.0f;
	}
	else
	{
		_xSpeed = -5.0f;
	}
	cout << "enemyHp:" << _enemyInfo.hp << endl;
}

bool Enemy::waitTime(float time)
{
	if (_stopTime > time)
	{
		_stopTime = 0;
		return true;
	}
	else
	{
		_stopTime++;
		return false;
	}
}

