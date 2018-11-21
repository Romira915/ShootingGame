#ifndef DEF_OTHER_H
#define DEF_OTHER_H

#define START_X 100
#define START_Y 400
#define EXIT_X 100
#define EXIT_Y 500

#define SET_SCREENSIZE_X 1280
#define SET_SCREENSIZE_Y 720

void Title_init(); // タイトル画面の初期化

void Title_Update(); // タイトル画面の更新

void Title_Draw(); // タイトル画面の描画

void Title_End(); // タイトル画面の終了処理

int Timecount_Update(); // 1フレーム更新するのにかかった時間を計算する関数。

int Timecount_return(); // 1フレーム更新するのにかかった時間を返す関数 単位ms

#endif // !DEF_OTHER_H

