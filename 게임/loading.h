#pragma once

#pragma once
#include "Stdafx.h"
#include "Define.h"
#include "Setmap.h"


class loading
{
public:
	loading();
	~loading();

	void Loadstart(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);//이미지 로딩
	void Loadbadack(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);
	void Loadtump(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);
	void Loadback(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);
	void Loadrope(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);
	void Loadstage1(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);
	void Loadstage2(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);
	void Loadgameover(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);
	void Loadhome(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);
	void Loadclear(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);

	Setmap Setmap;


	LPDIRECT3DTEXTURE9 Getstart_texture();//texture 정보 받아옴
	LPDIRECT3DTEXTURE9 Getbadack_texture();
	LPDIRECT3DTEXTURE9 Gettump_texture();
	LPDIRECT3DTEXTURE9 Getback_texture();
	LPDIRECT3DTEXTURE9 Getrope_texture();
	LPDIRECT3DTEXTURE9 Getstage1_texture();
	LPDIRECT3DTEXTURE9 Getstage2_texture();
	LPDIRECT3DTEXTURE9 Getgameover_texture();
	LPDIRECT3DTEXTURE9 Gethome_texture();
	LPDIRECT3DTEXTURE9 Getclear_texture();

private:
	LPDIRECT3DTEXTURE9 start_texture;
	LPDIRECT3DTEXTURE9 badack_texture;
	LPDIRECT3DTEXTURE9 tump_texture;
	LPDIRECT3DTEXTURE9 back_texture;
	LPDIRECT3DTEXTURE9 rope_texture;
	LPDIRECT3DTEXTURE9 stage1_texture;
	LPDIRECT3DTEXTURE9 stage2_texture;
	LPDIRECT3DTEXTURE9 gameover_texture;
	LPDIRECT3DTEXTURE9 home_texture;
	LPDIRECT3DTEXTURE9 clear_texture;

	
	
};