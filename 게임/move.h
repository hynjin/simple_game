#pragma once
#include "Stdafx.h"
#include "Define.h"
#include <Windows.h>
#include "crush.h"


const int dis=2;

class move
{
public:
	move();
	~move();

	void Loadghost(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);//캐릭터의 이미지 로딩

	LPDIRECT3DTEXTURE9 Getghost_texture();//texture 정보 받아옴
	D3DXVECTOR3 Getghost_vector(float ghostX, float ghostY);//vector 정보 받아옴

	void rightmove(float &ghostX, float &ghostY);//이동
	void leftmove(float &ghostX, float &ghostY);
	void upmove(float &ghostX, float &ghostY);
	void downmove(float &ghostX, float &ghostY);
	void show_move();//이미지 스프라이트

	RECT* Get_Image();//스프라이트 시 이미지에서 texture의 위치 바꿈

	D3DXVECTOR3 jump(float &ghostX, float &ghostY,int cnt);//cnt는 몇 프레임에 점프를 할지 정하기 위해서
	D3DXVECTOR3 fall(float &ghostX, float &ghostY);
	
	int die(float,float);//무덤에 부딪혀서 죽음
	int clear(float,float);

	crush crush;

private:
	LPDIRECT3DTEXTURE9 ghost_texture;
	D3DXVECTOR3 ghost_vector;

	RECT Image;

	double high;
	int check;//0이면 바닥과 닿음 1이면 로프와 닿음 2이면 장애물에 닿음 3점프중 4떨어져 죽음 5점프중 오르내림 6도착
	int stage_check;
	int move_check;//애니메이션
};