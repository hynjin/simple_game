/*
�����̴� ��ֹ�
->�̵��ϸ鼭 
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
	void show_dark();//�̹��� ��������Ʈ

private:
	D3DXVECTOR3 dark_vector;
	LPDIRECT3DTEXTURE9 dark_texture;

	float darkX;
	float darkY;

	RECT Image;

	int dark_check;//ó�� ��ֹ��� ���ۿ� ���ܸ� �α� ���Ͽ�(�ȱ׷��� �������ڸ��� ĳ���Ͱ� ��ֹ��� ����)
	float change_stage;//���������� �ٲ�� �������� �̵� �Ÿ�
	float dis;
};