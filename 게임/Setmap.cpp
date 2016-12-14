/*
�� ���� �ϴ� �κ�
loding ���� �̹����� �θ��ٸ�
�̰������� �̹����� ��ǥ�� ����
*/
#include "Setmap.h"

Setmap :: Setmap()
{
	cnt=1;
	stage_num=0;//cnt�� ���������� �ѹ��� ��ǥ�� �����ϱ� ����
	dis=10;//�������� ����� �̵��ϴ� �Ÿ�
	badack_n=15;//��ֹ� ����
	rope_n=6;
	tump_n=9;
}

Setmap :: ~Setmap()
{

}
int Setmap :: Getstage(int s)//�������� Ȯ���� �ϰ� �׿� ���� ���� ����
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
	if(stage==2)//���� �ٲ�� �������� ��ֹ��� �Ʒ��� �̵�
	{
		dis+=0.5;
		home_vector.y+=dis;
	}
	if(stage==3)
		home_vector.y+=dis;
	if(stage==3 && cnt<=10)
	{
		obs.home_plus(home_vector.x,home_vector.y);//��ֹ� ��ǥ ���忡�� ������ ����
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
		badack_vector.y=302;//��������� ��������1
	}
	else if(num%badack_n==8)//������� �������� 2 ���� �� ������ ���� �̷��� ��
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
	
	if(stage==2)//���� �ٲ�� �������� ��ֹ��� �Ʒ��� �̵�
	{
		dis+=0.5;
		badack_vector.y+=dis;
		for(unsigned int i=0;i<obs.badack().size();i++)
			obs.badack_clear();//��������1�� ��ǥ ����
	}
	if(stage==3)
		badack_vector.y+=dis;
	if(badack_vector.y>700)
		stage=3;//�������� 2�� �� �ٲ�
	if(cnt<=8)
		obs.badack_plus(badack_vector.x,badack_vector.y);//���� ��ǥ�� ���Ϳ� ����
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
	else if(num%rope_n==1)//���� ���� ����
	{
		rope_vector.x=90;
		rope_vector.y=132;
	}
	else if(num%rope_n==2)
	{
		rope_vector.x=560;
		rope_vector.y=274;
	}//���Ⱑ�� �������� 1
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
	if(stage==2)//���� �ٲ�� �������� ��ֹ��� �Ʒ��� �̵�
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
		obs.rope_plus(rope_vector.x,rope_vector.y);//������ ��ǥ�� ���Ϳ� ����
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
	}//��������� ��������1
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
	if(stage==2)//���� �ٲ�� �������� ��ֹ��� �Ʒ��� �̵�
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
		obs.tump_plus(tump_vector.x,tump_vector.y);//������ ��ǥ�� ���Ϳ� ����
	if( cnt<=8 && cnt>4 && stage==3)
	{
		obs.tump_plus(tump_vector.x,tump_vector.y);
	}
	cnt++;
	if(stage==3)
		stage_num++;
	return this->tump_vector;
}