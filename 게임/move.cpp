/*
���ɰ� ���õ� �κе� ��� �̰���
�̹��� �ε��� �ٸ����� �Űܵ� �ɵ� ����(������ �׳� ����)
�̹��� �ε��� ��ǥ �ִϸ��̼Ǳ��� �Ѱ��� ���� ����
��ǥ�� ���� ������ ���������� ó���ϰ� ���� �ް� �ϴ� ���� ������ �־ �̰��� ���Ƴ���

���� �̵��� ���� ���װ� ��û����(�������� ���� ��� ������ �߻�)
*/
#include "move.h"

move :: move()
{
	Image.top = 0;
	Image.bottom = GhostSize_Y;
	Image.left = 0;
	Image.right = GhostSize_X;

	move_check=0;
	check=0;
	high=-3;
	crush.call();
}

move :: ~move()
{

}

void move :: Loadghost(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("ghost_m.png"),GhostSize_X*13,GhostSize_Y,D3DCOLOR_XRGB(0,0,0),ghost_texture)))
	 {
	  MessageBox(hWnd,_T("���� �̹��� �ε��� �����Ͽ����ϴ�."),_T("���� �̹��� �ε� ����."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}

void move :: show_move()
{
	if(move_check==0)//������
	{
		Image.left = 0;
		Image.right = GhostSize_X;
	}
	else if(move_check == 5)
	{
		Image.left = GhostSize_X;
		Image.right = GhostSize_X*2;
	}
	else if(move_check == 11)
	{
		Image.left = GhostSize_X*2;
		Image.right = GhostSize_X*3;
	}
	else if(move_check == 16)
	{
		Image.left = GhostSize_X*3;
		Image.right = GhostSize_X*4;
	}
	else if(move_check == 21)//Ⱥ��
	{
		Image.left = GhostSize_X*4;
		Image.right = GhostSize_X*5;
	}
	else if(move_check == 26)
	{
		Image.left = GhostSize_X*5;
		Image.right = GhostSize_X*6;
	}
	else if(move_check == 31)
	{
		Image.left = GhostSize_X*6;
		Image.right = GhostSize_X*7;
	}
	else if(move_check == 36)
	{
		Image.left = GhostSize_X*7;
		Image.right = GhostSize_X*8;
	}
	else if(move_check == 41)//����
	{
		Image.left = GhostSize_X*8;
		Image.right = GhostSize_X*9;
	}
	else if(move_check == 46)
	{
		Image.left = GhostSize_X*9;
		Image.right = GhostSize_X*10;
	}
	else if(move_check == 51)
	{
		Image.left = GhostSize_X*10;
		Image.right = GhostSize_X*11;
	}
	else if(move_check == 56)//�Ʒ���
	{
		Image.left = GhostSize_X*11;
		Image.right = GhostSize_X*12;
	}
	else if(move_check == 61)
	{
		Image.left = GhostSize_X*12;
		Image.right = GhostSize_X*13;
	}
}

RECT* move::Get_Image()
{
	return &this->Image;
}

LPDIRECT3DTEXTURE9 move :: Getghost_texture()
{
	Image.left;
	Image.right;
	return this->ghost_texture;
}

D3DXVECTOR3 move :: Getghost_vector(float ghostX, float ghostY)
{
	ghost_vector.x=ghostX;
	ghost_vector.y=ghostY;
	return this->ghost_vector;
}

void move :: rightmove(float &ghostX,float &ghostY)
{
	crush.rope_check(ghostX,ghostY,check);
	if(ghostX<=585)
	{
		if(check!=1&&check!=4)
		{
			move_check++;//�ִϸ��̼�
			if(move_check==21)
				move_check=0;
			else if(move_check>21)
				move_check=0;
			ghostX+=dis;
			Getghost_vector(ghostX,ghostY);
		}
		else if(check==1)
		{
			crush.badack_check(ghostX,ghostY,check);
			if(check==0)
			{
				move_check++;
			if(move_check==21)
				move_check=0;
			else if(move_check>21)
				move_check=0;
				ghostX+=dis;
				Getghost_vector(ghostX,ghostY);
			}
		}
	}
}

void move :: leftmove(float &ghostX,float &ghostY)
{
	crush.rope_check(ghostX,ghostY,check);
	if(ghostX>=0)
	{
		if(check!=1&&check!=4)
		{
			move_check++;
			if(move_check==46)
				move_check=21;
			else if(move_check>46||move_check<21)
				move_check=21;
			ghostX-=dis;
			Getghost_vector(ghostX,ghostY);
		}
		else if(check==1)
		{
			crush.badack_check(ghostX,ghostY,check);
			if(check==0)
			{
				move_check++;
			if(move_check==46)
				move_check=21;
			else if(move_check>46||move_check<21)
				move_check=21;
			ghostX-=dis;
			Getghost_vector(ghostX,ghostY);
			}
		}
	}
}

void move :: upmove(float &ghostX,float &ghostY)
{
	if(check==3)
		high=-3;
	if(ghostY>=0)
	{
		crush.rope_check(ghostX,ghostY,check);
		if(check==1)
		{
			if(ghostY>crush.ropeh[crush.cnt].vector.y+2)
			{
				move_check++;	
				if(move_check==56)
					move_check=41;
				else if(move_check>56 || move_check<41)
					move_check=41;
				ghostY-=dis;
				Getghost_vector(ghostX,ghostY);
			}
		}
	}
}//�������� ���� ����

void move :: downmove(float &ghostX,float &ghostY)
{
	if(check=3)
		high=-3;
	if(ghostY<=400)
	{
		crush.rope_check(ghostX,ghostY,check);
		if(check==1)
		{
			if(ghostY>crush.ropeh[crush.cnt].vector.y-2)
			{
				move_check++;
				if(move_check==56)
					move_check=41;
				else if(move_check>56 || move_check<41)
					move_check=41;
				ghostY+=dis;
				Getghost_vector(ghostX,ghostY);
			}
		}
	}
}

D3DXVECTOR3 move :: jump(float &ghostX, float &ghostY,int cnt)//�������� �ٸ鼭 ����Ű->����
{
	move_check=0;
	if(cnt==49)
	{
		cnt=0;
		fall(ghostX,ghostY);
		high=-3;
	}
	if(ghostY<=500)
	{
		if(GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			move_check++;
			if(move_check==46)
				move_check=21;
			else if(move_check>46||move_check<21)
				move_check=21;
			check=3;
			leftmove(ghostX,ghostY);
		}
		else if(GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			move_check++;
			if(move_check==21)
				move_check=0;
			else if(move_check>21)
				move_check=0;
			check=3;
			rightmove(ghostX,ghostY);
		}
		if(crush.rope_check(ghostX,ghostY,check)==1 && (GetAsyncKeyState(VK_UP) & 0x8000||GetAsyncKeyState(VK_DOWN) & 0x8000))//������ ��������
		{
			if(GetAsyncKeyState(VK_UP) & 0x8000)
			{
				move_check++;	
				if(move_check==56)
					move_check=41;
				else if(move_check>56 || move_check<41)
					move_check=41;
				check=3;
				upmove(ghostX,ghostY);
			}
			else if(GetAsyncKeyState(VK_DOWN) & 0x8000)
			{
				move_check++;
				if(move_check==56)
					move_check=41;
				else if(move_check>56 || move_check<41)
				check=3;
				downmove(ghostX,ghostY);
			}
		}
		else//�Ϲ� ���� ����
		{	
			if(cnt<25)
			{
				high+=0.1;
				if(crush.rope_check(ghostX,ghostY,check)!=1)//�������� ���ڸ� ������ �������ؼ�
					ghostY+=(float)high;
				else if(GetAsyncKeyState(VK_LEFT) & 0x8001 || GetAsyncKeyState(VK_RIGHT) & 0x8001)//0x8001 ������ ������ �ְ� ��� ���� ����
					ghostX-=dis;
			}
			else
			{
				if(cnt<49)
				{
					if(crush.rope_check(ghostX,ghostY,check)!=1)
						ghostY-=(float)high;
					else if(GetAsyncKeyState(VK_LEFT) & 0x8001 || GetAsyncKeyState(VK_RIGHT) & 0x8001)
						ghostX+=dis;
					high-=0.1;
				}
			}
		}
	}
	ghost_vector.x=ghostX;
	ghost_vector.y=ghostY;
	
	return this->ghost_vector;
}

D3DXVECTOR3 move :: fall(float &ghostX, float &ghostY)
{
	crush.badack_check(ghostX,ghostY,check);
	if(check==4)
	{
		while(crush.badack_check(ghostX,ghostY,check)==4)
		{
			move_check++;
			if(move_check==66)
				move_check=56;
			else if(move_check>61 || move_check<56)
				move_check=56;

			ghostY+=dis*2;
			ghost_vector.x=ghostX;
			ghost_vector.y=ghostY;
			crush.badack_check(ghostX,ghostY,check);
			return this->ghost_vector;
		}
	}
	return this->ghost_vector;
}

int move :: die(float ghostX,float ghostY)
{
	if(crush.tump_check(ghostX,ghostY,check)==2)
		return 2;
	else if(crush.dark_check(ghostX,ghostY,check)==2)
		return 2;
	else
		return 0;
}

int move :: clear(float ghostX,float ghostY)
{
	return crush.home_check(ghostX,ghostY,check);
}