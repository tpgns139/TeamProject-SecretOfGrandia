#pragma once
#include<fstream>
#include <commdlg.h> //OPENFILENAME을 위한 헤더
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
	CTRL_SAVE,			//세이브 버튼에서 사용될 것
	CTRL_LOAD,			//로드 버튼에서 사용될 것
	CTRL_TERRAINDRAW,	//지형 그리기 버튼
	CTRL_OBJDRAW,		//오브젝트 그리기 버튼 (벽, 에너미 등)
	CTRL_ERASER,		//지우개 버튼 (잘못찍은 오브젝트등을 지움지움)
	CTRL_COL,
	CTRL_COLERASE,
	CTRL_NOTJUMP,
	CTRL_NONE
};
//현재 타일 == 내가 클릭한 현재타일 정보를 저장할 구조체
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
	vector<tagTile*>		_tiles; // 타일맵필드
	vector<OBJSTRUCT>		_Vobj;
	char*					token;	//파일 맵 로드를 위한 토큰
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

