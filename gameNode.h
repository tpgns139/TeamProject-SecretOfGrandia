#pragma once
#include "image.h"
#include "TileMap.h"




class gameNode
{
private:
	HDC _hdc;
	bool _managerInit;
public:
	gameNode();
	virtual ~gameNode();

	int _crtSelect;

	//마이크로소프트 전용 디버깅 반환자인데
	//S_OK, E_FAIL, SUCCDED 등으로 초기화가 잘됐는지 아닌지 출력창에 호출함.

	virtual HRESULT init();			//초기화 전용 함수
	virtual HRESULT init(bool managerInit);
	virtual void release();			//메모리 해제 함수
	virtual void Start();
	virtual void update();			//연산 전용 함수
	virtual void render();			//그리기 전용 함수

	virtual void setMap();

	virtual void save();
	virtual void load();
	virtual void setGameObj(OBJSTRUCT obj);
	virtual float getTileSize();
	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);

};

