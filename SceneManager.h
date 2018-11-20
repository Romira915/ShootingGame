#ifndef DEF_SCENEMANAGER_H
#define DEF_SCENEMANAGER_H

typedef enum {
	Title,
	Battle
}eScene;

void SceneMgr_Update();

void SceneMgr_Draw();

void SceneChange(eScene);

#endif // !DEF_SCENEMANAGER_H

