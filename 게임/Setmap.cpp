/*
맵 설정 하는 부분
loding 에서 이미지를 부른다면
이곳에서는 이미지의 좌표를 설정
*/
#include "Setmap.h"

Setmap :: Setmap()
{
	cnt=1;
	stage_num=0;//cnt와 마찬가지로 한번만 좌표를 저장하기 위해
	dis=10;//스테이지 변경시 이동하는 거리
	badack_n=15;//장애물 갯수
	rope_n=6;
	tump_n=9;
}

Setmap :: ~Setmap()
{

}
int Setmap :: Getstage(int s)//스테이지 확인을 하고 그에 따라 맵을 설정
{
	return this->stage=s;
}

D3DXVECTOR3 Setmap :: Getstart_vector()
{
	return this->start_vector;
}
D3DXVECTOR3 Setmap :: Getback_vector()
{
	return this->back_vector;
}
D3DXVECTOR3 Setmap :: Getstage_vector()
{
	stage_vector.x=520;
	stage_vector.y=0;
	return this->stage_vector;
}
D3DXVECTOR3 Setmap :: Getgameover_vector()
{
	gameover_vector.x=180;
	gameover_vector.y=20;
	return this->gameover_vector;
}
D3DXVECTOR3 Setmap :: Getclear_vector()
{
	clear_vector.x=80;
	clear_vector.y=20;
	return this->clear_vector;
}
D3DXVECTOR3 Setmap :: Gethome_vector()
{
	home_vector.x=310;
	home_vector.y=-355;
	if(stage==2)//맵이 바뀌는 과정에서 장애물이 아래로 이동
	{
		dis+=0.5;
		home_vector.y+=dis;
	}
	if(stage==3)
		home_vector.y+=dis;
	if(stage==3 && cnt<=10)
	{
		obs.home_plus(home_vector.x,home_vector.y);//장애물 좌표 저장에는 문제가 없음
	}
		return this->home_vector;
}

D3DXVECTOR3 Setmap :: Getbadack_vector(int num)
{
	if(num%badack_n==0)
	{
		badack_vector.x=0;
		badack_vector.y=0;
	}
	else if(num%badack_n==1)
	{
		badack_vector.x=200;
		badack_vector.y=0;
	}
	else if(num%badack_n==2)
	{
		badack_vector.x=380;
		badack_vector.y=0;
	}
	else if(num%badack_n==3)
	{
		badack_vector.x=60;
		badack_vector.y=160;
	}
	else if(num%badack_n==4)
	{
		badack_vector.x=370;
		badack_vector.y=160;
	}
	else if(num%badack_n==5)
	{
		badack_vector.x=0;
		badack_vector.y=302;
	}
	else if(num%badack_n==6)
	{
		badack_vector.x=200;
		badack_vector.y=302;
	}
	else if(num%badack_n==7)
	{
		badack_vector.x=400;
		badack_vector.y=302;//여기까지가 스테이지1
	}
	else if(num%badack_n==8)//여기부터 스테이지 2 현재 맵 세팅을 위해 이렇게 됨
	{
		badack_vector.x=-100;
		badack_vector.y=-302;
	}
	else if(num%badack_n==9)
	{
		badack_vector.x=200;
		badack_vector.y=-302;
	}
	else if(num%badack_n==10)
	{
		badack_vector.x=500;
		badack_vector.y=-302;
	}
	else if(num%badack_n==11)
	{
		badack_vector.x=-160;
		badack_vector.y=-160;
	}
	else if(num%badack_n==12)
	{
		badack_vector.x=150;
		badack_vector.y=-160;
	}
	else if(num%badack_n==13)
	{
		badack_vector.x=250;
		badack_vector.y=-160;
	}
	else if(num%badack_n==14)
	{
		badack_vector.x=550;
		badack_vector.y=-160;
	}
	
	if(stage==2)//맵이 바뀌는 과정에서 장애물이 아래로 이동
	{
		dis+=0.5;
		badack_vector.y+=dis;
		for(unsigned int i=0;i<obs.badack().size();i++)
			obs.badack_clear();//스테이지1의 좌표 지움
	}
	if(stage==3)
		badack_vector.y+=dis;
	if(badack_vector.y>700)
		stage=3;//스테이지 2로 다 바뀜
	if(cnt<=8)
		obs.badack_plus(badack_vector.x,badack_vector.y);//땅의 좌표를 벡터에 저장
	if(cnt<=14 && cnt>5 && stage==3)
	{
		obs.badack_plus(badack_vector.x,badack_vector.y);
	}
	return this->badack_vector;
}
D3DXVECTOR3 Setmap :: Getrope_vector(int num)
{
	if(num%rope_n==0)
	{
		rope_vector.x=450;
		rope_vector.y=-10;
	}
	else if(num%rope_n==1)//제일 위에 로프
	{
		rope_vector.x=90;
		rope_vector.y=132;
	}
	else if(num%rope_n==2)
	{
		rope_vector.x=560;
		rope_vector.y=274;
	}//여기가지 스테이지 1
	else if(num%rope_n==3)
	{
		rope_vector.x=100;
		rope_vector.y=-330;
	}
	else if(num%rope_n==4)
	{
		rope_vector.x=530;
		rope_vector.y=-330;
	}
	else if(num%rope_n==5)
	{
		rope_vector.x=200;
		rope_vector.y=-180;
	}
	if(stage==2)//맵이 바뀌는 과정에서 장애물이 아래로 이동
	{
		dis+=0.5;
		rope_vector.y+=dis;
		for(unsigned int i=0;i<obs.rope().size();i++)
			obs.rope_clear();
	}
	if(stage==3)
		rope_vector.y+=dis;
	if(cnt<=3)
	{
		obs.rope_plus(rope_vector.x,rope_vector.y);//로프의 좌표를 벡터에 저장
	}
	if(cnt<=5 && cnt>3 && stage==3)
	{
		obs.rope_plus(rope_vector.x,rope_vector.y);
	}
	return this->rope_vector;
}
D3DXVECTOR3 Setmap :: Gettump_vector(int num)
{
	if(num%tump_n==0)
	{
		tump_vector.x=420;
		tump_vector.y=277;
	}
	else if(num%tump_n==1)
	{
		tump_vector.x=130;
		tump_vector.y=277;
	}
	else if(num%tump_n==2)
	{
		tump_vector.x=400;
		tump_vector.y=410;
	}
	else if(num%tump_n==3)
	{
		tump_vector.x=160;
		tump_vector.y=135;
	}//여기까지가 스테이지1
	else if(num%tump_n==4)
	{
		tump_vector.x=250;
		tump_vector.y=-185;
	}
	else if(num%tump_n==5)
	{
		tump_vector.x=370;
		tump_vector.y=-185;
	}
	else if(num%tump_n==6)
	{
		tump_vector.x=100;
		tump_vector.y=-25;
	}
	else if(num%tump_n==7)
	{
		tump_vector.x=380;
		tump_vector.y=-25;
	}
	else if(num%tump_n==8)
	{
		tump_vector.x=230;
		tump_vector.y=-325;
	}
	if(stage==2)//맵이 바뀌는 과정에서 장애물이 아래로 이동
	{
		dis+=0.5;
		tump_vector.y+=dis;
		for(unsigned int i=0;i<obs.tump().size();i++)
			obs.tump_clear();
		cnt=0;
	}
	if(stage==3)
		tump_vector.y+=dis;
	if(cnt<=4)
		obs.tump_plus(tump_vector.x,tump_vector.y);//무덤의 좌표를 벡터에 저장
	if( cnt<=8 && cnt>4 && stage==3)
	{
		obs.tump_plus(tump_vector.x,tump_vector.y);
	}
	cnt++;
	if(stage==3)
		stage_num++;
	return this->tump_vector;
}