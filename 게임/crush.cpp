/*
장애물의 좌표정보를 받아와서
캐릭터와 장애물의 충동여부 확인
*/
#include "crush.h"

crush ::crush()
{
	stage=1;
}
crush :: ~crush()
{

}
void crush :: call()
{
	tumph=ob.tump();
	ropeh=ob.rope();
	badackh=ob.badack();
	homeh=ob.home();
}

int crush:: badack_check(double ghostx,double ghosty,int &check)
{
	for(unsigned int i=0;i<badackh.size();i++)
	{
		if(ghostx>(badackh[i].vector.x-GhostSize_X/3) && (ghostx+GhostSize_X)<(badackh[i].vector.x+badack_x+GhostSize_X/3))
		{
			if((ghosty+GhostSize_Y)>=badackh[i].vector.y && (ghosty+GhostSize_Y)<=(badackh[i].vector.y+badack_y))//Y 줄일 필요
			{
				return check=0;
			}
		}
		else if(ghosty>400)
			return check=0;
	}
	if(rope_check(ghostx,ghosty,check)==1)
		return check=1;

	return check=4;
}

int crush:: rope_check(double ghostx,double ghosty,int &check)
{
	for(unsigned int i=0;i<ropeh.size();i++)
	{
		if((ghostx+GhostSize_X/2)>=(ropeh[i].vector.x+rope_x/2)&&(ghostx+GhostSize_X/2)<=(ropeh[i].vector.x+rope_x))
		{
			if((ghosty+GhostSize_Y/2)<(ropeh[i].vector.y+rope_y) && (ghosty+GhostSize_Y/2)>ropeh[i].vector.y)
			{
				if(i==0)
					stage=2;
				else
					stage=1;
				cnt=i;//로프를 타고 너무 올라가지 않도록 함(->move에서 사용)
				return check=1;
			}
		}
	}
	return check=0;
}

int crush:: tump_check(double ghostx,double ghosty,int &check)
{
	for(unsigned int i=0;i<tumph.size();i++)
	{
		if((ghostx+GhostSize_X/2)>tumph[i].vector.x && (ghostx+GhostSize_X/2)<(tumph[i].vector.x+tump_x))
		{
			if((ghosty+GhostSize_Y/2)<(tumph[i].vector.y+tump_y) && (ghosty+GhostSize_Y/2)>tumph[i].vector.y)
			{
					return check=2;
			}
		}
	}
	return check=0;
}

int crush:: home_check(double ghostx,double ghosty,int &check)
{
	for(unsigned int i=0;i<homeh.size();i++)
	{
		if((ghostx+GhostSize_X/2)>homeh[i].vector.x && (ghostx+GhostSize_X/2)<(homeh[i].vector.x+65))//여기서 65라는 숫자는 집의 사이즈
		{
			if((ghosty+GhostSize_Y/2)<(homeh[i].vector.y+65) && (ghosty+GhostSize_Y/2)>homeh[i].vector.y)
			{
					return check=6;
			}
		}
	}
	return check=0;
}

void crush :: Getdark(D3DXVECTOR3 dark_vector)
{
	darkx=dark_vector.x;
	darky=dark_vector.y;
}

int crush :: dark_check(double ghostx, double ghosty, int &check)
{
	for(unsigned int i=0;i<tumph.size();i++)
	{
		if((ghostx+GhostSize_X/2)>darkx && (ghostx+GhostSize_X/2)<(darkx+140))//140은 움직이는 장애물 가로 사이즈
		{
			if((ghosty+GhostSize_Y/2)<(darky+100) && (ghosty+GhostSize_Y/2)>darky)//100은 움직이는 장애물 세로 사이즈
			{
					return check=2;
			}
		}
	}
	return check=0;
}

//나는 바보인가 보다