#include "CMTransform.h"
#include "Object.h"
#include <Eigen/Core>
BEGIN_CM_NAMESPACE
CMTransform::CMTransform(Object* attachedObject)
    : CMComponent(attachedObject) {}

CMPosition CMTransform::worldToLocal(const CMPosition& worldPos) {
  if (this->object()->transform.world != CMPosition(0, 0)) {
    return worldPos - (this->object()->transform.world);
  }
  return worldPos;
}

CMPosition CMTransform::localToWorld(const CMPosition& localPos) {
  if (this->object()->transform.world != CMPosition(0, 0)) {
    return this->object()->transform.world + localPos;
  }
  return localPos;
}

int CMTransform::manhattanDis(const CMPosition& point) {
  return STD abs(point.x() - world.x()) + STD abs(point.y() - world.y());
}

int CMTransform::chebyshevDis(const CMPosition& point) {
  auto xdis = STD abs(point.x() - world.x());
  auto ydis = STD abs(point.y() - world.y());
  return xdis > ydis ? xdis : ydis;
}

Owner<CMComponent> CMTransform::clone() {
  auto comp = STD make_unique<CMTransform>(object());
  comp->world = world;
  comp->setPosition(getPosition());
  return comp;
}

QString CMTransform::toString() {
  auto parentStr = CMComponent::toString();
  parentStr = parentStr.left(parentStr.length() - 2);
  return parentStr + QString(",World:%1 ,%2 \n}").arg(world.x()).arg(world.y());
}

CMPosition CMTransform::transform(const CMPosition& offset, OFFSET type) {
  if (type == OFFSET::WORLD) {
  } else {
  }
  return QPoint();
}

END_CM_NAMESPACE