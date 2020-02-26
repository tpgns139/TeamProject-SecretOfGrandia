#pragma once
#include"GameObject.h"
#include"SkulHead.h"
#define JUMPSPEED -25
enum PlayerKinds
{
	p_noHeadHasWeapon=0,
	p_noHeadnotWeapon,
	p_HeadHasWeapon ,
	p_HeadnotWeapon,
	p_archor,
	p_knight,
	p_securityboss
};
enum PlayerState
{
	p_idle = 0,
	p_idleAttack,
	p_idleAttackTwo,
	p_idleAttackthree,
	p_run,
	p_runAttack,
	p_runAttackTwo,
	p_runAttackthree,
	p_jumpdash,
	p_dash,
	p_jump,
	p_drop,
	p_jumpAttack,
	p_ASkill,
	p_jumpASkill
};

enum PlayerDirection
{
	p_left,
	p_right
	
};
enum PlayerCoolTimeList
{
	p_dashSkill,
	p_nomalASkill,
	p_securityASkill
};

struct p_coolTime
{
	float _remainTime;
	float _coolTime;
	bool _using;
};


struct playerInfo
{
	float _hp;
	float damage;
};
class Player:public GameObject
{
private:
	typedef unordered_map <PlayerState, image*> ani;
	typedef multimap <PlayerKinds, ani>	playerKindsImage;
	playerKindsImage*								_playerImages;
	GameObject*										_playerHead;
	unordered_map<string, RECT>						_bodyRect;
	unordered_map<string, RECT>::iterator			_bodyRectiter;
	unordered_map<PlayerCoolTimeList, p_coolTime>	_coolTimeList;

	vector<PlayerKinds>								_playerKindsList;//나중에 추가할 곳

	int												_playerKindsIndex;
	playerInfo	_playerInfo;
	PlayerKinds _nowPK,_prePK;
	PlayerState _nowPS,_prePS;
	PlayerDirection _nowDir, _preDir;



	vector<RECT*>		_colider;
	float _gravity,_flyTime,_dashTime;
	float _xSpeed, _ySpeed;

	bool _flying;
	bool _downKey,_attack;

	POINT _downPoint;
	int _jumpCount;

	float _elipseTime, _changeFrameTime;
public:
	Player();
	~Player();

	void Start();
	virtual HRESULT init();
	virtual void update();

	virtual void render();

	void insetPlayerImage(PlayerKinds playerkinds, PlayerState playerstate, image* playerimage);
	void changePlayerImage();
	void setcurrentFrameX();
	virtual RECT* getRect(string name);
	void setRect();
	void colWithWall();
	void hit(float damage);
	bool checkUseSkill(PlayerCoolTimeList name);
	void setCoolTime();

	void setSkillCoolTime(PlayerCoolTimeList name, float coolTime);

	void erasePlayer();

	void useSkill(PlayerCoolTimeList name);
	void resetSkill();


	void normalAttack();


	bool findRect(RECT* ins);
	void eraseRect(RECT *ins);
	void setnomalAttackRange(POINT size, PlayerDirection _dir);
	void finishAttack();
};

