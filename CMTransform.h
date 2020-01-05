
#pragma once
#include "CMComponent.h"
#include "CMPosition.h"
BEGIN_CM_NAMESPACE
class CMTransform : public CMComponent {
  Q_OBJECT
 public:
  using Pointer = Ptr<CMTransform>;

  enum OFFSET { WORLD, LOCAL };
  Q_INVOKABLE explicit CMTransform(Object* attachedObject);

  CMPosition transform(const CMPosition& offset, OFFSET type);

  CMPosition worldToLocal(const CMPosition& worldPos);

  CMPosition localToWorld(const CMPosition& localPos);

  CMPosition localPosition() { return worldToLocal(world); }

  CMPosition& getPosition() const { return world; }

  void setPosition(const CMPosition& worldPos) { world = worldPos; }

  int manhattanDis(const CMPosition& point);

  int chebyshevDis(const CMPosition& point);

  Owner<CMComponent> clone() override;

  QString toString() override;

 private:
  CMPosition world;
};

END_CM_NAMESPACE
