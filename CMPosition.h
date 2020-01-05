#pragma once
#include "CMDefines.h"
BEGIN_CM_NAMESPACE
class CMPosition {
 public:
     CMPosition() : pos() {}

     CMPosition(int x, int y) : pos(x, y) {}

     CMPosition(const QPoint& point) : pos(point) {}

  void setPos(const QPoint& point) { pos = point; }

  void setPos(int x, int y) { pos = {x, y}; }

  int x() const { return pos.x(); }

  int y() const { return pos.y(); }

  int& rX() { return pos.rx(); }

  int& rY() { return pos.ry(); }

  CMPosition manhattanLength(const CMPosition& position);

  int dot(const CMPosition& CMPosition);

  inline CMPosition& operator=(const CMPosition& CMPosition) = default;

  inline CMPosition& operator+=(const CMPosition& offset);

  inline const bool operator!=(const CMPosition& CMPosition);

  inline const bool operator==(const CMPosition& CMPosition);

  inline CMPosition& operator-=(const CMPosition& offset);

  inline CMPosition& operator*=(int factor);

  inline CMPosition& operator/=(int factor);

  friend const CMPosition operator+(const CMPosition& pos,
                                    const CMPosition& offset);
  friend const CMPosition operator-(const CMPosition& pos,
                                    const CMPosition& offset);
  friend const CMPosition operator*(const CMPosition& pos, int factor);
  friend const CMPosition operator/(const CMPosition& pos, int factor);
 private:
  QPoint pos;
};


inline const CMPosition operator+(const CMPosition& pos, const CMPosition& offset) {
  return {pos.pos + offset.pos};
}

inline const CMPosition operator-(const CMPosition& pos, const CMPosition& offset) {
  return {pos.pos - offset.pos};
}

inline const CMPosition operator*(const CMPosition& pos, int factor) {
  return {pos * factor};
}

inline const CMPosition operator/(const CMPosition& pos, int factor) {
  return {pos / factor};
}
inline CMPosition CMPosition::manhattanLength(const CMPosition& position) {
  return {abs(position.x() - pos.x()), abs(position.y() - pos.y())};
}

inline int CMPosition::dot(const CMPosition& CMPosition) {
  return QPoint::dotProduct(pos, CMPosition.pos);
}

inline const bool CMPosition::operator!=(const CMPosition& CMPosition) {
  return pos != CMPosition.pos;
}

inline const bool CMPosition::operator==(const CMPosition& CMPosition) {
  return pos == CMPosition.pos;
}

inline CMPosition& CMPosition::operator-=(const CMPosition& offset) {
  pos -= offset.pos;
  return *this;
}

inline CMPosition& CMPosition::operator*=(int factor) {
  pos *= (factor);
  return *this;
}

inline CMPosition& CMPosition::operator/=(int factor) {
  pos /= (factor);
  return *this;
}
inline CMPosition& CMPosition::operator+=(const CMPosition& offset) {
  pos += (offset.pos);
  return *this;
}

END_CM_NAMESPACE