#include "stdafx.h"
#include "Player.h"
#include"BasicScene.h"
Player::Player()
{
}


Player::~Player()
{
}

void Player::Start()
{

}

HRESULT Player::init()
{
	_nowPS =_prePS= p_idle;
	_nowPK=_prePK = p_HeadnotWeapon;
	_nowDir = _preDir = p_right;

	_frame = G_Frame;
	_currentFrame.x = 0;
	_currentFrame.y = 0;
	_size.x = 160;
	_size.y = 119;
	_gravity = 5;
	_playerInfo.damage = 10;
	_center.x = 300;
	_center.y = 1500;

	_playerInfo._hp = 100;


	_jumpCount = 0;
	_downKey = false;
	_flying = false;
	_xSpeed = 0;
	_ySpeed = 0;


	//머리통 추가
	_playerHead = new SkulHead(-500,-500);
	_playerHead->init();
	((BasicScene*)SCENEMANAGER->getCurrentScene())->settingObj(_playerHead);
	

	setSkillCoolTime(p_dashSkill, 10.0f);
	setSkillCoolTime(p_nomalASkill, 20.0f);
	setSkillCoolTime(p_securityASkill, 20.0f);

	_bodyRect.insert(make_pair("body", RectMakeCenter(_center.x, _center.y, 100, 100)));
	_bodyRect.insert(make_pair("bottom", RectMakeCenter(_center.x, _center.y, 100, 100)));
	_bodyRect.insert(make_pair("rightBody", RectMakeCenter(_center.x, _center.y, 100, 100)));
	_bodyRect.insert(make_pair("leftBody", RectMakeCenter(_center.x, _center.y, 100, 100)));
	_bodyRect.insert(make_pair("normalAttack", RectMakeCenter(_center.x, _center.y, 100, 100)));

	_playerImages = new playerKindsImage;
	
	insetPlayerImage(p_HeadnotWeapon, p_idle, IMAGEMANAGER->addFrameImage("playerHeadNotHasWeaponIdle", "img/Character/Skul/skul_Idle_NoWeapon.png", 4, 2));
	insetPlayerImage(p_HeadnotWeapon, p_run, IMAGEMANAGER->addFrameImage("playerHeadNotHasWeaponRun", "img/Character/Skul/skul_Walk_NoWeapon.png", 8, 2));
	insetPlayerImage(p_HeadnotWeapon, p_jump, IMAGEMANAGER->addFrameImage("playerHeadNotHasWeaponJump", "img/Character/Skul/skul_Jump.png", 2, 2));
	insetPlayerImage(p_HeadnotWeapon, p_drop, IMAGEMANAGER->addFrameImage("playerHeadNotHasWeaponDrop", "img/Character/Skul/skul_Fall.png", 5, 2));
	insetPlayerImage(p_HeadnotWeapon, p_dash, IMAGEMANAGER->addFrameImage("playerHeadNotHasWeaponDash", "img/Character/Skul/skul_Dash.png", 5, 2));
	insetPlayerImage(p_HeadnotWeapon, p_jumpdash, IMAGEMANAGER->addFrameImage("playerHeadNotHasWeaponJumpDash", "img/Character/Skul/skul_Dash.png", 5, 2));
	insetPlayerImage(p_HeadnotWeapon, p_ASkill, IMAGEMANAGER->addFrameImage("playerHeadNotHasWeaponJumpDash", "img/Character/Skul/Skul_BasicSkill.png", 4, 2));
	insetPlayerImage(p_HeadnotWeapon, p_jumpASkill, IMAGEMANAGER->addFrameImage("playerHeadNotHasWeaponJumpDash", "img/Character/Skul/Skul_BasicSkill.png", 4, 2));

	insetPlayerImage(p_HeadnotWeapon, p_idleAttack, IMAGEMANAGER->addFrameImage("playerHeadNotHasWeaponIdleAttack", "img/Character/Skul/skul_Attack.png", 5, 2));
	insetPlayerImage(p_HeadnotWeapon, p_jumpAttack, IMAGEMANAGER->addFrameImage("playerHeadNotHasWeaponJumpAttack", "img/Character/Skul/skul_Jump_Attack.png", 4, 2));


	insetPlayerImage(p_noHeadnotWeapon, p_idle, IMAGEMANAGER->addFrameImage("playerNoHeadNotHasWeaponIdle", "img/Character/Skul/skul_Idle_HaveWeapon_NoHead.png", 4, 2));
	insetPlayerImage(p_noHeadnotWeapon, p_run, IMAGEMANAGER->addFrameImage("playerNoHeadNotHasWeaponRun", "img/Character/Skul/skul_Walk_NoHead_Weapon.png", 8, 2));
	insetPlayerImage(p_noHeadnotWeapon, p_jump, IMAGEMANAGER->addFrameImage("playerNoHeadNotHasWeaponJump", "img/Character/Skul/skul_Jump_NoHead.png", 2, 2));
	insetPlayerImage(p_noHeadnotWeapon, p_drop, IMAGEMANAGER->addFrameImage("playerNoHeadNotHasWeaponDrop", "img/Character/Skul/skul_Fall_NoHead.png", 5, 2));
	insetPlayerImage(p_noHeadnotWeapon, p_dash, IMAGEMANAGER->addFrameImage("playerNoHeadNotHasWeaponDash", "img/Character/Skul/skul_Dash_NoHead.png", 5, 2));
	insetPlayerImage(p_noHeadnotWeapon, p_jumpdash, IMAGEMANAGER->addFrameImage("playerNoHeadNotHasWeaponJumpDash", "img/Character/Skul/skul_Dash_NoHead.png", 5, 2));

	insetPlayerImage(p_noHeadnotWeapon, p_idleAttack, IMAGEMANAGER->addFrameImage("playerNoHeadNotHasWeaponIdleAttack", "img/Character/Skul/skul_Attack_NoHead.png", 9, 2));
	insetPlayerImage(p_noHeadnotWeapon, p_jumpAttack, IMAGEMANAGER->addFrameImage("playerNoHeadNotHasWeaponJumpAttack", "img/Character/Skul/skul_Jump_NoHead_Attack.png", 4, 2));



	insetPlayerImage(p_securityboss, p_run, IMAGEMANAGER->addFrameImage("playerHeadNotHasWeaponIdle", "img/Character/SecurityBoss/Move.png", 6, 2));
	insetPlayerImage(p_securityboss, p_idle, IMAGEMANAGER->addFrameImage("playerHeadNotHasWeaponIdle", "img/Character/SecurityBoss/Idle.png", 6, 2));
	insetPlayerImage(p_securityboss, p_idleAttack, IMAGEMANAGER->addFrameImage("playerHeadNotHasWeaponRun", "img/Character/SecurityBoss/Attack_One.png", 5, 2));
	insetPlayerImage(p_securityboss, p_idleAttackTwo, IMAGEMANAGER->addFrameImage("playerHeadNotHasWeaponJump", "img/Character/SecurityBoss/Atack_Two.png", 5, 2));
	insetPlayerImage(p_securityboss, p_idleAttackthree, IMAGEMANAGER->addFrameImage("playerHeadNotHasWeaponDrop", "img/Character/SecurityBoss/Attack_C.png", 6, 2));

	insetPlayerImage(p_securityboss, p_dash, IMAGEMANAGER->addFrameImage("playerHeadNotHasWeaponJump", "img/Character/SecurityBoss/Dash.png", 5, 2));
	insetPlayerImage(p_securityboss, p_jump, IMAGEMANAGER->addFrameImage("playerHeadNotHasWeaponDrop", "img/Character/SecurityBoss/Jump.png", 2, 2));
	insetPlayerImage(p_securityboss, p_jumpAttack, IMAGEMANAGER->addFrameImage("playerHeadNotHasWeaponJump", "img/Character/SecurityBoss/Jump_Attack.png", 5, 2));
	insetPlayerImage(p_securityboss, p_ASkill, IMAGEMANAGER->addFrameImage("playerHeadNotHasWeaponDrop", "img/Character/SecurityBoss/Skill_A.png", 22, 2));
	insetPlayerImage(p_securityboss, p_jumpASkill, IMAGEMANAGER->addFrameImage("playerHeadNotHasWeaponDrop", "img/Character/SecurityBoss/Skill_A.png", 22, 2));
	insetPlayerImage(p_securityboss, p_drop, IMAGEMANAGER->addFrameImage("playerHeadNotHasWeaponJump", "img/Character/SecurityBoss/Fall.png", 5, 2));



	_image = _playerImages->find(_nowPK)->second.find(_nowPS)->second;
	
	return S_OK;
}

void Player::update()
{
	setCoolTime();
	//지금 점프상태일때는 State를 유지해야함
	_xSpeed = 0;
	_elipseTime = 0.5f;
	_changeFrameTime++;
	if (_nowPK == p_noHeadHasWeapon || _nowPK == p_noHeadnotWeapon)
	{
		if (checkUseSkill(p_nomalASkill))
		{
			_nowPK = p_HeadnotWeapon;
			((SkulHead*)_playerHead)->resetHead();
		}
	}
	if (_nowPS == p_dash || _nowPS == p_jumpdash)
	{
		_dashTime += _elipseTime;
	}
	else
	{
		_dashTime = 0;
	}
	if (_flying)
	{
		_flyTime += _elipseTime;
		if (_ySpeed + (_gravity * _flyTime) / 2.0f > 0&&_nowPS!=p_jumpAttack&& _nowPS != p_jumpASkill)
		{
			_nowPS = p_drop;
		}
	}
	else
	{
		_flyTime = 0;
	}
	if (KEYMANAGER->isOnceKeyDown('O'))
	{
		_nowPK = p_securityboss;
	}
	
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (_nowPS == p_idle)
		{
			_nowPS = p_run;
		}
		
		if (_nowPS != p_ASkill 
			&& _nowPS != p_idleAttack && _nowPS != p_idleAttackTwo && _nowPS != p_idleAttackthree
			&&_nowPS!=p_dash && _nowPS != p_jumpdash)
		{
			_nowDir = p_left;
			_xSpeed = -5;
		}
	}
	else if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (_nowPS == p_idle)
		{
			_nowPS = p_run;
		}
		

		if (_nowPS != p_ASkill
			&& _nowPS != p_idleAttack && _nowPS != p_idleAttackTwo && _nowPS != p_idleAttackthree
			&& _nowPS != p_dash && _nowPS != p_jumpdash) 
		{
			_nowDir = p_right;
			_xSpeed = 5;
		}
	}


	if(KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		if (_nowPS ==p_run)
		{
			_nowPS = p_idle;
		}
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		if (_nowPS == p_run)
		{
			_nowPS = p_idle;
		}
	}
	
	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			_downKey = true;
		}
		if (_flying&&_jumpCount==0)
		{
			_jumpCount++;
			_ySpeed = JUMPSPEED;
			_flyTime = 0;
			_downPoint.y = -9999;
		}
		else if(!_flying)
		{
			_ySpeed = JUMPSPEED;
		
		}
		if (_nowPS != p_jumpASkill && _nowPS != p_jumpAttack) 
		{
			_nowPS = p_jump;
		}
		_flying = true;
		
	}

	//dash스킬 사용
	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		if (checkUseSkill(p_dashSkill))
		{
			if (_flying)
			{
				_nowPS = p_jumpdash;
			}
			else
			{
				_nowPS = p_dash;
			}

			_ySpeed = 0;
			_flying = false;
			useSkill(p_dashSkill);
		}
	}
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		switch (_nowPS)
		{
		case p_idle:
			_nowPS = p_idleAttack;
			break;
		case p_run:
			_nowPS = p_idleAttack;
			break;
		case p_jump:
			_nowPS = p_jumpAttack;
			break;
		case p_drop:
			_nowPS = p_jumpAttack;
			break;
		}
		_attack = true;
	}
	if (KEYMANAGER->isOnceKeyUp('X'))
	{
		_attack = false;
	}
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		switch (_nowPK)
		{
		case p_archor:
			break;
		case p_knight:
			break;
		case p_securityboss:
			if (checkUseSkill(p_securityASkill))
			{
				if (_flying)
				{
					_nowPS = p_jumpASkill;
				}
				else
				{
					_nowPS = p_ASkill;
				}
				useSkill(p_securityASkill);
				_ySpeed = 0;
				_flying = false;

			}
			break;
		default:
			if (checkUseSkill(p_nomalASkill))
			{
				if (_flying)
				{
					_nowPS = p_jumpASkill;
				}
				else
				{
					_nowPS = p_ASkill;
				}
				useSkill(p_nomalASkill);
				((SkulHead*)_playerHead)->useHeadThrow(PointMake(_center.x, _center.y - 25), _nowDir);
				_ySpeed = 0;
				_flying = false;
				
			}
			break;
		}
		
	}

	if (_nowPS == p_dash || _nowPS == p_jumpdash)
	{
		if (_nowDir == p_left)
		{
			_xSpeed = -(5+2*_dashTime);
		}
		else
		{
			_xSpeed = (5 + 2*_dashTime);
		}
	}

	//이미지 바꾸기 (State에 맞춰서)
	
	changePlayerImage();
	setcurrentFrameX();

	normalAttack();


	//위치 맞추기
	_center.x += _xSpeed;
	_center.y += (_ySpeed*_elipseTime +(_gravity * _flyTime*_elipseTime) / 2.0f);
	if (_center.x < 0)
	{
		_center.x = 0;
	}
	if (_center.y < 0)
	{
		_center.y = 0;
	}
	CAMERA->setCameraX(_center.x-WINSIZEX/2.0f);
	CAMERA->setCameraY(_center.y-(WINSIZEY/3.0f)*2.0f);
	



	//충돌로 멈추게 만들기
	colWithWall();
	setRect();
	setnomalAttackRange(PointMake(50,75), _nowDir);
}

void Player::render()
{
	_image->frameRender(_center.x, _center.y, _currentFrame.x, _currentFrame.y, _image->getFrameWidth(), _image->getFrameHeight());
	for (_bodyRectiter = _bodyRect.begin(); _bodyRectiter != _bodyRect.end(); _bodyRectiter++)
	{
		RENDER->Rectangle(_bodyRectiter->second, D2D1::ColorF(D2D1::ColorF::Black));
	}
}

void Player::insetPlayerImage(PlayerKinds playerkinds, PlayerState playerstate, image * playerimage)
{
	unordered_map<PlayerState, image*> ins;
	ins.insert(make_pair((playerstate), playerimage));
	_playerImages->insert(make_pair(playerkinds, ins));
}

void Player::changePlayerImage()
{
	if (_nowPK == _prePK && _nowPS == _prePS&&_preDir==_nowDir)return;
	typedef multimap <PlayerKinds, ani>::iterator	mapIter;
	typedef ani::iterator							aniIter;
	pair<mapIter, mapIter>  result= _playerImages->equal_range(_nowPK);
	for (mapIter it = result.first; it != result.second; it++)
	{
		for (aniIter iter = it->second.begin(); iter!=it->second.end() ; iter++)
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

		_currentFrame.x = _image->getMaxFrameX()-1;
	}
	_preDir = _nowDir;

}

void Player::setcurrentFrameX()
{
	if (_preDir == p_right)
	{
		if (_changeFrameTime > 3)
		{
			_currentFrame.x += 1;
			_changeFrameTime = 0.0f;
		}
		if (_currentFrame.x >= _image->getMaxFrameX())
		{
			if (_nowPS == p_idleAttack)
			{
				if (_attack)
				{
					switch (_nowPK)
					{
					case p_securityboss:
						_nowPS = p_idleAttackTwo;
						_center.x += 5;
						break;
					default:
						_nowPS = p_idleAttackTwo;
						break;
					}
				}
				else
				{
					_nowPS = p_idle;

				}

			}
			else if (_nowPS == p_idleAttackTwo)
			{
				if (_attack)
				{
					switch (_nowPK)
					{
					case p_securityboss:
						_nowPS = p_idleAttackthree;
						_center.x += 5;
						break;
					default:
						_nowPS = p_idle;
						break;
					}
				}
				else
				{
					_nowPS = p_idle;
				}

			}
			else if (_nowPS == p_idleAttackthree)
			{

				_nowPS = p_idle;


			}
			else if (_nowPS == p_jumpAttack)
			{
				_nowPS = p_jump;
			}
			else if (_nowPS == p_runAttack)
			{
				_nowPS = p_run;
			}
			else if (_nowPS == p_jumpdash)
			{
				_nowPS = p_drop;
				_flying = true;
			}
			else if (_nowPS == p_dash)
			{
				_nowPS = p_idle;

			}
			else if (_nowPS == p_ASkill)
			{
				if (_nowPK == p_HeadnotWeapon)
				{
					_nowPK = p_noHeadnotWeapon;
				}
				_nowPS = p_idle;
			}
			else if (_nowPS == p_jumpASkill)
			{
				if (_flying)
				{
					_nowPS = p_jump; 
					if (_nowPK == p_HeadnotWeapon)
					{
						_nowPK = p_noHeadnotWeapon;
					}

				}
				else
				{
					_nowPS = p_idle; 
					if (_nowPK == p_HeadnotWeapon)
					{
						_nowPK = p_noHeadnotWeapon;
					}

				}
				_flying = true;
			}
			_currentFrame.x = 0;
		}
	}
	else
	{
		if (_changeFrameTime > 3)
		{
			_currentFrame.x -= 1;
			_changeFrameTime = 0.0f;
		}
		if (_currentFrame.x <= 0)
		{
			if (_nowPS == p_idleAttack)
			{
				if (_attack)
				{
					switch (_nowPK)
					{
					case p_securityboss:
						_nowPS = p_idleAttackTwo;
						_center.x += 5;
						break;
						break;
					default:
						_nowPS = p_idleAttackTwo;
						break;
					}
				}
				else
				{
					_nowPS = p_idle;
				}
				
			}
			else if (_nowPS == p_idleAttackTwo)
			{
				if (_attack)
				{
					switch (_nowPK)
					{
					case p_securityboss:
						_nowPS = p_idleAttackthree;
						_center.x += 5;
						break;
					default:
						_nowPS = p_idle;
						break;
					}
				}
				else
				{
					_nowPS = p_idle;
				}

			}
			else if (_nowPS == p_idleAttackthree)
			{

				_nowPS = p_idle;
			

			}
			else if (_nowPS == p_jumpAttack)
			{
				_nowPS = p_jump;
			
			}
			else if (_nowPS == p_runAttack)
			{
				_nowPS = p_run;
			
			}
			else if (_nowPS == p_jumpdash)
			{
				_nowPS = p_drop;
				_flying = true;
			}
			else if (_nowPS == p_dash)
			{
				_nowPS = p_idle;

			}
			else if (_nowPS == p_ASkill)
			{
				_nowPS = p_idle; 
				if (_nowPK == p_HeadnotWeapon)
				{
					_nowPK = p_noHeadnotWeapon;
				}
			}
			else if (_nowPS == p_jumpASkill)
			{
				if (_flying)
				{
					_nowPS = p_jump; 
					if (_nowPK == p_HeadnotWeapon)
					{
						_nowPK = p_noHeadnotWeapon;
					}
				}
				else
				{
					_nowPS = p_idle; 
					if (_nowPK == p_HeadnotWeapon)
					{
						_nowPK = p_noHeadnotWeapon;
					}
				}
				_flying = true;
			}
			_currentFrame.x = _image->getMaxFrameX()-1;
		}
		_colider.clear();
	}
}

RECT* Player::getRect(string name)
{
	return &_bodyRect.find(name)->second;
}

void Player::setRect()
{
	unordered_map<string, RECT>::iterator	iRect;
	for (iRect = _bodyRect.begin(); iRect != _bodyRect.end(); iRect++)
	{
		if (iRect->first == "body")
		{
			iRect->second=RectMakeCenter(_center.x, _center.y, 50, 70);
		}
		if (iRect->first == "bottom")
		{
			iRect->second = RectMakeCenter(_center.x, _center.y+36, 50, 2);
		}
		if (iRect->first == "rightBody")
		{
			iRect->second = RectMakeCenter(_center.x+26, _center.y, 2, 70);
		}
		if (iRect->first == "leftBody")
		{
			iRect->second = RectMakeCenter(_center.x - 26, _center.y, 2, 70);
		}
	}
}

void Player::colWithWall()
{
	unordered_map<string, RECT>::iterator	iRect;
	if (_nowPS != p_jump)
	{
		for (iRect = _bodyRect.begin(); iRect != _bodyRect.end(); iRect++)
		{
			if (iRect->first == "bottom")
			{
				POINT point = TILEMANAGER->getIndex(PointMake((iRect->second.left + iRect->second.right) / 2, (iRect->second.bottom + iRect->second.top) / 2), TILESIZE);
				if (TILEMANAGER->getTotalTile()[point.x + point.y * 100]->getAttribute() != nonBlocking && (_downPoint.y != point.y))
				{
					_flying = false;
					_ySpeed = 0;
					if (_nowPS == p_drop || _nowPS == p_jumpAttack)
					{
						_nowPS = p_idle;
					}
					_center.y = TILEMANAGER->getTotalTile()[point.x + point.y * 100]->getRect().top - 35;
					_downPoint.y = -9999;
					_jumpCount = 0;
					_downKey = false;
				}
				else
				{
					if (_nowPS != p_jumpdash&& _nowPS != p_jumpASkill)
					{
						_flying = true;
					}
				}
			}
			if (iRect->first == "rightBody")
			{
				POINT point = TILEMANAGER->getIndex(PointMake((iRect->second.left + iRect->second.right) / 2, (iRect->second.bottom + iRect->second.top) / 2), TILESIZE);
				if (TILEMANAGER->getTotalTile()[point.x + point.y * 100]->getAttribute() == notJump&&_nowDir==p_right)
				{
					_center.x = TILEMANAGER->getTotalTile()[point.x + point.y * 100]->getRect().left - 25;
					if (_nowPS == p_dash)
					{
						_nowPS = p_idle;
					}
				}
			}
			if (iRect->first == "leftBody")
			{
				POINT point = TILEMANAGER->getIndex(PointMake((iRect->second.left + iRect->second.right) / 2, (iRect->second.bottom + iRect->second.top) / 2), TILESIZE);
				if (TILEMANAGER->getTotalTile()[point.x + point.y * 100]->getAttribute() == notJump && _nowDir == p_left)
				{
					_center.x = TILEMANAGER->getTotalTile()[point.x + point.y * 100]->getRect().right + 25;
					if (_nowPS == p_dash)
					{
						_nowPS = p_idle;
					}
				}
			}
		}
	}
	//아래 점프 할때 들어가는 부분
	else
	{
		for (iRect = _bodyRect.begin(); iRect != _bodyRect.end(); iRect++)
		{
			if (iRect->first == "bottom")
			{
				POINT point = TILEMANAGER->getIndex(PointMake((iRect->second.left + iRect->second.right) / 2, (iRect->second.bottom + iRect->second.top) / 2), TILESIZE);

				if (TILEMANAGER->getTotalTile()[point.x + point.y * 100]->getAttribute() == blocking&& _downKey)
				{
					_flying = true;
					_ySpeed = -5;
					_downPoint.y = point.y;
					_downKey = false;
				}
			}
			if (iRect->first == "rightBody")
			{
				POINT point = TILEMANAGER->getIndex(PointMake((iRect->second.left + iRect->second.right) / 2, (iRect->second.bottom + iRect->second.top) / 2), TILESIZE);
				if (TILEMANAGER->getTotalTile()[point.x + point.y * 100]->getAttribute() == notJump && _nowDir == p_right)
				{
					_center.x = TILEMANAGER->getTotalTile()[point.x + point.y * 100]->getRect().left - 25;

				}
			}
			if (iRect->first == "leftBody")
			{
				POINT point = TILEMANAGER->getIndex(PointMake((iRect->second.left + iRect->second.right) / 2, (iRect->second.bottom + iRect->second.top) / 2), TILESIZE);
				if (TILEMANAGER->getTotalTile()[point.x + point.y * 100]->getAttribute() == notJump && _nowDir == p_left)
				{
					_center.x = TILEMANAGER->getTotalTile()[point.x + point.y * 100]->getRect().right + 25;

				}
			}
		}
	}
	setRect();
}

void Player::hit(float damage)
{
	_playerInfo._hp -= damage;
	cout << _playerInfo._hp << endl;
	if (_playerInfo._hp < 0)
	{
		erasePlayer();
	}
}


bool Player::checkUseSkill(PlayerCoolTimeList name)
{
	unordered_map<PlayerCoolTimeList, p_coolTime>::iterator	cIter;

	for (cIter = _coolTimeList.begin(); cIter != _coolTimeList.end(); cIter++)
	{
		if (cIter->first == name)
		{
			return cIter->second._using;
		}
	}
	return false;
}

void Player::setCoolTime()
{
	unordered_map<PlayerCoolTimeList, p_coolTime>::iterator	cIter;

	for (cIter = _coolTimeList.begin(); cIter != _coolTimeList.end(); cIter++)
	{
		if (!cIter->second._using)
		{
			cIter->second._remainTime += TIMEMANAGER->getElapsedTime();
			if (cIter->second._remainTime >= cIter->second._coolTime)
			{
				cIter->second._remainTime = 0;
				cIter->second._using = true;
			}
		}
	}
}

void Player::setSkillCoolTime(PlayerCoolTimeList name, float coolTime)
{
	p_coolTime ins;
	ins._coolTime = coolTime;
	ins._remainTime = 0;
	ins._using = true;
	_coolTimeList.insert(make_pair(name, ins));
}

void Player::erasePlayer()
{
	PLAYERMANAGER->erasePlayer(this);
}


void Player::useSkill(PlayerCoolTimeList name)
{
	unordered_map<PlayerCoolTimeList, p_coolTime>::iterator	cIter;

	for (cIter = _coolTimeList.begin(); cIter != _coolTimeList.end(); cIter++)
	{
		if (cIter->first==name)
		{
			cIter->second._remainTime=0;
			cIter->second._using = false;

		}
	}
}

void Player::resetSkill()
{
	unordered_map<PlayerCoolTimeList, p_coolTime>::iterator	cIter;

	for (cIter = _coolTimeList.begin(); cIter != _coolTimeList.end(); cIter++)
	{
		if (cIter->first == p_nomalASkill)
		{
			cIter->second._remainTime = 0;
			cIter->second._using = true;
			_nowPK = p_HeadnotWeapon;
		}

	}
}

void Player::normalAttack()
{
	if (_nowPK == p_securityboss)
	{
		if (_nowPS == p_ASkill||
			_nowPS == p_runAttack ||
			_nowPS == p_jumpAttack ||
			_nowPS == p_idleAttack ||
			_nowPS == p_idleAttackTwo ||
			_nowPS == p_idleAttackthree ||
			_nowPS == p_runAttackTwo ||
			_nowPS == p_runAttackthree)
		{
			RECT rc;
			unordered_map<string, RECT>::iterator	iRect;

			for (int i = 0; i < ENEMYMANAGER->getEnemy().size(); i++)
			{
				for (iRect = _bodyRect.begin(); iRect != _bodyRect.end(); iRect++)
				{
					if (iRect->first == "normalAttack")
					{
						if (IntersectRect(&rc, ENEMYMANAGER->getEnemy()[i]->getBodyRect(), &iRect->second))
						{
							if (!findRect(ENEMYMANAGER->getEnemy()[i]->getBodyRect()))
							{
								_colider.push_back(ENEMYMANAGER->getEnemy()[i]->getBodyRect());
								ENEMYMANAGER->getEnemy()[i]->hit(_playerInfo.damage);
								cout << "hit" << endl;
								break;
							}
						}
						else
						{
							if (findRect(ENEMYMANAGER->getEnemy()[i]->getBodyRect()))
							{
								eraseRect(ENEMYMANAGER->getEnemy()[i]->getBodyRect());
								break;
							}
						}
					}
				}
			}
		}
	}
}

bool Player::findRect(RECT * ins)
{
	vector<RECT*>::iterator		iter;
	for (iter = _colider.begin(); iter != _colider.end(); iter++)
	{
		if ((ins) == ((*iter)))return true;
	}
	return false;
}

void Player::eraseRect(RECT * ins)
{
	vector<RECT*>::iterator		iter;
	for (iter = _colider.begin(); iter != _colider.end(); )
	{
		if ((ins) == ((*iter)))
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
void Player::setnomalAttackRange(POINT size, PlayerDirection _dir)
{
	unordered_map<string, RECT>::iterator	iRect;
	for (iRect = _bodyRect.begin(); iRect != _bodyRect.end(); iRect++)
	{
		if (iRect->first == "normalAttack")
		{
			if (_dir == E_RIGHT)
				iRect->second = RectMakeCenter(_center.x + size.x/2 , _center.y, size.x*2, size.y);
			else
				iRect->second = RectMakeCenter(_center.x - size.x/2, _center.y, size.x * 2, size.y);
			break;
		}
	}
}

void Player::finishAttack()
{
	_colider.clear();
}
