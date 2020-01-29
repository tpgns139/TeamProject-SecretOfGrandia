#include "stdafx.h"
#include "Flower.h"


Flower::Flower()
{
}


Flower::~Flower()
{
}

HRESULT Flower::init(POINT pos, int FPS, float SPEED)
{

	//idle
	IMAGEMANAGER->addFrameImage("F_idle_Right", "img/flower/idle_Right.bmp", 1660, 126, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("F_idle_Left", "img/flower/idle_Left.bmp", 1660, 126, 10, 1, true, RGB(255, 0, 255));
	//Atk						
	IMAGEMANAGER->addFrameImage("F_Atk_Left", "img/flower/Atk_Left.bmp", 3304, 176, 14, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("F_Atk_Right", "img/flower/Atk_Right.bmp", 3304, 176, 14, 1, true, RGB(255, 0, 255));
	//up						
	IMAGEMANAGER->addFrameImage("F_UP_Left", "img/flower/UP_Left.bmp", 2952, 128, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("F_UP_Right", "img/flower/UP_Right.bmp", 2952, 128, 18, 1, true, RGB(255, 0, 255));
	//dmg					
	IMAGEMANAGER->addFrameImage("F_Dmg_Left", "img/flower/Dmg_Left.bmp", 608, 106, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("F_Dmg_Right", "img/flower/Dmg_Right.bmp", 608, 106, 4, 1, true, RGB(255, 0, 255));
	//deadEffect
	IMAGEMANAGER->addFrameImage("F_deadEffect", "img/flower/F_deadEffect.bmp", 2728, 98, 22, 1, true, RGB(255, 0, 255));


	//idle
	int Flower_Idle_Right[] = { 0,1,2,3,4,5,6,7,8,9 };
	KEYANIMANAGER->addArrayFrameAnimation("F_idle_Right", "F_idle_Right", Flower_Idle_Right, 10, FPS, true);
	int Flower_Idle_Left[] = { 0,1,2,3,4,5,6,7,8,9 };
	KEYANIMANAGER->addArrayFrameAnimation("F_idle_Left", "F_idle_Left", Flower_Idle_Left, 10, FPS, true);
	//Atk
	int Flower_Atk_Left[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13 };
	KEYANIMANAGER->addArrayFrameAnimation("F_Atk_Left", "F_Atk_Left", Flower_Atk_Left, 14, FPS, true);
	int Flower_Atk_Right[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13 };
	KEYANIMANAGER->addArrayFrameAnimation("F_Atk_Right", "F_Atk_Right", Flower_Atk_Right, 14, FPS, true);
	//up
	int Flower_Up_Left[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };
	KEYANIMANAGER->addArrayFrameAnimation("F_UP_Left", "F_UP_Left", Flower_Up_Left, 18, FPS, true);
	int Flower_Up_Right[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };
	KEYANIMANAGER->addArrayFrameAnimation("F_UP_Right", "F_UP_Right", Flower_Up_Right, 18, FPS, true);
	//Dmg
	int Flower_Dmg_Left[] = { 0,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("F_Dmg_Left", "F_Dmg_Left", Flower_Dmg_Left, 4, FPS, true);
	int Flower_Dmg_Right[] = { 0,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("F_Dmg_Right", "F_Dmg_Right", Flower_Dmg_Right, 4, FPS, true);
	//deadEffect
	int Flower_DeadEffect[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21 };
	KEYANIMANAGER->addArrayFrameAnimation("F_deadEffect", "F_deadEffect", Flower_DeadEffect, 22, FPS, true);




	en.name = Name_Flower;
	Enemy::init(pos, FPS, SPEED);


	en.img = IMAGEMANAGER->findImage("F_idle_Right");
	en.Ani = KEYANIMANAGER->findAnimation("F_idle_Right");
	en.changeAni = true;
	en.Ani->start();

	return S_OK;
}

void Flower::release()
{
}

void Flower::update()
{
	en.rc = RectMakeCenter(
		en.x,
		en.y,
		en.img->getFrameWidth(),
		en.img->getFrameHeight());


}



void Flower::render()
{
	if (KEYMANAGER->isToggleKey('1'))
	{
		Rectangle(_backBuffer->getMemDC(), en.rc);
	}
	en.img->aniRender(_backBuffer->getMemDC(),
		en.rc.left,
		en.rc.top,
		en.Ani);
}
