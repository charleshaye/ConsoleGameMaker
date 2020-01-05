#include "CMCamera.h"
BEGIN_CM_NAMESPACE

CMCamera::CMCamera(Object* id) : CMComponent(id) {}

Owner<CMComponent> CMCamera::clone() {
  auto comp = STD make_unique<CMCamera>(object());
  comp->cameraRect = cameraRect;
  return comp;
}

QString CMCamera::toString() { return QString(); }

END_CM_NAMESPACE