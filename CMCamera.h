#pragma once

#include <QRect>
#include "CMComponent.h"

BEGIN_CM_NAMESPACE

class CMCamera : public CMComponent {
  Q_OBJECT
 public:
  using Pointer = Ptr<CMCamera>;
  Q_INVOKABLE CMCamera(Object* id);
  Owner<CMComponent> clone() override;

  QString toString() override;

 private:
  QSize cameraRect;
};
END_CM_NAMESPACE
