#pragma once
#include"gameNode.h"
#include"GameObject.h"
#include"Slime.h"
#include"Rabbit.h"
#include"Hydra.h"
#include"Flower.h"
#include"Hydra_W.h"

class BasicScene:public gameNode
{
protected:
	vector<GameObject*> _gameObj;
	vector<tagTile*>		 _tiles; // ≈∏¿œ∏ « µÂ

	float tileSize;
public:
	virtual HRESULT init();
	virtual void Start();
	virtual void setGameObj(OBJSTRUCT obj);
	void settingObj(GameObject* ins);
	void eraseObject(GameObject* ins);
	virtual void update();
	virtual void render();
	float getTileSize();
	BasicScene();
	~BasicScene();
};

