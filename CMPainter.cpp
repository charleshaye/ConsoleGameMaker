#include "CMPainter.h"
#include "PainterDevice_Win.h"
#include "CMApplication.h"
BEGIN_CM_NAMESPACE
CMPainter::CMPainter(Object* attachedObject) CM_NOEXCEPT
    : CMComponent(attachedObject),
      priority(0),
      device(CMApplication::getPainterDevice())
{}

Owner<CMComponent> CMPainter::clone() {
  auto newPtr = STD make_unique<CMPainter>(object());
  newPtr->device = device;
  newPtr->setActive(isActive());
  newPtr->priority = priority;
  return newPtr;
}
QString CMPainter::toString() { return CMComponent::toString(); }
END_CM_NAMESPACE