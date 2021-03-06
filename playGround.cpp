#include "stdafx.h"
#include "playGround.h"
#include "TileMap.h"

playGround::playGround()
{
}


playGround::~playGround()
{
}


HRESULT playGround::init()
{
	gameNode::init(true);

	SCENEMANAGER->addScene("maptoolScene", new MapToolScene);
	SCENEMANAGER->addScene("stageOne", new StageOne);
	SCENEMANAGER->changeScene("maptoolScene");



	return S_OK;
}


void playGround::release()
{
	gameNode::release();


}


void playGround::update()
{
	gameNode::update();
	SCENEMANAGER->update();
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		SCENEMANAGER->changeScene("stageOne");
	}
}




void playGround::render()
{
	RENDER->getRenderTarget()->BeginDraw();
	RENDER->getRenderTarget()->Clear(D2D1::ColorF(D2D1::ColorF::Gray));
	//========================================================
	SCENEMANAGER->render();

//====================================================
	RENDER->getRenderTarget()->EndDraw();
}

