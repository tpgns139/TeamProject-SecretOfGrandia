#include "stdafx.h"
#include "ImageManager.h"
#include"Render.h"

imageManager::imageManager()
{
}


imageManager::~imageManager()
{
}

HRESULT imageManager::init()
{
	return S_OK;
}

void imageManager::release()
{
}

image * imageManager::addFrameImage(std::string key, std::string path, int maxFrameX, int maxFrameY)
{
	//--------------------------------------
	//���ڴ��� �����Ѵ�.
	//--------------------------------------
	IWICBitmapDecoder*	decoderPtr = nullptr;
	HRESULT hr = E_FAIL;

	std::wstring _wString = std::wstring(path.begin(), path.end());
	LPCWSTR FilePath = _wString.c_str();


	hr = RENDER->getImageFactory()->CreateDecoderFromFilename(FilePath, nullptr, GENERIC_READ, WICDecodeMetadataCacheOnDemand, &decoderPtr);
	assert(hr == S_OK);


	//���ڴ����� �������� ��´�
	IWICBitmapFrameDecode* framePtr = nullptr;
	hr = decoderPtr->GetFrame(0, &framePtr);
	assert(hr == S_OK);
	//�������� ������� �ؼ� ���� �����͸� �����.
	IWICFormatConverter* converter = RENDER->getSrcBmp();
	//SafeRelease(converter);
	hr = RENDER->getImageFactory()->CreateFormatConverter(&converter);
	assert(hr == S_OK);

	hr = converter->Initialize(
		framePtr,
		GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone,
		nullptr,
		0.0f,
		WICBitmapPaletteTypeCustom
	);
	assert(hr == S_OK);
	//����Ʈ�� �����͸� ������� �ؼ� ���� ��Ʈ���� �����.
	ID2D1Bitmap* bitmap = RENDER->getBitmap();
	SafeRelease(bitmap);
	hr = RENDER->getRenderTarget()->CreateBitmapFromWicBitmap
	(
		converter,
		nullptr,
		&bitmap
	);
	assert(hr == S_OK);
	SafeRelease(decoderPtr);
	SafeRelease(framePtr);
	image* _image = new image;
	_image->setImage(bitmap);
	_image->setMaxFrameX(maxFrameX);
	_image->setMaxFrameY(maxFrameY);
	_image->setFrameHeight(bitmap->GetSize().height / maxFrameY);
	_image->setFrameWidth(bitmap->GetSize().width / maxFrameX);

	_imageMap.insert(std::make_pair(key, _image));
	return _image;
}

image* imageManager::addImage(std::string key, std::string path)
{
	//--------------------------------------
	//���ڴ��� �����Ѵ�.
	//--------------------------------------
	IWICBitmapDecoder*	decoderPtr = nullptr;
	HRESULT hr = E_FAIL;

	std::wstring _wString = std::wstring(path.begin(), path.end());
	LPCWSTR FilePath = _wString.c_str();


	hr = RENDER->getImageFactory()->CreateDecoderFromFilename(FilePath, nullptr, GENERIC_READ, WICDecodeMetadataCacheOnDemand, &decoderPtr);
	assert(hr == S_OK);


	//���ڴ����� �������� ��´�
	IWICBitmapFrameDecode* framePtr = nullptr;
	hr = decoderPtr->GetFrame(0, &framePtr);
	assert(hr == S_OK);
	//�������� ������� �ؼ� ���� �����͸� �����.
	IWICFormatConverter* converter = RENDER->getSrcBmp();
	//SafeRelease(converter);
	hr = RENDER->getImageFactory()->CreateFormatConverter(&converter);
	assert(hr == S_OK);

	hr = converter->Initialize(
		framePtr,
		GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone,
		nullptr,
		0.0f,
		WICBitmapPaletteTypeCustom
	);
	assert(hr == S_OK);
	//����Ʈ�� �����͸� ������� �ؼ� ���� ��Ʈ���� �����.
	ID2D1Bitmap* bitmap = RENDER->getBitmap();
	SafeRelease(bitmap);
	hr = RENDER->getRenderTarget()->CreateBitmapFromWicBitmap
	(
		converter,
		nullptr,
		&bitmap
	);
	assert(hr == S_OK);
	SafeRelease(decoderPtr);
	SafeRelease(framePtr);
	image* _image = new image;
	_image->setImage(bitmap);

	_imageMap.insert(std::make_pair(key, _image));
	return _image;

}
image * imageManager::findImage(std::string key)
{
	for (_iTImageMap = _imageMap.begin(); _iTImageMap != _imageMap.end(); _iTImageMap++)
	{
		if (_iTImageMap->first == key)
		{
			return _iTImageMap->second;
		}
	}
	return nullptr;
}
