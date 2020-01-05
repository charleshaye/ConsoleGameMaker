#include "CMUpdater.h"
BEGIN_CM_NAMESPACE
CMUpdater::CMUpdater(Object* attachedObject) : CMComponent(attachedObject) {}

Owner<CMComponent> CMUpdater::clone() { return Owner<CMUpdater>(); }

QString CMUpdater::toString() { return QString(); }

END_CM_NAMESPACE