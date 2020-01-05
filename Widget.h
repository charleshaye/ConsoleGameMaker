#pragma once
// Created on 2019-10-12   23: 33: 34
// Platform: Windows 10 1903
// Namespace:

// Title: No Title

#include <qrect.h>
#include "CMInputEvent.h"
#include "Object.h"

BEGIN_CM_NAMESPACE
class Widget:public Object {
    Q_OBJECT
 public:
  Widget(Object *parent = nullptr, const QString &Name = "");

  // @brief:鼠标双击本窗口调用
  // @param:CMMouseEvent* 鼠标事件
  // @ret:bool 是否调用完成
  // @birth:created  on 2019  10  12
  virtual void mouseDoubleClickEvent(CMMouseEvent *);

  // @brief:鼠标单击本窗口调用
  // @param:CMMouseEvent* 鼠标事件
  // @ret:bool 是否调用完成
  // @birth:created  on 2019  10  12
  virtual void mouseClickEvent(CMMouseEvent *);

  // @brief:鼠标于本窗口释放调用
  // @param:CMMouseEvent* 鼠标事件
  // @ret:bool 是否调用完成
  // @birth:created  on 2019  10  12
  virtual void mouseReleaseEvent(CMMouseEvent *);

  // @brief:按键按下调用
  // @param:CMKeyEvent* 键盘事件
  //@ret:bool 是否调用完成
  // @birth:created  on 2019  10  12
  virtual void keyPressEvent(CMKeyEvent *);

  // @brief:按键抬起调用
  // @param:CMKeyEvent* 键盘事件
  // @ret:bool 是否调用完成d
  // @birth:created  on 2019  10  12
  virtual void keyReleaseEvent(CMKeyEvent *);

  // @brief:鼠标移动时调用
  // @param:CMMouseEvent* 鼠标事件
  // @ret:bool 是否调用完成
  // @birth:created  on 2019  10  12
  virtual void mouseMoveEvent(CMMouseEvent *);

  virtual void mouseEnterEvent(CMMouseEvent *) {}

  virtual ~Widget() {}

 private:
  friend class Application;
  friend class Scene;
};

END_CM_NAMESPACE