/*
��ֹ��� ��ǥ������ �޾ƿͼ�
ĳ���Ϳ� ��ֹ��� �浿���� Ȯ��
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
			if((ghosty+GhostSize_Y)>=badackh[i].vector.y && (ghosty+GhostSize_Y)<=(badackh[i].vector.y+badack_y))//Y ���� �ʿ�
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
				cnt=i;//������ Ÿ�� �ʹ� �ö��� �ʵ��� ��(->move���� ���)
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
		if((ghostx+GhostSize_X/2)>homeh[i].vector.x && (ghostx+GhostSize_X/2)<(homeh[i].vector.x+65))//���⼭ 65��� ���ڴ� ���� ������
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
		if((ghostx+GhostSize_X/2)>darkx && (ghostx+GhostSize_X/2)<(darkx+140))//140�� �����̴� ��ֹ� ���� ������
		{
			if((ghosty+GhostSize_Y/2)<(darky+100) && (ghosty+GhostSize_Y/2)>darky)//100�� �����̴� ��ֹ� ���� ������
			{
					return check=2;
			}
		}
	}
	return check=0;
}

//���� �ٺ��ΰ� ����