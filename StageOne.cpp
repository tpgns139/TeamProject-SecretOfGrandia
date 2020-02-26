#include "stdafx.h"
#include "StageOne.h"


StageOne::StageOne()
{
}


StageOne::~StageOne()
{
}

HRESULT StageOne::init()
{
	IMAGEMANAGER->addImage("SkulRightHead", "img/Character/Skul/Skul_righthead.png");
	IMAGEMANAGER->addImage("SkulLeftHead", "img/Character/Skul/Skul_lefthead.png");
	tileSize = 64;
	TILEMANAGER->load("Stage/stageOne.txt");
	return S_OK;
}

void StageOne::Start()
{

	TILEMANAGER->setShowRect(false);
	TILEMANAGER->setShowCol(false);
	PLAYERMANAGER->addPlayer("PlayerOne", new Player);
	PLAYERMANAGER->findPlayer("PlayerOne")->init();
	this->settingObj(PLAYERMANAGER->findPlayer("PlayerOne"));
	GameObject* conEnemy = new knight;
	((Enemy*)conEnemy)->init(PointMake(1000, 1500));
	ENEMYMANAGER->setEnemy((Enemy*)conEnemy);
	this->settingObj(conEnemy);


}

void StageOne::update()
{
	BasicScene::update();
}

void StageOne::render()
{
	IMAGEMANAGER->findImage("Tutorial_backGroundOne")->render(1152, 960, 2304, 1920);
	IMAGEMANAGER->findImage("Tutorial_backGroundOne")->render(3456, 960, 2304, 1920);
	TILEMANAGER->render();
	BasicScene::render();

	
	
}
