#include "stdafx.h"
#include "TileMap.h"
#include"gameNode.h"

TileMap::TileMap()
{
}


TileMap::~TileMap()
{
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