#include "stdafx.h"
#include "Image.h"


image::image()
{
}


image::~image()
{
}
//					뿌릴 중심x위치,뿌릴 중심y위치,너비,높이
void image::render(float x, float y, float sizeX, float sizeY)
{
	::D2D1_RECT_F dxArea = ::D2D1::RectF(-sizeX * 0.5f, -sizeY * 0.5f, sizeX * 0.5f, sizeY * 0.5f);
	
	using namespace D2D1;
	Matrix3x2F trans = Matrix3x2F::Translation(x , y);
	Matrix3x2F camera = Matrix3x2F::Translation(-CAMERA->getCameraX(), -CAMERA->getCameraY());
	_rect = RectMakeCenter(x-CAMERA->getCameraX(),y-CAMERA->getCameraY(), sizeX, sizeY);

	RENDER->getRenderTarget()->SetTransform(trans*camera);

	RENDER->getRenderTarget()->DrawBitmap(_image, dxArea, 1.0f);

	//RENDER->getRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
}
//					뿌릴 x위치,뿌릴 y위치,너비,높이
void image::render(float x, float y, float Degree, float sizeX, float sizeY)
{

	::D2D1_RECT_F dxArea = ::D2D1::RectF(-sizeX * 0.5f, -sizeY * 0.5f, sizeX * 0.5f, sizeY * 0.5f);

	_rect = RectMakeCenter(x - CAMERA->getCameraX(), y - CAMERA->getCameraY(), sizeX, sizeY);
	using namespace D2D1;
	Matrix3x2F trans = Matrix3x2F::Translation(x, y);
	Matrix3x2F camera = Matrix3x2F::Translation(-CAMERA->getCameraX(), -CAMERA->getCameraY());
	Matrix3x2F rot = Matrix3x2F::Rotation(Degree);
	RENDER->getRenderTarget()->SetTransform(rot*trans*camera);

	RENDER->getRenderTarget()->DrawBitmap(_image, dxArea, 1.0f);

	RENDER->getRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
}

void image::UIrender(float x, float y, float sizeX, float sizeY)
{

	::D2D1_RECT_F dxArea = ::D2D1::RectF(-sizeX * 0.5f, -sizeY * 0.5f, sizeX * 0.5f, sizeY * 0.5f);


	_rect = RectMakeCenter(x , y , sizeX, sizeY);
	using namespace D2D1;
	Matrix3x2F trans = Matrix3x2F::Translation(x, y);


	RENDER->getRenderTarget()->SetTransform(trans);

	RENDER->getRenderTarget()->DrawBitmap(_image, dxArea, 1.0f);
}

void image::frameRender(float x, float y, int frameX, int frameY, float sizeX, float sizeY)
{
	::D2D1_RECT_F dxArea =
		::D2D1::RectF
		(
			- (sizeX)* 0.5f,
			- (sizeY) * 0.5f,
			 (sizeX) * 0.5f,
			 (sizeY) * 0.5f
		);

	_rect = RectMakeCenter(x - CAMERA->getCameraX(), y - CAMERA->getCameraY(), sizeX, sizeY);
	using namespace D2D1;
	Matrix3x2F trans = Matrix3x2F::Translation(x, y );
	Matrix3x2F camera = Matrix3x2F::Translation(-CAMERA->getCameraX(), -CAMERA->getCameraY());
	RENDER->getRenderTarget()->SetTransform(trans*camera);
	float frameWidth = _image->GetSize().width / _maxFrameX;
	float frameHeight = _image->GetSize().height / _maxFrameY;
	::D2D1_RECT_F frameRect = ::D2D1::RectF(frameX*frameWidth, frameY*frameHeight, (frameX + 1)*frameWidth, (frameY + 1)*frameHeight);

	RENDER->getRenderTarget()->DrawBitmap(
		_image,
		dxArea,
		1.0f,
		D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		frameRect
	);

	RENDER->getRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
}

void image::frameRender(float x, float y, float Degree, int frameX, int frameY, float sizeX, float sizeY)
{
	::D2D1_RECT_F dxArea =
		::D2D1::RectF
		(
			-(sizeX*_maxFrameX)* 0.5f,
			-(sizeY*_maxFrameY) * 0.5f,
			(sizeX*_maxFrameX) * 0.5f,
			(sizeY*_maxFrameY) * 0.5f
		);

	_rect = RectMakeCenter(x - CAMERA->getCameraX(), y - CAMERA->getCameraY(), sizeX, sizeY);
	using namespace D2D1;
	Matrix3x2F trans = Matrix3x2F::Translation(x, y);
	RENDER->getRenderTarget()->SetTransform(trans);
	float frameWidth = _image->GetSize().width / _maxFrameX;
	float frameHeight = _image->GetSize().height / _maxFrameY;
	::D2D1_RECT_F frameRect = ::D2D1::RectF(frameX*frameWidth, frameY*frameHeight, (frameX + 1)*frameWidth, (frameY + 1)*frameHeight);

	RENDER->getRenderTarget()->DrawBitmap(
		_image,
		dxArea,
		1.0f,
		D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		frameRect
	);

	RENDER->getRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
}
