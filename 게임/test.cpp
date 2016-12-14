#pragma once
#include "Stdafx.h"
#include <stdio.h>
#include <windows.h>
#include "directX.h"

#pragma comment(linker,"/entry:WinMainCRTStartup /subsystem:console")//콘솔창도 띄울수 있도록


LRESULT WINAPI WndProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );

void Render();
void Loop(MSG msg,HWND hWnd);


static DirectX directx;

LRESULT WINAPI WndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	static double ghostX=5,ghostY=5;
	switch(msg) 
	{
	case WM_KEYDOWN:

		if( wParam == VK_ESCAPE )
			::DestroyWindow(hWnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
		break;
	}
	return DefWindowProc(hWnd,msg,wParam,lParam);
}

INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR, INT)
{
	WNDCLASSEX wc;
	MSG msg; 
	ZeroMemory(&msg, sizeof(msg));
	wc.cbSize        = sizeof(wc);
	wc.lpszClassName = TEXT("Game_KHJ");
	wc.lpfnWndProc   = WndProc;
	wc.style         = CS_VREDRAW | CS_HREDRAW;
	wc.hInstance     = hInst;
	wc.hIcon         = LoadIcon( NULL, IDI_APPLICATION );
	wc.hIconSm       = LoadIcon( NULL,IDI_APPLICATION );
	wc.hCursor       = LoadCursor( NULL, IDC_ARROW );
	wc.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
	wc.lpszMenuName  = 0;
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	RegisterClassEx(&wc);

	HWND hWnd;

	hWnd = CreateWindowEx( 0, TEXT("Game_KHJ"), TEXT("Game_KHJ"),
		WS_OVERLAPPEDWINDOW & WS_SYSMENU, 0,0,WINDOWSIZE_X,WINDOWSIZE_Y, GetDesktopWindow(),0,wc.hInstance,0);//세로길이는 그때마다 바꿀것
	

	ShowWindow(hWnd, SW_SHOWDEFAULT);   
	// SW_SHOWDEFAULT : STARTUPINFO 구조체가 지정하는 보이기 상태로 만든다.

	directx.CreateDevice(hWnd);//디바이스 생성
	directx.ImageSetting(hWnd);//이미지 로딩.

	Loop(msg,hWnd);


	UnregisterClass(TEXT("Game_KHJ"),wc.hInstance);
	//등록된 레지스트 클래스 소거


	return 0;
}



void Loop(MSG msg,HWND hWnd)
{
	//HDC hdc;

	while(msg.message != WM_QUIT)
	{
		if(PeekMessage(&msg,NULL,0U,0U,PM_REMOVE))
			//PeekMessage : GetMessage와 마찬가지로 메시지 큐에서 메시지를 읽는다 메시지의 범위를 줄수 있는 기능도 GetMessage와 동일하다.
			//그러나 이함수는 GetMessage와 달리 읽은 메시지를 무조건 제거하지 않으며 큐가 비어있는경우 대기하지 않고 곧바로 리턴한다는 점이 다르다.
			// 따라서 이함수는 메시지를 읽지않고 단순히 메시지가 있는지 확인만 할 수 있으며 이런 특성은 백그라운드 작업에 적절하다.
			//인자 PM_REMOVE : 메시지를 읽은 후 큐에서 메시지를 제거한다. 

		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		else
		{
			directx.Render();
			/*Render()함수는 후면버퍼에 그린 화면을 전면버퍼로 보내주는 함수이다. 
			위에서 보면 알수있듯이특이하게 메시지루프안에서 화면을 그려주고 있다. 
			이는 게임 혹은 3D 프로그램의 특성상 사용자의 시각적인 면을 고려한 것으로 메시지대기중 
			여유분의 CPU를 활용하여 보다 빠르고 자연스럽게 화면에 보여주기 위한 처리방법이다.*/
		}
	}
}
