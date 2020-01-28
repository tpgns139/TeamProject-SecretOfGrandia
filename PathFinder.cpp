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
		//��������Ʈ���� ���� ������ ���� Ŭ�����Ʈ�� �̵�
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

		//���� ����ϴ� ��尡 ���������� Ȯ��
		if (currentNode == end)
		{
			//�´ٸ� ��θ� �����ؼ� �Ѱ���
			while (currentNode != NULL)
			{
				path.push_back(currentNode);
				currentNode = currentNode->getParentNode();
			}
			ReleaseList();
			return move(path);

		}


		//���� ��带 �������� ����Ʈ�� ����
		CheckOpenList(currentNode);


		//�˻��� ���� ���ٸ� ��
		if (openList.size() == 0) break;


	}
	ReleaseList();
	return move(path);
}


void PathFinder::CheckOpenList(tagTile * currentNode)
{

	function<void(POINT)> AddOpenList = [&](POINT dir)
	{
		//Ÿ���� ����� üũ
		//Ÿ���� �ִ� ������ ����ų�, close����Ʈ�� �̹� �ְų�, open����Ʈ�� �̹� �ְų�, �̵��� �ذ��� Ÿ���̰ų�
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

		//�� �������� �ٸ� ����ó�� ���



		//�װ� �� �ƴϸ� ���� �����ؼ� �˻縦 ������ open����Ʈ�� �߰�
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

