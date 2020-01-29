#include "stdafx.h"
#include "Slime.h"


Slime::Slime()
{
}


Slime::~Slime()
{
}

HRESULT Slime::init(POINT pos, int FPS, float SPEED)
{

	//idle
	IMAGEMANAGER->addFrameImage("S_idle", "img/slime/idle.bmp", 400, 36, 8, 1, true, RGB(255, 0, 255));
	//Atk						
	IMAGEMANAGER->addFrameImage("S_Atk_Down", "img/slime/Atk_Down.bmp", 756, 52, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("S_Atk_Up", "img/slime/Atk_Up.bmp", 756, 52, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("S_Atk_Left", "img/slime/Atk_Left.bmp", 1044, 32, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("S_Atk_Right", "img/slime/Atk_Right.bmp", 1044, 32, 18, 1, true, RGB(255, 0, 255));
	//run						
	IMAGEMANAGER->addFrameImage("S_Run", "img/slime/Run_2.bmp", 700, 46, 14, 1, true, RGB(255, 0, 255));
	//dmg					
	IMAGEMANAGER->addFrameImage("S_Dmg", "img/slime/Dmg_Up.bmp", 108, 28, 2, 1, true, RGB(255, 0, 255));
	//dead
	IMAGEMANAGER->addFrameImage("S_dead", "img/slime/S_dead.bmp", 954, 58, 9, 1, true, RGB(255, 0, 255));


	//idle
	int Slime_Idle[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("S_idle", "S_idle", Slime_Idle, 8, FPS, true);
	//Atk
	int Slime_Atk_Left[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };
	KEYANIMANAGER->addArrayFrameAnimation("S_Atk_Left", "S_Atk_Left", Slime_Atk_Left, 18, FPS, true);
	int Slime_Atk_Right[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };
	KEYANIMANAGER->addArrayFrameAnimation("S_Atk_Right", "S_Atk_Right", Slime_Atk_Right, 18, FPS, true);
	int Slime_Atk_Down[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };
	KEYANIMANAGER->addArrayFrameAnimation("S_Atk_Down", "S_Atk_Down", Slime_Atk_Down, 18, FPS, true);
	int Slime_Atk_Up[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };
	KEYANIMANAGER->addArrayFrameAnimation("S_Atk_Up", "S_Atk_Up", Slime_Atk_Up, 18, FPS, true);
	//run
	int Slime_Run[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13 };
	KEYANIMANAGER->addArrayFrameAnimation("S_Run", "S_Run", Slime_Run, 14, FPS, true);
	//dmg					
	int Slime_Dmg[] = { 0,1 };
	KEYANIMANAGER->addArrayFrameAnimation("S_Dmg", "S_Dmg", Slime_Dmg, 2, FPS, true);
	//Dead
	int Slime_Dead[] = { 0,1,2,3,4,5,6,7,8 };
	KEYANIMANAGER->addArrayFrameAnimation("S_dead", "S_dead", Slime_Dead, 9, FPS, true);






	en.name = Name_Slime;

	Enemy::init(pos, FPS, SPEED);


	en.img = IMAGEMANAGER->findImage("S_idle");
	en.Ani = KEYANIMANAGER->findAnimation("S_idle");
	en.changeAni = true;
	en.Ani->start();

	return S_OK;
}

void Slime::release()
{
}

void Slime::update()
{

	en.rc = RectMakeCenter(
		en.x,
		en.y,
		en.img->getFrameWidth(),
		en.img->getFrameHeight());


}

void Slime::render()
{
	if (KEYMANAGER->isToggleKey('1'))
	{
		Rectangle(getMemDC(), en.rc);
	}
	en.img->aniRender(getMemDC(), en.rc.left, en.rc.top, en.Ani);
}
