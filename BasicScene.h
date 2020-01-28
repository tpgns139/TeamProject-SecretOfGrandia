#pragma once
#include"gameNode.h"
#include"GameObject.h"
#include"Slime.h"
#include"Rabbit.h"
#include"Hydra.h"
#include"Flower.h"
class BasicScene:public gameNode
{
protected:
	vector<GameObject*> _gameObj;
	vector<tagTile*>		 _tiles; // ≈∏¿œ∏ « µÂ
public:
	virtual void setGameObj(OBJSTRUCT obj);
	void settingObj(GameObject* ins, OBJSTRUCT obj);
	virtual void update();
	virtual void render();
	BasicScene();
	~BasicScene();
};

