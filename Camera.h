#pragma once
#include"singletonBase.h"
class Camera:public singletonBase<Camera>
{
private:
	float _posX, _posY;
public:
	Camera();
	~Camera();
	HRESULT init();
	float getCameraX() { return _posX; }
	float getCameraY() { return _posY; }
	void setCameraX(float x) { _posX = x; }
	void setCameraY(float y) { _posY = y; }
	
};

