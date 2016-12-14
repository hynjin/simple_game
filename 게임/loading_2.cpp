#include "loading_2.h"

stage2 :: stage2()
{

}

stage2 :: ~stage2()
{

}

void stage2 :: Loadbadack(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("badack.png"),badack_x,badack_y,D3DCOLOR_XRGB(0,0,0),badack_texture)))
	 {
	  MessageBox(hWnd,_T("땅 이미지 로딩에 실패하였습니다."),_T("땅 이미지 로딩 실패."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}
void stage2 :: Loadtump(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("tump.png"),tump_x,tump_y,D3DCOLOR_XRGB(0,0,0),tump_texture)))
	 {
	  MessageBox(hWnd,_T("무덤 이미지 로딩에 실패하였습니다."),_T("무덤 이미지 로딩 실패."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}
void stage2 :: Loadback(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("back.bmp"),WINDOWSIZE_X,WINDOWSIZE_Y,D3DCOLOR_XRGB(0,0,0),back_texture)))
	 {
	  MessageBox(hWnd,_T("배경 이미지 로딩에 실패하였습니다."),_T("배경 이미지 로딩 실패."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
	back_vector.x=0;
	back_vector.y=0;
	back_vector.z=0;
}
void stage2 :: Loadrope(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("rope.png"),rope_x,rope_y,D3DCOLOR_XRGB(0,0,0),rope_texture)))
	 {
	  MessageBox(hWnd,_T("밧줄 이미지 로딩에 실패하였습니다."),_T("밧줄 이미지 로딩 실패."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}
/*
void stage2 :: Loadstage1(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("stage1.png"),100,30,D3DCOLOR_XRGB(0,0,0),stage_texture)))
	 {
	  MessageBox(hWnd,_T("스테이지 이미지 로딩에 실패하였습니다."),_T("스테이지 이미지 로딩 실패."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}*/
void stage2 :: Loadstage2(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("stage2.png"),100,30,D3DCOLOR_XRGB(0,0,0),stage_texture)))
	 {
	  MessageBox(hWnd,_T("스테이지 이미지 로딩에 실패하였습니다."),_T("스테이지 이미지 로딩 실패."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}
void stage2 :: Loadgameover(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("gameover.png"),300,400,D3DCOLOR_XRGB(0,0,0),gameover_texture)))
	 {
	  MessageBox(hWnd,_T("게임오버 이미지 로딩에 실패하였습니다."),_T("게임오버 이미지 로딩 실패."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}
LPDIRECT3DTEXTURE9 stage2 :: Getbadack_texture()
{
	return this->badack_texture;
}
LPDIRECT3DTEXTURE9 stage2 :: Gettump_texture()
{
	return this->tump_texture;
}
LPDIRECT3DTEXTURE9 stage2 :: Getback_texture()
{
	return this->back_texture;
}
LPDIRECT3DTEXTURE9 stage2 :: Getrope_texture()
{
	return this->rope_texture;
}
LPDIRECT3DTEXTURE9 stage2 :: Getstage_texture()
{
	return this->stage_texture;
}
LPDIRECT3DTEXTURE9 stage2 :: Getgameover_texture()
{
	return this->gameover_texture;
}
D3DXVECTOR3 stage2 :: Getbadack_vector1()
{
	badack_vector.x=0;
	badack_vector.y=0;

//	if(cnt==1)
//		obs.badack_plus(badack_vector.x,badack_vector.y);

	cnt++;
	return this->badack_vector;
}
D3DXVECTOR3 stage2 :: Getbadack_vector2()
{
	badack_vector.x=0;
	badack_vector.y=0;
	
//	if(cnt==1)
//		obs.badack_plus(badack_vector.x,badack_vector.y);
	return this->badack_vector;
}
D3DXVECTOR3 stage2 :: Getbadack_vector3()
{
	badack_vector.x=0;
	badack_vector.y=160;
	
//	if(cnt==1)
//		obs.badack_plus(badack_vector.x,badack_vector.y);

	return this->badack_vector;
}
D3DXVECTOR3 stage2 :: Getbadack_vector4()
{
	badack_vector.x=0;
	badack_vector.y=160;
	
//	if(cnt==1)
//		obs.badack_plus(badack_vector.x,badack_vector.y);
	
	return this->badack_vector;
}
D3DXVECTOR3 stage2 :: Getbadack_vector5()
{
	badack_vector.x=0;
	badack_vector.y=302;

//	if(cnt==1)
//		obs.badack_plus(badack_vector.x,badack_vector.y);
	
	return this->badack_vector;
}
D3DXVECTOR3 stage2 :: Getbadack_vector6()
{
	badack_vector.x=200;
	badack_vector.y=302;

//	if(cnt==1)
//		obs.badack_plus(badack_vector.x,badack_vector.y);
	
	return this->badack_vector;
}
D3DXVECTOR3 stage2 :: Getbadack_vector7()
{
	badack_vector.x=400;
	badack_vector.y=302;

//	if(cnt==1)
//		obs.badack_plus(badack_vector.x,badack_vector.y);
	
	return this->badack_vector;
}
D3DXVECTOR3 stage2 :: Gettump_vector1()
{
	tump_vector.x=420;
	tump_vector.y=277;

//	if(cnt==1)
//		obs.tump_plus(tump_vector.x,tump_vector.y);
	
	return this->tump_vector;
}
D3DXVECTOR3 stage2 :: Gettump_vector2()
{
	tump_vector.x=130;
	tump_vector.y=277;

//	if(cnt==1)
//		obs.tump_plus(tump_vector.x,tump_vector.y);
	
	return this->tump_vector;
}
D3DXVECTOR3 stage2 :: Gettump_vector3()
{
	tump_vector.x=400;
	tump_vector.y=410;

//	if(cnt==1)
//		obs.tump_plus(tump_vector.x,tump_vector.y);
	
	return this->tump_vector;
}
D3DXVECTOR3 stage2 :: Gettump_vector4()
{
	tump_vector.x=160;
	tump_vector.y=130;

//	if(cnt==1)
//		obs.tump_plus(tump_vector.x,tump_vector.y);
	
	return this->tump_vector;
}
D3DXVECTOR3 stage2 :: Getback_vector()
{
	return this->back_vector;
}
D3DXVECTOR3 stage2 :: Getrope_vector1()
{
	rope_vector.x=450;
	rope_vector.y=-5;

//	if(cnt==1)
//		obs.rope_plus(rope_vector.x,rope_vector.y);
	
	return this->rope_vector;
}
D3DXVECTOR3 stage2 :: Getrope_vector2()
{
	rope_vector.x=90;
	rope_vector.y=132;

//	if(cnt==1)
//		obs.rope_plus(rope_vector.x,rope_vector.y);
	
	return this->rope_vector;
}
D3DXVECTOR3 stage2 :: Getrope_vector3()
{
	rope_vector.x=560;
	rope_vector.y=274;

//	if(cnt==1)
//		obs.rope_plus(rope_vector.x,rope_vector.y);
	
	return this->rope_vector;
}
D3DXVECTOR3 stage2 :: Getstage_vector()
{
	stage_vector.x=520;
	stage_vector.y=0;
	return this->stage_vector;
}
D3DXVECTOR3 stage2 :: Getgameover_vector()
{
	gameover_vector.x=180;
	gameover_vector.y=20;
	return this->gameover_vector;
}

int stage2 :: stage_check(float ghostY)
{
	if(ghostY<10.0)
		return 2;
	return 1;
}