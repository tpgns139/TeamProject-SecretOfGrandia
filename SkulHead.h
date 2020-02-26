#pragma once
#include"GameObject.h"
#define HeadSpeed  20
enum H_Dir
{
	H_Left,
	H_Right
};
class SkulHead:public GameObject
{
private:
	bool _throwHead,_stopMoving;
	float _angle,_xSpeed,_ySpeed;

	float _elipseTime, _flyTime, _gravity;
	H_Dir _direction;
	unordered_map<string, RECT>						_bodyRect;

public:
	SkulHead(float Xpos, float Ypos);
	~SkulHead();

	void Start();
	virtual HRESULT init();
	virtual void update();
	virtual void render();
	void useHeadThrow(POINT Pos,int dir);
	void resetHead();
	void moveHead();
	void setRect();
	void colCheck();
};

