#pragma once
#include"image.h"
class SampleTile
{
private:
	int maxIdX, maxIdY;
	image* _img;
	vector<RECT> _rect;
	float _sizeX, _sizeY;
public:
	SampleTile(int x,int y, int sizeX, int sizeY, image* img);
	~SampleTile();
	void update();
	void render();
};

