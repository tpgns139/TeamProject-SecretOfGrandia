#include "stdafx.h"
#include "StageOneScene.h"


StageOneScene::StageOneScene()
{
}


StageOneScene::~StageOneScene()
{
}

HRESULT StageOneScene::init()
{
	
	IMAGEMANAGER->addImage("Hydra", "img/Hydra.bmp", 303, 487, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Player", "img/Player.bmp", 60, 90, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Slime", "img/Slime.bmp", 50, 36, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Rabbit", "img/Rabbit.bmp", 50, 44, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Flower", "img/Flower.bmp", 146, 126, true, RGB(255, 0, 255));
	_tiles = TILEMANAGER->load("Stage/StageOne.txt");
	TILEMANAGER->loadObj("Object/stageOne.txt","stageOne");
	for (int i = 0; i < _gameObj.size(); i++)
	{
		_gameObj[i]->init();
	}
	return S_OK;
}

void StageOneScene::render()
{
	BasicScene::render();
	
}
