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
	tileSize = 64;
	TILEMANAGER->load("Stage/stageOne.txt");
	return S_OK;
}

void StageOne::Start()
{

	TILEMANAGER->setShowRect(true);
	TILEMANAGER->setShowCol(false);
}

void StageOne::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		CAMERA->setCameraX(CAMERA->getCameraX() - 5);
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		CAMERA->setCameraX(CAMERA->getCameraX() + 5);
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		CAMERA->setCameraY(CAMERA->getCameraY() - 5);
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		CAMERA->setCameraY(CAMERA->getCameraY() + 5);
	}
}

void StageOne::render()
{
	IMAGEMANAGER->findImage("Tutorial_backGroundOne")->render(1152, 960, 2304, 1920);
	IMAGEMANAGER->findImage("Tutorial_backGroundOne")->render(3456, 960, 2304, 1920);
	TILEMANAGER->render();
}
