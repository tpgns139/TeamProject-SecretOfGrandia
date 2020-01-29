#include "stdafx.h"
#include "Hydra_W.h"


#include "stdafx.h"
#include "Hydra_W.h"


Hydra_W::Hydra_W()
{
}


Hydra_W::~Hydra_W()
{
}

HRESULT Hydra_W::init(POINT pos, int FPS, float SPEED)
{

	_isAttack = true; //false바꾸기
	//Big
	IMAGEMANAGER->addFrameImage("W_Atk_Big_Left", "img/Hydra_W/Atk_Big_Left.bmp", 7504, 224, 28, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("W_Atk_Big_Right", "img/Hydra_W/Atk_Big_Right.bmp", 7504, 224, 28, 1, true, RGB(255, 0, 255));
	//shake						 
	IMAGEMANAGER->addFrameImage("W_Atk_Big_Shake", "img/Hydra_W/Atk_Big_Shake.bmp", 3698, 124, 18, 1, true, RGB(255, 0, 255));
	//small						 
	IMAGEMANAGER->addFrameImage("W_Atk_Small_Left", "img/Hydra_W/Atk_Small_Left.bmp", 7394, 203, 28, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("W_Atk_Small_Right", "img/Hydra_W/Atk_Small_Right.bmp", 7394, 203, 28, 1, true, RGB(255, 0, 255));
	//shake						 
	IMAGEMANAGER->addFrameImage("W_Atk_small_Shake", "img/Hydra_W/Atk_small_shake_Left.bmp", 4284, 142, 18, 1, true, RGB(255, 0, 255));
	//Bend						 
	IMAGEMANAGER->addFrameImage("W_Bend_Down_Left", "img/Hydra_W/Bend_Down_Left.bmp", 360, 58, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("W_Bend_Down_Right", "img/Hydra_W/Bend_Down_Right.bmp", 360, 58, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("W_Bend_Up_Left", "img/Hydra_W/Bend_Up_Left.bmp", 360, 58, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("W_Bend_Up_Right", "img/Hydra_W/Bend_Up_Right.bmp", 360, 58, 6, 1, true, RGB(255, 0, 255));
	//Turn						 
	IMAGEMANAGER->addFrameImage("W_T_Left", "img/Hydra_W/T_Left.bmp", 216, 54, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("W_T_Right", "img/Hydra_W/T_Right.bmp", 216, 54, 4, 1, true, RGB(255, 0, 255));
	//Face
	IMAGEMANAGER->addImage("W_Big_Face_Left", "img/Hydra_W/Big_Face_Left.bmp", 186, 138, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("W_Big_Face_Right", "img/Hydra_W/Big_Face_Right.bmp", 186, 138, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("W_Big_Face_Turn", "img/Hydra_W/Big_Face_Turn.bmp", 872, 144, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("W_Front", "img/Hydra_W/W_Front.bmp", 500, 154, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("W_Small_Face_Trun", "img/Hydra_W/Small_Face_Trun.bmp", 952, 140, 4, 1, true, RGB(255, 0, 255));

	//breath
	IMAGEMANAGER->addFrameImage("W_B_Left", "img/Hydra_W/W_B_Left.bmp", 4484, 174, 19, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("W_B_Right", "img/Hydra_W/W_B_Right.bmp", 4484, 174, 19, 1, true, RGB(255, 0, 255));
	//Beam
	IMAGEMANAGER->addFrameImage("W_Beam", "img/Hydra_W/W_Beam.bmp", 204, 50, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("W_beam01", "img/Hydra_W/beam01.bmp", 14, 2, true, RGB(255, 0, 255));


	//Big_Atk
	int W_Atk_Big_Left[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27 };
	KEYANIMANAGER->addArrayFrameAnimation("W_Atk_Big_Left", "W_Atk_Big_Left", W_Atk_Big_Left, 28, FPS, true);
	int W_Atk_Big_Right[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27 };
	KEYANIMANAGER->addArrayFrameAnimation("W_Atk_Big_Right", "W_Atk_Big_Right", W_Atk_Big_Left, 28, FPS, true);
	//Big_Skake
	int W_Atk_Big_Shake[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };
	KEYANIMANAGER->addArrayFrameAnimation("W_Atk_Big_Shake", "W_Atk_Big_Shake", W_Atk_Big_Shake, 18, FPS, true);
	//Small_Atk
	int W_Atk_Small_Left[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27 };
	KEYANIMANAGER->addArrayFrameAnimation("W_Atk_Small_Left", "W_Atk_Small_Left", W_Atk_Small_Left, 28, FPS, true);
	int W_Atk_Small_Right[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27 };
	KEYANIMANAGER->addArrayFrameAnimation("W_Atk_Small_Right", "W_Atk_Small_Right", W_Atk_Small_Right, 28, FPS, true);
	//Bend		
	int W_Bend_Down_Left[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("W_Bend_Down_Left", "W_Bend_Down_Left", W_Bend_Down_Left, 6, FPS, true);
	int W_Bend_Down_Right[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("W_Bend_Down_Right", "W_Bend_Down_Right", W_Bend_Down_Right, 6, FPS, true);
	int W_Bend_Up_Left[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("W_Bend_Up_Left", "W_Bend_Up_Left", W_Bend_Up_Left, 6, FPS, true);
	int W_Bend_Up_Right[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("W_Bend_Up_Right", "W_Bend_Up_Right", W_Bend_Up_Right, 6, FPS, true);
	//Turn
	int W_T_Left[] = { 0,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("W_T_Left", "W_T_Left", W_T_Left, 4, FPS, true);
	int W_T_Right[] = { 0,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("W_T_Right", "W_T_Right", W_T_Right, 4, FPS, true);
	//Big Face
	/*int W_Big_Face_Left[] = {0};
	KEYANIMANAGER->addArrayFrameAnimation("W_Big_Face_Left", "W_Big_Face_Left", W_Big_Face_Left, 1, FPS, true);
	int W_Big_Face_Right[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("W_Big_Face_Right", "W_Big_Face_Right", W_Big_Face_Right, 1, FPS, true);*/
	int W_Big_Face_Turn[] = { 0,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("W_Big_Face_Turn", "W_Big_Face_Turn", W_Big_Face_Turn, 4, FPS, true);
	//Face Front
	int W_Front[] = { 0,1 };
	KEYANIMANAGER->addArrayFrameAnimation("W_Front", "W_Front", W_Front, 2, FPS, true);
	//Small Face
	int W_Small_Face_Trun[] = { 0,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("W_Small_Face_Trun", "W_Small_Face_Trun", W_Small_Face_Trun, 4, FPS, true);
	//breath
	int W_B_Left[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18 };
	KEYANIMANAGER->addArrayFrameAnimation("W_B_Left", "W_B_Left", W_B_Left, 19, FPS, true);
	int W_B_Right[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18 };
	KEYANIMANAGER->addArrayFrameAnimation("W_B_Right", "W_B_Right", W_B_Right, 19, FPS, true);

	//Beam
	int W_Beam[] = { 0,1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("W_Beam", "W_Beam", W_Beam, 3, FPS, true);
	/*int W_beam01[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("W_beam01", "W_beam01", W_beam01, 1, FPS, true);*/







	en.name = Name_Hydra_W;

	Enemy::init(pos, FPS, SPEED);


	en.img = IMAGEMANAGER->findImage("W_Atk_Big_Left");
	en.Ani = KEYANIMANAGER->findAnimation("W_Atk_Big_Left");
	en.changeAni = true;
	en.Ani->start();

	for (int i = 0;i < EA;i++)
	{
		body[i].bodyImg = IMAGEMANAGER->findImage("W_Bend_Down_Left");
		body[i].BodyAni = KEYANIMANAGER->findAnimation("W_Bend_Down_Left");
		body[i].x = en.x;
		body[i].y = en.y;
		//body[i].BodyAni->start();
	}


	count = 0;
	set = 0;
	gap[0] = gap[1] = 0;
	body[0].y = en.y + 180;

	body[0].rc = RectMakeCenter(body[0].x,
		body[0].y,
		body[0].bodyImg->getFrameWidth(), body[0].bodyImg->getFrameHeight());

	return S_OK;
}

void Hydra_W::release()
{
}

void Hydra_W::update()
{



	//body[0].Hdis = getDistance(en.x, en.y,body[0].x, body[0].y);
	//body[0].Hang = getAngle(en.x, en.y,body[0].x, body[0].y);
	//
	//if (body[0].Hdis > body[0].bodyImg->getFrameHeight()/2)
	//{
	//	body[0].x -= (cosf(body[0].Hang) * TAIL_SPEED);
	//	//body[0].y -= (-sinf(body[0].Hang) * TAIL_SPEED);
	//}
	//
	//
	//for (int i = 1; i < EA;i++)
	//{
	//	body[i].Hdis = getDistance(body[i - 1].x, body[i - 1].y,body[i].x,body[i].y);
	//	body[i].Hang = getAngle(body[i - 1].x,body[i - 1].y,body[i].x,body[i].y);
	//	
	//	if (body[i].Hdis > body[i].bodyImg->getFrameHeight()/2)
	//	{
	//		body[i].x -= (cosf(body[i].Hang) * TAIL_SPEED);
	//		//body[i].y -= (-sinf(body[i].Hang) * TAIL_SPEED);
	//	}
	//}






	if (_isAttack)
	{
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			en.x -= HEAD_SPEED;
		}

		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			en.x += HEAD_SPEED;
		}

		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			en.y -= HEAD_SPEED;
		}

		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			en.y += HEAD_SPEED;
		}



		en.rc = RectMakeCenter(en.x, en.y, en.img->getFrameWidth(), en.img->getFrameHeight());




		//사이값
		gap[0] = (body[0].x - en.x) / 6;
		gap[1] = (body[0].y - en.y) / 6;


		for (int i = 1;i < EA;i++)//
		{
			body[i].rc = RectMakeCenter(body[i].x - gap[0] * i,
				body[0].y - gap[1] * i,
				body[i].bodyImg->getFrameWidth(), body[i].bodyImg->getFrameHeight());
		}

	}
	else
	{

	}


}

void Hydra_W::render()
{
	if (KEYMANAGER->isToggleKey('1'))
	{
		Rectangle(_backBuffer->getMemDC(), en.rc);
		for (int i = 0;i < EA;i++)
		{
			Rectangle(_backBuffer->getMemDC(), body[i].rc);
		}
	}
	for (int i = 0;i < EA;i++) //i<6까지
	{
		body[i].bodyImg->aniRender(_backBuffer->getMemDC(), body[i].rc.left, body[i].rc.top, body[i].BodyAni);
	}
	en.img->aniRender(_backBuffer->getMemDC(), en.rc.left, en.rc.top, en.Ani);

}
