#include "InputTranslator.h"

#include "SceneManager.h"

BEGIN_CM_NAMESPACE
void InputTranslator::startLoop() {
  while (true) {
    CMInputEvent *e = translateInputEvent();
    if (e) {
      CMApplication::postEvent(CMApplication::instance(), e);
    }
  }
}
END_CM_NAMESPACE