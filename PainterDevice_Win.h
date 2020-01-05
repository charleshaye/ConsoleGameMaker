#pragma once

#include <Windows.h>
#include <QScopedPointer>
#include "CMTypeTraits.h"
#include "PainterDevice.h"
BEGIN_CM_NAMESPACE
class PainterDevice_Win : public PainterDevice {
 public:
  PainterDevice_Win();
   void drawChar(const QPoint &point, char_t ch,
                        FontColor font = FontColor::Default,
                        BackColor back = BackColor::Default) override;

   void drawRect(const QRect &rect, char_t ch, bool isSolidCore = false,
                        FontColor font = FontColor::Default,
                        BackColor back = BackColor::Default) override;

   void drawText(const QString &text, const QPoint &point,
                        FontColor font = FontColor::Default,
                        BackColor back = BackColor::Default) override;

   void drawLine(const QPoint &start, size_t length, char_t ch,
                        Direction dirc, FontColor font = FontColor::Default,
                        BackColor back = BackColor::Default) override;

   void flushScreen() override;

   size_t getDeviceHeight() const { return deviceHeight; }

   size_t getDeviceWidth() const { return deviceWidth; }

 private:
  CM_NO_COPY(PainterDevice_Win)
  size_t deviceHeight;
  size_t deviceWidth;
  HANDLE hOutBuf;
  HANDLE hOutput;
  HANDLE NotActiveBuf;
};

END_CM_NAMESPACE
