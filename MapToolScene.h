#pragma once
#include"BasicScene.h"
class MapToolScene:public BasicScene
{
private:
	unordered_map<string, image*> _buttonMap;
	unordered_map<string, image*>::iterator _buttonMapIter;
public:
	MapToolScene();
	~MapToolScene();

	HRESULT init();
	virtual void update();
	virtual void render();
};

