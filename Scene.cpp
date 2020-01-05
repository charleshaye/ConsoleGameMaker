#include "Scene.h"

#include "Widget.h"
BEGIN_CM_NAMESPACE
Scene::Scene(const QString& Name) : isactive(false) {
  setObjectName("__Root Scene__");
}
void Scene::addObject(ObjectPtr obj) {
  obj->setParent(this);
  obj->scene = this;
}

Widget* FindWidget(Widget* widget, const QPoint& pos) {
  /*for (auto child : widget->children()) {
          if (static_cast<Object*>(child)->isEventReceiver()) {
                  if (static_cast< Widget* >( child )->GetRect().contains(pos))
  { return static_cast< Widget* >(child);
                  }
                  else {
                          return FindWidget(static_cast< Widget* >(child),pos);
                  }
          }
  }*/
  return widget;
}

//
// bool Scene::event(Event *e) {
//	if (isActive()) {
//		//switch (e->type()) {
//		//	case Event::MouseButtonDblClick:
//		//	case Event::MouseButtonPress:
//		//	case Event::MouseButtonRelease:
//		//	//case Event::MouseMove:
//		//		for (auto obj : children()) {
//		//			if (static_cast< Object* >( obj
//)->isEventReceiver()) {
//		//				auto mouseEvent = static_cast<
// MouseEvent* >( e );
//		//				if (static_cast< Widget* >( obj
//)->GetRect().contains(mouseEvent->mousePos())) {
//		//					return FindWidget(
//		//						static_cast< Widget* >(
//obj
//),
//		//						static_cast< MouseEvent*
//>( e )->mousePos())
//		//						->event(e);
//		//				}
//		//			}
//		//		}
//		//		break;
//		//	case Event::KeyPress:
//		//	case Event::KeyRelease:
//		//		traverseChildren([ = ] (Object* obj) {
//		//			if (obj->isEventReceiver()) {
//		//				obj->event(e);
//		//			}
//		//		});
//		//		break;
//		//	default:
//		//		customEvent(e);
//		//		break;
//		//}
//	}
//	return true;
//}

END_CM_NAMESPACE