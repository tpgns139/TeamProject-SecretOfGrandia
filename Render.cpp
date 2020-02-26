#include "stdafx.h"
#include "Render.h"


Render::Render()
{
}


Render::~Render()
{
}
void Render::initalizeD2D()
{
	CoInitialize(NULL);

	HRESULT hr = E_FAIL;
	//-------------------------
	//	D2D Factory를 생성한다.
	//-------------------------
	hr = ::D2D1CreateFactory(
		D2D1_FACTORY_TYPE_SINGLE_THREADED,
		&_D2DFactory);
	assert(hr == S_OK);
	//--------------------------------------
	//Windows Imagind Component Factory 생성
	//--------------------------------------
	hr = ::CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&_WICFactory));
	assert(hr == S_OK);

}

void Render::createRenderTarget(HWND hWnd)
{
	//------------------------------------
	//윈도우 클라이언트 영역을 얻는다.
	//------------------------------------
	RECT winRc;
	::GetClientRect(hWnd, &winRc);

	//윈도우 클라이언트 렉트의 사이즈를 얻는다.
	//								가로,세로하면 저절로 크기가 넘어감
	D2D1_SIZE_U size = D2D1::SizeU(winRc.right - winRc.left, winRc.bottom - winRc.top);

	HRESULT hr = _D2DFactory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(hWnd, size),
		&_D2DRenderTaget);
	assert(hr == S_OK);
}

void Render::initRenderTager(HWND hWnd)
{
	CoInitialize(NULL);
	initalizeD2D();
	createRenderTarget(hWnd);
}

void Render::Rectangle(RECT rc, D2D1_COLOR_F color, bool fill)
{
	ID2D1SolidColorBrush *brush = 0;
	D2D1_RECT_F _relativeRect = { rc.left-CAMERA->getCameraX(),rc.top-CAMERA->getCameraY(),rc.right - CAMERA->getCameraX(),rc.bottom - CAMERA->getCameraY() };
	_D2DRenderTaget->CreateSolidColorBrush(color, &brush);
	_D2DRenderTaget->DrawRectangle(_relativeRect, brush);
	if(fill)
	_D2DRenderTaget->FillRectangle(_relativeRect, brush);
	_D2DRenderTaget->SetTransform(D2D1::Matrix3x2F::Identity());
	SafeRelease(brush);
}

void Render::elipse(RECT rc, D2D1_COLOR_F color, bool fill )
{
	ID2D1SolidColorBrush *brush = 0;
	_D2DRenderTaget->CreateSolidColorBrush(color, &brush);
	_D2DRenderTaget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F((rc.left+rc.right)/2.0f, (rc.top+rc.bottom)/2.0f), (rc.right-rc.left)/2.0f, (rc.bottom-rc.top)/2.0f), brush);
	if(fill)
	_D2DRenderTaget->FillEllipse(D2D1::Ellipse(D2D1::Point2F((rc.left + rc.right) / 2.0f, (rc.top + rc.bottom) / 2.0f), (rc.right - rc.left) / 2.0f, (rc.bottom - rc.top) / 2.0f),brush);
	_D2DRenderTaget->SetTransform(D2D1::Matrix3x2F::Identity());
	SafeRelease(brush);
}
