#include "stdafx.h"
#include "SkulHead.h"

#define PI 3.141592
#define DEGREE  PI/180

SkulHead::SkulHead(float Xpos, float Ypos)
{
	_center.x = Xpos;
	_center.y = Ypos;	
	_throwHead = false;
}

SkulHead::~SkulHead()
{
}

HRESULT SkulHead::init()
{
	_frame = G_notFrame;
	_image = IMAGEMANAGER->findImage("SkulRightHead");
	_size.x = 25;
	_size.y = 25;
	_ySpeed = 0;
	_xSpeed = 0;
	_gravity = 5;
	_stopMoving = false;
	_throwHead = false;
	_bodyRect.insert(make_pair("body", RectMakeCenter(_center.x, _center.y, 100, 100)));
	_bodyRect.insert(make_pair("bottom", RectMakeCenter(_center.x, _center.y, 100, 100)));
	_bodyRect.insert(make_pair("rightBody", RectMakeCenter(_center.x, _center.y, 100, 100)));
	_bodyRect.insert(make_pair("leftBody", RectMakeCenter(_center.x, _center.y, 100, 100)));
	_elipseTime = 0.5f;
	return S_OK;
}

void SkulHead::Start()
{
}



void SkulHead::update()
{
	if (_stopMoving)
	{
		_flyTime += _elipseTime;
		
	}
	else
	{
		_flyTime = 0;
	}
	colCheck();

	moveHead();
	setRect();

}

void SkulHead::render()
{
	
	_image->render(_center.x, _center.y,_angle ,_size.x, _size.y);

	
}

void SkulHead::useHeadThrow(POINT Pos, int dir)
{
	_direction = (H_Dir)dir;
	switch (_direction)
	{
	case H_Left:
		_image = IMAGEMANAGER->findImage("SkulLeftHead");
		_xSpeed = -HeadSpeed;
		break;
	case H_Right:
		_image = IMAGEMANAGER->findImage("SkulRightHead");
		_xSpeed = HeadSpeed;
		break;
	default:
		break;
	}
	
	_throwHead = true;
	_angle = 0;
	_center = Pos;
}

void SkulHead::resetHead()
{
	_stopMoving = false;
	_throwHead = false;
	_center.y = -500;
	_center.x = -500;
	_xSpeed = 0;
	_ySpeed = 0;
	_flyTime = 0;
	setRect();
}

void SkulHead::moveHead()
{
	if (_throwHead)
	{
		if (_stopMoving)
		{
			_center.y += _ySpeed + (_gravity * _flyTime) / 2.0f;
		}
		else
		{
			switch (_direction)
			{
			case H_Left:
				_angle -= 15;
				break;
			case H_Right:
				_angle += 15;
				break;
			}
		}
		_center.x += _xSpeed;

	}
	
}

void SkulHead::setRect()
{
	unordered_map<string, RECT>::iterator	iRect;
	for (iRect = _bodyRect.begin(); iRect != _bodyRect.end(); iRect++)
	{
		if (iRect->first == "body")
		{
			iRect->second = RectMakeCenter(_center.x, _center.y, _size.x, _size.y);
		}
		if (iRect->first == "bottom")
		{
			iRect->second = RectMakeCenter(_center.x, _center.y + (_size.y/2.0f)+1, _size.x, 2);
		}
		if (iRect->first == "rightBody")
		{
			iRect->second = RectMakeCenter(_center.x +((_size.x / 2.0f) + 1), _center.y, 2, _size.y);
		}
		if (iRect->first == "leftBody")
		{
			iRect->second = RectMakeCenter(_center.x -((_size.x / 2.0f) + 1), _center.y, 2, _size.y);
		}
	}
}

void SkulHead::colCheck()
{
	unordered_map<string, RECT>::iterator	iRect;
	if (PLAYERMANAGER->findPlayer("PlayerOne") != nullptr)
	{
		RECT* playerRect = PLAYERMANAGER->findPlayer("PlayerOne")->getRect("body");

		for (iRect = _bodyRect.begin(); iRect != _bodyRect.end(); iRect++)
		{
			POINT point = TILEMANAGER->getIndex(PointMake((iRect->second.left + iRect->second.right) / 2, (iRect->second.bottom + iRect->second.top) / 2), TILESIZE);
			if (iRect->first == "body")
			{
				if (_stopMoving)
				{
					RECT HeadBody = iRect->second;
					RECT Temp;
					if (IntersectRect(&Temp, playerRect, &HeadBody))
					{
						PLAYERMANAGER->findPlayer("PlayerOne")->resetSkill();
						resetHead();
					}
				}
			}
			if (point.x + point.y * 100 >= 0 && point.x + point.y * 100 < TILEMANAGER->getTotalTile().size())
			{
				if (iRect->first == "bottom")
				{
					if (TILEMANAGER->getTotalTile()[point.x + point.y * 100]->getAttribute() != nonBlocking)
					{
						_center.y = TILEMANAGER->getTotalTile()[point.x + point.y * 100]->getRect().top - (_size.y / 2.0f);
						_xSpeed -= _xSpeed * 0.8;
						_flyTime = 0;
						_ySpeed = 0;
					}

				}
				if (!_stopMoving)
				{
					if (iRect->first == "rightBody")
					{
						if (TILEMANAGER->getTotalTile()[point.x + point.y * 100]->getAttribute() != nonBlocking)
						{
							_stopMoving = true;
							float randAngle = (RND->getFromFloatTo(90, 270)) + 180;
							_xSpeed = -(_xSpeed*cos(randAngle*DEGREE))*0.5f;
							_ySpeed = (_xSpeed*sinf((randAngle*DEGREE)))*0.5f;
						}
					}
					if (iRect->first == "leftBody")
					{
						if (TILEMANAGER->getTotalTile()[point.x + point.y * 100]->getAttribute() != nonBlocking)
						{
							_stopMoving = true;
							float randAngle = (RND->getFromFloatTo(90, 270)) + 180;
							_xSpeed = -(_xSpeed*cos(randAngle*DEGREE))*0.5f;
							_ySpeed = (_xSpeed*sinf((randAngle*DEGREE)))*0.5f;
						}
					}
				}
			}
		}

	}
}
