// Created on 2019-10-12   23: 36: 01
// Platform: Windows 10 1903
// Namespace:

// Title: No Title
#pragma once

#include <QPropertyAnimation>
#include <QStateMachine>
#include "Animation.h"
#include "CMPainter.h"

BEGIN_CM_NAMESPACE

class CMAnimator final : public CMComponent {
  Q_OBJECT
 public:
  Q_INVOKABLE explicit CMAnimator(Object* attachedObject);
  void addAnimation(Animation anime);
  void addState();
  void Start();
   Owner<CMComponent> clone()override;
   QString toString()override;

 private:
  QStateMachine stateMachine;
  Ptr<PainterDevice> device;
};

END_CM_NAMESPACE
