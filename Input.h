#pragma once
#include <QObject>
#include <QScopedPointer>
#include "InputTranslator.h"

BEGIN_CM_NAMESPACE
class Input final : public QObject {
  Q_OBJECT
  static QScopedPointer<InputTranslator> translator;

 public:
  Input();
  static void readInput();
  static bool getMouseDown();
  static bool getKeyDown();
  static KeyCode getKey();
  static MouseButton getMouse();
};
END_CM_NAMESPACE
