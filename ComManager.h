#pragma once
#include <tuple>
#include <vector>
#include "CMTypeTraits.h"
#include "Coms.h"
#include "Object.h"
BEGIN_CM_NAMESPACE

class ComManager {
 public:
  template <class T>
  using ComPair = STD pair<Object*, Ptr<T>>;

  template <class T>
  using Container_t = STD vector<ComPair<T>>;

  template <class COM_t>
  auto addComponent(Object* attachedObject) {
    auto ptr = STD make_shared<COM_t>(attachedObject);
    GetContainer<COM_t>().push_back(ComPair<COM_t>{attachedObject, ptr});
    return ptr;
  }

  template <class COM_t>
  auto getComponent(Object* attachedObject) {
    return getComHelper<COM_t>(Getcontainer<COM_t>(), attachedObject);
  }

  template <class COM_t>
  void removeComponent(Object* attachedObject) {
    removeComHelper<COM_t>(GetContainer<COM_t>(), attachedObject);
  }

  void cloneComs(Object* oldId, Object* newId) {
    STD apply(
        [oldId, newId](auto&... cons) {
          return (traverseCon(cons, oldId, newId), ...);
        },
        Containers);
  }

 private:
  template <class T>
  Container_t<is_derived_t<CMUpdater, T>>& GetContainer() {
    return STD get<0>(Containers);
  }

  template <class T>
  Container_t<is_derived_t<CMAudioPlayer, T>>& GetContainer() {
    return STD get<1>(Containers);
  }

  template <class T>
  Container_t<is_derived_t<CMAnimator, T>>& GetContainer() {
    return STD get<2>(Containers);
  }

  template <class T>
  Container_t<is_derived_t<CMCollider, T>>& GetContainer() {
    return STD get<3>(Containers);
  }

  template <class T>
  Container_t<is_derived_t<CMCamera, T>>& GetContainer() {
    return STD get<4>(Containers);
  }

  template <class T>
  Container_t<is_derived_t<CMPainter, T>>& GetContainer() {
    return STD get<5>(Containers);
  }

  template <class COM_t>
  auto getComHelper(Container_t<COM_t>& container, Object* attachedObject) {
    auto res = STD find_if(container.begin(), container.end(),
                            [attachedObject](const ComPair<COM_t>& pair) {
                              return (pair.first == attachedObject) &&
                                     object_cast<COM_t>(pair.second);
                            });

    if (res != container.end())
      return res->second;
    else
      return nullptr;
  }
  template <class COM_t>
  void removeComHelper(Container_t<COM_t>& container,
                       Object* attachedObject) {
    auto it = STD find_if(container.begin(), container.end(),
                           [attachedObject](const ComPair<COM_t>& pair) {
                             return (pair.first == attachedObject) &&
                                    object_cast<COM_t>(pair.second);
                           });
    if (it != container.end()) {
      STD swap(*it, container.back());
      container.pop_back();
    }
  }
  template <class T>
  static void traverseCon(Container_t<T>& con, Object* oldId,
      Object* newId) {
      using pair_t = typename Container_t<T>::value_type;
      using RawPointer = STD add_pointer_t<T>;
      for (auto& e : con) {
          if (e.first == oldId) {
              auto cloned = e.second->clone();
#ifdef _CM_HAS_EXCEPTION
              cloned = object_cast< RawPointer >( cloned );
              if (!cloned)
                  throw Clone_Failed_Exception(T::staticMetaObject.className(),
                      cloned->metaObject()->className());
#endif  // _CM_HAS_EXCEPTION
              con.push_back(pair_t{ newId, static_cast< RawPointer >( cloned.release() ) });
          }
      }
  }
    STD tuple<Container_t<CMUpdater>, Container_t<CMAudioPlayer>,
               Container_t<CMAnimator>, Container_t<CMCollider>,
               Container_t<CMCamera>, Container_t<CMPainter>>
        Containers;
    friend class Scene;
  };

  END_CM_NAMESPACE