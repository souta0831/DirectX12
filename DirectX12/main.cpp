#include"Window.h"
int main(void) {
	Window* win = new Window();

	//表示
	ShowWindow(win->GetHWND(), SW_SHOW);
	MSG msg;

	while (msg.message != WM_QUIT)
	{
		//呼び出し側スレッドが所有しているウィンドウに送信されたメッセージの保留されている物を取得
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			//仮想キーメッセージを文字メッセージに変換
			TranslateMessage(&msg);
			//1つのウィドウプロシージャにメッセージを送出する
			DispatchMessage(&msg);
		}
	}

	//ウィンドウクラスの解放
	delete win;

	return 0;

}