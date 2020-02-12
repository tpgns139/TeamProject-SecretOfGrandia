#include "stdafx.h"
#include "TileMap.h"
#include"gameNode.h"



TileMap::TileMap()
{
}


TileMap::~TileMap()
{
}

void TileMap::setCurrentTile(TYPE _type, int indexX, int indexY)
{
	_currentTile->x = indexX;
	_currentTile->y = indexY;
	_currentTile->_type = _type;

}

void TileMap::setSampleTile(image * image)
{

}



HRESULT TileMap::init()
{
	_currentTile = new tagCurrentTile;
	_sampleTile.insert(make_pair("Terrain", new sampleMap));
	_sampleTile.find("Terrain")->second->insert(make_pair("springMap",new SampleTile(12,12,20,20,IMAGEMANAGER->addImage("springMap", "img/Tile/autumn_Tile.png"))));
	_crtl = CTRL_NONE;
	for (int i = 0;i < 100;i++)
	{
		for (int j = 0;j < 100;j++)
		{
			_tiles.push_back(new tagTile);
			_tiles[i* 100 + j]->setIdX(j);
			_tiles[i* 100 + j]->setIdY(i);
			_tiles[i* 100 + j]->setCenterX(TILESIZE / 2 + TILESIZE * j);
			_tiles[i* 100 + j]->setCenterY(TILESIZE / 2 + TILESIZE * i);

			_tiles[i* 100 + j]->setRect(RectMakeCenter(
				_tiles[i* 100 + j]->getCenterX(),
				_tiles[i* 100 + j]->getCenterY(),
				TILESIZE, 
				TILESIZE));

			_tiles[i* 100 + j]->setType(TYPE_NONE);
		}
		
	}
	return S_OK;
}

void TileMap::release()
{

}




void TileMap::loadObj(string FileName,string StageName)
{
	HANDLE file;
	DWORD read;
	OBJSTRUCT ins[100];
	_tiles.clear();
	int size = filesize(FileName.c_str());
	file = CreateFile(FileName.c_str(), GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	ReadFile(file, ins, size, &read, NULL);

	
	for (int i = 0; i < size / sizeof(OBJSTRUCT); i++)
	{
		SCENEMANAGER->findScene(StageName)->setGameObj(std::move(ins[i]));
	}
	CloseHandle(file);
}
std::ifstream::pos_type TileMap::filesize(const char* filename)
{
	std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
	return in.tellg();
}
vector<tagTile*> TileMap::load(string FileName)
{
	HANDLE file;
	DWORD read;
	tagTile ins[TILEX * TILEY];
	_tiles.clear();
	file = CreateFile(FileName.c_str(), GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	ReadFile(file, ins, sizeof(tagTile) * TILEX * TILEY, &read, NULL);
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		_tiles.push_back(new tagTile);
		(*_tiles[i]) = ins[i];

	}
	
	CloseHandle(file);
	return _tiles;
}

void TileMap::update()
{
	_sampleTile.find("Terrain")->second->find("springMap")->second->update();
	POINT mousePos = { _ptMouse.x + CAMERA->getCameraX(),_ptMouse.y + CAMERA->getCameraY() };
	POINT cameraStart = { CAMERA->getCameraX(),CAMERA->getCameraY() };
	POINT cameraEnd = { CAMERA->getCameraX() + WINSIZEX,CAMERA->getCameraY() + WINSIZEY };
	if (_leftButtonDown) 
	{
		for (int i = getIndex(cameraStart).y;i < getIndex(cameraEnd).y;i++)
		{
			for (int j = getIndex(cameraStart).x;j < getIndex(cameraEnd).x;j++)
			{
				if (i >= 0 && j >= 0 && i * 100 + j < _tiles.size())
				{
					if (_tiles[i * 100 + j]->getIdX() == getIndex(mousePos).x&& _tiles[i * 100 + j]->getIdY() == getIndex(mousePos).y)
					{

						break;
					}
				}
			}
		}
	}
}

void TileMap::render()
{
	POINT cameraStart = { CAMERA->getCameraX(),CAMERA->getCameraY() };
	POINT cameraEnd = { CAMERA->getCameraX()+WINSIZEX,CAMERA->getCameraY()+WINSIZEY };

	for (int i = getIndex(cameraStart).y;i < getIndex(cameraEnd).y;i++)
	{
		for (int j = getIndex(cameraStart).x;j < getIndex(cameraEnd).x;j++)
		{
			if (i >= 0 && j >= 0 && i * 100 + j < _tiles.size())
			{
				RECT ins = RectMakeCenter(_tiles[i * 100 + j]->getCenterX() - CAMERA->getCameraX(),
					_tiles[i * 100 + j]->getCenterY() - CAMERA->getCameraY(),
					TILESIZE,
					TILESIZE);
				RENDER->Rectangle(D2D1::RectF(ins.left, ins.top, ins.right, ins.bottom), D2D1::ColorF(D2D1::ColorF::Black));
			}
		}
		
	}

	_sampleTile.find("Terrain")->second->find("springMap")->second->render();
}