#ifndef DEF_OTHER_H
#define DEF_OTHER_H

#define SET_SCREENSIZE_X 1280
#define SET_SCREENSIZE_Y 720

#define START_X (int)(0.25 * SET_SCREENSIZE_X)
#define START_Y (int)(0.6 * SET_SCREENSIZE_Y)
#define EXIT_X (int)(0.25 * SET_SCREENSIZE_X)
#define EXIT_Y (int)(0.7 * SET_SCREENSIZE_Y)


void Title_init(); // �^�C�g����ʂ̏�����

void Title_Update(); // �^�C�g����ʂ̍X�V

void Title_Draw(); // �^�C�g����ʂ̕`��

void Title_End(); // �^�C�g����ʂ̏I������

int Timecount_Update(); // 1�t���[���X�V����̂ɂ����������Ԃ��v�Z����֐��B

int Timecount_return(); // 1�t���[���X�V����̂ɂ����������Ԃ�Ԃ��֐� �P��ms

#endif // !DEF_OTHER_H

