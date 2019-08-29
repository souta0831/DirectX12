#include"Window.h"
#include <tchar.h>

Window::Window() {
	CreateWnd();
}
Window::~Window()
{
	//�E�B���h�E�̉��
	UnregisterClass(window.lpszClassName, window.hInstance);
}
//�E�B���h�E�v���V�[�W��
LRESULT Window::WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	//�E�B���h�E���j�����ꂽ�Ƃ�
	if (msg == WM_DESTROY)
	{
		//OS�ɑ΂��ăA�v���P�[�V�����I����`����
		PostQuitMessage(0);
		return 0;
	}
	//�K��̏������s��
	return DefWindowProc(hwnd, msg, wparam, lparam);
}

void Window::CreateWnd() {
	window.cbClsExtra = 0;
	//WNDCLASSEX�̃T�C�Y���w��
	window.cbSize = sizeof(WNDCLASSEX);
	//�����0�w��ł����݂����ł��B
	window.cbWndExtra = 0;
	//�E�B���h�E�̔w�i�F���w��
	window.hbrBackground = CreateSolidBrush(COLOR_BACKGROUND);
	//�}�E�X�J�[�\���̎w��B����͕W���̂��̂��w�肵�Ă܂�
	window.hCursor = LoadCursor(NULL, IDC_ARROW);
	//�g�p����A�C�R���̎w��B����͕W���̂��̂��w�肵�Ă܂��B
	window.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	//�g�p����A�C�R���̎w��B����͕W���̂��̂��w�肵�Ă܂��B
	window.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	//�C���X�^���X�n���h���̎w��
	window.hInstance = GetModuleHandle(0);
	//�E�B���h�E�v���V�[�W���̎w��
    window.lpfnWndProc = (WNDPROC)WindowProced;
	//�E�B���h�E�̖��O���w��
	window.lpszClassName = "DirectX";
	//�E�B���h�E���j���[�̖��O���w��
	window.lpszMenuName = "DirectX";
	//�E�B���h�E�̏����������w��ł��܂��B����͐����������ɕύX����������S�̂����������܂��B
	window.style = CS_HREDRAW | CS_VREDRAW;
	//�E�B���h�E�̓o�^
	RegisterClassEx(&window);

	//�c����480
	rect.bottom = 720;
	rect.left = 0;
	//������640
	rect.right = 1280;
	rect.top = 0;

	//�T�C�Y��o�^
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);


}