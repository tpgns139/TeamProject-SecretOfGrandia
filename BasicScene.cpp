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

void BasicScene::settingObj(GameObject* ins)
{
	_gameObj.push_back(ins);
}

void BasicScene::eraseObject(GameObject * ins)
{
	for (int i = 0; i < _gameObj.size(); i++)
	{
		if (_gameObj[i] == ins)
		{
			_gameObj.erase(_gameObj.begin()+i);
			break;
		}
	}
}

void BasicScene::update()
{

	for (int i = 0; i < _gameObj.size(); i++)
	{
		_gameObj[i]->update();
	}
}

void BasicScene::render()
{
	for (int i = 0; i < _gameObj.size(); i++)
	{
		_gameObj[i]->render();
	}
	
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
