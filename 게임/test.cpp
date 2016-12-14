#pragma once
#include "Stdafx.h"
#include <stdio.h>
#include <windows.h>
#include "directX.h"

#pragma comment(linker,"/entry:WinMainCRTStartup /subsystem:console")//�ܼ�â�� ���� �ֵ���


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
		WS_OVERLAPPEDWINDOW & WS_SYSMENU, 0,0,WINDOWSIZE_X,WINDOWSIZE_Y, GetDesktopWindow(),0,wc.hInstance,0);//���α��̴� �׶����� �ٲܰ�
	

	ShowWindow(hWnd, SW_SHOWDEFAULT);   
	// SW_SHOWDEFAULT : STARTUPINFO ����ü�� �����ϴ� ���̱� ���·� �����.

	directx.CreateDevice(hWnd);//����̽� ����
	directx.ImageSetting(hWnd);//�̹��� �ε�.

	Loop(msg,hWnd);


	UnregisterClass(TEXT("Game_KHJ"),wc.hInstance);
	//��ϵ� ������Ʈ Ŭ���� �Ұ�


	return 0;
}



void Loop(MSG msg,HWND hWnd)
{
	//HDC hdc;

	while(msg.message != WM_QUIT)
	{
		if(PeekMessage(&msg,NULL,0U,0U,PM_REMOVE))
			//PeekMessage : GetMessage�� ���������� �޽��� ť���� �޽����� �д´� �޽����� ������ �ټ� �ִ� ��ɵ� GetMessage�� �����ϴ�.
			//�׷��� ���Լ��� GetMessage�� �޸� ���� �޽����� ������ �������� ������ ť�� ����ִ°�� ������� �ʰ� ��ٷ� �����Ѵٴ� ���� �ٸ���.
			// ���� ���Լ��� �޽����� �����ʰ� �ܼ��� �޽����� �ִ��� Ȯ�θ� �� �� ������ �̷� Ư���� ��׶��� �۾��� �����ϴ�.
			//���� PM_REMOVE : �޽����� ���� �� ť���� �޽����� �����Ѵ�. 

		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		else
		{
			directx.Render();
			/*Render()�Լ��� �ĸ���ۿ� �׸� ȭ���� ������۷� �����ִ� �Լ��̴�. 
			������ ���� �˼��ֵ���Ư���ϰ� �޽��������ȿ��� ȭ���� �׷��ְ� �ִ�. 
			�̴� ���� Ȥ�� 3D ���α׷��� Ư���� ������� �ð����� ���� ����� ������ �޽�������� 
			�������� CPU�� Ȱ���Ͽ� ���� ������ �ڿ������� ȭ�鿡 �����ֱ� ���� ó������̴�.*/
		}
	}
}
