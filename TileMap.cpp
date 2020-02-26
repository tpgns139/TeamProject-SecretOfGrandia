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
	_sampleTile.find("Terrain")->second->insert(make_pair("springMap",new SampleTile(6,6,20,20,IMAGEMANAGER->addFrameImage("springMap", "img/Tile/autumn_Tile.png",6,6))));
	showRect = false;
	return S_OK;
}

void TileMap::release()
{
	for (int i = 0; i < _tiles.size(); i++)
	{
		SAFE_DELETE(_tiles[i]);
	}
	SAFE_DELETE(_currentTile);
}

void TileMap::Start()
{
	_crtl = CTRL_NONE;
	tileSize = SCENEMANAGER->getCurrentScene()->getTileSize();
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (i * 100 + j >_tiles.size()-1||_tiles.size()==0)
			{
				_tiles.push_back(new tagTile);
				_tiles[i * 100 + j]->setIdX(j);
				_tiles[i * 100 + j]->setIdY(i);
				_tiles[i * 100 + j]->setAttribute(nonBlocking);
				_tiles[i * 100 + j]->setType(TYPE_NONE);
			}
			
			_tiles[i * 100 + j]->setCenterX(tileSize / 2 + tileSize * j);
			_tiles[i * 100 + j]->setCenterY(tileSize / 2 + tileSize * i);
			_tiles[i * 100 + j]->setRect(RectMakeCenter(
				_tiles[i * 100 + j]->getCenterX(),
				_tiles[i * 100 + j]->getCenterY(),
				tileSize,
				tileSize));

		}

	}
}

void TileMap::update()
{
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
		for (int i = getIndex(cameraStart, tileSize).y;i < getIndex(cameraEnd, tileSize).y;i++)
		{
			for (int j = getIndex(cameraStart, tileSize).x;j < getIndex(cameraEnd, tileSize).x;j++)
			{
				if (i >= 0 && j >= 0 && i * 100 + j < _tiles.size())
				{
					if (_tiles[i * 100 + j]->getIdX() == getIndex(mousePos, tileSize).x&& _tiles[i * 100 + j]->getIdY() == getIndex(mousePos, tileSize).y)
					{
						if (_crtl == CTRL_TERRAINDRAW)
						{
							_tiles[i * 100 + j]->setType(_currentTile->_type);
							_tiles[i * 100 + j]->setTerrainFrameIdx(_currentTile->x);
							_tiles[i * 100 + j]->setTerrainFrameIdY(_currentTile->y);
							break;
						}
						else if(_crtl==CTRL_COL)
						{
							_tiles[i * 100 + j]->setAttribute(blocking);
							break;
						}
						else if (_crtl == CTRL_NOTJUMP)
						{
							_tiles[i * 100 + j]->setAttribute(notJump);
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

	for (int i = getIndex(cameraStart, tileSize).y;i <= getIndex(cameraEnd, tileSize).y;i++)
	{
		for (int j = getIndex(cameraStart, tileSize).x;j <= getIndex(cameraEnd, tileSize).x;j++)
		{
			if (i >= 0 && j >= 0 && i * 100 + j < _tiles.size())
			{
				RECT ins = RectMakeCenter(_tiles[i * 100 + j]->getCenterX() - CAMERA->getCameraX(),
					_tiles[i * 100 + j]->getCenterY() - CAMERA->getCameraY(),
					tileSize,
					tileSize);
				if (showRect)
				{
					//RENDER->Rectangle(D2D1::RectF(ins.left, ins.top, ins.right, ins.bottom), D2D1::ColorF(D2D1::ColorF::Black));
				}
				if (_tiles[i * 100 + j]->getType() == TYPE_TERRAIN) 
				{
					IMAGEMANAGER->findImage("springMap")->frameRender(_tiles[i * 100 + j]->getCenterX(),
						_tiles[i * 100 + j]->getCenterY(),
						_tiles[i * 100 + j]->getTerrainFrameIdx(),
						_tiles[i * 100 + j]->getTerrainFrameIdY(),
						tileSize,
						tileSize);
				}
				
				if (showCol)
				{
					if (_tiles[i * 100 + j]->getAttribute() == notJump)
					{
						//파란색 원그리기
						RENDER->elipse(ins, D2D1::ColorF(D2D1::ColorF::Blue), true);
					}
					if (_tiles[i * 100 + j]->getAttribute() == blocking)
					{
						//검정색 원그리기
						RENDER->elipse(ins, D2D1::ColorF(D2D1::ColorF::Black), true);
					}
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
		tagTile ins[TILEX * TILEY];


		OPENFILENAME ofn;
		char filePathSize[1028] = "";
		ZeroMemory(&ofn, sizeof(OPENFILENAME));

		ofn.lStructSize = sizeof(OPENFILENAME);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = filePathSize;
		ofn.nMaxFile = sizeof(filePathSize);
		ofn.nFilterIndex = true;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = NULL;
		ofn.lpstrInitialDir = NULL;
		ofn.lpstrFilter = ("타일파일저장");
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (GetOpenFileName(&ofn) == FALSE) return;

		char temp[1028];
		strncpy_s(temp, strlen(ofn.lpstrFile) + 1, ofn.lpstrFile, strlen(ofn.lpstrFile));

		char* context = NULL;
		token = strtok_s(temp, "\\", &context);
		while (strlen(context))
		{
			token = strtok_s(NULL, "\\", &context);
		}


		for (int i = 0; i < TILEX * TILEY; i++)
		{
			ins[i] = *_tiles[i];
		}
		file = CreateFile(token, GENERIC_WRITE, 0, NULL,
			CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

		WriteFile(file, ins, sizeof(tagTile) * TILEX * TILEY, &write, NULL);

		CloseHandle(file);
}

void TileMap::load()
{

	HANDLE file;	// 이것은 파일이다.
	DWORD read;		// 이것은 리드이다.
	tagTile ins[TILEX * TILEY];	// 이것은 타일을 담을 곳이다.


	OPENFILENAME ofn;		// 이것은 오픈파일네임이다.
	char filePathSize[1028] = "";	// 이것은 파일패쓰사이즈이다.
	ZeroMemory(&ofn, sizeof(OPENFILENAME));	// 이건 제로 메모리 이다.

	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = NULL;
	ofn.lpstrFile = filePathSize;
	ofn.nMaxFile = sizeof(filePathSize);
	ofn.nFilterIndex = true;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = NULL;
	ofn.lpstrInitialDir = NULL;
	ofn.lpstrFilter = ("타일파일불러오기");
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	if (GetOpenFileName(&ofn) == FALSE) return;

	char temp[1028];
	strncpy_s(temp, strlen(ofn.lpstrFile) + 1, ofn.lpstrFile, strlen(ofn.lpstrFile));

	char* context = NULL;
	token = strtok_s(temp, "\\", &context);
	while (strlen(context))
	{
		token = strtok_s(NULL, "\\", &context);
	}
	file = CreateFile(token, GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	ReadFile(file, ins, sizeof(tagTile) * TILEX * TILEY, &read, NULL);
	_tiles.clear();
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (&ins[i] != nullptr)
		{
			_tiles.push_back(new tagTile);
			(*_tiles[i]) = ins[i];
		}
	}
	CloseHandle(file);
}
void TileMap::loadObj(string FileName, string StageName)
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
void TileMap::load(string FileName)
{
	HANDLE file;
	DWORD read;
	tagTile ins[TILEX * TILEY];	// 이것은 타일을 담을 곳이다.
	_tiles.clear();
	file = CreateFile(FileName.c_str(), GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	ReadFile(file, ins, sizeof(tagTile) * TILEX * TILEY, &read, NULL);
	_tiles.clear();
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		_tiles.push_back(new tagTile);
		(*_tiles[i]) = ins[i];
	
	}
	
	CloseHandle(file);
}