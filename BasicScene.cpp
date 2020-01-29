#include "stdafx.h"
#include "BasicScene.h"


void BasicScene::setGameObj(OBJSTRUCT obj)
{
	GameObject* ins = NULL;
	switch (obj.kinds)
	{
	case PLAYER:
		break;
	case SLIME:
		 ins= new Slime;
		ins->setimage(IMAGEMANAGER->findImage("Slime"));
		settingObj(ins, obj);
		break;
	case RABBIT:
		 ins = new Rabbit;
		ins->setimage(IMAGEMANAGER->findImage("Rabbit"));
		settingObj(ins, obj);
		break;
	case HYDRA:
		 ins = new Hydra;
		ins->setimage(IMAGEMANAGER->findImage("Hydra"));
		settingObj(ins, obj);
		break;
	case FLOWER:
		ins = new Flower;
		ins->init(PointMake(WINSIZEX/2, WINSIZEY/2), 10, 2);
		ins->setimage(IMAGEMANAGER->findImage("Flower"));
		settingObj(ins, obj);
		break;

	}
	
}

void BasicScene::settingObj(GameObject* ins, OBJSTRUCT obj)
{
	ins->setCenter(obj.center);
	ins->setFrame(obj.frame);
	ins->setOBJECT(obj.kinds);
	ins->setRect(obj.rc);
	_gameObj.push_back(ins);
}

void BasicScene::update()
{
	for (int i = 0; i < _gameObj.size(); i++)
	{
		for (int j = i; j < _gameObj.size(); j++)
		{
			if (_gameObj[i]->getRect().bottom > _gameObj[j]->getRect().bottom)
			{
				GameObject* temp = _gameObj[i];
				_gameObj[i] = _gameObj[j];
				_gameObj[j] = temp;
			}
		}
	}
}

void BasicScene::render()
{
	IMAGEMANAGER->findImage("BackGround")->render(getMemDC(),0,0);

	for (int i = 0; i < _tiles.size(); ++i)
	{
		if (_tiles[i]->getType() == TYPE_TERRAIN)
		{
			IMAGEMANAGER->frameRender("mapTiles", _backBuffer->getMemDC(),
				_tiles[i]->getRect().left,
				_tiles[i]->getRect().top,
				_tiles[i]->getTerrainFrameIdx(),
				_tiles[i]->getTerrainFrameIdY());
		}
		else if (_tiles[i]->getType() == TYPE_TERRAIN2)
		{
			IMAGEMANAGER->frameRender("Boss_Map_Fall", _backBuffer->getMemDC(),
				_tiles[i]->getRect().left,
				_tiles[i]->getRect().top,
				_tiles[i]->getTerrainFrameIdx(),
				_tiles[i]->getTerrainFrameIdY());
		}
		else if (_tiles[i]->getType() == TYPE_TERRAIN3)
		{
			IMAGEMANAGER->frameRender("Second_Map", _backBuffer->getMemDC(),
				_tiles[i]->getRect().left,
				_tiles[i]->getRect().top,
				_tiles[i]->getTerrainFrameIdx(),
				_tiles[i]->getTerrainFrameIdY());
		}
		else if (_tiles[i]->getType() == TYPE_TERRAIN4)
		{
			IMAGEMANAGER->frameRender("Boss_Map_Summer", _backBuffer->getMemDC(),
				_tiles[i]->getRect().left,
				_tiles[i]->getRect().top,
				_tiles[i]->getTerrainFrameIdx(),
				_tiles[i]->getTerrainFrameIdY());
		}
		else if (_tiles[i]->getType() == TYPE_TERRAIN5)
		{
			IMAGEMANAGER->frameRender("Boss_Map_Winter", _backBuffer->getMemDC(),
				_tiles[i]->getRect().left,
				_tiles[i]->getRect().top,
				_tiles[i]->getTerrainFrameIdx(),
				_tiles[i]->getTerrainFrameIdY());
		}
		else if (_tiles[i]->getType() == TYPE_TERRAIN6)
		{
			IMAGEMANAGER->frameRender("Second_floor", _backBuffer->getMemDC(),
				_tiles[i]->getRect().left,
				_tiles[i]->getRect().top,
				_tiles[i]->getTerrainFrameIdx(),
				_tiles[i]->getTerrainFrameIdY());
		}
	}
	for (int i = 0; i < _gameObj.size(); i++)
	{
		_gameObj[i]->getImage()->render(getMemDC(), _gameObj[i]->getCenter().x ,_gameObj[i]->getCenter().y);
	}
	
}

BasicScene::BasicScene()
{
}


BasicScene::~BasicScene()
{
}
