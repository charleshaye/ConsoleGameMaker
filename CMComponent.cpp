#include "CMComponent.h"
#include "Object.h"
#include "Scene.h"
#include "SceneManager.h"
BEGIN_CM_NAMESPACE

using Pointer = CMComponent::Pointer;
CMComponent::CMComponent(Object* attachedObject)
    : isactive(true),
      attachedObject(attachedObject),
      objectTransform(&attachedObject->transform) {
  setObjectName("");
}

Owner<CMComponent> CMComponent::clone() {
  auto newCom = STD make_unique<CMComponent>(object());
  newCom->isactive = isactive;
  return newCom;
}

QString CMComponent::toString() {
  return QString("Name:%1,\nAttachedObject address:%2\n")
      .arg(objectName())
      .arg(QString::number((quint32)attachedObject, 16));
}

void CMComponent::moveToObject(Object* des) {
  if (attachedObject) {
    attachedObject = des;
  }
}

END_CM_NAMESPACE