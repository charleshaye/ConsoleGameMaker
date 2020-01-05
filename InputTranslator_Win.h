// Created on 2019-10-12   23: 34: 02
// Platform: Windows 10 1903
// Namespace:

// Title: No Title
#pragma once

#include <Windows.h>
#include <QScopedPointer>
#include "CMDefines.h"
#include "InputTranslator.h"

BEGIN_CM_NAMESPACE

class InputTranslator_Win : public InputTranslator {
 public:
  InputTranslator_Win(size_t screenLength = 234,
                      size_t screenWidth = 48) CM_NOEXCEPT;

  virtual ~InputTranslator_Win();

  virtual CMInputEvent *translateInputEvent() override;

 protected:

  virtual CMInputEvent *translateMouseEvent() override;


  virtual CMInputEvent *translateKeyBoardEvent() override;

 private:
  static INPUT_RECORD Rec;
  static DWORD Res;
};

END_CM_NAMESPACE
