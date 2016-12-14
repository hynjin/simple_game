/*
�̹����� �θ���
�̹����� �׸���
ĳ������ �̵��� ó���ϰ�
�����Լ��� �����ְ�...
*/
#include "directX.h"

DirectX::DirectX(void)
{
	ghostX=0;//ĳ���� ��� ��ġ
	ghostY=400;
	check=0;//���� �Լ��� ��� ����Ǵ��� üũ
	badack_num=0;//�� �׸��� �Լ��� ���
	rope_num=0;//���� �׸��� �Լ��� ���
	tump_num=0;//���� �׸��� �Լ��� ���
	stage=1;//�������� 1
}


DirectX::~DirectX(void)
{
}


void DirectX::CreateDevice(HWND hWnd)
{
	//�ٷ��κ� 

 //�׷���ī�� �������̽� ����
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
 
 if(NULL==m_pD3D)
  throw E_FAIL;
//Direct3DCreate9�� Direct3D�� ����ϱ� ���ؼ�  IDirect3D9Ex��� �������̽��� ����ϴ�.
//Direct3DCreate9�Լ��� ���ڴ� �׻� D3D_SDK_VERSION�Դϴ�. Direct3D�� SDK�� ����ؾ��ϱ� �����Դϴ�.
// ���� ����� ���ø����̼��� ���� �ٸ� �����̶�� NULL �� ��ȯ�մϴ�.

 ZeroMemory(&d3dpp, sizeof(d3dpp));// ����� ����ü�����Ͽ� �ʱ�ȭ == memset(&(&d3dpp, 0,  sizeof(D3DPRESENT_PARAMETERS))
 d3dpp.Windowed = TRUE;//â��� ����- Ǯ��ũ���� false�� �α⵵��, ������ ������ TRUE  
 d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;//������۸�(�����)���� ȭ����ȯ�� ��� �Ұ��ΰ�? - ���� ȿ������ SWAPȿ��
 d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;//���� ����ȭ�鿡 ���缭 �ĸ���� ����
 d3dpp.EnableAutoDepthStencil = TRUE;//  ���� ����(Z����)�� ����� �Ұ��ΰ� - ���Ľ� ���� ��� ����.
 d3dpp.AutoDepthStencilFormat = D3DFMT_D16; // ���� �ܰ踦 ������� ����ȭ �� ���ΰ�? 
											// D16�� 16��Ʈ��(�뷫 65000������ ���� ��츦 ǥ���� �� �ֽ��ϴ�.
											// �������� ����ϹǷ� D32�� ����������
m_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL,hWnd,D3DCREATE_SOFTWARE_VERTEXPROCESSING,&d3dpp, &m_pd3dDevice);
 // ����̽��� ���� ���� �����Ѵ�. 
 // D3DADAPTER_DEFAULT ����Ʈ ���� ī�带 ����Ѵ�(��κ��� ����ī�尡 �ϳ��̴�)
 // D3DDEVTYPE_HAL HAL����̽��� �����Ѵ� (HW������ġ�� ����ϰڴٴ� �ǹ�);
 // ����ó���� ���ī�忡�� �����ϴ� SWó���� �����Ѵ�.(HW�� ������ ��� ���� ���� ������ ����)

 // �׷����������̽��� �����ϰ� m_pd3dDevice��� �̸��� �ٿ��־���.
 //�츮�� ������ m_pd3dDevice�� ���� �׷���ī�忡 ����� ���� �� �ִ�.


 //HAL�̶�?
 //�پ��� ������ �׷���ī�� ��ġ���� ���� ũ�� Ĩ�� ������� Nvidia �� Radeon�� �ְ�, ���⼭ ����� ���۷����� �����ϰų�,
 //�Ǵ� �پ��� �ɼ��� ���ٿ�, �پ��� �����(�Ⱑ����Ʈ, �Ƽ���, �̿���, �����̾� ���)���� �׷���ī�带 �������ϴ�.
 //���ظ� �������� �����, �Ȱ��� ȭ�鿡 �ϳ��� ���� ���� �Լ� ������, �ȸ��� SetPixel();�̶�� ���� �� �ְ�,
 //�ٸ� ȸ��� DrawPixel(); �̶�� ���� �� �ֽ��ϴ�. �̷��� ������ ������ ���ϰ� ���α׷��� �� �ҽ��� �����ÿ� 
 //� �׷���ī��� �����ǰ�, � �׷���ī��� ���������� �������� �ʴ� ������ ����� �߻���ų �� ������,
 //ġ���� ������ ���߽�ų �����Ұ� �����մϴ�. ���� �̿� ���� ǥ��(����Ʈ��/�Ծ�)���ν�, ������ ��ɿ� ����
 // ǥ�رԾ��� Micro Soft���� ���������ν�, ��������� �� �Ծุ ���Ѽ� �ϵ��� �����ϰ� �Ǹ�, 
 //�� ���߻簡 �׷���ī�带 ������ε� ���� �����ϴ��� DirectX������ �ش� �׷���ī�尡 �������� �����ϰ� �� �� �ְ� �˴ϴ�.
 // �� �Ծ��� �ٷ� HAL�Դϴ�. 
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 D3DXCreateSprite(m_pd3dDevice,&m_pSprite);

}

void DirectX::ImageSetting(HWND hWnd)//�̹����� loading Ŭ�������� �޾ƿ�
{
	loading.Loadstart(hWnd,m_pd3dDevice);
	loading.Loadbadack(hWnd,m_pd3dDevice);
	loading.Loadback(hWnd,m_pd3dDevice);
	loading.Loadrope(hWnd,m_pd3dDevice);
	loading.Loadtump(hWnd,m_pd3dDevice);
	loading.Loadgameover(hWnd,m_pd3dDevice);
	loading.Loadhome(hWnd,m_pd3dDevice);
	loading.Loadclear(hWnd,m_pd3dDevice);
	dark.Loaddark(hWnd,m_pd3dDevice);
	
	loading.Loadstage1(hWnd,m_pd3dDevice);
	loading.Loadstage2(hWnd,m_pd3dDevice);

	move.Loadghost(hWnd,m_pd3dDevice);

	winhandle = hWnd;
}

void DirectX::DrawImage()//��ӹٲ�(�ε��� �� �ȿ� ������ ���� ���� ��� �ε��ϴ� ����)
{//�׸� �׸��� ���� Setmap���� �޾ƿ�
	m_pSprite->Draw(loading.Getback_texture(),NULL,NULL,&loading.Setmap.Getback_vector(),D3DCOLOR_XRGB(255,255,255));//���׸���

	for(int i=0;i<15;badack_num++,i++)//�ʱ�ȭ �Ǳ� ���� ��� ������ �ϳ��� �׸��� ���� for�� ���
		m_pSprite->Draw(loading.Getbadack_texture(),NULL,NULL,&loading.Setmap.Getbadack_vector(badack_num),D3DCOLOR_XRGB(255,255,255));//�� �׸���
	
	for(int i=0;i<6;rope_num++,i++)
		m_pSprite->Draw(loading.Getrope_texture(),NULL,NULL,&loading.Setmap.Getrope_vector(rope_num),D3DCOLOR_XRGB(255,255,255));//���� �׸���
	
	for(int i=0;i<9;tump_num++,i++)
		m_pSprite->Draw(loading.Gettump_texture(),NULL,NULL,&loading.Setmap.Gettump_vector(tump_num),D3DCOLOR_XRGB(255,255,255));//��ֹ� �׸���
	
	if(move.crush.stage==2 && ghostY<=10)//������ ������ ���� ������ ����� ���->��������2
	{
		loading.Setmap.Getstage(2);//�������� 2�� �ٱʹ� ����
		stage=2;
	}

	m_pSprite->Draw(loading.Gethome_texture(),NULL,NULL,&loading.Setmap.Gethome_vector(),D3DCOLOR_XRGB(255,255,255));//������ �׸���
	
	if(stage==1)
		m_pSprite->Draw(loading.Getstage1_texture(),NULL,NULL,&loading.Setmap.Getstage_vector(),D3DCOLOR_XRGB(255,255,255));//��������1 ǥ��
	else
		m_pSprite->Draw(loading.Getstage2_texture(),NULL,NULL,&loading.Setmap.Getstage_vector(),D3DCOLOR_XRGB(255,255,255));//��������2 ǥ��
	
	m_pSprite->Draw(dark.Getdark_texture(),dark.Get_Image(),NULL,&dark.Getdark_vector(),D3DCOLOR_XRGB(255,255,255));
	dark.show_dark();
	dark.dark_move(stage);

	move.crush.Getdark(dark.Getdark_vector());

	if(check==1)
	{
		send_ob();
		move.crush.call();
	}
}

void DirectX::ghost_DrawImage()//��ӹٲ�(�ε��� �� �ȿ� ������ ���� ���� ��� �ε��ϴ� ����)
{
	if(stage!=2)//���������� �����ϴ� ���ȿ��� ���� üũ ���� (���⿡�� stage==2�� ��������2�� ���� �ƴ�)
	{
		move.fall(ghostX,ghostY);
		move.show_move();
	}
	m_pSprite->Draw(move.Getghost_texture(),move.Get_Image(),NULL,&move.Getghost_vector(ghostX,ghostY),D3DCOLOR_XRGB(255,255,255));
	if(stage==2)
		ghostY+=5;
	if(stage==2 && ghostY>=370)
	{
		dark.dark_start();//�����̴� ��ֹ��� ��ġ ���� ����
		send_ob();
		move.crush.call();
		stage=3;//�������� ����Ϸ�
	}
}


void DirectX::Render()//����ϰ� ������ ��! ������ ���� ���׵� ���� ��! ���⼭ ��� ���� �߻��̶�� ��!
{	
	m_pd3dDevice->Clear(0,NULL,D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER,D3DCOLOR_XRGB(14,14,72),1.0f,0);
	// ȭ�� �ʱ�ȭ 
	///// �ĸ���۸� �Ķ���(0,0,255)���� �����
	/*
	if(check==0)//ó�� ����
	{
		if(SUCCEEDED(m_pd3dDevice->BeginScene()))// �ĸ���ۿ� �׸�������
		{
			m_pSprite->Begin(D3DXSPRITE_ALPHABLEND); 
			this->m_pSprite->Draw(loading.Getstart_texture(),NULL,NULL,&loading.Setmap.Getstart_vector(),D3DCOLOR_XRGB(255,255,255));
			m_pSprite->End();
		}
		m_pd3dDevice->EndScene();//����� �� �׷ȴٴ� ���� �˸���.
		m_pd3dDevice->Present( NULL, NULL, NULL, NULL );//���� ���ۿ� �ĸ� ���۸� ��ü�Ѵ�.

		if(GetAsyncKeyState(VK_RETURN) & 0x8000)
			check++;
	}
	else
	{
	if(move.die(ghostX,ghostY)==2)
	{
		if(SUCCEEDED(m_pd3dDevice->BeginScene()))// �ĸ���ۿ� �׸�������
		{
			m_pSprite->Begin(D3DXSPRITE_ALPHABLEND); 
			this->DrawImage();
			this->ghost_DrawImage();
			this->m_pSprite->Draw(loading.Getgameover_texture(),NULL,NULL,&loading.Setmap.Getgameover_vector(),D3DCOLOR_XRGB(255,255,255));
			m_pSprite->End();
		}
		m_pd3dDevice->EndScene();//����� �� �׷ȴٴ� ���� �˸���.
		m_pd3dDevice->Present( NULL, NULL, NULL, NULL );//���� ���ۿ� �ĸ� ���۸� ��ü�Ѵ�.
	}
	else if(move.clear(ghostX,ghostY)==6)
	{
		if(SUCCEEDED(m_pd3dDevice->BeginScene()))// �ĸ���ۿ� �׸�������
		{
			m_pSprite->Begin(D3DXSPRITE_ALPHABLEND); 
			this->DrawImage();
			this->ghost_DrawImage();
			this->m_pSprite->Draw(loading.Getclear_texture(),NULL,NULL,&loading.Setmap.Getclear_vector(),D3DCOLOR_XRGB(255,255,255));
			m_pSprite->End();
		}
		m_pd3dDevice->EndScene();//����� �� �׷ȴٴ� ���� �˸���.
		m_pd3dDevice->Present( NULL, NULL, NULL, NULL );//���� ���ۿ� �ĸ� ���۸� ��ü�Ѵ�.
	}
	else
	{
		if(SUCCEEDED(m_pd3dDevice->BeginScene()))// �ĸ���ۿ� �׸�������
		{
			m_pSprite->Begin(D3DXSPRITE_ALPHABLEND); 
			this->DrawImage();
			this->ghost_DrawImage();
			m_pSprite->End();
		}
		m_pd3dDevice->EndScene();//����� �� �׷ȴٴ� ���� �˸���.
		m_pd3dDevice->Present( NULL, NULL, NULL, NULL );//���� ���ۿ� �ĸ� ���۸� ��ü�Ѵ�.


		if(GetAsyncKeyState(VK_UP) & 0x8000)
			 move.upmove(ghostX,ghostY);
		if(GetAsyncKeyState(VK_DOWN) & 0x8000)
			 move.downmove(ghostX,ghostY);
		if(GetAsyncKeyState(VK_LEFT) & 0x8000)
			 move.leftmove(ghostX,ghostY);
		if(GetAsyncKeyState(VK_RIGHT) & 0x8000)
			move.rightmove(ghostX,ghostY);
		if(GetAsyncKeyState(VK_SPACE) & 0x8000 )
			{
				for(int i=0;i<50;i++)
				{
					if(SUCCEEDED(m_pd3dDevice->BeginScene()))// �ĸ���ۿ� �׸�������
					{
						m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
						this->DrawImage();
						this->m_pSprite->Draw(move.Getghost_texture(),move.Get_Image(),NULL,&move.jump(ghostX,ghostY,i),D3DCOLOR_XRGB(255,255,255));
						m_pSprite->End();
					} 
					m_pd3dDevice->EndScene();//����� �� �׷ȴٴ� ���� �˸���.
					m_pd3dDevice->Present( NULL, NULL, NULL, NULL );//���� ���ۿ� �ĸ� ���۸� ��ü�Ѵ�
				//������ ��� �ؾ����� ���� �̷��� �ߴ�...�̰� �ƴѰ� ������;;;�̤�
				}
			}
	}
	}
	*/
	
	if(SUCCEEDED(m_pd3dDevice->BeginScene()))// �ĸ���ۿ� �׸�������
		{
			m_pSprite->Begin(D3DXSPRITE_ALPHABLEND); 
			if(check==0)//ó������
			{
				this->m_pSprite->Draw(loading.Getstart_texture(),NULL,NULL,&loading.Setmap.Getstart_vector(),D3DCOLOR_XRGB(255,255,255));
				if(GetAsyncKeyState(VK_RETURN) & 0x8000)
					check++;
			}
			else//���� ���� ������ ���=�������
			{
				this->DrawImage();
				this->ghost_DrawImage();

				if(GetAsyncKeyState(VK_SPACE) & 0x8000 )//������ ������ ����
				{
					for(int i=0;i<50;i++)
					{
						{
							m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
							this->DrawImage();
							this->m_pSprite->Draw(move.Getghost_texture(),move.Get_Image(),NULL,&move.jump(ghostX,ghostY,i),D3DCOLOR_XRGB(255,255,255));
							m_pSprite->End();
						} 
						m_pd3dDevice->EndScene();//����� �� �׷ȴٴ� ���� �˸���.
						m_pd3dDevice->Present( NULL, NULL, NULL, NULL );//���� ���ۿ� �ĸ� ���۸� ��ü�Ѵ�
						}
				}
				else if(move.clear(ghostX,ghostY)==6)//������
				{
					dark.dark_stop();
					this->m_pSprite->Draw(loading.Getclear_texture(),NULL,NULL,&loading.Setmap.Getclear_vector(),D3DCOLOR_XRGB(255,255,255));
				}
				else if(GetAsyncKeyState(VK_UP) & 0x8000)
					 move.upmove(ghostX,ghostY);
				else if(GetAsyncKeyState(VK_DOWN) & 0x8000)
					 move.downmove(ghostX,ghostY);
				else if(GetAsyncKeyState(VK_LEFT) & 0x8000)
					 move.leftmove(ghostX,ghostY);
				else if(GetAsyncKeyState(VK_RIGHT) & 0x8000)
					move.rightmove(ghostX,ghostY);
				
			}
			m_pSprite->End();
		}
		m_pd3dDevice->EndScene();//����� �� �׷ȴٴ� ���� �˸���.
		m_pd3dDevice->Present( NULL, NULL, NULL, NULL );//���� ���ۿ� �ĸ� ���۸� ��ü�Ѵ�.
		
}


//����̽�(BeginScene) => ��������Ʈ(Begin) => ��������Ʈ(Draw)=>...=>(Draw)
//=> ��������Ʈ(End) => ����̽�(EndScene) => ����̽�(Present)



void DirectX::send_ob()//��ֹ� ��ǥ �޾ƿ���
{
	move.crush.ob=loading.Setmap.obs;
}