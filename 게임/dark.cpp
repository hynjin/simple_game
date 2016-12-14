#include "dark.h"
#include "stdio.h"

Dark :: Dark()
{
	darkX=-300;
	darkY=340;

	Image.top = 0;
	Image.bottom = 140;
	Image.left = 0;
	Image.right = 140;

	dark_check=0;

	dis=1.2;//��ֹ��� �̵��ϴ� �Ÿ�->�ӵ� ����
	change_stage=10;//�������� ����� �̵��Ÿ�
}
Dark :: ~Dark()
{

}
void Dark :: Loaddark(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("dark.png"),140,100,D3DCOLOR_XRGB(0,0,0),dark_texture)))
	 {
	  MessageBox(hWnd,_T("��� �ε��� �����Ͽ����ϴ�."),_T("��� �̹��� �ε� ����."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}
D3DXVECTOR3 Dark :: Getdark_vector()
{
	dark_vector.x=darkX;
	dark_vector.y=darkY;
	
	return this->dark_vector;
}
void Dark :: show_dark()//���ҽ��� ��� �ϴ� �ִϸ��̼��� �ȳ���
{/*
	if(dark_check == 12)//�Ʒ���
	{
		Image.left = 140*0;
		Image.right = 140*1;
	}
	else if(dark_check == 24)
	{
		Image.left = 140*1;
		Image.right = 140*2;
	}
	else if(dark_check == 36)
	{
		Image.left = 140*2;
		Image.right = 140*3;
	}*/
}
RECT* Dark::Get_Image()
{
	return &this->Image;
}
LPDIRECT3DTEXTURE9 Dark :: Getdark_texture()
{
	Image.left;
	Image.right;
	return this->dark_texture;
}

void Dark :: dark_move(int stage)
{
	if(stage==1)
	{
		if(dark_check>300)
		{
			if(darkX<640)//��ֹ��� ���� ���� ������ �� ���������� �ٽ� �����̱� �����ϵ���
				darkX+=dis;
			if(darkX>540)
			{
				darkY-=140;
				dis=-dis;//��ֹ��� �̵����� �ٲٱ�
				dis=1.4*dis;//��ֹ��� �ӵ� ����
			}
			if(darkX<-10)
			{
				darkY-=140;
				dis=-dis;//��ֹ��� �̵����� �ٲٱ�
				dis=1.2*dis;//��ֹ��� �ӵ� ����
			}
		}
		else if(dark_check==300)
		{
			darkX=0;
		}	
	}
	else if(stage==2)//�������� ����������� ��ֹ��� �Ʒ��� ����������
	{
		change_stage+=0.5;
		darkY+=change_stage;
		dark_check=0;
	}
	else if(stage==3)//�������� ����Ϸ�
	{
		if(dark_check>300)
		{
			if(darkX<640)//��ֹ��� ���� ���� ������ �� ���������� �ٽ� �����̱� �����ϵ���
				darkX+=dis;
			if(darkX>540)
			{
				darkY-=140;
				dis=-dis;//��ֹ��� �̵����� �ٲٱ�
				dis=1.1*dis;//��ֹ��� �ӵ� ����
			}
			if(darkX<-10)
			{
				darkY-=140;
				dis=-dis;//��ֹ��� �̵����� �ٲٱ�
				dis=1.1*dis;//��ֹ��� �ӵ� ����
			}
		}
		else if(dark_check==300)
		{
			darkX=0;
			darkY=300;
		}	
	}
	dark_check++;
}


void Dark :: dark_stop()
{
	dis=0;
}

void Dark :: dark_start()
{
	darkX=-300;
	darkY=340;
	dark_check=0;
	dis=1.2;
}