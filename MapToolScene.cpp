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
	tileSize = 32;
	_buttonMap.insert(make_pair("TileMap", IMAGEMANAGER->addImage("TileButton", "img/TileButton/BT_Ground.png" )));
	_buttonMap.insert(make_pair("TileErase", IMAGEMANAGER->addImage("TileErase", "img/TileButton/BT_Tile_E.png")));
	_buttonMap.insert(make_pair("TileSave", IMAGEMANAGER->addImage("TileSave", "img/TileButton/BT_Save.png")));
	_buttonMap.insert(make_pair("TileLoad", IMAGEMANAGER->addImage("TileLoad", "img/TileButton/BT_Load.png")));
	_buttonMap.insert(make_pair("Collider", IMAGEMANAGER->addImage("Collider", "img/TileButton/backGround_Select_Pointer.png")));//Á¡ÇÁ ¶Û ¼ö ÀÖ´Â ¶¥ Ç¥½Ã
	_buttonMap.insert(make_pair("notJump", IMAGEMANAGER->addImage("notJump", "img/TileButton/backGround_Select.png")));		//Á¡ÇÁ ¸ø¶Ù´Â ¶¥ Ç¥½Ã

	IMAGEMANAGER->addImage("Tutorial_backGroundOne", "img/BackGround/tutorial_BG_0.png");


	
	return S_OK;
}

void MapToolScene::Start()
{
	TILEMANAGER->setShowRect(true);
	TILEMANAGER->setShowCol(true);
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
			TILEMANAGER->setCTRL(CTRL_TERRAINDRAW);

		}
		if (PtInRect((&IMAGEMANAGER->findImage("TileErase")->getRect()), _ptMouse))
		{
			TILEMANAGER->setCTRL(CTRL_ERASER);

		}
		if (PtInRect((&IMAGEMANAGER->findImage("TileSave")->getRect()), _ptMouse))
		{
			TILEMANAGER->setCTRL(CTRL_SAVE);
			TILEMANAGER->save();

		}
		if (PtInRect((&IMAGEMANAGER->findImage("TileLoad")->getRect()), _ptMouse))
		{
			TILEMANAGER->setCTRL(CTRL_LOAD);
			TILEMANAGER->load();
		}
		if (PtInRect((&IMAGEMANAGER->findImage("Collider")->getRect()), _ptMouse))
		{
			TILEMANAGER->setCTRL(CTRL_COL);
		}
		if (PtInRect((&IMAGEMANAGER->findImage("notJump")->getRect()), _ptMouse))
		{
			TILEMANAGER->setCTRL(CTRL_NOTJUMP);
		}
	}
	TILEMANAGER->update();


}

void MapToolScene::render()
{
	//µŞ¹è°æ Âï±â
	IMAGEMANAGER->findImage("Tutorial_backGroundOne")->render(576, 480, 1152, 960);
	IMAGEMANAGER->findImage("Tutorial_backGroundOne")->render(1728, 480, 1152, 960);
	//Å¸ÀÏ Âï±â
	TILEMANAGER->render();

	//buttonÂï±â
	int i = 0;
	for (_buttonMapIter =_buttonMap.begin();_buttonMapIter != _buttonMap.end();_buttonMapIter++)
	{
		_buttonMapIter->second->UIrender(25 + 50 * i, 25,50,50);
		i++;
	}
}
