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

	void Loadghost(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);//ĳ������ �̹��� �ε�

	LPDIRECT3DTEXTURE9 Getghost_texture();//texture ���� �޾ƿ�
	D3DXVECTOR3 Getghost_vector(float ghostX, float ghostY);//vector ���� �޾ƿ�

	void rightmove(float &ghostX, float &ghostY);//�̵�
	void leftmove(float &ghostX, float &ghostY);
	void upmove(float &ghostX, float &ghostY);
	void downmove(float &ghostX, float &ghostY);
	void show_move();//�̹��� ��������Ʈ

	RECT* Get_Image();//��������Ʈ �� �̹������� texture�� ��ġ �ٲ�

	D3DXVECTOR3 jump(float &ghostX, float &ghostY,int cnt);//cnt�� �� �����ӿ� ������ ���� ���ϱ� ���ؼ�
	D3DXVECTOR3 fall(float &ghostX, float &ghostY);
	
	int die(float,float);//������ �ε����� ����
	int clear(float,float);

	crush crush;

private:
	LPDIRECT3DTEXTURE9 ghost_texture;
	D3DXVECTOR3 ghost_vector;

	RECT Image;

	double high;
	int check;//0�̸� �ٴڰ� ���� 1�̸� ������ ���� 2�̸� ��ֹ��� ���� 3������ 4������ ���� 5������ �������� 6����
	int stage_check;
	int move_check;//�ִϸ��̼�
};