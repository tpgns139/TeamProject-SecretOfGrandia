#pragma once
#include"BasicScene.h"
class StageTwoScene :public BasicScene
{
public:
	StageTwoScene();
	~StageTwoScene();

	virtual HRESULT init();
	virtual void render();
};

