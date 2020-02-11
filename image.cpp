#include "stdafx.h"
#include "Image.h"


image::image()
{
}


image::~image()
{
}
//					뿌릴 x위치,뿌릴 y위치,너비,높이
void image::render(float x, float y)
{
	::D2D1_RECT_F dxArea = ::D2D1::RectF(-_width * 0.5f, -_height * 0.5f, _width * 0.5f, _height * 0.5f);
	
	using namespace D2D1;
	Matrix3x2F trans = Matrix3x2F::Translation(x , y);
	Matrix3x2F camera = Matrix3x2F::Translation(-CAMERA->getCameraX(), -CAMERA->getCameraY());
	_rect = RectMakeCenter(x-CAMERA->getCameraX(),y-CAMERA->getCameraY(),_width,_height);

	RENDER->getRenderTarget()->SetTransform(trans*camera);

	RENDER->getRenderTarget()->DrawBitmap(_image, dxArea, 1.0f);

	//RENDER->getRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
}
//					뿌릴 x위치,뿌릴 y위치,너비,높이
void image::render(float x, float y, float Degree)
{

	::D2D1_RECT_F dxArea = ::D2D1::RectF(-_width * 0.5f, -_height * 0.5f, _width * 0.5f, _height * 0.5f);

	_rect = RectMakeCenter(x - CAMERA->getCameraX(), y - CAMERA->getCameraY(), _width, _height);
	using namespace D2D1;
	Matrix3x2F trans = Matrix3x2F::Translation(x, y);
	Matrix3x2F rot = Matrix3x2F::Rotation(Degree);

	RENDER->getRenderTarget()->SetTransform(rot * trans);

	RENDER->getRenderTarget()->DrawBitmap(_image, dxArea, 1.0f);

	RENDER->getRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
}

void image::UIrender(float x, float y)
{

	::D2D1_RECT_F dxArea = ::D2D1::RectF(-_width * 0.5f, -_height * 0.5f, _width * 0.5f, _height * 0.5f);


	_rect = RectMakeCenter(x , y , _width, _height);
	using namespace D2D1;
	Matrix3x2F trans = Matrix3x2F::Translation(x, y);


	RENDER->getRenderTarget()->SetTransform(trans);

	RENDER->getRenderTarget()->DrawBitmap(_image, dxArea, 1.0f);
}

void image::frameRender(float x, float y, int frameX, int frameY)
{
	::D2D1_RECT_F dxArea =
		::D2D1::RectF
		(
			- (_frameWidth*_maxFrameX)* 0.5f,
			- (_frameHegith*_maxFrameY) * 0.5f,
			 (_frameWidth*_maxFrameX) * 0.5f,
			 (_frameHegith*_maxFrameY) * 0.5f
		);

	_rect = RectMakeCenter(x - CAMERA->getCameraX(), y - CAMERA->getCameraY(), _frameWidth, _frameHegith);
	using namespace D2D1;
	Matrix3x2F trans = Matrix3x2F::Translation(x, y );
	RENDER->getRenderTarget()->SetTransform(trans);
	::D2D1_RECT_F frameRect = ::D2D1::RectF(frameX*_frameWidth, frameY*_frameHegith, (frameX + 1)*_frameWidth, (frameY + 1)*_frameHegith);

	RENDER->getRenderTarget()->DrawBitmap(
		_image,
		dxArea,
		1.0f,
		D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		frameRect
	);

	RENDER->getRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
}

void image::frameRender(float x, float y, float Degree, int frameX, int frameY)
{
	::D2D1_RECT_F dxArea =
		::D2D1::RectF
		(
			-(_frameWidth*_maxFrameX)* 0.5f,
			-(_frameHegith*_maxFrameY) * 0.5f,
			(_frameWidth*_maxFrameX) * 0.5f,
			(_frameHegith*_maxFrameY) * 0.5f
		);

	_rect = RectMakeCenter(x - CAMERA->getCameraX(), y - CAMERA->getCameraY(), _frameWidth, _frameHegith);
	using namespace D2D1;
	Matrix3x2F trans = Matrix3x2F::Translation(x, y);
	RENDER->getRenderTarget()->SetTransform(trans);
	::D2D1_RECT_F frameRect = ::D2D1::RectF(frameX*_frameWidth, frameY*_frameHegith, (frameX + 1)*_frameWidth, (frameY + 1)*_frameHegith);

	RENDER->getRenderTarget()->DrawBitmap(
		_image,
		dxArea,
		1.0f,
		D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		frameRect
	);

	RENDER->getRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
}
