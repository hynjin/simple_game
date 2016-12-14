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
	
	D3DXVECTOR3 Getstart_vector();//이미지의 좌표를 vector에 저장(vector.h와는 다름)

	D3DXVECTOR3 Getbadack_vector(int);
	D3DXVECTOR3 Getrope_vector(int);
	D3DXVECTOR3 Gettump_vector(int);//여기에서 int는 direct에서 장애물을 for문으로 한번에 출력하기 위해 사용
	D3DXVECTOR3 Gethome_vector();

	D3DXVECTOR3 Getback_vector();

	D3DXVECTOR3 Getstage_vector();

	D3DXVECTOR3 Getgameover_vector();
	D3DXVECTOR3 Getclear_vector();

	obstacle obs;
	
	int Getstage(int);
	int stage;
	int stage_num;//스테이지가 바뀌는 순간에 좌표저장을 위해

private:
	D3DXVECTOR3 start_vector;
	D3DXVECTOR3 badack_vector;// 다이렉트 3차원 벡터
	D3DXVECTOR3 tump_vector;
	D3DXVECTOR3 back_vector;
	D3DXVECTOR3 rope_vector;//static D3DXVECTOR3   BBB(5,5,0);// 다이렉트 3차원 벡터 이렇게 써도된다.
	D3DXVECTOR3 stage_vector;
	D3DXVECTOR3 gameover_vector;
	D3DXVECTOR3 home_vector;
	D3DXVECTOR3 clear_vector;
	
	RECT MSGdrawPosition;//이건 여기에 필요가..없나?뭐지 이거

	int cnt;
	float dis;//맵이 바뀌는 과정에서 장애물의 좌표를 변경

	node tumph;
	node ropeh;
	node badackh;
	node homeh;

	int badack_n;
	int rope_n;
	int tump_n;//장애물 갯수
};