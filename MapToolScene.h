#pragma once
#include"BasicScene.h"
#define TILESIZE 16
class MapToolScene:public BasicScene
{
private:
	unordered_map<string, image*> _buttonMap;
	unordered_map<string, image*>::iterator _buttonMapIter;
public:
	MapToolScene();
	~MapToolScene();

	virtual HRESULT init();
	virtual void Start();
	virtual void update();
	virtual void render();
};

