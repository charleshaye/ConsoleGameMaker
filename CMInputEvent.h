#pragma once
#include <qcoreevent.h>
#include <QPoint>
#include "CMDefines.h"
#include "KeyCode.h"
BEGIN_CM_NAMESPACE

using Event = QEvent;

class CMInputEvent : public QEvent {
 public:
  CMInputEvent(Type Event);
  virtual ~CMInputEvent();
};

class CMKeyEvent : public CMInputEvent {
  bool AutoRepeat;
  KeyCode keycode;
  static const Type EventType;

 public:
  inline bool isAutoRepeat() { return static_cast<bool>(AutoRepeat); }
  inline KeyCode Code() { return static_cast<KeyCode>(keycode); }
  CMKeyEvent(Type CMKeyEventType, KeyCode code, bool isAutoRep);
  virtual ~CMKeyEvent();
};

class CMMouseEvent : public CMInputEvent {
  bool DoubleClicked;
  MouseButton button;
  static const Type EventType;
  QPoint mousePosition;

 public:
  inline bool isDoubleClicked() { return DoubleClicked; }
  inline bool isAutoRepeat() { return static_cast<bool>(DoubleClicked); }
  inline MouseButton Code() { return static_cast<MouseButton>(button); }
  CMMouseEvent(Type Event);
  CMMouseEvent(Type CMMouseEventType, MouseButton code, QPoint position);
  virtual ~CMMouseEvent();
};

namespace UserEvent { 
    extern const QEvent::Type MouseMoveEvent;
    extern const QEvent::Type MouseWheelEvent;
}

END_CM_NAMESPACE