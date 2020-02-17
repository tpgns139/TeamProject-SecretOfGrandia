#pragma once
#include"BasicScene.h"
class StageOne:public BasicScene
{
public:
	StageOne();
	~StageOne();


	virtual HRESULT init();
	virtual void Start();
	virtual void update();
	virtual void render();
};

