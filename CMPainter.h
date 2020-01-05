// Created on 2019-10-12   23: 33: 14
// Platform: Windows 10 1903
// Namespace:
// Title: No Title

#pragma once
#include "CMComponent.h"
#include "PainterDevice.h"
#include "sprite.h"

BEGIN_CM_NAMESPACE

class CMPainter : public CMComponent {
  Q_OBJECT
 public:
  using sprite_t = Sprite<Image<QChar>>;

  using pointer = Ptr<CMPainter>;

  Q_INVOKABLE explicit CMPainter(Object* attachedObject) CM_NOEXCEPT;

  sprite_t& rSprite() { return sprite; }

  Owner<CMComponent> clone() override;

  QString toString() override;

 private:
  PainterDevice* device;
  sprite_t sprite;
};

END_CM_NAMESPACE