#include "stdafx.h"
#include "BasicScene.h"


HRESULT BasicScene::init()
{
	return S_OK;
}

void BasicScene::Start()
{
}

void BasicScene::setGameObj(OBJSTRUCT obj)
{
	
	
}

void BasicScene::settingObj(GameObject* ins, OBJSTRUCT obj)
{
	_gameObj.push_back(ins);
}

void BasicScene::update()
{
	
}

void BasicScene::render()
{
	
	
}

float BasicScene::getTileSize()
{
	return tileSize;
}

BasicScene::BasicScene()
{
}


BasicScene::~BasicScene()
{
}
