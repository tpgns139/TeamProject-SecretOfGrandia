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

void Camera::setCameraX(float x)
{
	 _posX = x; 
	 if (_posX < 0)
	 {
		 _posX = 0;
	 }
}

void Camera::setCameraY(float y)
{
	_posY = (int)y;
	if (_posY < 0)
	{
		_posY = 0;
	}
}
