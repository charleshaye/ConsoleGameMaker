#include "PainterDevice.h"
BEGIN_CM_NAMESPACE
int PainterDevice::calStringWidth(const QString& str) CM_NOEXCEPT {
  size_t width = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i].unicode() <= 0x7F && str[i].unicode() > 0x00) {
      ++width;
    } else
      width += 2;
  }
  return width;
}
END_CM_NAMESPACE