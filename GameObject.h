#pragma once


class GameObject
{
private:
	frameImage _frame;
	image* _image;
	OBJECT _kinds;
	POINT _center;
	RECT _rc;

public:
	GameObject();
	~GameObject();


	virtual void update();
	virtual HRESULT init();
	void setFrame(frameImage fm) { _frame = fm; }
	frameImage getFrame() { return _frame; }

	void setimage(image* im) { _image = im; }
	image* getImage() { return _image; }

	void setOBJECT(OBJECT obj) { _kinds = obj; }
	OBJECT getObject() { return _kinds; }

	void setCenter(POINT centerPoint) { _center = centerPoint; }
	POINT getCenter() { return _center; }

	RECT getRect() { return _rc; }
	void setRect(RECT rc) { _rc = rc; }
};


