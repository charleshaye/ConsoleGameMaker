#include "CMInputEvent.h"

BEGIN_CM_NAMESPACE
namespace UserEvent {
    const QEvent::Type MouseMoveEvent =
        ( QEvent::Type )QEvent::registerEventType(QEvent::User + 102);
    const QEvent::Type MouseWheelEvent =
        ( QEvent::Type )QEvent::registerEventType(QEvent::User + 101);
}
CMInputEvent::CMInputEvent(Type Event):QEvent(Event) {

}

CMInputEvent::~CMInputEvent() {
}


CMKeyEvent::CMKeyEvent(Type keyEventType, KeyCode code,bool isAutoRep):
    CMInputEvent(keyEventType) {
}

CMKeyEvent::~CMKeyEvent() {


}

CMMouseEvent::CMMouseEvent(Type Event):CMInputEvent(Event) {



}

CMMouseEvent::CMMouseEvent(Type MouseEventType, MouseButton code,QPoint position):CMInputEvent(MouseEventType) {
}

CMMouseEvent::~CMMouseEvent() {
}


END_CM_NAMESPACE
