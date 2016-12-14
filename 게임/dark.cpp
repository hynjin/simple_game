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

	dis=1.2;//장애물이 이동하는 거리->속도 관여
	change_stage=10;//스테이지 변경시 이동거리
}
Dark :: ~Dark()
{

}
void Dark :: Loaddark(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("dark.png"),140,100,D3DCOLOR_XRGB(0,0,0),dark_texture)))
	 {
	  MessageBox(hWnd,_T("어둠 로딩에 실패하였습니다."),_T("어둠 이미지 로딩 실패."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}
D3DXVECTOR3 Dark :: Getdark_vector()
{
	dark_vector.x=darkX;
	dark_vector.y=darkY;
	
	return this->dark_vector;
}
void Dark :: show_dark()//리소스가 없어서 일단 애니메이션은 안넣음
{/*
	if(dark_check == 12)//아래쪽
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
			if(darkX<640)//장애물이 층의 끝에 도달할 시 다음층에서 다시 움직이기 시작하도록
				darkX+=dis;
			if(darkX>540)
			{
				darkY-=140;
				dis=-dis;//장애물의 이동방향 바꾸기
				dis=1.4*dis;//장애물의 속도 증가
			}
			if(darkX<-10)
			{
				darkY-=140;
				dis=-dis;//장애물의 이동방향 바꾸기
				dis=1.2*dis;//장애물의 속도 증가
			}
		}
		else if(dark_check==300)
		{
			darkX=0;
		}	
	}
	else if(stage==2)//스테이지 변경과정에서 장애물이 아래로 내려가도록
	{
		change_stage+=0.5;
		darkY+=change_stage;
		dark_check=0;
	}
	else if(stage==3)//스테이지 변경완료
	{
		if(dark_check>300)
		{
			if(darkX<640)//장애물이 층의 끝에 도달할 시 다음층에서 다시 움직이기 시작하도록
				darkX+=dis;
			if(darkX>540)
			{
				darkY-=140;
				dis=-dis;//장애물의 이동방향 바꾸기
				dis=1.1*dis;//장애물의 속도 증가
			}
			if(darkX<-10)
			{
				darkY-=140;
				dis=-dis;//장애물의 이동방향 바꾸기
				dis=1.1*dis;//장애물의 속도 증가
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