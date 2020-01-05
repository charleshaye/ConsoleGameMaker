#pragma once

#include <QString>
#include <array>
#include "CMDefines.h"

BEGIN_CM_NAMESPACE
template <class Char_t>
class Image {
  Image(int width, int height) {
    img.resize(height);
    for (size_t i = 0; i < height; i++) {
      img[i].resize(width);
    }
  }

  Image(STD initializer_list<Char_t> list) : img(list) {}

  QVector<Char_t> getLine(int num) const {
    if (num > img.size() || num < 0) return QVector<Char_t>();
    return img[num];
  }

  void setLine(int num, const QVector<Char_t>& line) CM_NOEXCEPT {
    if (num > img.size() || num < 0) return;
    img[num] = line;
  }

  int lineSize() const CM_NOEXCEPT { return img.size(); }

  Image& operator=(const Image& other) { img = other.img; }

 private:
  QVector<QVector<Char_t>> img;
};

template <int width, int height, class Char_t = QChar>
class ConstImage {
  constexpr ConstImage() CM_NOEXCEPT {}

  constexpr ConstImage(STD initializer_list<Char_t> list)
      : img(list) CM_NOEXCEPT {}

  constexpr int Width() const CM_NOEXCEPT { return width; }

  constexpr int Length() const CM_NOEXCEPT { return length; }

 private:
  const STD array<STD array<Char_t, width>, height> img;
};

struct ConstSprite {};

struct DynamicSprite {};

template <class T>
class Sprite {};

template <int width, int height, class Char_t>
class Sprite<ConstImage<width, height, Char_t>> {
 public:
  Sprite(ConstImage<width, height, Char_t>* imgPtr) CM_NOEXCEPT
      : image(imgPtr) {}

  Sprite(STD initializer_list<Char_t> list) CM_NOEXCEPT : image(list) {}

  constexpr int Width() const CM_NOEXCEPT { return width; }

  constexpr int Length() const CM_NOEXCEPT { return length; }

 private:
  const ConstImage<width, height, Char_t>* image;
};

template <class Char_t>
class Sprite<Image<Char_t>> {
 public:
  Sprite() CM_NOEXCEPT {}

  Sprite(const Sprite& other) CM_NOEXCEPT { image = other.image; }

  Sprite(int width, int height) CM_NOEXCEPT : image(width, height) {}

  Sprite(STD initializer_list<Char_t> list) CM_NOEXCEPT : image(list) {}

  void setLine(int num, const QVector<Char_t>& line) CM_NOEXCEPT {
    return image->setLine(num, line);
  }

  QVector<Char_t> getLine(int num) const CM_NOEXCEPT { image->getLine(); }

  int lineSize() const CM_NOEXCEPT { return img.size(); }

  Sprite& operator=(const Sprite& other) CM_NOEXCEPT {
    image = other.image;
    return *this;
  }

 private:
  Image<Char_t>* image = nullptr;
};

END_CM_NAMESPACE
