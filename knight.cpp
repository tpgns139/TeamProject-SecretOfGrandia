#include "stdafx.h"
#include "knight.h"


knight::knight()
{
}


knight::~knight()
{
}


HRESULT knight::init(POINT pos)
{
	Enemy::init(pos);
	insertEnemyImage(E_Knight, E_idle, IMAGEMANAGER->addFrameImage("EnemyKnightIdle", "img/Enemy/Knight/soldier_Idle.png", 5, 2));
	insertEnemyImage(E_Knight, E_run, IMAGEMANAGER->addFrameImage("EnemyKnightRun", "img/Enemy/Knight/soldier_Run.png", 8, 2));
	insertEnemyImage(E_Knight, E_attack, IMAGEMANAGER->addFrameImage("EnemyKnightJump", "img/Enemy/Knight/soldier_Attack.png", 5, 2));
	insertEnemyImage(E_Knight, E_Hit, IMAGEMANAGER->addFrameImage("EnemyKnightHit", "img/Enemy/Knight/soldier_Hit.png", 2, 2));
	insertEnemyImage(E_Knight, E_attackWait, IMAGEMANAGER->addFrameImage("EnemyKnightHit", "img/Enemy/Knight/attackWait.png", 1, 2));


	_bodyRect.insert(make_pair("checkPlayer", RectMakeCenter(_center.x, _center.y, 100, 100)));
	_bodyRect.insert(make_pair("attackRange", RectMakeCenter(_center.x, _center.y, 100, 100)));
	_nowDir = E_RIGHT;
	_nowPK = E_Knight;
	_nowPS = E_idle;
	_xSpeed = 0;
	_frameTerm = 5;
	_findPlayer = false;
	setEnemyImage();


	_enemyInfo.damage = 10;
	_enemyInfo.hp = 30;

	return S_OK;
}

void knight::release()
{
}

void knight::update()
{
	if (_findPlayer)
	{
		attackWait();
		setState();
		if (_nowPS == E_idle)
		{
			_nowPS = E_run;
			
		}
		if (_nowPS == E_run)
		{
			if (_nowDir == E_LEFT)
			{
				_xSpeed = -3.0f;
			}
			else
			{
				_xSpeed = 3.0f;
			}
		}
	
		if (_nowPS == E_attack)
		{
			attackPlayer();
		}
		else
		{
			finishAttack();
		}
	}
	else
	{
		
	}
	Enemy::update();
	//전체적인 렉트 크기 결정
	Enemy::setRect(PointMake(50, 120));
	//기본 공격 범위
	Enemy::setnomalAttackRange(PointMake(75, 120),_nowDir);
	if (_nowPS != E_Hit)
	{
		findPlayer();

	}
	colWithWall();
}

void knight::render()
{
	_image->frameRender(_center.x, _center.y, _currentFrame.x, _currentFrame.y, _image->getFrameWidth(), _image->getFrameHeight());
	unordered_map<string, RECT>::iterator	iRect;
	for (iRect = _bodyRect.begin(); iRect != _bodyRect.end(); iRect++)
	{
		RECT rc = iRect->second;
		RENDER->Rectangle(rc, D2D1::ColorF(D2D1::ColorF::Black));
	}
}

void knight::colWithWall()
{
	unordered_map<string, RECT>::iterator	iRect;
	if (_nowPS != p_jump)
	{
		for (iRect = _bodyRect.begin(); iRect != _bodyRect.end(); iRect++)
		{
			if (iRect->first == "bottom")
			{
				POINT point = TILEMANAGER->getIndex(PointMake((iRect->second.left + iRect->second.right) / 2, (iRect->second.bottom + iRect->second.top) / 2), TILESIZE);
				if (TILEMANAGER->getTotalTile()[point.x + point.y * 100]->getAttribute() != nonBlocking)
				{
					_flying = false;
					_ySpeed = 0;
					_center.y = TILEMANAGER->getTotalTile()[point.x + point.y * 100]->getRect().top - 35;
				}
				else
				{
					_flying = true;
				}
			}
			if (iRect->first == "rightBody")
			{
				POINT point = TILEMANAGER->getIndex(PointMake((iRect->second.left + iRect->second.right) / 2, (iRect->second.bottom + iRect->second.top) / 2), TILESIZE);
				if (TILEMANAGER->getTotalTile()[point.x + point.y * 100]->getAttribute() == notJump )
				{
					_center.x = TILEMANAGER->getTotalTile()[point.x + point.y * 100]->getRect().left - _size.x/2;
				}
			}
			if (iRect->first == "leftBody")
			{
				POINT point = TILEMANAGER->getIndex(PointMake((iRect->second.left + iRect->second.right) / 2, (iRect->second.bottom + iRect->second.top) / 2), TILESIZE);
				if (TILEMANAGER->getTotalTile()[point.x + point.y * 100]->getAttribute() == notJump)
				{
					_center.x = TILEMANAGER->getTotalTile()[point.x + point.y * 100]->getRect().right + _size.x / 2;
				}
				else if ( point.x < 0)
				{
					_center.x =  _size.x / 2;
				}
			}
		}
	}
}

void knight::findPlayer()
{

	if (PLAYERMANAGER->findPlayer("PlayerOne") != NULL)
	{
		GameObject* player = PLAYERMANAGER->findPlayer("PlayerOne");
		if (!_findPlayer)
		{
			RECT rc;
			unordered_map<string, RECT>::iterator	iRect;
			for (iRect = _bodyRect.begin(); iRect != _bodyRect.end(); iRect++)
			{
				if (iRect->first == "checkPlayer")
				{
					if (IntersectRect(&rc, player->getRect("body"), &iRect->second))
					{
						_findPlayer = true;
						break;
					}
				}
			}
		}
		else
		{
			if (_nowPS != E_attack &&
				_nowPS != E_attackWait)
			{
				if (player->getCenter().x < _center.x)
				{
					_nowDir = E_LEFT;
				}
				else
				{
					_nowDir = E_RIGHT;
				}
			}

		}
	}
}

void knight::attackWait()
{

	if (PLAYERMANAGER->findPlayer("PlayerOne") != NULL)
	{
		GameObject* player = PLAYERMANAGER->findPlayer("PlayerOne");
		RECT rc;
		unordered_map<string, RECT>::iterator	iRect;
		if (_nowPS != E_attack&&
			_nowPS!=E_Hit)
		{
			for (iRect = _bodyRect.begin(); iRect != _bodyRect.end(); iRect++)
			{
				if (iRect->first == "attackRange")
				{
					if (IntersectRect(&rc, player->getRect("body"), &iRect->second))
					{
						_nowPS = E_attackWait;
						_xSpeed = 0;
						break;
					}
				}
			}
		}
	}
}

void knight::attackPlayer()
{
	if (PLAYERMANAGER->findPlayer("PlayerOne") != NULL)
	{
		GameObject* player = PLAYERMANAGER->findPlayer("PlayerOne");
		RECT rc;
		unordered_map<string, RECT>::iterator	iRect;
		for (iRect = _bodyRect.begin(); iRect != _bodyRect.end(); iRect++)
		{
			if (iRect->first == "attackRange")
			{
				if (IntersectRect(&rc, player->getRect("body"), &iRect->second))
				{
					if (!findRect(player->getRect("body")))
					{
						cout << "attack!!" << endl;
						_colider.push_back(player->getRect("body"));
						((Player*)player)->hit(_enemyInfo.damage);
						break;
					}

				}
				else
				{
					if (findRect(player->getRect("body")))
					{
						eraseRect(player->getRect("body"));
						break;
					}
				}
			}

		}
	}
}

void knight::setState()
{
	if (_nowPS == E_attackWait)
	{
		_frameCount++;
		if (_frameCount > 50)
		{
			_nowPS = E_attack;
			if (_nowDir == E_LEFT)
			{
				_xSpeed = -2.0f;
			}
			else
			{

				_xSpeed = 2.0f;
			}
			_frameCount = 0;
		}
	}
}

bool knight::findRect(RECT* rc)
{
	vector<RECT*>::iterator		iter;
	for (iter = _colider.begin(); iter != _colider.end(); iter++)
	{
		if ((rc)==((*iter)))return true;
	}
	return false;
}

void knight::finishAttack()
{
	if (PLAYERMANAGER->findPlayer("PlayerOne") != NULL)
	{

		GameObject* player = PLAYERMANAGER->findPlayer("PlayerOne");
		if (findRect(player->getRect("body")))
		{
			eraseRect(player->getRect("body"));
		}
	}
}

void knight::eraseRect(RECT * rc)
{
	vector<RECT*>::iterator		iter;
	for (iter = _colider.begin(); iter != _colider.end(); )
	{
		if ((rc) == ((*iter)))
		{
			_colider.erase(iter);
			break;
		}
		else
		{
			iter++;
		}
	}
}







