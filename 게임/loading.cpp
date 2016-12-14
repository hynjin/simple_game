/*
이미지를 불러오는 부분
*/
#include "loading.h"

loading :: loading()
{
}

loading :: ~loading()
{
}

void loading :: Loadstart(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("start.png"),WINDOWSIZE_X,WINDOWSIZE_Y,D3DCOLOR_XRGB(0,0,0),start_texture)))
	 {
	  MessageBox(hWnd,_T("시작 이미지 로딩에 실패하였습니다."),_T("시작 이미지 로딩 실패."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}
void loading :: Loadbadack(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("badack.png"),badack_x,badack_y,D3DCOLOR_XRGB(0,0,0),badack_texture)))
	 {
	  MessageBox(hWnd,_T("땅 이미지 로딩에 실패하였습니다."),_T("땅 이미지 로딩 실패."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}
void loading :: Loadtump(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("tump.png"),tump_x,tump_y,D3DCOLOR_XRGB(0,0,0),tump_texture)))
	 {
	  MessageBox(hWnd,_T("무덤 이미지 로딩에 실패하였습니다."),_T("무덤 이미지 로딩 실패."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}
void loading :: Loadback(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("back.bmp"),WINDOWSIZE_X,WINDOWSIZE_Y,D3DCOLOR_XRGB(0,0,0),back_texture)))
	 {
	  MessageBox(hWnd,_T("배경 이미지 로딩에 실패하였습니다."),_T("배경 이미지 로딩 실패."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}
void loading :: Loadrope(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("rope.png"),rope_x,rope_y,D3DCOLOR_XRGB(0,0,0),rope_texture)))
	 {
	  MessageBox(hWnd,_T("밧줄 이미지 로딩에 실패하였습니다."),_T("밧줄 이미지 로딩 실패."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}
void loading :: Loadstage1(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("stage1.png"),100,30,D3DCOLOR_XRGB(0,0,0),stage1_texture)))
	 {
	  MessageBox(hWnd,_T("스테이지 이미지 로딩에 실패하였습니다."),_T("스테이지 이미지 로딩 실패."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}
void loading :: Loadstage2(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("stage2.png"),100,30,D3DCOLOR_XRGB(0,0,0),stage2_texture)))
	 {
	  MessageBox(hWnd,_T("스테이지 이미지 로딩에 실패하였습니다."),_T("스테이지 이미지 로딩 실패."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}
void loading :: Loadgameover(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("gameover.png"),300,400,D3DCOLOR_XRGB(0,0,0),gameover_texture)))
	 {
	  MessageBox(hWnd,_T("게임오버 이미지 로딩에 실패하였습니다."),_T("게임오버 이미지 로딩 실패."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}
void loading :: Loadhome(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("home.png"),65,65,D3DCOLOR_XRGB(0,0,0),home_texture)))
	 {
	  MessageBox(hWnd,_T("집 이미지 로딩에 실패하였습니다."),_T("집 이미지 로딩 실패."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}
void loading :: Loadclear(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("clear.png"),500,400,D3DCOLOR_XRGB(0,0,0),clear_texture)))
	 {
	  MessageBox(hWnd,_T("클리어 로딩에 실패하였습니다."),_T("클리어 이미지 로딩 실패."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}


LPDIRECT3DTEXTURE9 loading :: Getstart_texture()
{
	return this->start_texture;
}
LPDIRECT3DTEXTURE9 loading :: Getbadack_texture()
{
	return this->badack_texture;
}
LPDIRECT3DTEXTURE9 loading :: Gettump_texture()
{
	return this->tump_texture;
}
LPDIRECT3DTEXTURE9 loading :: Getback_texture()
{
	return this->back_texture;
}
LPDIRECT3DTEXTURE9 loading :: Getrope_texture()
{
	return this->rope_texture;
}
LPDIRECT3DTEXTURE9 loading :: Getstage1_texture()
{
	return this->stage1_texture;
}
LPDIRECT3DTEXTURE9 loading :: Getstage2_texture()
{
	return this->stage2_texture;
}
LPDIRECT3DTEXTURE9 loading :: Getgameover_texture()
{
	return this->gameover_texture;
}
LPDIRECT3DTEXTURE9 loading :: Gethome_texture()
{
	return this->home_texture;
}
LPDIRECT3DTEXTURE9 loading :: Getclear_texture()
{
	return this->clear_texture;
}
