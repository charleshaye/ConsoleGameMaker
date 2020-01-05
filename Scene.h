#pragma once
// Created on 2019-10-12   23: 33: 25
// Platform: Windows 10 1903
// Namespace:CM
// Title: No Title

#include "ComManager.h"

BEGIN_CM_NAMESPACE

class Scene : public QObject {
  Q_OBJECT
 public:
  Scene(const QString& Name);
  void addObject(Object* obj);
  bool isactive;

 private:
  friend class Object;

  template <class T>
  Ptr<T> getComponent(Object* Id) {
    // static_assert( !is_derived_v<Component, T>, "Type must be inherit from 7
    // kind of Component Type" );
    return manager.getComponent<T>(Id);
  }

  template <class T>
  Ptr<T> addComponent(Object* Id) {
    // static_assert( !is_derived_v<Component, T>, "Type must be inherit from 7
    // kind of Component Type" );
    return manager.addComponent<T>(Id);
  }

  template <class T>
  void removeComponent(Object* Id) {
    // static_assert( !is_derived_v<Component, T>, "Type must be inherit from 7
    // kind of Component Type" );
    return manager.removeComponent<T>(Id);
  }

  void cloneComs(Object* oldId, Object* newId) {
    manager.cloneComs(oldId, newId);
  }

  ComManager manager;
};

END_CM_NAMESPACE