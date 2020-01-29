#pragma once
#include "GameObject.h"

enum EnemyState
{
	Idle,
	Run,
	Atk,
	Dmg,
	Dead,
	deadEffect
};

enum BossState
{
	Come,
	Boss_Idle,
	Heading,
	Breath,
	Stun,
	Big,
	Small

};
enum EnemyName
{
	Name_Rabbit,
	Name_Slime,
	Name_Flower,
	Name_Hydra_S, //여름
	Name_Hydra_F, //가을
	Name_Hydra_W  //겨울
};

enum direction
{
	LEFT,
	RIGHT,
	DOWN,
	UP
};

struct info
{
	RECT rc;
	RECT senseRC;
	float x, y;
	image* img;
	direction dir;
	EnemyName name;
	EnemyState state;
	BossState _BossState;
	animation* Ani;
	bool changeAni;
	int FPS;
	float SPEED;
};

class Enemy : public GameObject
{
protected:

	info en;


public:
	Enemy();
	~Enemy();
	virtual HRESULT init();
	virtual HRESULT init(POINT pos, int FPS, float SPEED);
	virtual void release();
	virtual void update();
	virtual void render();
	

};

