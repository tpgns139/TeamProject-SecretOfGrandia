#pragma once
#define TILESIZE 64 // 타일사이즈 

//타일 갯수는 가로 20 / 세로 20
#define TILEX 30 // 타일 갯수
#define TILEY 30

//타일 총 사이즈는 640 X 640
#define TILESIZEX TILESIZE * TILEX
#define TILESIZEY TILESIZE * TILEY

enum frameImage
{
	Frame,
	NotFrame
};
enum attribute
{
	nonBlocking,
	blocking,
	notJump
};

enum TYPE
{
	TYPE_TERRAIN,
	TYPE_TERRAIN2,
	TYPE_TERRAIN3,
	TYPE_TERRAIN4,
	TYPE_TERRAIN5,
	TYPE_TERRAIN6,
	TYPE_NONE
};
class tagTile
{
private:
	TYPE type;
	RECT rc;				//렉트
	int terrainFrameX;		//터레인 번호
	int terrainFrameY;		//터레인 번호


	POINT center;

	int indexX;
	int indexY;

	attribute _attribute;

	tagTile* _parentNode;
	bool _isOpen;


	//F = G + H
	float _totalCost;		//총 비용
	float _costFromStart;	//시작위치로부터 현재 노드
	float _costToGoal;		//현재 노드로부터 도착점까지 경로비용


public:
	tagTile() {}
	~tagTile() {}
	//================= 접근자 & 설정자 ==================
	void setType(TYPE tp) { type = tp; }
	TYPE getType() { return type; }


	void setAttribute(attribute str) { _attribute = str; }
	attribute getAttribute() { return _attribute; }

	void setTotalCost(float totalCost) { _totalCost = totalCost; }
	float getTotalCost() { return _totalCost; }

	void setCostFromStart(float costFromStart) { _costFromStart = costFromStart; }
	float getCostFromStart() { return _costFromStart; }

	void setCostToGoal(float costToGoal) { _costToGoal = costToGoal; }
	float getCostToGoal() { return _costToGoal; }

	void setParentNode(tagTile* t) { _parentNode = t; }
	tagTile* getParentNode() { return _parentNode; }

	void setIsOpen(bool isOpen) { _isOpen = isOpen; }
	bool getIsOpen() { return _isOpen; }

	RECT getRect() { return rc; }
	void setRect(RECT rect) { rc = rect; }

	int getTerrainFrameIdx() { return terrainFrameX; }
	void setTerrainFrameIdx(int num) { terrainFrameX = num; }

	int getTerrainFrameIdY() { return terrainFrameY; }
	void setTerrainFrameIdY(int num) { terrainFrameY = num; }

	float getCenterX() { return center.x; }
	float getCenterY() { return center.y; }
	void setCenterX(float x) { center.x = x; }
	void setCenterY(float y) { center.y = y; }

	int getIdX() { return indexX; }
	void setIdX(int index) {
		indexX = index;
	}
	int getIdY() { return indexY; }
	void setIdY(int index) {
		indexY = index;
	}
	void render();

};
