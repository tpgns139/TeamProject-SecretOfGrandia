#include "stdafx.h"
#include "Camera.h"


Camera::Camera()
{
}


Camera::~Camera()
{
}

HRESULT Camera::init()
{
	_posX = 0;
	_posY = 0;
	return S_OK;
}
