#include "CMAnimator.h"


BEGIN_CM_NAMESPACE
CMAnimator::CMAnimator(Object* attachedObject) : CMComponent(attachedObject) {
    
}
void CMAnimator::addAnimation(Animation animate) {}

void CMAnimator::addState() {}

void CMAnimator::Start() {}

Owner<CMComponent> CMAnimator::clone() {
  auto comp = STD make_unique<CMAnimator>(object());
  return comp;
}

QString CMAnimator::toString() { return QString(); }

END_CM_NAMESPACE