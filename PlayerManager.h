#pragma once
#include"Player.h"
#include"singletonBase.h"
class PlayerManager:public singletonBase<PlayerManager>
{
private:
	map<string, Player*> _player;
	map<string, Player*>::iterator _iplayer;
public:
	PlayerManager();
	~PlayerManager();

	void Start();
	void update();
	void addPlayer(string name, Player* player) { _player.insert(make_pair(name, player)); }
	void erasePlayer(GameObject* ins);
	Player* findPlayer(string name);
};

