#include "stdafx.h"
#include "PlayerManager.h"
#include "BasicScene.h"

PlayerManager::PlayerManager()
{
}


PlayerManager::~PlayerManager()
{
}



void PlayerManager::Start()
{
	
}

void PlayerManager::update()
{
	for (_iplayer = _player.begin(); _iplayer != _player.end(); _iplayer++)
	{
		_iplayer->second->update();
	}
}

void PlayerManager::erasePlayer(GameObject * ins)
{
	for (_iplayer = _player.begin(); _iplayer != _player.end(); )
	{
		if ((_iplayer->second)==ins)
		{

			((BasicScene*)SCENEMANAGER->getCurrentScene())->eraseObject(_iplayer->second);
			_player.erase(_iplayer);
			break;
		}
		else
		{
			_iplayer++;
		}
	}
}

Player * PlayerManager::findPlayer(string name)
{
	for (_iplayer = _player.begin(); _iplayer != _player.end(); )
	{
		if ((_iplayer->first) == name)
		{

			return _iplayer->second;
		}
		else
		{
			_iplayer++;
		}
	}
	return NULL;
}
