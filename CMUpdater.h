#pragma once
#include "CMComponent.h"
#include "CMInputEvent.h"

BEGIN_CM_NAMESPACE
class CMUpdater : public CMComponent {
  Q_OBJECT
 public:
  using Pointer = Ptr<CMUpdater>;
  Q_INVOKABLE explicit CMUpdater(Object* attachedObject);
  virtual void onStart() {}
  virtual void onActive() {}
  virtual void onUpdate() {}
  virtual void onFixedTimeUpdate() {}
  virtual void onDeActive() {}
  virtual void onDestroy() {}
  virtual void onMouseDown(CMMouseEvent* e) {}
  virtual void onMouseEnter(CMMouseEvent* e) {}
  virtual void onMouseExit(CMMouseEvent* e) {}
  virtual void onMouseUp(CMMouseEvent* e) {}
  virtual void onTriggerEnter(Object* other) {}
  virtual void onCollision(Object* other) {}
  virtual void onVisible() {}
  virtual void onInvisible() {}


  Owner<CMComponent> clone() override;
  

  QString toString() override;
};

END_CM_NAMESPACE