#pragma once
#include <qrect.h>
#include <QChar>
#include "CMDefines.h"
#include "Color.h"
#include "Sprite.h"
BEGIN_CM_NAMESPACE

using char_t = QChar;
enum class Direction { UP, DOWN, LEFT, RIGHT = 3 };
struct PainterDevice {
  CM_INTERFACE(PainterDevice)
  virtual void drawChar(const QPoint &point, char_t ch,
                        FontColor font = FontColor::Default,
                        BackColor back = BackColor::Default) =0;

  virtual void drawRect(const QRect &rect, char_t ch, bool isSolidCore = false,
                        FontColor font = FontColor::Default,
                        BackColor back = BackColor::Default) =0;

  virtual void drawText(const QString &text, const QPoint &point,
                        FontColor font = FontColor::Default,
                        BackColor back = BackColor::Default) =0;

  virtual void drawLine(const QPoint &start, size_t length, char_t ch,
                        Direction dirc, FontColor font = FontColor::Default,
                        BackColor back = BackColor::Default) =0;

  virtual void flushScreen() = 0;

  static int calStringWidth(const QString &str) CM_NOEXCEPT;
};

END_CM_NAMESPACE
