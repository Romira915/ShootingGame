#ifndef DEF_OTHER_H
#define DEF_OTHER_H

#define START_X 100
#define START_Y 400
#define EXIT_X 100
#define EXIT_Y 500

#define SET_SCREENSIZE_X 1280
#define SET_SCREENSIZE_Y 720

void Title_init(); // �^�C�g����ʂ̏�����

void Title_Update(); // �^�C�g����ʂ̍X�V

void Title_Draw(); // �^�C�g����ʂ̕`��

void Title_End(); // �^�C�g����ʂ̏I������

int Timecount_Update(); // 1�t���[���X�V����̂ɂ����������Ԃ��v�Z����֐��B

int Timecount_return(); // 1�t���[���X�V����̂ɂ����������Ԃ�Ԃ��֐� �P��ms

#endif // !DEF_OTHER_H

