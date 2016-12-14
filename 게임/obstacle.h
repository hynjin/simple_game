/*
맵을 인식하는 부분
땅, 밧줄, 장애물, 도착지점에 대한 좌표를 저장
*/
#include "Stdafx.h"
#include <vector>
using namespace std;

typedef struct node
{
	D3DXVECTOR3 vector;//바로 벡터로 장애물 저장하기 위해(함수를 줄일수 있을지도)
}node;

class obstacle
{
public:
	obstacle();
	~obstacle();

	void badack_plus(float x,float y);//장애물 좌표 저장
	void rope_plus(float x,float y);
	void tump_plus(float x,float y);
	void home_plus(float x,float y);

	void badack_clear();//장애물 좌표 정보 삭제
	void rope_clear();
	void tump_clear();


	vector<node> badack();
	vector<node> rope();
	vector<node> tump();
	vector<node> home();

private:
	vector<node>badack_v;
	vector<node>rope_v;
	vector<node>tump_v;
	vector<node>home_v;
};