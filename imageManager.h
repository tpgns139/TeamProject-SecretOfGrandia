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
	image* addImage(std::string key, std::string path);
	image* findImage(std::string key);
};

