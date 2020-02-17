#include "stdafx.h"
#include "PlayerManager.h"


PlayerManager::PlayerManager()
{
}


PlayerManager::~PlayerManager()
{
}

Player * PlayerManager::findPlayer(string name)
{
	return _player.find(name)->second;
}
