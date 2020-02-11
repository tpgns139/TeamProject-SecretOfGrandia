#pragma once
class image
{
private:
	ID2D1Bitmap* _image;
	RECT _rect;
	int _frameX, _frameY, _maxFrameX, _maxFrameY;
	float _width, _height;
	float _frameWidth, _frameHegith;

public:
	image();
	~image();

	void setMaxFrameX(int maxX) { _maxFrameX = maxX; }
	int getMaxFrameX() { return _maxFrameX; }

	void setMaxFrameY(int maxY) { _maxFrameY = maxY; }
	int getMaxFrameY() { return _maxFrameY; }

	void setImage(ID2D1Bitmap* image) {_image = image; }
	void setWidth(float width) { _width = width; }
	void setHeight(float height) { _height = height; }
	void setFrameWidth(float frameWidth) { _frameWidth = frameWidth; }
	void setFrameHeight(float frameHeight) { _frameHegith = frameHeight; }


	void render(float x, float y);
	void render(float x, float y, float Degree);
	void UIrender(float x, float y);

	float getWidth() { return _width; }
	float getHeight() { return _height; }

	float getFrameWidth() { return _frameWidth; }
	float getFrameHeight() { return _frameHegith; }


	void frameRender(float x, float y,  int frameX, int frameY);
	void frameRender(float x, float y,  float Degree, int frameX, int frameY);

	float getX() { return 0; }
	void setX(float X){}
	
	float getY() { return 0; }
	void setY(float Y){}

	RECT getRect() 
	{
		return _rect;
	}
};

