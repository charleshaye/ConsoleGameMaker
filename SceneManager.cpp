#include "SceneManager.h"

#include "CMExceptions.h"
#include "KeyCode.h"

BEGIN_CM_NAMESPACE
SceneManager::SceneManager() {}

SceneManager::SceneMap SceneManager::sceneMap;
Scene* SceneManager::foucused;

Scene* SceneManager::findScene(const QString& name) {
  auto it = sceneMap.find(name);
  if (it != sceneMap.end()) return (*it).second;
  return nullptr;
}

void SceneManager::setFoucusedScene(const QString& Name) {
  auto it = sceneMap.find(Name);
  if (it != sceneMap.end()) foucused = (*it).second;
  foucused->isactive = true;
}

void SceneManager::loadScene(const QString& Name, LoadSceneFlag flag) {
  auto sceneIt = sceneMap.find(Name);
  if (sceneIt != sceneMap.end()) {
    switch (flag) {
      case CM::LoadSceneFlag::DELETECURRENT: {
        foucused->isactive = false;
        sceneMap.erase(foucused->objectName());
      } break;

      case CM::LoadSceneFlag::KEEPCURRENT: {
      } break;

      case CM::LoadSceneFlag::NOTKEEPCURRENT: {
        foucused->isactive = false;
      } break;

      default:
        break;
    }
    (*sceneIt).second->isactive = true;
    foucused = (*sceneIt).second;
  } else
    throw Mem_Not_Found_Exception(Name);
}
END_CM_NAMESPACE