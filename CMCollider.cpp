#include "CMCollider.h"
BEGIN_CM_NAMESPACE
CMCollider::CMCollider(Object* attachedObject) 
    : CMComponent(attachedObject),
      size(0,0),
      position(0,0)
    {}

bool CMCollider::isOverLapRect(const QRect& otherRect) const  {
 /* return !(
      ((rect.right() < otherRect.left()) ||
       (rect.bottom() > otherRect.top())) ||
      ((otherRect.right() < rect.left()) || (otherRect.bottom() > rect.top())));*/
    return false;
}

Owner<CMComponent> CMCollider::clone() {
  auto newPtr = STD make_unique<CMCollider>(object());
  newPtr->setActive(isActive());
  return newPtr;
}

QString CMCollider::toString() { return CMComponent::toString(); }

Owner<CMComponent> clone() {
	return Owner<CMComponent>();
}

QString toString() {
	return QString();
}
END_CM_NAMESPACE