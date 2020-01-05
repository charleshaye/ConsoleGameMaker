#pragma once
#include <map>
#include "Scene.h"
BEGIN_CM_NAMESPACE

enum ChangeSceneType { Delete, DeActive, Continue };

enum class LoadSceneFlag { DELETECURRENT, KEEPCURRENT, NOTKEEPCURRENT };

class SceneManager {
 public:
  SceneManager();
  static Scene* findScene(const QString& name);

  static void loadScene(const QString& Name,
                        LoadSceneFlag flag = LoadSceneFlag::NOTKEEPCURRENT);

  static void addScene(Scene* scene) {
    sceneMap[scene->objectName()] = scene;
    foucused = scene;
  }

  static Scene* foucusedScene() { return foucused; }
  static void setFoucusedScene(const QString& Name);

 private:
  using SceneMap = STD map<QString, Scene*>;
  static SceneMap sceneMap;
  static Scene* foucused;
};

END_CM_NAMESPACE