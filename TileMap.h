#pragma once
#include<fstream>
#include <commdlg.h> //OPENFILENAME�� ���� ���
#include"tagTile.h"
#include"SampleTile.h"
enum OBJECT
{
	Monster,
	Character
};
struct tagSampleTile
{
	RECT rcTile;
	int terrainFrameX;
	int terrainFrameY;
};
enum CTRL
{
	CTRL_SAVE,			//���̺� ��ư���� ���� ��
	CTRL_LOAD,			//�ε� ��ư���� ���� ��
	CTRL_TERRAINDRAW,	//���� �׸��� ��ư
	CTRL_OBJDRAW,		//������Ʈ �׸��� ��ư (��, ���ʹ� ��)
	CTRL_ERASER,		//���찳 ��ư (�߸����� ������Ʈ���� ��������)
	CTRL_COL,
	CTRL_COLERASE,
	CTRL_NONE
};
//���� Ÿ�� == ���� Ŭ���� ����Ÿ�� ������ ������ ����ü
struct tagCurrentTile
{
	TYPE _type;
	int x;
	int y;
};
struct OBJSTRUCT
{
	POINT center;
	RECT rc;
	OBJECT kinds;
	frameImage frame;
};
//TileManger
typedef unordered_map<string, SampleTile*> sampleMap;
class TileMap :public singletonBase<TileMap>
{
private:
	vector<tagTile*>		_tiles; // Ÿ�ϸ��ʵ�
	vector<OBJSTRUCT>		_Vobj;
	char*					token;	//���� �� �ε带 ���� ��ū
	CTRL					_crtl;
	unordered_map<string, sampleMap*> _sampleTile;
	tagCurrentTile*			_currentTile;
public:
	HRESULT init();
	void release();
	std::ifstream::pos_type filesize(const char* filename);

	virtual void loadObj(string FileName, string StageName);
	vector<tagTile*> load(string FileName);
	vector<tagTile*> getTotalTile() { return _tiles; }

	POINT getIndex(POINT centerPos) 
	{
		POINT ins = { centerPos.x / TILESIZE,centerPos.y / TILESIZE };
		return ins;
	}
	void setCTRL(CTRL ins) { _crtl = ins; }
	CTRL getCTRL() { return _crtl; }
	void update();

	void render();
	TileMap();
	~TileMap();

	void setCurrentTile(TYPE _type, int indexX, int indexY);

	void setSampleTile(image* image);
};

