#include "stdafx.h"
#include "MapToolScene.h"
#include"gameNode.h"

MapToolScene::MapToolScene()
{
}


MapToolScene::~MapToolScene()
{
}

HRESULT MapToolScene::init()
{
	IMAGEMANAGER->addImage("map", "img/Tile/autumn_Tile.png", 200, 200);
	_buttonMap.insert(make_pair("TileMap", IMAGEMANAGER->addImage("TileButton", "img/TileButton/BT_Ground.png", 50, 50)));
	return S_OK;
}

void MapToolScene::update()
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
	if (_leftButtonDown) 
	{
		if (PtInRect((&IMAGEMANAGER->findImage("TileButton")->getRect()), _ptMouse))
		{
			cout << "ptinrect!!" << endl;
		}
	}



}

void MapToolScene::render()
{
	//buttonÂï±â
	int i = 0;
	for (_buttonMapIter =_buttonMap.begin();_buttonMapIter != _buttonMap.end();_buttonMapIter++)
	{
		_buttonMapIter->second->UIrender(25 + 50 * i, 25);
		i++;
	}
}
