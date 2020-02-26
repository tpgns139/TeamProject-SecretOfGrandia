#pragma once
#include "GameObject.h"
#define Gravity		5
enum EnemyState
{
	E_idle,
	E_run,
	E_attack,
	E_drop,
	E_Hit,
	E_attackWait
};
enum EnemyKinds
{
	E_Knight
};
typedef unordered_map <EnemyState, image*> ani;
typedef multimap<EnemyKinds, ani>	_EnemyAniMap;
enum direction
{
	E_LEFT,
	E_RIGHT

};
struct enemyInfo
{
	float damage;
	float hp;
};
class Enemy : public GameObject
{
protected:
	EnemyKinds _nowPK, _prePK;
	EnemyState _nowPS, _prePS;
	direction _nowDir, _preDir;
	_EnemyAniMap		*_ani;
	bool				_flying;
	float				_xSpeed, _ySpeed, _gravity, _flyTime, _elipseTime;
	int					_frameTerm;
	unordered_map<string, RECT>						_bodyRect;
	enemyInfo			_enemyInfo;
	float _countFrameTime;
	int _stopTime;
public:
	Enemy();
	~Enemy();
	virtual HRESULT init();
	virtual HRESULT init(POINT pos);
	virtual void release();
	virtual void update();
	virtual void render();
	
	void insertEnemyImage(EnemyKinds playerkinds, EnemyState playerstate, image* enemyImage);
	void setEnemyImage();
	void setFrameNum();
	void setRect(POINT size);
	void setnomalAttackRange(POINT size, direction _dir);
	RECT* getBodyRect();
	void hit(float damage);
	bool waitTime(float time);
};


