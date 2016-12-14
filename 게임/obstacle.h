/*
���� �ν��ϴ� �κ�
��, ����, ��ֹ�, ���������� ���� ��ǥ�� ����
*/
#include "Stdafx.h"
#include <vector>
using namespace std;

typedef struct node
{
	D3DXVECTOR3 vector;//�ٷ� ���ͷ� ��ֹ� �����ϱ� ����(�Լ��� ���ϼ� ��������)
}node;

class obstacle
{
public:
	obstacle();
	~obstacle();

	void badack_plus(float x,float y);//��ֹ� ��ǥ ����
	void rope_plus(float x,float y);
	void tump_plus(float x,float y);
	void home_plus(float x,float y);

	void badack_clear();//��ֹ� ��ǥ ���� ����
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