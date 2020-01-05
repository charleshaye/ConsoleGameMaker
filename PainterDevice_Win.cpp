#include "PainterDevice_Win.h"
#include <qstring.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "Resources.h"
BEGIN_CM_NAMESPACE


PainterDevice_Win::PainterDevice_Win():
    deviceHeight(237),
    deviceWidth(60),
    hOutBuf(CreateConsoleScreenBuffer(GENERIC_WRITE, FILE_SHARE_WRITE, NULL,
                                        CONSOLE_TEXTMODE_BUFFER, NULL)) ,
    hOutput(CreateConsoleScreenBuffer(GENERIC_WRITE, FILE_SHARE_WRITE, NULL,
                                        CONSOLE_TEXTMODE_BUFFER, NULL)) ,
    NotActiveBuf(hOutput)
{
  DWORD mode;
  HANDLE stdIn = GetStdHandle(STD_INPUT_HANDLE);
  GetConsoleMode(stdIn, &mode);
  mode &= ~ENABLE_QUICK_EDIT_MODE;  //
  mode &= ~ENABLE_INSERT_MODE;      //
  SetConsoleMode(stdIn, mode);
  COORD SIZE = {static_cast<SHORT>(getDeviceHeight()),
                static_cast<SHORT>(getDeviceWidth())};
  SetConsoleScreenBufferSize(hOutBuf, SIZE);
  SetConsoleScreenBufferSize(hOutput, SIZE);
  CONSOLE_CURSOR_INFO cci{1, 0};
  SetConsoleCursorInfo(NotActiveBuf, &cci);
  SetConsoleCursorInfo(hOutBuf, &cci);
  // SetConsoleActiveScreenBuffer(hOutput);
}

void PainterDevice_Win::flushScreen() {
  if (NotActiveBuf == hOutBuf) {
    SetConsoleActiveScreenBuffer(hOutBuf);
    NotActiveBuf = hOutput;
  } else {
    SetConsoleActiveScreenBuffer(hOutput);
    NotActiveBuf = hOutBuf;
  }
}

//size_t checkParam(size_t deviceWidth,size_t deviceHeight,const QPoint &start, size_t length, Direction dirc) {
//  switch (dirc) {
//    case Direction::UP:
//      if (start.y() - length < 0) return start.y() - 1;
//      break;
//    case Direction::DOWN:
//      if (start.y() + length > deviceWidth)
//        return deviceHeight - start.y() - 1;
//      break;
//    case Direction::LEFT:
//      if (start.x() - length < 0) return start.x() - 1;
//      break;
//    case Direction::RIGHT:
//      if (start.x() + length > deviceHeight)
//        return deviceHeight - start.x() - 1;
//      break;
//    default:
//      break;
//  }
//  return length;
//}

inline DWORD TranslateColor(FontColor font, BackColor back) {
  return DWORD(font) | DWORD(back);
}

void PainterDevice_Win::drawLine(const QPoint &start, size_t length, char_t ch,
                                 Direction dirc, FontColor font,
                                 BackColor back) {
  SHORT realLength = checkParam(getDeviceWidth(),getDeviceHeight(),start, length, dirc);
  SHORT X = start.x();
  SHORT Y = start.y();
  SetConsoleTextAttribute(NotActiveBuf, TranslateColor(font, back));
  DWORD num;
  switch (dirc) {
    case Direction::UP:
      for (int i = 0; i < realLength; i++) {
        FillConsoleOutputCharacter(NotActiveBuf, ch.unicode(), 1,
                                   {X, (SHORT)(Y - i)}, &num);
      }
      break;
    case Direction::DOWN:
      for (int i = 0; i < realLength; i++) {
        FillConsoleOutputCharacter(NotActiveBuf, ch.unicode(), 1,
                                   {X, (SHORT)(Y + i)}, &num);
      }
      break;
    case Direction::LEFT:
      FillConsoleOutputCharacter(NotActiveBuf, ch.unicode(), realLength,
                                 {X - realLength, Y}, &num);
      break;
    case Direction::RIGHT:
      FillConsoleOutputCharacter(NotActiveBuf, ch.unicode(), realLength, {X, Y},
                                 &num);
      break;
    default:
      break;
  }
}

void PainterDevice_Win::drawChar(const QPoint &point, char_t ch, FontColor font,
                                 BackColor back) {
  COORD coord{static_cast<SHORT>(point.x()), static_cast<SHORT>(point.y())};
  DWORD res;
  FillConsoleOutputCharacter(NotActiveBuf, ch.unicode(), 1, coord, &res);
}

void PainterDevice_Win::drawRect(const QRect &rect, char_t ch, bool isSolidCore,
                                 FontColor font, BackColor back) {
  if (isSolidCore) {
    COORD coord{static_cast<SHORT>(rect.topLeft().x()),
                static_cast<SHORT>(rect.topLeft().y())};

    DWORD num;

    SetConsoleTextAttribute(NotActiveBuf, TranslateColor(font, back));

    for (SHORT i = 0; i < rect.height(); i++) {
      FillConsoleOutputCharacter(NotActiveBuf, ch.unicode(), rect.width(),
                                 {static_cast<SHORT>(rect.topLeft().x()), i},
                                 &num);
    }
  } else {
    drawLine(rect.topLeft(), rect.width(), ch, Direction::RIGHT, font, back);

    drawLine(rect.topLeft() += {0, 1}, rect.height(), ch, Direction::DOWN, font,
             back);

    drawLine(rect.topRight() += {0, 1}, rect.height(), ch, Direction::DOWN,
             font, back);

    drawLine(rect.bottomLeft(), rect.width(), ch, Direction::RIGHT, font, back);
  }
}

void PainterDevice_Win::drawText(const QString &text, const QPoint &point,
                                 FontColor font, BackColor back) {
  DWORD res;
  for (int i = 0; i < text.size(); i++) {
    FillConsoleOutputCharacter(NotActiveBuf, text[i].unicode(), 1,
                               {(SHORT)(point.x() + i), (SHORT)point.y()},
                               &res);
  }
}

END_CM_NAMESPACE