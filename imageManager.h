#pragma once
#include"image.h"
#include"singletonBase.h"
class imageManager :public singletonBase<imageManager>
{
private:
	std::unordered_map<std::string, image*> _imageMap;
	std::unordered_map<std::string, image*>::iterator _iTImageMap;
public:
	imageManager();
	~imageManager();

	HRESULT init();

	virtual void release();
	image* addImage(std::string key, std::string path, float sizeX, float sizeY);
	image* addFrameImage(std::string key, std::string path, int maxFrameX, int maxFrameY, float sizeX, float sizeY);
	image* findImage(std::string key);
};

