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
	_sampleTile.find("Terrain")->second->insert(make_pair("springMap",new SampleTile(12,12,20,20,IMAGEMANAGER->addFrameImage("springMap", "img/Tile/autumn_Tile.png",12,12))));
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
	_tiles.clear();
	file = CreateFile(FileName.c_str(), GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		_tiles.push_back(new tagTile);
		ReadFile(file, _tiles[i], sizeof(tagTile) * TILEX * TILEY, &read, NULL);

	}
	
	CloseHandle(file);
	return _tiles;
}

void TileMap::update()
{
	_tileAmount = _tiles.size();
	switch (_crtl)
	{
	case CTRL_TERRAINDRAW:
		_currentSampleTile =_sampleTile.find("Terrain")->second->find("springMap")->second;
		break;
	case CTRL_ERASER:
		_currentSampleTile = nullptr;
		break;

	}
	if(_currentSampleTile)
	{
		_currentSampleTile->update();
	}
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
						if (_crtl == CTRL_TERRAINDRAW)
						{
							_tiles[i * 100 + j]->setType(_currentTile->_type);
							_tiles[i * 100 + j]->setTerrainFrameIdx(_currentTile->x);
							_tiles[i * 100 + j]->setTerrainFrameIdY(_currentTile->y);
							break;
						}
						else
						{
							_tiles[i * 100 + j]->setType(TYPE_NONE);
							_tiles[i * 100 + j]->setTerrainFrameIdx(0);
							_tiles[i * 100 + j]->setTerrainFrameIdY(0);
							break;
						}
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
				if (_tiles[i * 100 + j]->getType() == TYPE_TERRAIN) 
				{
					IMAGEMANAGER->findImage("springMap")->frameRender(_tiles[i * 100 + j]->getCenterX(),
						_tiles[i * 100 + j]->getCenterY(),
						_tiles[i * 100 + j]->getTerrainFrameIdx(),
						_tiles[i * 100 + j]->getTerrainFrameIdY(),
						TILESIZE,
						TILESIZE);
				}
			}
		}
		
	}
	if (_currentSampleTile) 
	{
		_currentSampleTile->render();
	}
}
void TileMap::save()
{
	//파일저장 하는거 옛날에 해봤쥬? 그걸로 저장하면 됨.
//확장자는 .map 으로 저장한다.
	HANDLE file;
	DWORD write;
	DWORD read;

	file = CreateFile("mapSave.map", GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	for (int i = 0;i < _tiles.size();i++)
	{
		WriteFile(file, _tiles[i], sizeof(tagTile), &write, NULL);
	}

	CloseHandle(file);
}