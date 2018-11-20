#ifndef DEF_OTHER_H
#define DEF_OTHER_H

void Title_init(); // タイトル画面の初期化

void Title_Update(); // タイトル画面の更新

void Title_Draw(); // タイトル画面の描画

void Title_End(); // タイトル画面の終了処理

int Timecount_Update(); // 1フレーム更新するのにかかった時間を計算する関数。

int Timecount_return(); // 1フレーム更新するのにかかった時間を返す関数 単位ms

#endif // !DEF_OTHER_H

