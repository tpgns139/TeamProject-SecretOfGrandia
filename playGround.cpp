#include "stdafx.h"
#include "playGround.h"
#include "TileMap.h"

playGround::playGround()
{
}


playGround::~playGround()
{
}


HRESULT playGround::init()
{
	gameNode::init(true);
	IMAGEMANAGER->addFrameImage("mapTiles", "img/Stage/¸ÊÅø_»ö±ò¹öÀü1¹ø.bmp", 0, 0, 800, 640, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Second_floor", "img/Stage/2Ãþµ¹_»ö±ò¹öÀü_2.bmp", 0, 0, 800, 640, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ladder", "img/Stage/»ç´Ù¸®.bmp", 0, 0, 364, 184, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ladder_two", "img/Stage/»ç´Ù¸®2.bmp", 0, 0, 371, 234, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Second_Map", "img/Stage/Second_Map.bmp", 0, 0, 800, 640, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Boss_Map_Fall", "img/Stage/Boss_Map(F).bmp", 0, 0, 800, 640, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Boss_Map_Summer", "img/Stage/Boss_Map(S).bmp", 0, 0, 800, 640, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Boss_Map_Winter", "img/Stage/Boss_Map(W).bmp", 0, 0, 800, 640, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("BackGround", "img/Stage/BackGround.bmp", WINSIZEX, WINSIZEY,false,RGB(0,0,0));

	SCENEMANAGER->addScene("stageOne", new StageOneScene);
	SCENEMANAGER->addScene("Loading", new LoadingScene);
	SCENEMANAGER->addScene("stageTwo", new StageTwoScene);

	SCENEMANAGER->changeScene("stageTwo");
	return S_OK;
}


void playGround::release()
{
	gameNode::release();


}


void playGround::update()
{
	gameNode::update();
	SCENEMANAGER->update();
	
}




void playGround::render()
{

	PatBlt(getMemDC(), 0, 0, 3, WINSIZEY, WHITENESS);
//========================================================
	SCENEMANAGER->render();

//====================================================
	_backBuffer->render(getHDC(), 0, 0);
}

