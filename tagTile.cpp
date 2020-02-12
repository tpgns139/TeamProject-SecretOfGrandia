#include "stdafx.h"

void tagTile::render()
{
	switch (type)
	{
	case TYPE_TERRAIN:
		IMAGEMANAGER->findImage("springMap")->frameRender(center.x, center.y, terrainFrameX, terrainFrameY, TILESIZE, TILESIZE);
		break;
	case TYPE_TERRAIN2:
		break;
	case TYPE_TERRAIN3:
		break;
	case TYPE_TERRAIN4:
		break;
	case TYPE_TERRAIN5:
		break;
	case TYPE_TERRAIN6:
		break;
	case TYPE_NONE:
		break;
	default:
		break;
	}
}
