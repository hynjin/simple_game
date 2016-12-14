#pragma once
#include "Stdafx.h"
#include "loading.h"
#include "move.h"
#include "dark.h"

class DirectX
{
		D3DPRESENT_PARAMETERS d3dpp;
		LPDIRECT3DDEVICE9 m_pd3dDevice; //�������� ����� D3D ����̽�
		LPD3DXSPRITE m_pSprite;//D3DXSprite ��ü
		LPDIRECT3D9 m_pD3D;//D3DDevice ����� ��ü ����

		loading loading;
		Dark dark;

		HWND winhandle;

		int check;//��ֹ� ��ǥ�� �ѹ��� �ҷ����� ���Ͽ� ���
		int stage;//�������� üũ�� 2�ϰ��� ��������2�� ��ȯ���̶�� ��

	public:

		DirectX(void);
		~DirectX(void);

		void CreateDevice(HWND hWnd);
		void ImageSetting(HWND hWnd);//�ѹ��� ȣ��Ǵ� �κ� �̹��� �ε�
		void DrawImage();//Render���� ��� �ҷ����� �κ�, �̹����� �׸�
		void ghost_DrawImage();//ĳ������ �̵��� ǥ���ϱ� ����
		void Render();//test.cpp�� LOOP���� �Լ� �ҷ����� �κ�

		void send_ob();//����� ��ֹ� ��ǥ �޾ƿ�

		float ghostX;//ĳ������ ��ǥ
		float ghostY;

		class move move;

		int badack_num;//��ֹ��� �׸��� for���� �̿��Ͽ� �׸��� ���Ͽ� ���
		int rope_num;
		int tump_num;
};

