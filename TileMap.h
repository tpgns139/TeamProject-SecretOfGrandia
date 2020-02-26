#pragma once
#include<fstream>
#include <commdlg.h> //OPENFILENAME�� ���� ���
#include"tagTile.h"
#include"SampleTile.h"
#include"knight.h"
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
	CTRL_NOTJUMP,
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
typedef map<string, SampleTile*> sampleMap;
class TileMap :public singletonBase<TileMap>
{
private:
	vector<tagTile*>		_tiles; // Ÿ�ϸ��ʵ�
	vector<OBJSTRUCT>		_Vobj;
	char*					token;	//���� �� �ε带 ���� ��ū
	CTRL					_crtl;
	unordered_map<string, sampleMap*> _sampleTile;
	unordered_map<string, tagTile>					_ins;
	tagCurrentTile*			_currentTile;
	SampleTile*				_currentSampleTile;


	bool showRect,showCol;
	float tileSize;

	int _tileAmount;
public:
	HRESULT init();
	void release();
	std::ifstream::pos_type filesize(const char* filename);

	virtual void loadObj(string FileName, string StageName);
	
	vector<tagTile*> getTotalTile() { return _tiles; }

	POINT getIndex(POINT centerPos, float tileSize)
	{
		POINT ins = { centerPos.x / tileSize,centerPos.y / tileSize };
		return ins;
	}
	void setCTRL(CTRL ins) { _crtl = ins; }
	
	void setShowCol(bool check) { showCol = check; }
	void setShowRect(bool check) { showRect = check; }
	CTRL getCTRL() { return _crtl; }
	void update();
	void Start();
	void render();
	TileMap();
	~TileMap();

	void setCurrentTile(TYPE _type, int indexX, int indexY);

	void setSampleTile(image* image);
	void save();

	void load(string FileName);
	void load();
};

