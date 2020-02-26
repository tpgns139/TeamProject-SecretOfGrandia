#pragma once
enum multiImage
{
	G_notFrame,
	G_Frame
};
class GameObject
{
protected:
	image* _image;
	POINT _center,_size,_currentFrame;
	RECT _rc;
	multiImage _frame;

public:
	GameObject();
	~GameObject();

	virtual HRESULT init();
	virtual void update();
	image* getImage() { return _image; }
	multiImage getFrame() { return _frame; }
	POINT getCenter() { return _center; }
	POINT getSize() { return _size; }
	POINT getCurrentFrameNum(){return _currentFrame;}
	virtual RECT* getRect(string name);
	virtual void render();
};


