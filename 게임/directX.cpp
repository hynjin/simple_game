/*
이미지를 부르고
이미지를 그리고
캐릭터의 이동을 처리하고
랜더함수도 여기있고...
*/
#include "directX.h"

DirectX::DirectX(void)
{
	ghostX=0;//캐릭터 출발 위치
	ghostY=400;
	check=0;//랜더 함수가 몇번 실행되는지 체크
	badack_num=0;//땅 그리는 함수에 사용
	rope_num=0;//로프 그리는 함수에 사용
	tump_num=0;//무덤 그리는 함수에 사용
	stage=1;//스테이지 1
}


DirectX::~DirectX(void)
{
}


void DirectX::CreateDevice(HWND hWnd)
{
	//다렉부분 

 //그래픽카드 인터페이스 생성
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
 
 if(NULL==m_pD3D)
  throw E_FAIL;
//Direct3DCreate9는 Direct3D를 사용하기 위해서  IDirect3D9Ex라는 인터페이스를 만듭니다.
//Direct3DCreate9함수의 인자는 항상 D3D_SDK_VERSION입니다. Direct3D의 SDK를 사용해야하기 때문입니다.
// 만약 헤더와 어플리케이션이 서로 다른 버젼이라면 NULL 을 반환합니다.

 ZeroMemory(&d3dpp, sizeof(d3dpp));// 선언된 구조체에대하여 초기화 == memset(&(&d3dpp, 0,  sizeof(D3DPRESENT_PARAMETERS))
 d3dpp.Windowed = TRUE;//창모드 생성- 풀스크린시 false를 두기도함, 하지만 무조건 TRUE  
 d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;//더블버퍼링(백버퍼)간의 화면전환을 어떻게 할것인가? - 가장 효율적인 SWAP효과
 d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;//현재 바탕화면에 맞춰서 후면버퍼 생성
 d3dpp.EnableAutoDepthStencil = TRUE;//  깊이 버퍼(Z버퍼)의 사용을 할것인가 - 스탠실 버퍼 사용 안함.
 d3dpp.AutoDepthStencilFormat = D3DFMT_D16; // 깊이 단계를 어느정도 세분화 할 것인가? 
											// D16은 16비트로(대략 65000가지의 깊의 경우를 표현할 수 있습니다.
											// 이정도면 충분하므로 D32도 존재하지만
m_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL,hWnd,D3DCREATE_SOFTWARE_VERTEXPROCESSING,&d3dpp, &m_pd3dDevice);
 // 디바이스를 위와 같이 설정한다. 
 // D3DADAPTER_DEFAULT 디폴트 비디오 카드를 사용한다(대부분은 비디오카드가 하나이다)
 // D3DDEVTYPE_HAL HAL디바이스를 생성한다 (HW가속장치를 사용하겠다는 의미);
 // 정점처리는 모든카드에서 지원하는 SW처리로 생성한다.(HW로 생성할 경우 더욱 높은 성능을 낸다)

 // 그래픽인터페이스를 생성하고 m_pd3dDevice라는 이름을 붙여주었다.
 //우리는 앞으로 m_pd3dDevice를 통해 그래픽카드에 명령을 내릴 수 있다.


 //HAL이란?
 //다양한 종류의 그래픽카드 장치들이 현재 크게 칩셋 제조사로 Nvidia 와 Radeon이 있고, 여기서 기계적 레퍼런스를 개조하거나,
 //또는 다양한 옵션을 덧붙여, 다양한 유통사(기가바이트, 아수스, 이엠텍, 사파이어 등등)에서 그래픽카드를 내놓습니다.
 //이해를 돕기위한 쉬운예로, 똑같이 화면에 하나의 점을 찍어내는 함수 조차도, 어떤회사는 SetPixel();이라고 지을 수 있고,
 //다른 회사는 DrawPixel(); 이라고 지을 수 있습니다. 이러한 각자의 개성에 강하게 프로그래밍 된 소스는 구동시에 
 //어떤 그래픽카드는 구동되고, 어떤 그래픽카드는 정상적으로 구동되지 않는 문제를 충분히 발생시킬 수 있으며,
 //치명적 에러를 유발시킬 위험요소가 존재합니다. 따라서 이에 대한 표준(프로트콜/규약)으로써, 제공할 기능에 대한
 // 표준규약을 Micro Soft에서 제공함으로써, 제조사들은 이 규약만 지켜서 하드웨어를 개발하게 되면, 
 //각 개발사가 그래픽카드를 어떤식으로든 내부 수정하더라도 DirectX에서는 해당 그래픽카드가 문제없이 구동하게 될 수 있게 됩니다.
 // 이 규약이 바로 HAL입니다. 
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 D3DXCreateSprite(m_pd3dDevice,&m_pSprite);

}

void DirectX::ImageSetting(HWND hWnd)//이미지는 loading 클래스에서 받아옴
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

void DirectX::DrawImage()//계속바뀜(로딩이 이 안에 있으면 쓸데 없이 계속 로딩하는 것임)
{//그림 그리는 것은 Setmap에서 받아옴
	m_pSprite->Draw(loading.Getback_texture(),NULL,NULL,&loading.Setmap.Getback_vector(),D3DCOLOR_XRGB(255,255,255));//배경그리기

	for(int i=0;i<15;badack_num++,i++)//초기화 되기 전에 모든 지형을 하나씩 그리기 위해 for문 사용
		m_pSprite->Draw(loading.Getbadack_texture(),NULL,NULL,&loading.Setmap.Getbadack_vector(badack_num),D3DCOLOR_XRGB(255,255,255));//땅 그리기
	
	for(int i=0;i<6;rope_num++,i++)
		m_pSprite->Draw(loading.Getrope_texture(),NULL,NULL,&loading.Setmap.Getrope_vector(rope_num),D3DCOLOR_XRGB(255,255,255));//밧줄 그리기
	
	for(int i=0;i<9;tump_num++,i++)
		m_pSprite->Draw(loading.Gettump_texture(),NULL,NULL,&loading.Setmap.Gettump_vector(tump_num),D3DCOLOR_XRGB(255,255,255));//장애물 그리기
	
	if(move.crush.stage==2 && ghostY<=10)//마지막 로프를 통해 맨위에 닿았을 경우->스테이지2
	{
		loading.Setmap.Getstage(2);//스테이지 2로 바귀는 시점
		stage=2;
	}

	m_pSprite->Draw(loading.Gethome_texture(),NULL,NULL,&loading.Setmap.Gethome_vector(),D3DCOLOR_XRGB(255,255,255));//도착점 그리기
	
	if(stage==1)
		m_pSprite->Draw(loading.Getstage1_texture(),NULL,NULL,&loading.Setmap.Getstage_vector(),D3DCOLOR_XRGB(255,255,255));//스테이지1 표시
	else
		m_pSprite->Draw(loading.Getstage2_texture(),NULL,NULL,&loading.Setmap.Getstage_vector(),D3DCOLOR_XRGB(255,255,255));//스테이지2 표시
	
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

void DirectX::ghost_DrawImage()//계속바뀜(로딩이 이 안에 있으면 쓸데 없이 계속 로딩하는 것임)
{
	if(stage!=2)//스테이지를 변경하는 동안에는 상테 체크 안함 (여기에서 stage==2는 스테이지2란 뜻이 아님)
	{
		move.fall(ghostX,ghostY);
		move.show_move();
	}
	m_pSprite->Draw(move.Getghost_texture(),move.Get_Image(),NULL,&move.Getghost_vector(ghostX,ghostY),D3DCOLOR_XRGB(255,255,255));
	if(stage==2)
		ghostY+=5;
	if(stage==2 && ghostY>=370)
	{
		dark.dark_start();//움직이는 장애물의 위치 새로 지정
		send_ob();
		move.crush.call();
		stage=3;//스테이지 변경완료
	}
}


void DirectX::Render()//깔끔하게 정리할 것! 무수히 많은 버그도 잡을 것! 여기서 모든 문제 발생이라고 봄!
{	
	m_pd3dDevice->Clear(0,NULL,D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER,D3DCOLOR_XRGB(14,14,72),1.0f,0);
	// 화면 초기화 
	///// 후면버퍼를 파란색(0,0,255)으로 지운다
	/*
	if(check==0)//처음 시작
	{
		if(SUCCEEDED(m_pd3dDevice->BeginScene()))// 후면버퍼에 그리기위해
		{
			m_pSprite->Begin(D3DXSPRITE_ALPHABLEND); 
			this->m_pSprite->Draw(loading.Getstart_texture(),NULL,NULL,&loading.Setmap.Getstart_vector(),D3DCOLOR_XRGB(255,255,255));
			m_pSprite->End();
		}
		m_pd3dDevice->EndScene();//장면을 다 그렸다는 것을 알린다.
		m_pd3dDevice->Present( NULL, NULL, NULL, NULL );//전면 버퍼와 후면 버퍼를 교체한다.

		if(GetAsyncKeyState(VK_RETURN) & 0x8000)
			check++;
	}
	else
	{
	if(move.die(ghostX,ghostY)==2)
	{
		if(SUCCEEDED(m_pd3dDevice->BeginScene()))// 후면버퍼에 그리기위해
		{
			m_pSprite->Begin(D3DXSPRITE_ALPHABLEND); 
			this->DrawImage();
			this->ghost_DrawImage();
			this->m_pSprite->Draw(loading.Getgameover_texture(),NULL,NULL,&loading.Setmap.Getgameover_vector(),D3DCOLOR_XRGB(255,255,255));
			m_pSprite->End();
		}
		m_pd3dDevice->EndScene();//장면을 다 그렸다는 것을 알린다.
		m_pd3dDevice->Present( NULL, NULL, NULL, NULL );//전면 버퍼와 후면 버퍼를 교체한다.
	}
	else if(move.clear(ghostX,ghostY)==6)
	{
		if(SUCCEEDED(m_pd3dDevice->BeginScene()))// 후면버퍼에 그리기위해
		{
			m_pSprite->Begin(D3DXSPRITE_ALPHABLEND); 
			this->DrawImage();
			this->ghost_DrawImage();
			this->m_pSprite->Draw(loading.Getclear_texture(),NULL,NULL,&loading.Setmap.Getclear_vector(),D3DCOLOR_XRGB(255,255,255));
			m_pSprite->End();
		}
		m_pd3dDevice->EndScene();//장면을 다 그렸다는 것을 알린다.
		m_pd3dDevice->Present( NULL, NULL, NULL, NULL );//전면 버퍼와 후면 버퍼를 교체한다.
	}
	else
	{
		if(SUCCEEDED(m_pd3dDevice->BeginScene()))// 후면버퍼에 그리기위해
		{
			m_pSprite->Begin(D3DXSPRITE_ALPHABLEND); 
			this->DrawImage();
			this->ghost_DrawImage();
			m_pSprite->End();
		}
		m_pd3dDevice->EndScene();//장면을 다 그렸다는 것을 알린다.
		m_pd3dDevice->Present( NULL, NULL, NULL, NULL );//전면 버퍼와 후면 버퍼를 교체한다.


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
					if(SUCCEEDED(m_pd3dDevice->BeginScene()))// 후면버퍼에 그리기위해
					{
						m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
						this->DrawImage();
						this->m_pSprite->Draw(move.Getghost_texture(),move.Get_Image(),NULL,&move.jump(ghostX,ghostY,i),D3DCOLOR_XRGB(255,255,255));
						m_pSprite->End();
					} 
					m_pd3dDevice->EndScene();//장면을 다 그렸다는 것을 알린다.
					m_pd3dDevice->Present( NULL, NULL, NULL, NULL );//전면 버퍼와 후면 버퍼를 교체한다
				//점프를 어떻게 해야할지 몰라 이렇게 했다...이거 아닌거 같은데;;;ㅜㅜ
				}
			}
	}
	}
	*/
	
	if(SUCCEEDED(m_pd3dDevice->BeginScene()))// 후면버퍼에 그리기위해
		{
			m_pSprite->Begin(D3DXSPRITE_ALPHABLEND); 
			if(check==0)//처음시작
			{
				this->m_pSprite->Draw(loading.Getstart_texture(),NULL,NULL,&loading.Setmap.Getstart_vector(),D3DCOLOR_XRGB(255,255,255));
				if(GetAsyncKeyState(VK_RETURN) & 0x8000)
					check++;
			}
			else//죽지 않은 상태일 경우=살아있음
			{
				this->DrawImage();
				this->ghost_DrawImage();

				if(GetAsyncKeyState(VK_SPACE) & 0x8000 )//점프시 문제가 많음
				{
					for(int i=0;i<50;i++)
					{
						{
							m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
							this->DrawImage();
							this->m_pSprite->Draw(move.Getghost_texture(),move.Get_Image(),NULL,&move.jump(ghostX,ghostY,i),D3DCOLOR_XRGB(255,255,255));
							m_pSprite->End();
						} 
						m_pd3dDevice->EndScene();//장면을 다 그렸다는 것을 알린다.
						m_pd3dDevice->Present( NULL, NULL, NULL, NULL );//전면 버퍼와 후면 버퍼를 교체한다
						}
				}
				else if(move.clear(ghostX,ghostY)==6)//끝났나
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
		m_pd3dDevice->EndScene();//장면을 다 그렸다는 것을 알린다.
		m_pd3dDevice->Present( NULL, NULL, NULL, NULL );//전면 버퍼와 후면 버퍼를 교체한다.
		
}


//디바이스(BeginScene) => 스프라이트(Begin) => 스프라이트(Draw)=>...=>(Draw)
//=> 스프라이트(End) => 디바이스(EndScene) => 디바이스(Present)



void DirectX::send_ob()//장애물 좌표 받아오기
{
	move.crush.ob=loading.Setmap.obs;
}