#pragma once

#pragma once
#include "Stdafx.h"
#include "Define.h"


class stage2
{
public:
	stage2();
	~stage2();

	void Loadbadack(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);
	void Loadtump(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);
	void Loadback(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);
	void Loadrope(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);
	void Loadstage1(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);
	void Loadstage2(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);
	void Loadgameover(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);

	LPDIRECT3DTEXTURE9 Getbadack_texture();
	LPDIRECT3DTEXTURE9 Gettump_texture();
	LPDIRECT3DTEXTURE9 Getback_texture();
	LPDIRECT3DTEXTURE9 Getrope_texture();
	LPDIRECT3DTEXTURE9 Getstage_texture();
	LPDIRECT3DTEXTURE9 Getgameover_texture();

	D3DXVECTOR3 Getbadack_vector1();
	D3DXVECTOR3 Getbadack_vector2();
	D3DXVECTOR3 Getbadack_vector3();
	D3DXVECTOR3 Getbadack_vector4();
	D3DXVECTOR3 Getbadack_vector5();
	D3DXVECTOR3 Getbadack_vector6();
	D3DXVECTOR3 Getbadack_vector7();
	
	D3DXVECTOR3 Getrope_vector1();
	D3DXVECTOR3 Getrope_vector2();
	D3DXVECTOR3 Getrope_vector3();
	
	D3DXVECTOR3 Gettump_vector1();
	D3DXVECTOR3 Gettump_vector2();
	D3DXVECTOR3 Gettump_vector3();
	D3DXVECTOR3 Gettump_vector4();

	D3DXVECTOR3 Getback_vector();

	D3DXVECTOR3 Getstage_vector();

	D3DXVECTOR3 Getgameover_vector();

	
	int stage_check(float);


private:
	LPDIRECT3DTEXTURE9 badack_texture;
	LPDIRECT3DTEXTURE9 tump_texture;
	LPDIRECT3DTEXTURE9 back_texture;
	LPDIRECT3DTEXTURE9 rope_texture;
	LPDIRECT3DTEXTURE9 stage_texture;
	LPDIRECT3DTEXTURE9 gameover_texture;
	
	D3DXVECTOR3 badack_vector;// 다이렉트 3차원 벡터
	D3DXVECTOR3 tump_vector;
	D3DXVECTOR3 back_vector;
	D3DXVECTOR3 rope_vector;//static D3DXVECTOR3   BBB(5,5,0);// 다이렉트 3차원 벡터 이렇게 써도된다.
	D3DXVECTOR3 stage_vector;
	D3DXVECTOR3 gameover_vector;
	
	RECT MSGdrawPosition;

	int cnt;

//	node tumph;
//	node ropeh;
//	node badackh;

};