#pragma once

#include <QRect>
#include "CMComponent.h"
#include "CMPosition.h"

BEGIN_CM_NAMESPACE
class CMCollider : public CMComponent {
  Q_OBJECT
 public:
  using Pointer = Ptr<CMCollider>;
  Q_INVOKABLE explicit CMCollider(Object* attachedObject) ;
  void setColliderWidth(int x) CM_NOEXCEPT { size.setWidth(x + 1); };

  void setColliderHeight(int x) CM_NOEXCEPT { size.setHeight(x + 1); }

  void setColliderSize(const QSize& size) CM_NOEXCEPT { this->size=size; }

  void setColliderSize(int width, int height) CM_NOEXCEPT {
      size.setHeight(height);
      size.setWidth(width);
  }
  void setColliderPos(const QPoint& point) CM_NOEXCEPT {
      position.setPos(point);
  }
  void setColliderPos(int x, int y) CM_NOEXCEPT {
      position.setPos(x, y);
  }
  void setColliderRect(int x, int y, int width, int height) CM_NOEXCEPT {
      position.setPos(x, y);
      size.setHeight(height);
      size.setWidth(width);
      
  }

  Owner<CMComponent> clone() override; 
  QString toString() override;

 private:
  bool isOverLapRect(const QRect& otherRect) const ;
  QSize size;
  CMPosition position;
};

END_CM_NAMESPACE