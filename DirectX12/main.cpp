#include"Window.h"
int main(void) {
	Window* win = new Window();

	//�\��
	ShowWindow(win->GetHWND(), SW_SHOW);
	MSG msg;

	while (msg.message != WM_QUIT)
	{
		//�Ăяo�����X���b�h�����L���Ă���E�B���h�E�ɑ��M���ꂽ���b�Z�[�W�ۗ̕�����Ă��镨���擾
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			//���z�L�[���b�Z�[�W�𕶎����b�Z�[�W�ɕϊ�
			TranslateMessage(&msg);
			//1�̃E�B�h�E�v���V�[�W���Ƀ��b�Z�[�W�𑗏o����
			DispatchMessage(&msg);
		}
	}

	//�E�B���h�E�N���X�̉��
	delete win;

	return 0;

}