#include "stdafx.h"
#include "PathFinder.h"

PathFinder::PathFinder()
{
}


PathFinder::~PathFinder()
{
}

vector<tagTile*> PathFinder::GetPath(vector<tagTile*> totalTile, tagTile * start, tagTile * end)
{
	vector<tagTile*> path;
	_vTotalList = totalTile;
	if (start == nullptr || end == nullptr) return move(path);
	if (end->getAttribute() == blocking) return move(path);
	if (start == end) return move(path);

	destIndex = { end->getIdX() , end->getIdY() };

	tagTile* startNode, *currentNode;
	startNode = new tagTile;
	startNode = start;
	openList.push_back(startNode);
	currentNode = startNode;

	while (true)
	{
		//열린리스트에서 가장 저렴한 길을 클로즈리스트로 이동
		size_t cheap = 0;
		for (size_t i = 1; i < openList.size(); i++)
		{
			if (openList[cheap]->getTotalCost() > openList[i]->getTotalCost())
			{
				cheap = i;
			}
		}
		currentNode = openList[cheap];
		closeList.push_back(currentNode);
		openList.erase(openList.begin() + cheap);

		//현재 계산하는 노드가 목적지인지 확인
		if (currentNode == end)
		{
			//맞다면 경로를 구성해서 넘겨줌
			while (currentNode != NULL)
			{
				path.push_back(currentNode);
				currentNode = currentNode->getParentNode();
			}
			ReleaseList();
			return move(path);

		}


		//현재 노드를 기준으로 리스트를 갱신
		CheckOpenList(currentNode);


		//검사할 길이 없다면 끝
		if (openList.size() == 0) break;


	}
	ReleaseList();
	return move(path);
}


void PathFinder::CheckOpenList(tagTile * currentNode)
{

	function<void(POINT)> AddOpenList = [&](POINT dir)
	{
		//타일의 방향들 체크
		//타일이 있는 범위를 벗어나거나, close리스트에 이미 있거나, open리스트에 이미 있거나, 이동이 붕가한 타일이거나
		POINT currentIndex = { currentNode->getIdX(),currentNode->getIdY() };
		if (currentIndex.x + dir.x < 0 || currentIndex.y + dir.y < 0
			|| currentIndex.x + dir.x >= TILENUMX
			|| currentIndex.y + dir.y >= TILENUMY)
		{
			return;
		}

		POINT checkTile = { currentIndex.x + dir.x ,  currentIndex.y + dir.y };
		tagTile* node=new tagTile;
		for (int i = 0;i < _vTotalList.size();i++)
		{
			if (_vTotalList[i]->getIdX() == checkTile.x&&
				_vTotalList[i]->getIdY() == checkTile.y)
			{
				node = _vTotalList[i];
				break;
			}
		}

		for (size_t t = 0; t < closeList.size(); t++)
		{
			if (node == closeList[t])
				return;
		}

		for (size_t t = 0; t < openList.size(); t++)
		{
			if (node->getIdX() == openList[t]->getIdX()&&
				node->getIdY() == openList[t]->getIdY())
			{
				if (openList[t]->getCostFromStart() < currentNode->getCostFromStart() + 10 * sqrtf((abs(dir.x) + abs(dir.y))))
				{
					CreateChildNode(openList[t]->getParentNode(), node,true);
					return;
				}
				
			}
		}
		attribute temp = node->getAttribute();

		if (temp == blocking)
		{
			return;
		}

		//못 지나가는 다른 예외처리 등등



		//그게 다 아니면 노드로 생성해서 검사를 수행할 open리스트에 추가
		CreateChildNode(currentNode, node,false);

	};

	AddOpenList({ -1, 0 });
	AddOpenList({ 1, 0 });
	AddOpenList({ 0, -1 });
	AddOpenList({ 0, 1 });

	AddOpenList({ -1, -1 });
	AddOpenList({ 1, 1 });
	AddOpenList({ 1, -1 });
	AddOpenList({ -1, 1 });


}

void PathFinder::CreateChildNode(tagTile * parentNode, tagTile * childTile,bool overlap)
{
	tagTile* node = new tagTile;
	node = childTile;
	node->setParentNode(parentNode);


	UINT delta = abs(childTile->getIdX() - parentNode->getIdX()) +
		abs(childTile->getIdY() - parentNode->getIdY());
	if (delta == 1)
	{
		node->setCostFromStart(parentNode->getCostFromStart() + 10);
	}
	else if (delta == 2)
	{
		node->setCostFromStart(parentNode->getCostFromStart() + 14);
	}
	tagTile* dsetTile = new tagTile;
	for (int i = 0;i < _vTotalList.size();i++)
	{
		if (_vTotalList[i]->getIdX() == destIndex.x&&
			_vTotalList[i]->getIdY() == destIndex.y)
		{
			dsetTile = _vTotalList[i];
		}
	}
	node->setCostToGoal((abs(childTile->getIdX() - dsetTile->getIdX()) +
		abs(childTile->getIdY() - dsetTile->getIdY())) * 10);

	node->setTotalCost(node->getCostFromStart() + node->getCostToGoal());
	if (!overlap) 
	{
		openList.push_back(node);
	}
}

void PathFinder::ReleaseList()
{
	openList.clear();
	closeList.clear();
}

