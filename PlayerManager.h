#pragma once
#include"Player.h"
#include"singletonBase.h"
class PlayerManager:public singletonBase<PlayerManager>
{
private:
	unordered_map<string, Player*> _player;
	unordered_map<string, Player*>::iterator _iplayer;
public:
	PlayerManager();
	~PlayerManager();

	HRESULT init();
	void update();
	void addPlayer(string name, Player* player) { _player.insert(make_pair(name, player)); }
	Player* findPlayer(string name);
};

