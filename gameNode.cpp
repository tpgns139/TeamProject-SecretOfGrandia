#include "stdafx.h"
#include "gameNode.h"


gameNode::gameNode()
{
}


gameNode::~gameNode()
{
}

HRESULT gameNode::init()
{

	_hdc = GetDC(_hWnd);
	_managerInit = false;

	
	return S_OK;
}

HRESULT gameNode::init(bool managerInit)
{
	_hdc = GetDC(_hWnd);
	_managerInit = managerInit;

	if (_managerInit)
	{
		SetTimer(_hWnd, 1, 10, NULL);
		KEYMANAGER->init();
		IMAGEMANAGER->init();
		TXTDATA->init();
		TIMEMANAGER->init();
		EFFECTMANAGER->init();
		SOUNDMANAGER->init();
		ENEMYMANAGER->init();
		SCENEMANAGER->init();
		KEYANIMANAGER->init();
		CAMERA->init();
		RENDER->initRenderTager(_hWnd);
		TILEMANAGER->init();
	}

	return S_OK;
}

void gameNode::release()
{
	if (_managerInit)
	{
		KillTimer(_hWnd, 1);
		KEYMANAGER->release();
		KEYMANAGER->releaseSingleton();
		IMAGEMANAGER->release();
		IMAGEMANAGER->releaseSingleton();
		TXTDATA->release();
		TXTDATA->releaseSingleton();
		TIMEMANAGER->release();
		TIMEMANAGER->releaseSingleton();
		EFFECTMANAGER->release();
		EFFECTMANAGER->releaseSingleton();
		SOUNDMANAGER->release();
		SOUNDMANAGER->releaseSingleton();
		SCENEMANAGER->release();
		SCENEMANAGER->releaseSingleton();
		KEYANIMANAGER->release();
		KEYANIMANAGER->releaseSingleton();
		TILEMANAGER->release();
		TILEMANAGER->releaseSingleton();
		CAMERA->releaseSingleton();
		RENDER->releaseSingleton();
		ENEMYMANAGER->release();
		ENEMYMANAGER->releaseSingleton();
	}

	ReleaseDC(_hWnd, _hdc);
}

void gameNode::Start()
{
}

void gameNode::update()
{
	InvalidateRect(_hWnd, NULL, false);
	SOUNDMANAGER->update();
}

void gameNode::render()
{

}

void gameNode::setMap()
{
}

void gameNode::save()
{
}

void gameNode::load()
{
}

void gameNode::setGameObj(OBJSTRUCT obj)
{
}

float gameNode::getTileSize()
{
	return 0.0f;
}

LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{

	PAINTSTRUCT ps;
	HDC			hdc;

	switch (iMessage)
	{
		case WM_CREATE:

		break;
		case WM_PAINT:
		{
			this->render();
		}
		break;
		case WM_TIMER:
			this->update();
		break;

		//���� ���ļ� ��� �ּ����� ���� ���������ض�
		//���� �̷��� �ϴ� ������ �������� �������� ��ȹ�� ��ȹ�ڵ��� �ϴٺ���
		//MFC ������ ������ ������ ���� ��ȹ��Ʈ�� �Ѱ��ִ� ���� �ٹݻ翴��
		//�׷��� �ɹ��������� ���� ������ ��ɸ� ž���ؼ� �Ѱ����.
		//���� ������ �޽����� ������� �ʰ� �츮 ��ҿ� �ϴ���� �ϸ� 
		//�̷� ������ ���ĵ� �˴ϴ�
		case WM_LBUTTONDOWN:
			_leftButtonDown = true;
		break;
		case WM_LBUTTONUP:
			_leftButtonDown = false;
		break;
		case WM_MOUSEMOVE:
			_ptMouse.x = static_cast<float>(LOWORD(lParam));
			_ptMouse.y = static_cast<float>(HIWORD(lParam));

		break;

		
		break;

		case WM_KEYDOWN:
		{
			switch (wParam)
			{
				case VK_ESCAPE:
					PostQuitMessage(0);
				break;

			}
		}
		break;


		case WM_DESTROY:
			PostQuitMessage(0);
		break;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
