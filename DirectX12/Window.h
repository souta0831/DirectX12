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

	//�E�B���h�E�v���V�[�W��
	static LRESULT WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

	void CreateWnd();

	WNDCLASSEX window;

	RECT rect;

	HWND handle;

};