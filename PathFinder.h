#pragma once
#include <deque>
#include"TileMap.h"
#include<functional>
//�� ������ ���� �� �Լ� = ��߿��� n���� + n���� ��ǥ����
//f(n) = g(n) + h(n)

#define TILEWIDTH 32
#define TILEHEIGHT 32

#define TILENUMX (WINSIZEX / TILEWIDTH)
#define TILENUMY (WINSIZEY / TILEHEIGHT)

class PathFinder :public singletonBase<PathFinder>
{
private:
	vector<tagTile*>			_vTotalList;
	vector<tagTile*>::iterator _viTotalList;
	POINT destIndex;

	vector<tagTile*> openList;
	vector<tagTile*> closeList;


	void CheckOpenList(tagTile* currentNode);
	void CreateChildNode(tagTile * parentNode, tagTile * childTile, bool overlap);

	void ReleaseList();

public:
	PathFinder();
	~PathFinder();

	vector<tagTile*> GetPath(vector<tagTile*> totalTile, tagTile * start, tagTile * end);
};

