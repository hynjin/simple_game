#pragma once

#pragma once
#include "Stdafx.h"
#include "Define.h"
#include "obstacle.h"

class Setmap
{
public:
	Setmap();
	~Setmap();
	
	D3DXVECTOR3 Getstart_vector();//�̹����� ��ǥ�� vector�� ����(vector.h�ʹ� �ٸ�)

	D3DXVECTOR3 Getbadack_vector(int);
	D3DXVECTOR3 Getrope_vector(int);
	D3DXVECTOR3 Gettump_vector(int);//���⿡�� int�� direct���� ��ֹ��� for������ �ѹ��� ����ϱ� ���� ���
	D3DXVECTOR3 Gethome_vector();

	D3DXVECTOR3 Getback_vector();

	D3DXVECTOR3 Getstage_vector();

	D3DXVECTOR3 Getgameover_vector();
	D3DXVECTOR3 Getclear_vector();

	obstacle obs;
	
	int Getstage(int);
	int stage;
	int stage_num;//���������� �ٲ�� ������ ��ǥ������ ����

private:
	D3DXVECTOR3 start_vector;
	D3DXVECTOR3 badack_vector;// ���̷�Ʈ 3���� ����
	D3DXVECTOR3 tump_vector;
	D3DXVECTOR3 back_vector;
	D3DXVECTOR3 rope_vector;//static D3DXVECTOR3   BBB(5,5,0);// ���̷�Ʈ 3���� ���� �̷��� �ᵵ�ȴ�.
	D3DXVECTOR3 stage_vector;
	D3DXVECTOR3 gameover_vector;
	D3DXVECTOR3 home_vector;
	D3DXVECTOR3 clear_vector;
	
	RECT MSGdrawPosition;//�̰� ���⿡ �ʿ䰡..����?���� �̰�

	int cnt;
	float dis;//���� �ٲ�� �������� ��ֹ��� ��ǥ�� ����

	node tumph;
	node ropeh;
	node badackh;
	node homeh;

	int badack_n;
	int rope_n;
	int tump_n;//��ֹ� ����
};