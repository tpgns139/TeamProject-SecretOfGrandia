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

	_progressBarTop = IMAGEMANAGER->addImage("frontBar", "hpBarTop.bmp", width,height);
	_progressBarBottom = IMAGEMANAGER->addImage("backBar", "hpBarBottom.bmp",width,height);

	//�ڿ� �򸮴� �������� ����ũ�⸦ �������� ��´�
	_width = _progressBarBottom->getWidth();


	return S_OK;

}

void progressBar::release()
{
}

void progressBar::update()
{
	//�ϴ��� �������� �ص�
	_rcProgress = RectMakeCenter(_x, _y, _progressBarTop->getWidth(), _progressBarBottom->getHeight());

}

void progressBar::render()
{
	IMAGEMANAGER->findImage("backBar")->render(
		_rcProgress.left + _progressBarBottom->getWidth() / 2,
		_y + _progressBarBottom->getHeight() / 2);

	IMAGEMANAGER->findImage("frontBar")->render(
		_rcProgress.left + _progressBarBottom->getWidth() / 2,
		_y + _progressBarBottom->getHeight() / 2);


}

void progressBar::setGauge(float currentGauge, float maxGauge)
{
	_width = (currentGauge / maxGauge) * _progressBarBottom->getWidth();

}
