#pragma once
#include "singletonBase.h"
#include <map>

class gameNode;

class sceneManager : public singletonBase<sceneManager>
{
public:
	typedef map<string, gameNode*>				mapSceneList;
	typedef map<string, gameNode*>::iterator	mapSceneIter;

private:
	static gameNode* _currentScene;
	mapSceneList _mSceneList;

public:
	sceneManager();
	~sceneManager();

	HRESULT init();
	void release();
	void update();
	void render();


	gameNode* getCurrentScene() { return _currentScene; }
	gameNode* addScene(string sceneName, gameNode* scene);
	gameNode* findScene(string sceneName);
	HRESULT changeScene(string sceneName);
};

class SceneManager
{
public:
	SceneManager();
	~SceneManager();
};

