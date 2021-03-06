#include "stdafx.h"
#include "progressBar.h"


progressBar::progressBar()
{
}


progressBar::~progressBar()
{
}

HRESULT progressBar::init(float x, float y, int width, int height)
{
	_x = x;
	_y = y;

	_rcProgress = RectMake(x, y, width, height);

	_progressBarTop = IMAGEMANAGER->addImage("frontBar", "hpBarTop.bmp");
	_progressBarBottom = IMAGEMANAGER->addImage("backBar", "hpBarBottom.bmp");

	//뒤에 깔리는 게이지의 가로크기를 기준으로 삼는다
	_width = _progressBarBottom->getWidth();


	return S_OK;

}

void progressBar::release()
{
}

void progressBar::update()
{
	//일단은 중점으로 해둠
	_rcProgress = RectMakeCenter(_x, _y, _progressBarTop->getWidth(), _progressBarBottom->getHeight());

}

void progressBar::render()
{
	IMAGEMANAGER->findImage("backBar")->render(
		_rcProgress.left +50,
		_y + 50,
		50,
		50);

	IMAGEMANAGER->findImage("frontBar")->render(
		_rcProgress.left + 50,
		_y + 50,
		50,
		50);


}

void progressBar::setGauge(float currentGauge, float maxGauge)
{
	_width = (currentGauge / maxGauge) * _progressBarBottom->getWidth();

}
