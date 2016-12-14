/*
벡터를 이용하여
장애물의 좌표위치를
저장 또는 삭제
*/
#include "obstacle.h"

obstacle :: obstacle()
{
	
}

obstacle :: ~obstacle()
{
}


void obstacle :: badack_plus(float x,float y)
{
	node ex;
	ex.vector.x=x;
	ex.vector.y=y;
	badack_v.push_back(ex);
}

void obstacle :: rope_plus(float x,float y)
{
	node ex;
	ex.vector.x=x;
	ex.vector.y=y;
	rope_v.push_back(ex);
}

void obstacle :: tump_plus(float x,float y)
{
	node ex;
	ex.vector.x=x;
	ex.vector.y=y;
	tump_v.push_back(ex);
}

void obstacle :: home_plus(float x,float y)
{
	node ex;
	ex.vector.x=x;
	ex.vector.y=y;
	home_v.push_back(ex);
}
void obstacle :: badack_clear()
{
	badack_v.clear();//왜 여기에 clear를 쓰면 문제가 생기는데 pop_back이면 문제가 없는가...?
}
void obstacle :: rope_clear()
{
	rope_v.clear();
}
void obstacle :: tump_clear()
{
	tump_v.clear();
}
vector<node> obstacle :: badack()
{
	return this->badack_v;
}

vector<node> obstacle :: rope()
{
	return this->rope_v;
}
	
vector<node> obstacle :: tump()
{
	return this->tump_v;
}

vector<node> obstacle :: home()
{
	return this->home_v;
}