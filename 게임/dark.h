/*
움직이는 장애물
->이동하면서 
*/
#include "Stdafx.h"

class Dark
{
public:
	Dark();
	~Dark();
	
	D3DXVECTOR3 Getdark_vector();
	LPDIRECT3DTEXTURE9 Getdark_texture();

	void Loaddark(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);

	void dark_move(int);
	void dark_stop();
	void dark_start();

	RECT* Get_Image();
	void show_dark();//이미지 스프라이트

private:
	D3DXVECTOR3 dark_vector;
	LPDIRECT3DTEXTURE9 dark_texture;

	float darkX;
	float darkY;

	RECT Image;

	int dark_check;//처음 장애물의 시작에 예외를 두기 위하여(안그러면 시작하자마자 캐릭터가 장애물에 먹힘)
	float change_stage;//스테이지가 바뀌는 과정에서 이동 거리
	float dis;
};