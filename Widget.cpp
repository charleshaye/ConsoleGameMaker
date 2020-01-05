#include "Widget.h"
#include "Resources.h"

BEGIN_CM_NAMESPACE
Widget::Widget(Object *parent, const QString &Name) {}

// WidgetPrivate::WidgetPrivate():isMouseEnter(false) {
//
//}
//
// void Widget::paintEvent() {
//	using namespace Resources;
//	const QRect& thisRect = GetRect();
//	int width = thisRect.width();
//	device->drawChar(thisRect.topLeft(),Tables[(int) TableOrder::LeftTop ]);
//	device->drawLine(thisRect.topLeft() += {1, 0}, thisRect.width()-3,
//Tables[(int) TableOrder::HorizonLine],Direction::RIGHT);
//	device->drawChar(thisRect.topRight(),Tables[(int) TableOrder::RightTop
//]);
//
//	device->drawLine(thisRect.topLeft() += {0, 1}, thisRect.height()-1,
//Tables[(int) TableOrder::UpLine],Direction::DOWN);
//	device->drawLine(thisRect.topRight() += {0, 1},
//thisRect.height()-1,Tables[(int) TableOrder::UpLine], Direction::DOWN);
//
//	device->drawChar(thisRect.bottomLeft(),Tables[(int)
//TableOrder::LeftBottom  ]); 	device->drawLine(thisRect.bottomLeft() += {1, 0},
//thisRect.width()-1,Tables[(int) TableOrder::HorizonLine], Direction::RIGHT);
//	device->drawChar(thisRect.bottomRight(),Tables[(int)
//TableOrder::RightBottom  ]);
//
//}
//
// Widget::~Widget() {}
//
//
//
// Widget::Widget(Object* parent, const QString& Name)
//	: I_ptr(new WidgetPrivate()),
//
//{
//
//}
//
//
//
// void Widget::mouseEnterEvent(CMMouseEvent*) {
//}
//
//
//	/*switch (e->type()) {
//		case Event::MouseButtonDblClick:
//			mouseDoubleClickEvent(static_cast< CMMouseEvent* >( e ));
//			break;
//
//		case Event::MouseButtonPress:
//			mouseClickEvent(static_cast< CMMouseEvent* >( e ));
//			break;
//
//		case Event::MouseButtonRelease:
//			mouseReleaseEvent(static_cast< CMMouseEvent* >( e ));
//			break;
//
//		case Event::MouseMove:
//			mouseMoveEvent(static_cast< CMMouseEvent* >( e ));
//			break;
//
//		case CMMouseEvent::mouseEnterEvent:
//			mouseEnterEvent(static_cast< CMMouseEvent* >( e ));
//			break;
//
//		case Event::KeyPress:
//			keyPressEvent(static_cast< CMKeyEvent* >( e ));
//			break;
//
//		case Event::KeyRelease:
//			keyReleaseEvent(static_cast< CMKeyEvent* >( e ));
//			break;
//		default:
//			return QObject::event(e);
//			break;
//	}
//	return true;*/
//
//
//
//
//
void Widget::mouseDoubleClickEvent(CMMouseEvent *e) { e->ignore(); }

void Widget::mouseClickEvent(CMMouseEvent *e) { e->ignore(); }

void Widget::mouseReleaseEvent(CMMouseEvent *e) { e->ignore(); }

void Widget::keyPressEvent(CMKeyEvent *e) { e->ignore(); }

void Widget::keyReleaseEvent(CMKeyEvent *e) { e->ignore(); }
void Widget::mouseMoveEvent(CMMouseEvent *e) { e->ignore(); }

END_CM_NAMESPACE