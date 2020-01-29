#include "stdafx.h"
#include "Rabbit.h"


Rabbit::Rabbit()
{
}


Rabbit::~Rabbit()
{
}



HRESULT Rabbit::init(POINT pos, int FPS, float SPEED)
{
	//idle
	IMAGEMANAGER->addFrameImage("R_idle_down", "img/rabbit/idle_Down.bmp", 600, 44, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("R_idle_up", "img/rabbit/idle_Up.bmp", 504, 46, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("R_idle_left", "img/rabbit/idle_Left.bmp", 696, 44, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("R_idle_right", "img/rabbit/idle_Right.bmp", 696, 44, 12, 1, true, RGB(255, 0, 255));
	//Atk						
	IMAGEMANAGER->addFrameImage("R_atk_down", "img/rabbit/Atk_Down.bmp", 690, 54, 15, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("R_atk_up", "img/rabbit/Atk_Up.bmp", 690, 56, 15, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("R_atk_left", "img/rabbit/Atk_Left.bmp", 900, 52, 15, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("R_atk_right", "img/rabbit/Atk_Right.bmp", 900, 52, 15, 1, true, RGB(255, 0, 255));
	//run						
	IMAGEMANAGER->addFrameImage("R_run_down", "img/rabbit/Run_Down.bmp", 550, 48, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("R_run_up", "img/rabbit/Run_Up.bmp", 506, 50, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("R_run_left", "img/rabbit/Run_Left.bmp", 660, 50, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("R_run_right", "img/rabbit/Run_Right.bmp", 660, 50, 11, 1, true, RGB(255, 0, 255));
	//dmg					
	IMAGEMANAGER->addFrameImage("R_dmg_down", "img/rabbit/Dmg_Down.bmp", 100, 44, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("R_dmg_up", "img/rabbit/Dmg_Up.bmp", 92, 46, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("R_dmg_left", "img/rabbit/Dmg_Left.bmp", 116, 44, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("R_dmg_right", "img/rabbit/Dmg_Right.bmp", 116, 44, 2, 1, true, RGB(255, 0, 255));
	//dead
	IMAGEMANAGER->addFrameImage("R_dead_Right", "img/rabbit/R_dead_Right.bmp", 1344, 76, 14, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("R_dead_Left", "img/rabbit/R_dead_Left.bmp", 1344, 76, 14, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("R_deadEffect", "img/rabbit/R_deadEffect.bmp", 420, 48, 6, 1, true, RGB(255, 0, 255));


	//idle
	int Rabbit_Idle_Left[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("R_Idle_Left", "R_idle_left", Rabbit_Idle_Left, 12, FPS, true);
	int Rabbit_Idle_Up[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("R_Idle_Up", "R_idle_up", Rabbit_Idle_Up, 12, FPS, true);
	int Rabbit_Idle_Right[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("R_Idle_Right", "R_idle_right", Rabbit_Idle_Right, 12, FPS, true);
	int Rabbit_Idle_Down[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("R_Idle_Down", "R_idle_down", Rabbit_Idle_Down, 12, FPS, true);
	//run
	int Rabbit_run_Left[] = { 0,1,2,3,4,5,6,7,8,9,10 };
	KEYANIMANAGER->addArrayFrameAnimation("R_run_Left", "R_run_left", Rabbit_run_Left, 11, FPS, true);
	int Rabbit_run_Up[] = { 0,1,2,3,4,5,6,7,8,9,10 };
	KEYANIMANAGER->addArrayFrameAnimation("R_run_Up", "R_run_up", Rabbit_run_Up, 11, FPS, true);
	int Rabbit_run_Right[] = { 0,1,2,3,4,5,6,7,8,9,10 };
	KEYANIMANAGER->addArrayFrameAnimation("R_run_Right", "R_run_right", Rabbit_run_Right, 11, FPS, true);
	int Rabbit_run_Down[] = { 0,1,2,3,4,5,6,7,8,9,10 };
	KEYANIMANAGER->addArrayFrameAnimation("R_run_Down", "R_run_down", Rabbit_run_Down, 11, FPS, true);
	//atk
	int Rabbit_atk_Left[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
	KEYANIMANAGER->addArrayFrameAnimation("R_atk_Left", "R_atk_left", Rabbit_atk_Left, 15, FPS, false);
	int Rabbit_atk_Up[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
	KEYANIMANAGER->addArrayFrameAnimation("R_atk_Up", "R_atk_up", Rabbit_atk_Up, 15, FPS, false);
	int Rabbit_atk_Right[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
	KEYANIMANAGER->addArrayFrameAnimation("R_atk_Right", "R_atk_right", Rabbit_atk_Right, 15, FPS, false);
	int Rabbit_atk_Down[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
	KEYANIMANAGER->addArrayFrameAnimation("R_atk_Down", "R_atk_down", Rabbit_atk_Down, 15, FPS, false);
	//dmg
	int Rabbit_dmg_Left[] = { 0,1 };
	KEYANIMANAGER->addArrayFrameAnimation("R_dmg_Left", "R_dmg_left", Rabbit_dmg_Left, 2, FPS, false);
	int Rabbit_dmg_Up[] = { 0,1 };
	KEYANIMANAGER->addArrayFrameAnimation("R_dmg_Up", "R_dmg_up", Rabbit_dmg_Up, 2, FPS, false);
	int Rabbit_dmg_Right[] = { 0,1 };
	KEYANIMANAGER->addArrayFrameAnimation("R_dmg_Right", "R_dmg_right", Rabbit_dmg_Right, 2, FPS, false);
	int Rabbit_dmg_Down[] = { 0,1 };
	KEYANIMANAGER->addArrayFrameAnimation("R_dmg_Down", "R_dmg_down", Rabbit_dmg_Down, 2, FPS, false);
	int Rabbit_Dead_Right[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13 };
	KEYANIMANAGER->addArrayFrameAnimation("R_dead_Right", "R_dead_Right", Rabbit_Dead_Right, 14, FPS, false);
	int Rabbit_Dead_Left[] = { 13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("R_dead_Left", "R_dead_Left", Rabbit_Dead_Left, 14, FPS, false);
	int Rabbit_Dead_Effect[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("R_deadEffect", "R_deadEffect", Rabbit_Dead_Effect, 6, FPS, false);


	en.name = Name_Rabbit;

	Enemy::init(pos, FPS, SPEED);



	en.img = IMAGEMANAGER->findImage("R_idle_left");
	en.Ani = KEYANIMANAGER->findAnimation("R_Idle_Left");


	count = 0;
	Movecheck = RND->getFromIntTo(0, 4);
	move = true;
	atk = false;


	en.changeAni = true;
	en.Ani->start();



	return S_OK;
}

void Rabbit::release()
{
}

void Rabbit::update()
{
	//R_control();


	if (!atk)moving();

	if (atk)attack();


	if (en.changeAni)
	{
		R_state();
	}




	rc = RectMakeCenter(_ptMouse.x, _ptMouse.y, 30, 30);



	en.senseRC = RectMakeCenter(en.x, en.y,
		en.img->getFrameWidth() * 2,
		en.img->getFrameHeight() * 2);
	en.rc = RectMakeCenter(en.x, en.y,
		en.img->getFrameWidth(),
		en.img->getFrameHeight());

	RECT temp;
	if (!IntersectRect(&temp, &en.senseRC, &rc))
	{
		atk = false;
	}
	if (IntersectRect(&temp, &en.senseRC, &rc))
	{
		atk = true;
	}


}

void Rabbit::render()
{
	if (KEYMANAGER->isToggleKey('1'))
	{
		Rectangle(_backBuffer->getMemDC(), en.senseRC);
		Rectangle(_backBuffer->getMemDC(), en.rc);
	}
	Rectangle(_backBuffer->getMemDC(), rc);
	en.img->aniRender(_backBuffer->getMemDC(), en.rc.left, en.rc.top, en.Ani);
}

void Rabbit::moving()
{


	en.state = Run;
	cout << en.dir << endl;
	//en.SPEED = 0.5F;

	count++;
	if (Movecheck == 0)
	{
		en.dir = LEFT;
	}
	if (Movecheck == 1)
	{
		en.dir = RIGHT;
	}
	if (Movecheck == 2)
	{
		en.dir = UP;
	}
	if (Movecheck == 3)
	{
		en.dir = DOWN;
	}
	if (count >= 80)
	{
		en.changeAni = true;
		Movecheck = RND->getFromIntTo(0, 4);
		count = 0;
	}



	switch (en.dir)
	{
	case LEFT:
		en.Ani = KEYANIMANAGER->findAnimation("R_run_Left");
		en.img = IMAGEMANAGER->findImage("R_run_left");
		en.x -= en.SPEED;
		break;
	case RIGHT:
		en.Ani = KEYANIMANAGER->findAnimation("R_run_Right");
		en.img = IMAGEMANAGER->findImage("R_run_right");
		en.x += en.SPEED;
		break;
	case DOWN:
		en.Ani = KEYANIMANAGER->findAnimation("R_run_Down");
		en.img = IMAGEMANAGER->findImage("R_run_down");
		en.y += en.SPEED;
		break;
	case UP:
		en.Ani = KEYANIMANAGER->findAnimation("R_run_Up");
		en.img = IMAGEMANAGER->findImage("R_run_up");
		en.y -= en.SPEED;
		break;
	}



}

void Rabbit::attack()
{

	en.state = Atk;
	cout << en.dir << endl;
	//en.SPEED = 0.5F;

	count++;
	if (Movecheck == 0)
	{
		en.dir = LEFT;
	}
	if (Movecheck == 1)
	{
		en.dir = RIGHT;
	}
	if (Movecheck == 2)
	{
		en.dir = UP;
	}
	if (Movecheck == 3)
	{
		en.dir = DOWN;
	}
	if (count >= 80)
	{
		en.changeAni = true;
		Movecheck = RND->getFromIntTo(0, 4);
		count = 0;
	}



	switch (en.dir)
	{
	case LEFT:
		en.img = IMAGEMANAGER->findImage("R_atk_left");
		en.Ani = KEYANIMANAGER->findAnimation("R_atk_Left");
		break;
	case RIGHT:
		en.img = IMAGEMANAGER->findImage("R_atk_right");
		en.Ani = KEYANIMANAGER->findAnimation("R_atk_Right");
		break;
	case DOWN:
		en.img = IMAGEMANAGER->findImage("R_atk_down");
		en.Ani = KEYANIMANAGER->findAnimation("R_atk_Down");
		break;
	case UP:
		en.img = IMAGEMANAGER->findImage("R_atk_up");
		en.Ani = KEYANIMANAGER->findAnimation("R_atk_Up");
		break;
	}

}







void Rabbit::R_state()
{
	switch (en.dir)
	{
	case LEFT:
		break;
	case RIGHT:
		break;
	case DOWN:
		break;
	case UP:
		break;
	}

	switch (en.state)
	{
	case Idle:
		switch (en.dir)
		{
		case LEFT:
			en.Ani = KEYANIMANAGER->findAnimation("R_Idle_Left");
			en.img = IMAGEMANAGER->findImage("R_idle_left");
			en.Ani->start();
			en.changeAni = false;
			break;
		case RIGHT:
			en.Ani = KEYANIMANAGER->findAnimation("R_Idle_Right");
			en.img = IMAGEMANAGER->findImage("R_idle_right");
			en.Ani->start();
			en.changeAni = false;
			break;
		case DOWN:
			en.Ani = KEYANIMANAGER->findAnimation("R_Idle_Down");
			en.img = IMAGEMANAGER->findImage("R_idle_down");
			en.Ani->start();
			en.changeAni = false;
			break;
		case UP:
			en.Ani = KEYANIMANAGER->findAnimation("R_Idle_Up");
			en.img = IMAGEMANAGER->findImage("R_idle_up");
			en.Ani->start();
			en.changeAni = false;
			break;
		}
		break;
	case Run:
		switch (en.dir)
		{
		case LEFT:
			//en.Ani = KEYANIMANAGER->findAnimation("R_run_Left");
			//en.img = IMAGEMANAGER->findImage("R_run_left");
			en.Ani->start();
			en.changeAni = false;
			break;
		case RIGHT:
			//en.Ani = KEYANIMANAGER->findAnimation("R_run_Right");
			//en.img = IMAGEMANAGER->findImage("R_run_right");
			en.Ani->start();
			en.changeAni = false;
			break;
		case DOWN:
			//en.Ani = KEYANIMANAGER->findAnimation("R_run_Down");
			//en.img = IMAGEMANAGER->findImage("R_run_down");
			en.Ani->start();
			en.changeAni = false;
			break;
		case UP:
			//en.Ani = KEYANIMANAGER->findAnimation("R_run_Up");
			//en.img = IMAGEMANAGER->findImage("R_run_up");
			en.Ani->start();
			en.changeAni = false;
			break;
		}
		break;
	case Atk:
		switch (en.dir)
		{
		case LEFT:
			//en.img = IMAGEMANAGER->findImage("R_atk_left");
			//en.Ani = KEYANIMANAGER->findAnimation("R_atk_Left");
			en.Ani->start();
			en.changeAni = false;
			break;
		case RIGHT:
			//en.img = IMAGEMANAGER->findImage("R_atk_right");
			//en.Ani = KEYANIMANAGER->findAnimation("R_atk_Right");
			en.Ani->start();
			en.changeAni = false;
			break;
		case DOWN:
			//en.img = IMAGEMANAGER->findImage("R_atk_down");
			//en.Ani = KEYANIMANAGER->findAnimation("R_atk_Down");
			en.Ani->start();
			en.changeAni = false;
			break;
		case UP:
			//en.img = IMAGEMANAGER->findImage("R_atk_up");
			//en.Ani = KEYANIMANAGER->findAnimation("R_atk_Up");
			en.Ani->start();
			en.changeAni = false;
			break;
		}
		break;
	case Dmg:
		switch (en.dir)
		{
		case LEFT:
			en.img = IMAGEMANAGER->findImage("R_dmg_left");
			en.Ani = KEYANIMANAGER->findAnimation("R_dmg_Left");
			en.Ani->start();
			en.changeAni = false;
			break;
		case RIGHT:
			en.img = IMAGEMANAGER->findImage("R_dmg_right");
			en.Ani = KEYANIMANAGER->findAnimation("R_dmg_Right");
			en.Ani->start();
			en.changeAni = false;
			break;
		case DOWN:
			en.img = IMAGEMANAGER->findImage("R_dmg_down");
			en.Ani = KEYANIMANAGER->findAnimation("R_dmg_Down");
			en.Ani->start();
			en.changeAni = false;
			break;
		case UP:
			en.img = IMAGEMANAGER->findImage("R_dmg_up");
			en.Ani = KEYANIMANAGER->findAnimation("R_dmg_Up");
			en.Ani->start();
			en.changeAni = false;
			break;
		}
		break;
	case Dead:
		switch (en.dir)
		{
		case LEFT:
			en.img = IMAGEMANAGER->findImage("R_dead_Left");
			en.Ani = KEYANIMANAGER->findAnimation("R_dead_Left");
			en.Ani->start();
			en.changeAni = false;
			break;
		case RIGHT:
			en.img = IMAGEMANAGER->findImage("R_dead_Right");
			en.Ani = KEYANIMANAGER->findAnimation("R_dead_Right");
			en.Ani->start();
			en.changeAni = false;
			break;
		case DOWN:
			en.img = IMAGEMANAGER->findImage("R_dead_Left");
			en.Ani = KEYANIMANAGER->findAnimation("R_dead_Left");
			en.Ani->start();
			en.changeAni = false;
			break;
		case UP:
			en.img = IMAGEMANAGER->findImage("R_dead_Right");
			en.Ani = KEYANIMANAGER->findAnimation("R_dead_Right");
			en.Ani->start();
			en.changeAni = false;
			break;
		}

		break;
	case deadEffect:
		en.img = IMAGEMANAGER->findImage("R_deadEffect");
		en.Ani = KEYANIMANAGER->findAnimation("R_deadEffect");
		en.Ani->start();
		en.changeAni = false;
		break;
	default:
		break;
	}
}

void Rabbit::R_control()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		en.state = Run;
		en.x -= en.SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		en.state = Run;
		en.x += en.SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		en.state = Run;
		en.y -= en.SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		en.state = Run;
		en.y += en.SPEED;
	}

	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		en.dir = LEFT;
		en.state = Idle;
		en.changeAni = true;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		en.dir = RIGHT;
		en.state = Idle;
		en.changeAni = true;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		en.dir = UP;
		en.state = Idle;
		en.changeAni = true;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		en.dir = DOWN;
		en.state = Idle;
		en.changeAni = true;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		en.dir = LEFT;
		en.changeAni = true;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		en.dir = RIGHT;
		en.changeAni = true;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		en.dir = UP;
		en.changeAni = true;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		en.dir = DOWN;
		en.changeAni = true;
	}
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		en.state = Atk;
		en.changeAni = true;
	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		en.state = Dmg;
		en.changeAni = true;
	}
	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		en.state = Dead;
		en.changeAni = true;
	}
	if (KEYMANAGER->isOnceKeyDown('F'))
	{
		en.state = deadEffect;
		en.changeAni = true;
	}
}
