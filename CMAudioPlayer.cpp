#include "CMAudioPlayer.h"
BEGIN_CM_NAMESPACE
CMAudioPlayer::CMAudioPlayer(Object* attachedObject)
    : CMComponent(attachedObject) {}
Owner<CMComponent> CMAudioPlayer::clone() {
  return STD make_unique<CMAudioPlayer>(object());
}
QString CMAudioPlayer::toString() { return QString(); }
END_CM_NAMESPACE