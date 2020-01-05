#include "InputTranslator_Win.h"

#include <qdebug.h>

#include <iostream>

#include "KeyCode.h"
BEGIN_CM_NAMESPACE

INPUT_RECORD InputTranslator_Win::Rec;
DWORD InputTranslator_Win::Res;

CMInputEvent *InputTranslator_Win::translateMouseEvent() {
  MouseButton button{MouseButton::Mouse_Left};
  switch (Rec.Event.MouseEvent.dwButtonState) {
    case FROM_LEFT_1ST_BUTTON_PRESSED:  //
      break;
    case FROM_LEFT_2ND_BUTTON_PRESSED:
      button = MouseButton::Mouse_Mid;  //
      break;
    case RIGHTMOST_BUTTON_PRESSED:
      button = MouseButton::Mouse_Right;  //
      break;
    case FROM_LEFT_3RD_BUTTON_PRESSED:  //
      break;
    case FROM_LEFT_4TH_BUTTON_PRESSED:  //
      break;
    default:
      break;
  }
#define MOUSE_CLICK 0x0000
  static bool down{false};
  QPoint mousePosition{Rec.Event.MouseEvent.dwMousePosition.X,
                       Rec.Event.MouseEvent.dwMousePosition.Y};  //
  switch (Rec.Event.MouseEvent.dwEventFlags) {
    case MOUSE_CLICK:
      if (down) {
        down = false;
        return new CMMouseEvent(Event::MouseButtonRelease, button,
                                mousePosition);  //
      } else {
        down = true;
        return new CMMouseEvent(Event::MouseButtonPress, button,
                                mousePosition);  //
      }

    case MOUSE_MOVED:
      return new CMMouseEvent(Event::MouseMove, button,
                              mousePosition);  //

    case DOUBLE_CLICK:
      return new CMMouseEvent(Event::MouseButtonDblClick, button,
                              mousePosition);  //

    case MOUSE_WHEELED:
      return new CMMouseEvent(UserEvent::MouseWheelEvent, button,
                              mousePosition);  //

    default:
      return nullptr;
  }
}

/// <summary>MyMethod is a method in the <c>MyClass</c> class.
/// </summary>
CMInputEvent *InputTranslator_Win::translateKeyBoardEvent() {
  KeyCode code = static_cast<KeyCode>(Rec.Event.KeyEvent.wVirtualKeyCode);
  if (Rec.Event.KeyEvent.bKeyDown) {
    return new CMKeyEvent(QEvent::KeyPress, code, false);
  }
  return new CMKeyEvent(QEvent::KeyRelease, code, false);
}

CMInputEvent *InputTranslator_Win::translateInputEvent() {
  DWORD num;
  ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &Rec, 1, &num);

  CMInputEvent *input{nullptr};

  if (Rec.EventType == KEY_EVENT || Rec.EventType == MOUSE_EVENT) {
    if (Rec.EventType == MOUSE_EVENT) {
      return translateMouseEvent();
    } else {
      return translateKeyBoardEvent();
    }
  }
  return translateOtherEvent();
}

InputTranslator_Win::InputTranslator_Win(size_t ScreenLength,
                                         size_t ScreenWidth) CM_NOEXCEPT {
  memset(&Rec, 0, sizeof(INPUT_RECORD));
}

InputTranslator_Win::~InputTranslator_Win() {}
END_CM_NAMESPACE