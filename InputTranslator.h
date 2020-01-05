// Created on 2019-10-12   23: 34: 15
// Platform: Windows 10 1903
// Namespace:

// Title: No Title
#pragma once
#include "CMApplication.h"
#include "CMInputEvent.h"

BEGIN_CM_NAMESPACE
class InputTranslator : public QObject {
  Q_OBJECT
 public:
  CM_INTERFACE(InputTranslator)
  virtual CMInputEvent *translateInputEvent() = 0;

  virtual CMInputEvent *translateMouseEvent() = 0;

  virtual CMInputEvent *translateKeyBoardEvent() = 0;

  virtual CMInputEvent *translateOtherEvent() { return nullptr; }

  void startLoop();
};

END_CM_NAMESPACE
