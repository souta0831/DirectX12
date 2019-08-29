#include"Window.h"
#include <tchar.h>

Window::Window() {
	CreateWnd();
}
Window::~Window()
{
	//ウィンドウの解放
	UnregisterClass(window.lpszClassName, window.hInstance);
}
//ウィンドウプロシージャ
LRESULT Window::WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	//ウィンドウが破棄されたとき
	if (msg == WM_DESTROY)
	{
		//OSに対してアプリケーション終了を伝える
		PostQuitMessage(0);
		return 0;
	}
	//規定の処理を行う
	return DefWindowProc(hwnd, msg, wparam, lparam);
}

void Window::CreateWnd() {
	window.cbClsExtra = 0;
	//WNDCLASSEXのサイズを指定
	window.cbSize = sizeof(WNDCLASSEX);
	//これは0指定でいいみたいです。
	window.cbWndExtra = 0;
	//ウィンドウの背景色を指定
	window.hbrBackground = CreateSolidBrush(COLOR_BACKGROUND);
	//マウスカーソルの指定。今回は標準のものを指定してます
	window.hCursor = LoadCursor(NULL, IDC_ARROW);
	//使用するアイコンの指定。今回は標準のものを指定してます。
	window.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	//使用するアイコンの指定。今回は標準のものを指定してます。
	window.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	//インスタンスハンドルの指定
	window.hInstance = GetModuleHandle(0);
	//ウィンドウプロシージャの指定
    window.lpfnWndProc = (WNDPROC)WindowProced;
	//ウィンドウの名前を指定
	window.lpszClassName = "DirectX";
	//ウィンドウメニューの名前を指定
	window.lpszMenuName = "DirectX";
	//ウィンドウの書き直しを指定できます。今回は水平か垂直に変更があったら全体を書き直します。
	window.style = CS_HREDRAW | CS_VREDRAW;
	//ウィンドウの登録
	RegisterClassEx(&window);

	//縦幅が480
	rect.bottom = 720;
	rect.left = 0;
	//横幅が640
	rect.right = 1280;
	rect.top = 0;

	//サイズを登録
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);


}