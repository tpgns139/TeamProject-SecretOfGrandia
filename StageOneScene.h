#pragma once
#include"BasicScene.h"


class StageOneScene:public BasicScene
{
private:
	
public:
	StageOneScene();
	~StageOneScene();

	virtual HRESULT init();
	virtual void render();
};

