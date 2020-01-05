#pragma once
#include <QObject>
#include <memory>
#include "CMDefines.h"
#ifdef _CM_HAS_EXCEPTION
#include "CMExceptions.h"
#endif

BEGIN_CM_NAMESPACE
class CMTransform;
class Object;
class CMComponent;
using ObjectId_t = quint32;

template <class T>
using Ptr = STD shared_ptr<T>;

template <class T>
using Owner = STD unique_ptr<T>;

class CMComponent : public QObject {
  Q_OBJECT
 public:
  using Pointer = Ptr<CMComponent>;

  Q_INVOKABLE explicit CMComponent(Object* attachedObject);
  Object* object() { return attachedObject; }

  bool isActive() const CM_NOEXCEPT { return isactive; }

  void setActive(bool flag = true) CM_NOEXCEPT { isactive = flag; }

  virtual Owner<CMComponent> clone();

  virtual QString toString();

  virtual void moveToObject(Object* des);

 private:
  friend class Object;
  Object* attachedObject;
  CMTransform* objectTransform;
  bool isactive;
};
END_CM_NAMESPACE