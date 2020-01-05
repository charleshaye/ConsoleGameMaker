#pragma once
// Created on 2019-10-12   23: 32: 29
// Platform: Windows 10 1903
// Namespace:
// Title: No Title

#include <QStack>
#include <QVector>
#include <memory>
#include "CMTransform.h"
#include "CMUpdater.h"
#include "Scene.h"

BEGIN_CM_NAMESPACE

class Scene;
class Object : public QObject {
  Q_OBJECT

 public:
  Q_INVOKABLE Object(Object* parent = nullptr, const QString& Name = "");

  Object* parent() const CM_NOEXCEPT {
    return static_cast<Object*>(QObject::parent());
  }

  void setParent(QObject* par) CM_NOEXCEPT {
    QObject::setParent(par);
    scene = static_cast<Object*>(par)->scene;
  }

  template <class T>
  Ptr<T> getComponent() {
    return scene->getComponent<T>(this);
  }

  template <class T>
  auto getComponents() {
    QVector<Ptr<T>> res;
    auto pCom = scene->getComponent<T>(this);
    if (pCom) res.push_back(pCom);
    traverseChildren([= this->parentScene, &res](Object* p) {
      auto pComp = scene->getComponent<T>(p);
      if (pComp) res.push_back(pComp);
    });
    return res;
  }

  template <class T>
  Ptr<T> getComponentFromChildren() {
    auto thisCom = scene->getComponent<T>(Id);
    if (thisCom == nullptr) {
      for (auto child : children()) {
        return scene->getComponent<T>(static_cast<Object*>(child));
      }
    }
    return nullptr;
  }

  template <class T>
  Ptr<T> addComponent() {
    return scene->addComponent<T>(this);
  }

  template <class T>
  void removeComponet() {
    scene->removeComponent<T>(this);
  }

  template <class TraverFunc>
  void traverseChildren(TraverFunc func) {
    QStack<Object*> stack;
    for (auto child : children()) {
      stack.push(static_cast<Object*>(child));
    }
    while (!stack.empty()) {
      auto lpNode = stack.top();
      stack.pop();
      func(lpNode);
      for (auto child : lpNode->children()) {
        stack.push(static_cast<Object*>(child));
      }
    }
  }

  Scene* parentScene() const CM_NOEXCEPT { return scene; }

  void broadcastMethod(const char* methodName) {
    traverseChildren(
        [=](Object* p) { QMetaObject::invokeMethod(p, methodName); });
  }

  void invokeMethod(const char* methodName) {
    QMetaObject::invokeMethod(this, methodName);
  }
  virtual Object* clone();

  virtual QString toString();

  CMTransform transform;

  bool isactive;

 private:
  friend class Scene;
  Scene* scene;
  static QHash<QByteArray, const QMetaObject*> metas;

 public:
  template <typename T>
  static void registerObject() {
    metas.insert(T::staticMetaObject.className(), &(T::staticMetaObject));
  }
  static Ptr<Object> createObject(const QByteArray& type) {
    const QMetaObject* meta = metas.value(type);
    return Ptr<Object>{static_cast<Object*>(meta->newInstance())};
  }
  static Ptr<Object> createObject(const QString& type) {
    const QMetaObject* meta = metas.value(type.toLocal8Bit());
    return Ptr<Object>{static_cast<Object*>(meta->newInstance())};
  }
};

// @brief:安全的父类指针向下转型，无需RTTI
// @param:Object* :指向Object子类的指针
// @ret:要转换类型的指针
// @birth:created  on 2019  10  12
template <class T, is_derived_t<Object, T>>
inline STD add_pointer_t<T> object_cast(Object* obj) {
  return qobject_cast<STD add_pointer_t<T>>(obj);
}

template <class _Des_t, class _Ori_t>
inline Ptr<_Des_t> object_cast(Ptr<_Ori_t> obj) {
  return Ptr<_Des_t>{qobject_cast<STD add_pointer_t<_Des_t>>(obj.get())};
}

template <class _Des_t, class _Ori_t>
inline Owner<_Des_t> object_cast(Owner<_Ori_t>& obj) {
  auto rawPointer = obj.release();
  return qobject_cast< STD add_pointer_t<_Des_t> >( rawPointer );
}

END_CM_NAMESPACE
