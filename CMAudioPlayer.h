#pragma once
#include "CMComponent.h"

BEGIN_CM_NAMESPACE

class CMAudioPlayer final : public CMComponent {
  Q_OBJECT
 public:
  using Pointer = Ptr<CMAudioPlayer>;
  Q_INVOKABLE explicit CMAudioPlayer(Object* attachedObject);
  Owner<CMComponent> clone() override;

  QString toString() override;
};
END_CM_NAMESPACE
