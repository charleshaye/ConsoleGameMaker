#pragma once
namespace Resources {
extern const wchar_t *Tables;
enum class TableOrder {
  LeftTop = 0,
  MidTop,
  RightTop,
  Left,
  Mid,
  Right,
  LeftBottom,
  MidBottom,
  RightBottom,
  UpLine,
  HorizonLine
};

extern const wchar_t *RomanNum;
enum class RomanNumOrder {
  one = 0,
  two,
  three,
  four,
  five,
  six,
  seven,
  eight,
  nine,
  ten
};
}  // namespace Resources