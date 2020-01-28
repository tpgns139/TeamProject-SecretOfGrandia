#pragma once
#include "image.h"
#include "TileMap.h"
#include"GameObject.h"
//����۴� ������ �Ѱ��� ������ �Ǵ� �������� �����ô�
static image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZEX, WINSIZEY);




class gameNode
{
private:
	HDC _hdc;
	bool _managerInit;
public:
	gameNode();
	virtual ~gameNode();

	int _crtSelect;

	//����ũ�μ���Ʈ ���� ����� ��ȯ���ε�
	//S_OK, E_FAIL, SUCCDED ������ �ʱ�ȭ�� �ߵƴ��� �ƴ��� ���â�� ȣ����.

	virtual HRESULT init();			//�ʱ�ȭ ���� �Լ�
	virtual HRESULT init(bool managerInit);
	virtual void release();			//�޸� ���� �Լ�
	virtual void update();			//���� ���� �Լ�
	virtual void render();			//�׸��� ���� �Լ�

	virtual void setMap();

	virtual void save();
	virtual void load();
	virtual void setGameObj(OBJSTRUCT obj);

	//������� DC�޸� ���� ������
	HDC getMemDC() { return _backBuffer->getMemDC(); }
	HDC getHDC() { return _hdc; }

	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);

};

