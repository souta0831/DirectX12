#pragma once
#include<Windows.h>
class Window {
public:
	Window();
	~Window();
	
	const HWND GetHWND(void)  {
		return handle;
	}

private:

	//ウィンドウプロシージャ
	static LRESULT WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

	void CreateWnd();

	WNDCLASSEX window;

	RECT rect;

	HWND handle;

};