#include "stdafx.h"
#include "SampleTile.h"




SampleTile::SampleTile(int x, int y, int sizeX, int sizeY, image* img)
{
	maxIdX = x;
	maxIdY = y;
	_img = img;
	_sizeX = sizeX;
	_sizeY = sizeY;
	for (int i = 0;i < maxIdY;i++)
	{
		for (int j = 0;j < maxIdX;j++)
		{
			_rect.push_back(RectMakeCenter(WINSIZEX-(sizeX*maxIdX)+(sizeX / 2 + sizeX * j),
				(sizeY / 2 + sizeY * i), 
				sizeX,
				sizeY));
		}
	}
}

SampleTile::~SampleTile()
{
}

void SampleTile::update()
{
	if (_leftButtonDown) 
	{
		for (int i = 0;i < _rect.size();i++)
		{
			if (PtInRect(&_rect[i], _ptMouse))
			{
				TILEMANAGER->setCurrentTile(TYPE_TERRAIN, i %maxIdX, i / maxIdX);
				break;
			}
		}
	}
}

void SampleTile::render()
{
	_img->UIrender(WINSIZEX-maxIdX*_sizeX / 2, maxIdY*_sizeY / 2, maxIdX*_sizeX, maxIdY*_sizeY);
	for (int i = 0;i < _rect.size();i++)
	{
		RENDER->Rectangle(D2D1::RectF(_rect[i].left, _rect[i].top, _rect[i].right, _rect[i].bottom), D2D1::ColorF(D2D1::ColorF::Black));
	}
}
