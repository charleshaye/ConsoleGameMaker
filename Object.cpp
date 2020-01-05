#include "Object.h"

#include "CMApplication.h"
#include "SceneManager.h"
BEGIN_CM_NAMESPACE

// @brief:初始化游戏对象
// @param:void
// @ret:void
// @birth:created  on 2019  10  12
Object::Object(ObjectPtr parent, const QString &Name)
    : QObject(parent),
      isactive(true),
      scene(SceneManager::foucusedScene()),
      transform(this) {
  setObjectName(Name);
}

ObjectPtr Object::clone() {
  auto newObj = new Object(nullptr, objectName());
  newObj->transform.setPosition(this->transform.getPosition());
  scene->cloneComs(this, newObj);
  return newObj;
}

QString Object::toString() {
  QString str = QString("Name: %1 ,\nComponents: [").arg(objectName());
  str += ']';
  return str;
}

END_CM_NAMESPACE